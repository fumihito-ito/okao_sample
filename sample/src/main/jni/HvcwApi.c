/*-------------------------------------------------------------------*/
/*  Copyright(C) 2015 by OMRON Corporation                           */
/*  All Rights Reserved.                                             */
/*                                                                   */
/*   This source code is the Confidential and Proprietary Property   */
/*   of OMRON Corporation.  Any unauthorized use, reproduction or    */
/*   transfer of this software is strictly prohibited.               */
/*                                                                   */
/*-------------------------------------------------------------------*/
#include <jni.h>
#include <android/log.h>
#include <stdlib.h>
#include <pthread.h>

#include "HvcwUtils.h"


static jobject gObjCallBack          = NULL;
static jobject gObjRenderingCallBack = NULL;
static jobject gObjLiveCallBack      = NULL;
static JavaVM  *g_JavaVM;	//JavaVM情報

static pthread_mutex_t  gRenderingCallBackMutex = PTHREAD_MUTEX_INITIALIZER;

/**
 * JNIロード時に呼び出されるコールバック
 * @param	vm
 * @aram	reserved
 */
jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	// javaVMを保存
	g_JavaVM = vm;

	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNI_OnLoad call...\n");
	return JNI_VERSION_1_6;
}

/**
 * 現在のJNIEnvを取得する
 * @return	現在のJNIEnv
 */
JNIEnv* getJNIEnv(int *attach)
{
	*attach = 0;

	if(g_JavaVM == NULL){
		return NULL;
	}

	JNIEnv *env;
	jint ret = (*g_JavaVM)->GetEnv(g_JavaVM, (void**)&env, JNI_VERSION_1_6);
	if(ret == JNI_OK){
		return env;
	}
	__android_log_print(ANDROID_LOG_INFO, "Debug", "GetEnv ret:%d\n", ret);

	ret = (*g_JavaVM)->AttachCurrentThread(g_JavaVM, &env, NULL);
	if(ret == JNI_OK){
		*attach = 1;	// 自分でアタッチしたという印
		return env;
	}

	__android_log_print(ANDROID_LOG_INFO, "Debug", "AttachCurrentThread ret:%d\n", ret);
	return NULL;
}

/*
 *
 */
static HVCW_INT32 DeleteGlobalObj()
{
	int attach;
	JNIEnv *env = getJNIEnv(&attach);

	/* グローバル参照開放 */
	if(gObjCallBack != NULL){
		(*env)->DeleteGlobalRef(env, gObjCallBack);
		gObjCallBack = NULL;
	}

	if(gObjRenderingCallBack != NULL){
		(*env)->DeleteGlobalRef(env, gObjRenderingCallBack);
		gObjRenderingCallBack = NULL;
	}

	if(gObjLiveCallBack != NULL){
		(*env)->DeleteGlobalRef(env, gObjLiveCallBack);
		gObjLiveCallBack = NULL;
	}

	if(attach){
		(*g_JavaVM)->DetachCurrentThread(g_JavaVM);
	}

	return HVCW_SUCCESS;
}


/* 制御関数(コールバック関数)       */
/* Javaのコールバックメソッドを呼ぶ */
static HVCW_INT32 EventCallbackFunction(HVCW_INT32 eventId, HVCW_VOID *pUserParam, HVCW_VOID *pEventInfo)
{
	jclass     cls    = NULL;
	jmethodID  mid    = NULL;
	HVCW_INT32 nRet   = 0;
	HVCW_INT32 param1 = 0;
	HVCW_INT32 param2 = 0;

	int attach;
	JNIEnv *env = getJNIEnv(&attach);

	/* NULL チェック */
	if((gObjCallBack == NULL) || (env == NULL)){
		return HVCW_INVALID_PARAM;
	}

	if(pEventInfo != NULL){
		param2 = *((HVCW_INT32 *)pEventInfo);
	}

	/* jclassを取得する */
	cls = (*env)->GetObjectClass(env, gObjCallBack);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	/* メソッドIDを取得する */
	mid = (*env)->GetMethodID(env, cls, "eventCallback", "(IJJ)I");
	if(mid == NULL){
		return HVCW_INVALID_PARAM;
	}

	/* メソッドを呼び出す */
	nRet = (*env)->CallIntMethod(env, gObjCallBack, mid, (jint)((int)eventId), (jlong)((long)param1), (jlong)((long)param2));

	/* Free local references */
	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	if(attach){
		(*g_JavaVM)->DetachCurrentThread(g_JavaVM);
	}

	return nRet;
}

/*
 *
 */
static HVCW_INT32 JNUSetEventCallback(JNIEnv *env, jobject objCallBack, HVCW_EventCallback *callbackFunc)
{
	/* グローバル参照確保 */
	gObjCallBack = (*env)->NewGlobalRef(env, objCallBack);

	*callbackFunc = EventCallbackFunction;

	return HVCW_SUCCESS;
}


/* 制御関数(コールバック関数)       */
/* Javaのコールバックメソッドを呼ぶ */
static HVCW_INT32 RenderingCallbackFunction(HVCW_BOOL isVideo,
									HVCW_VOID *pUserParam,
									HVCW_VOID *pRenderInfo,
									HVCW_UINT32 unInfoLen,
									HVCW_UINT32 unTimeStamp)
{
	jclass     cls    = NULL;
	jmethodID  mid    = NULL;
	HVCW_INT32 nRet   = 0;
	HVCW_INT32 param1 = 0;
	HHVC       hHVC   = (HHVC)pUserParam;
	jbyteArray arrSoundData = NULL;
	HVCW_VIDEOFRAME *pVideoFrame = NULL;
	jbyteArray arrY = NULL;
	jbyteArray arrU = NULL;
	jbyteArray arrV = NULL;
	jlong width = 0;
	jlong height = 0;
	jlong timeStamp = (jlong)((long)unTimeStamp);

	int attach;
	pthread_mutex_lock(&gRenderingCallBackMutex);

	JNIEnv *env = getJNIEnv(&attach);

	__android_log_print(ANDROID_LOG_INFO, "Debug", "RenderingCallbackFunction 001\n");
	/* NULL チェック */
	if((gObjRenderingCallBack == NULL) || (env == NULL)){
		nRet = HVCW_INVALID_PARAM;
		goto mutex_unlock;
	}

	__android_log_print(ANDROID_LOG_INFO, "Debug", "RenderingCallbackFunction 002\n");
	/* jclassを取得する */
	cls = (*env)->GetObjectClass(env, gObjRenderingCallBack);
	if(cls == NULL){
		nRet = HVCW_INVALID_PARAM;
		goto mutex_unlock;
	}

	if(isVideo == 0) {
		arrSoundData = (*env)->NewByteArray(env, unInfoLen);
		nRet = JNUSetSoundData(env, arrSoundData, (HVCW_BYTE*)pRenderInfo, (jlong)((long)unInfoLen));
		nRet = HVCW_FreeDecodedAudioBuffer(hHVC, pRenderInfo);

		__android_log_print(ANDROID_LOG_INFO, "Debug", "RenderingCallbackFunction 003\n");
		/* メソッドIDを取得する */
		mid = (*env)->GetMethodID(env, cls, "soundDataCallback", "(J[BJ)I");
		if(mid == NULL){
			nRet = HVCW_INVALID_PARAM;
			goto delete_local_ref;
		}

		__android_log_print(ANDROID_LOG_INFO, "Debug", "RenderingCallbackFunction 004\n");
		/* メソッドを呼び出す */
		nRet = (*env)->CallIntMethod(env, gObjRenderingCallBack, mid, (jlong)((long)param1), arrSoundData, timeStamp);
	}else{
		pVideoFrame = (HVCW_VIDEOFRAME*)pRenderInfo;
		width = (jlong)((long)pVideoFrame->width);
		height = (jlong)((long)pVideoFrame->height);
		arrY = (*env)->NewByteArray(env, pVideoFrame->stride[0] * pVideoFrame->height);
		arrU = (*env)->NewByteArray(env, pVideoFrame->stride[1] * pVideoFrame->height);
		arrV = (*env)->NewByteArray(env, pVideoFrame->stride[2] * pVideoFrame->height);
		nRet = JNUSetVideoFrame(env, arrY, arrU, arrV, pVideoFrame);
		nRet = HVCW_FreeDecodedVideoBuffer(hHVC, pRenderInfo);

		__android_log_print(ANDROID_LOG_INFO, "Debug", "RenderingCallbackFunction 003\n");
		/* メソッドIDを取得する */
		mid = (*env)->GetMethodID(env, cls, "videoFrameCallback", "(J[B[B[BJJJ)I");
		if(mid == NULL){
			nRet = HVCW_INVALID_PARAM;
			goto delete_local_ref;
		}

		__android_log_print(ANDROID_LOG_INFO, "Debug", "RenderingCallbackFunction 004\n");
		/* メソッドを呼び出す */
		nRet = (*env)->CallIntMethod(env, gObjRenderingCallBack, mid, (jlong)((long)param1), arrY, arrU, arrV, width, height, timeStamp);
	}

delete_local_ref:
	__android_log_print(ANDROID_LOG_INFO, "Debug", "RenderingCallbackFunction 005\n");
	/* Free local references */
	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	if(attach){
		(*g_JavaVM)->DetachCurrentThread(g_JavaVM);
	}
	__android_log_print(ANDROID_LOG_INFO, "Debug", "RenderingCallbackFunction END\n");

mutex_unlock:
	pthread_mutex_unlock(&gRenderingCallBackMutex);

	return nRet;
}


/*
 *
 */
static HVCW_INT32 JNUSetRenderingCallback(JNIEnv *env, jobject objCallBack, HVCW_RequestRenderingCallback *callbackFunc)
{
	/* グローバル参照確保 */
	gObjRenderingCallBack = (*env)->NewGlobalRef(env, objCallBack);

	*callbackFunc = RenderingCallbackFunction;

	return HVCW_SUCCESS;
}


/* 制御関数(コールバック関数)       */
/* Javaのコールバックメソッドを呼ぶ */
static HVCW_INT32 LiveEventCallbackFunction(HVCW_INT32 eventId, HVCW_VOID *pUserParam, HVCW_VOID *pEventInfo)
{
	jclass     cls    = NULL;
	jmethodID  mid    = NULL;
	HVCW_INT32 nRet   = 0;
	HVCW_INT32 param1 = 0;
	HVCW_INT32 param2 = 0;


	__android_log_print(ANDROID_LOG_INFO, "Debug", "LiveEventCallbackFunction 000\n");
	int attach;
	JNIEnv *env = getJNIEnv(&attach);

	__android_log_print(ANDROID_LOG_INFO, "Debug", "LiveEventCallbackFunction 001\n");
	/* NULL チェック */
	if((gObjLiveCallBack == NULL) || (env == NULL)){
		return HVCW_INVALID_PARAM;
	}

	__android_log_print(ANDROID_LOG_INFO, "Debug", "LiveEventCallbackFunction 002\n");
	if(pEventInfo != NULL){
		param2 = *((HVCW_INT32 *)pEventInfo);
	}

	__android_log_print(ANDROID_LOG_INFO, "Debug", "LiveEventCallbackFunction 003\n");
	/* jclassを取得する */
	cls = (*env)->GetObjectClass(env, gObjLiveCallBack);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	__android_log_print(ANDROID_LOG_INFO, "Debug", "LiveEventCallbackFunction 004\n");
	/* メソッドIDを取得する */
	mid = (*env)->GetMethodID(env, cls, "liveEventCallback", "(IJJ)I");
	if(mid == NULL){
		return HVCW_INVALID_PARAM;
	}

	__android_log_print(ANDROID_LOG_INFO, "Debug", "LiveEventCallbackFunction 005\n");
	/* メソッドを呼び出す */
	nRet = (*env)->CallIntMethod(env, gObjLiveCallBack, mid, (jint)((int)eventId), (jlong)((long)param1), (jlong)((long)param2));

	__android_log_print(ANDROID_LOG_INFO, "Debug", "LiveEventCallbackFunction 006\n");
	/* Free local references */
	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	if(attach){
		(*g_JavaVM)->DetachCurrentThread(g_JavaVM);
	}
	__android_log_print(ANDROID_LOG_INFO, "Debug", "LiveEventCallbackFunction END\n");
	return nRet;
}


/*
 *
 */
static HVCW_INT32 JNUSetLiveEventCallback(JNIEnv *env, jobject objCallBack, HVCW_LiveEventCallback *callbackFunc)
{
	/* グローバル参照確保 */
	gObjLiveCallBack = (*env)->NewGlobalRef(env, objCallBack);

	*callbackFunc = LiveEventCallbackFunction;

	return HVCW_SUCCESS;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    initLibrary()
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_initLibrary
(JNIEnv *env, jclass cls)
{
	pthread_mutex_init(&gRenderingCallBackMutex, NULL);

	return HVCW_SUCCESS;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getVersion
 * Signature: (Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getVersion
(JNIEnv *env, jclass cls, jobject objMajor, jobject objMinor, jobject objRelease)
{
	HVCW_INT32 nRet;
	HVCW_UINT8 ucMajor;
	HVCW_UINT8 ucMinor;
	HVCW_UINT8 ucRelease;

	if((objMajor == NULL) || (objMinor == NULL) || (objRelease == NULL)){
		return HVCW_INVALID_PARAM;
	}

	nRet = HVCW_GetVersion(&ucMajor, &ucMinor, &ucRelease);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, objMajor, (HVCW_INT32)ucMajor);

		nRet = JNUSetInt(env, objMinor, (HVCW_INT32)ucMinor);

		nRet = JNUSetInt(env, objRelease, (HVCW_INT32)ucRelease);
	}

	return HVCW_SUCCESS;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    createHandleNative
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_jp_co_omron_hvcw_HvcwApi_createHandleNative
(JNIEnv *env, jobject obj)
{
	HHVC hHVC = HVCW_CreateHandle();

	return (jlong)((long)hHVC);
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    deleteHandle
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_deleteHandle
(JNIEnv *env, jobject obj, jlong handle)
{
	HVCW_INT32 nRet;

	/* グローバル参照開放 */
	DeleteGlobalObj();

	HHVC hHVC = (HHVC)((long)handle);
	nRet = HVCW_DeleteHandle(hHVC);

	return nRet;
}


/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setCameraHandle
 * Signature: (JJ)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setCameraHandle
(JNIEnv *env, jobject obj, jlong handle, jlong cameraHandle)
{
	HVCW_INT32 nRet;

	C2W_HANDLE hCameraHandle = (C2W_HANDLE)((long)cameraHandle);
	HHVC       hHVC          = (HHVC)((long)handle);

	nRet = HVCW_SetCameraHandle(hHVC, hCameraHandle);

	return nRet;
}


/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    connect
 * Signature: (JLjava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_connect
(JNIEnv *env, jobject obj, jlong handle, jstring cameraId, jstring accessToken)
{
	HVCW_INT32 nRet;
	const char *pucCameraId;
	const char *pucAccessToken;

	pucCameraId    = (*env)->GetStringUTFChars(env, cameraId, 0);
	pucAccessToken = (*env)->GetStringUTFChars(env, accessToken, 0);

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_Connect(hHVC, (HVCW_UINT8*)pucCameraId, (HVCW_UINT8*)pucAccessToken);

	(*env)->ReleaseStringUTFChars(env, cameraId, pucCameraId);
	(*env)->ReleaseStringUTFChars(env, accessToken, pucAccessToken);

	return nRet;
}


/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    disconnect
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_disconnect
(JNIEnv *env, jobject obj, jlong handle)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_Disconnect(hHVC);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getCameraVersion
 * Signature: (JLjava/lang/StringBuffer;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getCameraVersion
(JNIEnv *env, jobject obj, jlong handle, jobject version)
{
	HVCW_INT32 nRet;
	HVCW_UINT8 aucVersion[128];

	memset(aucVersion, 0x00, 128); /* クリア */

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetCameraVersion(hHVC, aucVersion);
	if(HVCW_SUCCESS == nRet){
		ToStringBuffer(env, aucVersion, version);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    updateFirmware
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_updateFirmware
(JNIEnv *env, jobject obj, jlong handle)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_UpdateFirmware(hHVC);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setNightVisionMode
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setNightVisionMode
(JNIEnv *env, jobject obj, jlong handle, jint mode)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_SetNightVisionMode(hHVC, (HVCW_NIGHT_VISION_MODE)mode);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getNightVisionMode
 * Signature: (JLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getNightVisionMode
(JNIEnv *env, jobject obj, jlong handle, jobject mode)
{
	HVCW_INT32 nRet;
	HVCW_NIGHT_VISION_MODE eMode;

	if(mode == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetNightVisionMode(hHVC, &eMode);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, mode, (HVCW_INT32)eMode);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setNightVisionStatus
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setNightVisionStatus
(JNIEnv *env, jobject obj, jlong handle, jint status)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_SetNightVisionStatus(hHVC, (HVCW_NIGHT_VISION_STATUS)status);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getNightVisionStatus
 * Signature: (JLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getNightVisionStatus
(JNIEnv *env, jobject obj, jlong handle, jobject status)
{
	HVCW_INT32 nRet;
	HVCW_NIGHT_VISION_STATUS eStatus;

	if(status == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetNightVisionStatus(hHVC, &eStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, status, (HVCW_INT32)eStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    enableEventMonitor
 * Signature: (JLjava/lang/Object;Ljp/co/omron/hvcw/EventCallbackInterface;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_enableEventMonitor
(JNIEnv *env, jobject obj, jlong handle, jobject objUserParam, jobject callbackFunc)
{
	HVCW_INT32 nRet;
	HVCW_VOID *pUserParam;
	HVCW_EventCallback eventCallbackFunc;


	nRet = JNUSetEventCallback(env, callbackFunc, &eventCallbackFunc);


	HHVC hHVC = (HHVC)((long)handle);

	/* とりあえず pUserParam:0 */
	nRet = HVCW_EnableEventMonitor(hHVC, 0, eventCallbackFunc);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    disableEventMonitor
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_disableEventMonitor
(JNIEnv *env, jobject obj, jlong handle)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_DisableEventMonitor(hHVC);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setSpeakerVolume
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setSpeakerVolume
(JNIEnv *env, jobject obj, jlong handle, jint volume)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_SetSpeakerVolume(hHVC, (HVCW_INT32)volume);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getSpeakerVolume
 * Signature: (JLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getSpeakerVolume
(JNIEnv *env, jobject obj, jlong handle, jobject volume)
{
	HVCW_INT32 nRet;
	HVCW_UINT32 unVolume;

	if(volume == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetSpeakerVolume(hHVC, &unVolume);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, volume, unVolume);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setMicSensitivity
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setMicSensitivity
(JNIEnv *env, jobject obj, jlong handle, jint unSensitivity)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_SetMicSensitivity(hHVC, (HVCW_INT32)unSensitivity);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getMicSensitivity
 * Signature: (JLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getMicSensitivity
(JNIEnv *env, jobject obj, jlong handle, jobject sensitivity)
{
	HVCW_INT32 nRet;
	HVCW_UINT32 unSensitivity;

	if(sensitivity == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetMicSensitivity(hHVC, &unSensitivity);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, sensitivity, unSensitivity);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getWiFiRSSI
 * Signature: (JLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getWiFiRSSI
(JNIEnv *env, jobject obj, jlong handle, jobject wifiRssi)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nWifiRssi;

	if(wifiRssi == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetWiFiRSSI(hHVC, &nWifiRssi);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, wifiRssi, nWifiRssi);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    generateDataSoundFile
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_generateDataSoundFile
(JNIEnv *env, jclass cls, jstring targetFile, jstring ssid, jstring password, jstring accessToken)
{
	HVCW_INT32 nRet;
	const char *pucTargetFile;
	const char *pucSSID;
	const char *pucPassword;
	const char *pusAccessToken;


	pucTargetFile  = (*env)->GetStringUTFChars(env, targetFile, 0);
	pucSSID        = (*env)->GetStringUTFChars(env, ssid, 0);
	pucPassword    = (*env)->GetStringUTFChars(env, password, 0);
	pusAccessToken = (*env)->GetStringUTFChars(env, accessToken, 0);

	nRet = HVCW_GenerateDataSoundFile((HVCW_UINT8*)pucTargetFile, (HVCW_UINT8*)pucSSID, (HVCW_UINT8*)pucPassword, (HVCW_UINT8*)pusAccessToken);

	(*env)->ReleaseStringUTFChars(env, targetFile, pucTargetFile);
	(*env)->ReleaseStringUTFChars(env, ssid, pucSSID);
	(*env)->ReleaseStringUTFChars(env, password, pucPassword);
	(*env)->ReleaseStringUTFChars(env, accessToken, pusAccessToken);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    requestStorageFormat
 * Signature: (JLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_requestStorageFormat
(JNIEnv *env, jobject obj, jlong handle, jobject resultCode)
{
	HVCW_INT32 nRet;
	HVCW_STORAGE_FORMAT_RESULT_CODE eResultCode;

	if(resultCode == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_RequestStorageFormat(hHVC, &eResultCode);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, resultCode, (HVCW_INT32)eResultCode);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getConnectionType
 * Signature: (JLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getConnectionType
(JNIEnv *env, jobject obj, jlong handle, jobject connType)
{
	HVCW_INT32 nRet;
	HVCW_CONNECTION_TYPE eConnType;

	if(connType == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetConnectionType(hHVC, &eConnType);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, connType, (HVCW_INT32)eConnType);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    startLive
 * Signature: (JLjava/lang/Object;ILjp/co/omron/hvcw/RequestRenderingCallbackInterface;Ljp/co/omron/hvcw/LiveEventCallbackInterface;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_startLive
(JNIEnv *env, jobject obj, jlong handle, jobject objUserParam, jint videoResolution,
	jobject renderingCallback, jobject eventCallback)
{
	HVCW_INT32 nRet;
	HVCW_VOID *pUserParam;
	HVCW_RequestRenderingCallback renderingCallbackFunc;
	HVCW_LiveEventCallback liveEventCallbackFunc;


	__android_log_print(ANDROID_LOG_INFO, "Debug", "startLive 001 %p\n", renderingCallbackFunc);
	nRet = JNUSetRenderingCallback(env, renderingCallback, &renderingCallbackFunc);
	__android_log_print(ANDROID_LOG_INFO, "Debug", "startLive 002 %p\n", renderingCallbackFunc);

	__android_log_print(ANDROID_LOG_INFO, "Debug", "startLive 003 %p\n", liveEventCallbackFunc);
	nRet = JNUSetLiveEventCallback(env, eventCallback, &liveEventCallbackFunc);
	__android_log_print(ANDROID_LOG_INFO, "Debug", "startLive 004 %p\n", liveEventCallbackFunc);


	HHVC hHVC = (HHVC)((long)handle);

	/* とりあえずobjUserParamは無視してハンドルを送る */
	nRet = HVCW_StartLive(hHVC, (HVCW_VOID*)hHVC, (HVCW_VIDEO_RESOLUTION)videoResolution,
							renderingCallbackFunc, liveEventCallbackFunc);

	__android_log_print(ANDROID_LOG_INFO, "Debug", "startLive END retrun:%d\n", nRet);
	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    stopLive
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_stopLive
(JNIEnv *env, jobject obj, jlong handle)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_StopLive(hHVC);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    enterTalkMode
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_enterTalkMode
(JNIEnv *env, jobject obj, jlong handle)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_EnterTalkMode(hHVC);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    exitTalkMode
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_exitTalkMode
(JNIEnv *env, jobject obj, jlong handle)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_ExitTalkMode(hHVC);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    transferSoundData
 * Signature: (J[BI)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_transferSoundData
(JNIEnv *env, jobject obj, jlong handle, jbyteArray soundData, jint soundLen)
{
	HVCW_INT32 nRet;
	HVCW_UINT8 *pucSoundData;

	if(NULL == soundData){
		return HVCW_INVALID_PARAM;
	}

	pucSoundData = (HVCW_UINT8*)malloc(soundLen * sizeof(HVCW_UINT8));
	if(NULL == pucSoundData){
		return HVCW_FAILURE;
	}

	(*env)->GetByteArrayRegion(env, soundData, 0, soundLen, (jbyte*)pucSoundData);
	if((*env)->ExceptionOccurred(env) != NULL){
		(*env)->ExceptionClear(env);
		free(pucSoundData);
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_TransferSoundData(hHVC, pucSoundData, (HVCW_UINT32)soundLen);

	free(pucSoundData);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setVideoResolution
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setVideoResolution
(JNIEnv *env, jobject obj, jlong handle, jint videoResolution)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_SetVideoResolution(hHVC, (HVCW_VIDEO_RESOLUTION)videoResolution);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getVideoResolution
 * Signature: (JLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getVideoResolution
(JNIEnv *env, jobject obj, jlong handle, jobject videoResolution)
{
	HVCW_INT32 nRet;
	HVCW_VIDEO_RESOLUTION eVideoResolution;

	if(NULL == videoResolution){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetVideoResolution(hHVC, &eVideoResolution);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, videoResolution, (HVCW_INT32)eVideoResolution);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    enableSoundDetection
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_enableSoundDetection
(JNIEnv *env, jobject obj, jlong handle, jint sensitivity)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_EnableSoundDetection(hHVC, (HVCW_UINT32)sensitivity);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    disableSoundDetection
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_disableSoundDetection
(JNIEnv *env, jobject obj, jlong handle)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_DisableSoundDetection(hHVC);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getSoundDetection
 * Signature: (JLjp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getSoundDetection
(JNIEnv *env, jobject obj, jlong handle, jobject on, jobject sensitivity)
{
	HVCW_INT32 nRet;
	HVCW_BOOL bOn;
	HVCW_UINT32 unSensitivity;

	if((on == NULL) || (sensitivity == NULL)){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetSoundDetection(hHVC, &bOn, &unSensitivity);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, on, (HVCW_INT32)bOn);
		if(HVCW_SUCCESS != nRet){
			return nRet;
		}

		nRet = JNUSetInt(env, sensitivity, (HVCW_INT32)unSensitivity);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    enableMotionDetection
 * Signature: (JI[Ljp/co/omron/hvcw/DetectionParam;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_enableMotionDetection
(JNIEnv *env, jobject obj, jlong handle, jint detectionParamsCount, jobjectArray objDetectionParams)
{
	HVCW_INT32 nRet;
	HVCW_DETECTIONPARAM aDetectionParams[detectionParamsCount];

	if(objDetectionParams == NULL){
		return HVCW_INVALID_PARAM;
	}

	nRet = JNUGetDetectionParamArray(env, objDetectionParams, aDetectionParams, detectionParamsCount);
	if(HVCW_SUCCESS != nRet){
		return nRet;
	}


	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_EnableMotionDetection(hHVC, (HVCW_UINT32)detectionParamsCount, aDetectionParams);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    disableMotionDetection
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_disableMotionDetection
(JNIEnv *env, jobject obj, jlong handle)
{
	HVCW_INT32 nRet;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_DisableMotionDetection(hHVC);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getMotionDetection
 * Signature: (JLjp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;[Ljp/co/omron/hvcw/DetectionParam;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getMotionDetection
(JNIEnv *env, jobject obj, jlong handle, jobject on, jobject detectionParamCount, jobjectArray objDetectionParams)
{
	HVCW_INT32 nRet;
	HVCW_BOOL bOn;
	HVCW_UINT32 unDetectionParamCount;
	HVCW_DETECTIONPARAM aDetectionParams[MAX_DATA];

	if((NULL == on) || (NULL == detectionParamCount) || (NULL == objDetectionParams)){
		return HVCW_INVALID_PARAM;
	}


	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetMotionDetection(hHVC, &bOn, &unDetectionParamCount, aDetectionParams);

	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, on, (HVCW_INT32)bOn);
		if(HVCW_SUCCESS != nRet){
			return nRet;
		}

		nRet = JNUSetInt(env, detectionParamCount, (HVCW_INT32)unDetectionParamCount);
		if(HVCW_SUCCESS != nRet){
			return nRet;
		}

		nRet = JNUSetDetectionParamArray(env, objDetectionParams, aDetectionParams, MAX_DATA);
		if(HVCW_SUCCESS != nRet){
			return nRet;
		}
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getCameraMacAddress
 * Signature: (JLjava/lang/StringBuffer;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getCameraMacAddress
(JNIEnv *env, jobject obj, jlong handle, jobject macAddress)
{
	HVCW_INT32 nRet;
	HVCW_UINT8 aucMACAddress[32];

	memset(aucMACAddress, 0x00, 32); /* クリア */

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetCameraMacAddress(hHVC, aucMACAddress);
	if(HVCW_SUCCESS == nRet){
		ToStringBuffer(env, aucMACAddress, macAddress);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    checkNewFirmware
 * Signature: (JLjava/lang/StringBuffer;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_checkNewFirmware
(JNIEnv *env, jobject obj, jlong handle, jobject version)
{
	HVCW_INT32 nRet;
	HVCW_UINT8 aucVersion[128];

	memset(aucVersion, 0x00, 128); /* クリア */

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_CheckNewFirmware(hHVC, aucVersion);
	if(HVCW_SUCCESS == nRet){
		ToStringBuffer(env, aucVersion, version);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getStorageInfo
 * Signature: (JLjp/co/omron/hvcw/StorageInfo;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getStorageInfo
(JNIEnv *env, jobject obj, jlong handle, jobject objStorageInfo)
{
	HVCW_INT32 nRet;
	HVCW_STORAGEINFO StorageInfo;

	if(objStorageInfo == NULL){
		return HVCW_INVALID_PARAM;
	}


	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetStorageInfo(hHVC, &StorageInfo);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetStorageInfo(env, objStorageInfo, &StorageInfo);
	}

	return nRet;
}
