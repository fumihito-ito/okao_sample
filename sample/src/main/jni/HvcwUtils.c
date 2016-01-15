/*-------------------------------------------------------------------*/
/*  Copyright(C) 2015 by OMRON Corporation                           */
/*  All Rights Reserved.                                             */
/*                                                                   */
/*   This source code is the Confidential and Proprietary Property   */
/*   of OMRON Corporation.  Any unauthorized use, reproduction or    */
/*   transfer of this software is strictly prohibited.               */
/*                                                                   */
/*-------------------------------------------------------------------*/
#include "HvcwUtils.h"
#include <android/log.h>


/*
 * nValue -> objIntValue
 */
HVCW_INT32 JNUSetInt(JNIEnv *env, jobject objIntValue, HVCW_INT32 nValue)
{
	jclass clsSetInt = NULL;

	clsSetInt = (*env)->GetObjectClass(env, objIntValue);
	if(clsSetInt == NULL){
		return HVCW_INVALID_PARAM;
	}

	jfieldID fid = NULL;
	fid = (*env)->GetFieldID(env, clsSetInt, "value", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env,clsSetInt);
		clsSetInt = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objIntValue, fid, (jint)nValue);

	(*env)->DeleteLocalRef(env, clsSetInt);
	clsSetInt = NULL;

	return HVCW_SUCCESS;
}


/*
 * objRange -> pRange
 */
HVCW_INT32 JNUGetRange(JNIEnv *env, HVCW_RANGE *pRange, jobject objRange)
{
	jclass cls   = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objRange);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nMin", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pRange->nMin = (*env)->GetIntField(env, objRange, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nMax", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pRange->nMax = (*env)->GetIntField(env, objRange, fid);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pRange -> objRange
 */
HVCW_INT32 JNUSetRange(JNIEnv *env, jobject objRange, HVCW_RANGE *pRange)
{
	jclass cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objRange);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nMin", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetRange 001 %d %x\n", pRange->nMin, pRange->nMin);
	(*env)->SetIntField(env, objRange, fid, (jint)pRange->nMin);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nMax", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objRange, fid, (jint)pRange->nMax);

	(*env)->DeleteLocalRef(env,cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objPoint -> pPt
 */
HVCW_INT32 JNUGetPoint(JNIEnv *env, HVCW_POINT *pPt, jobject objPoint)
{
	HVCW_POINT *pPoint = pPt;
	jclass clsGetPoint = NULL;
	jfieldID fid = NULL;

	clsGetPoint = (*env)->GetObjectClass(env, objPoint);
	if(clsGetPoint == NULL){
		  return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsGetPoint, "x", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsGetPoint);
		clsGetPoint = NULL;
		return HVCW_INVALID_PARAM;
	}
	pPoint->nX = (*env)->GetIntField(env, objPoint, fid);

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsGetPoint, "y", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsGetPoint);
		clsGetPoint = NULL;
		return HVCW_INVALID_PARAM;
	}
	pPoint->nY = (*env)->GetIntField(env, objPoint, fid);

	(*env)->DeleteLocalRef(env, clsGetPoint);
	clsGetPoint = NULL;

	return HVCW_SUCCESS;
}


/*
 * pPt -> objPoint
 */
HVCW_INT32 JNUSetPoint(JNIEnv *env, jobject objPoint, HVCW_POINT *pPt)
{
	HVCW_POINT *pPoint = pPt;
	jclass cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objPoint);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "x", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objPoint, fid, (jint)pPoint->nX);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "y", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objPoint, fid, (jint)pPoint->nY);

	(*env)->DeleteLocalRef(env,cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objRect -> pRect
 */
HVCW_INT32 JNUGetRect(JNIEnv *env, HVCW_RECT *pRect, jobject objRect)
{
	jclass clsGetRect = NULL;
	jfieldID fid      = NULL;

	clsGetRect = (*env)->GetObjectClass(env, objRect);
	if(clsGetRect == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsGetRect, "x", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsGetRect);
		clsGetRect = NULL;
		return HVCW_INVALID_PARAM;
	}
	pRect->nX = (*env)->GetIntField(env, objRect, fid);

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsGetRect, "y", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsGetRect);
		clsGetRect = NULL;
		return HVCW_INVALID_PARAM;
	}
	pRect->nY = (*env)->GetIntField(env, objRect, fid);

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsGetRect, "width", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsGetRect);
		clsGetRect = NULL;
		return HVCW_INVALID_PARAM;
	}
	pRect->nWidth = (*env)->GetIntField(env, objRect, fid);

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsGetRect, "height", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsGetRect);
		clsGetRect = NULL;
		return HVCW_INVALID_PARAM;
	}
	pRect->nHeight = (*env)->GetIntField(env, objRect, fid);

	(*env)->DeleteLocalRef(env, clsGetRect);
	clsGetRect = NULL;

	return HVCW_SUCCESS;
}


/*
 * pRect -> objRect
 */
HVCW_INT32 JNUSetRect(JNIEnv *env, jobject objRect, HVCW_RECT *pRect)
{
	jclass clsSetRect = NULL;
	jfieldID fid      = NULL;

	clsSetRect = (*env)->GetObjectClass(env, objRect);
	if(clsSetRect == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSetRect, "x", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSetRect);
		clsSetRect = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objRect, fid, (jint)(pRect->nX));


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSetRect, "y", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSetRect);
		clsSetRect = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objRect, fid, (jint)(pRect->nY));


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSetRect, "width", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSetRect);
		clsSetRect = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objRect, fid, (jint)(pRect->nWidth));


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSetRect, "height", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSetRect);
		clsSetRect = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objRect, fid, (jint)(pRect->nHeight));

	(*env)->DeleteLocalRef(env, clsSetRect);
	clsSetRect = NULL;

	return HVCW_SUCCESS;
}


/*
 * objParam -> pParam
 */
HVCW_INT32 JNUGetDetectionParam(JNIEnv *env, HVCW_DETECTIONPARAM *pParam, jobject objParam)
{
	HVCW_INT32 nRet = 0;
	jclass clsParam = NULL;
	jfieldID fid    = NULL;
	jobject objRect = NULL;

	clsParam = (*env)->GetObjectClass(env, objParam);
	if(clsParam == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = (*env)->GetFieldID(env, clsParam, "rect", "Ljp/co/omron/hvcw/Rect;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsParam);
		clsParam = NULL;
		return HVCW_INVALID_PARAM;
	}

	objRect = (*env)->GetObjectField(env, objParam, fid);

	nRet = JNUGetRect(env, &(pParam->rect), objRect);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, clsParam);
		clsParam = NULL;
		return nRet;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsParam, "sensitivity", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsParam);
		clsParam = NULL;
		return HVCW_INVALID_PARAM;
	}
	pParam->sensitivity = (*env)->GetIntField(env, objParam, fid);

	(*env)->DeleteLocalRef(env, clsParam);
	clsParam = NULL;

	return HVCW_SUCCESS;
}

/*
 * pParam -> objParam
 */
HVCW_INT32 JNUSetDetectionParam(JNIEnv *env, jobject objParam, HVCW_DETECTIONPARAM *pParam)
{
	HVCW_INT32 nRet = 0;
	jclass clsParam = NULL;
	jfieldID fid    = NULL;
	jobject objRect = NULL;

	clsParam = (*env)->GetObjectClass(env, objParam);
	if(NULL == clsParam){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsParam, "rect", "Ljp/co/omron/hvcw/Rect;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsParam);
		clsParam = NULL;
		return HVCW_INVALID_PARAM;
	}
	objRect = (*env)->GetObjectField(env, objParam, fid);

	nRet = JNUSetRect(env, objRect, &(pParam->rect));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, clsParam);
		clsParam = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objParam, fid, objRect);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsParam, "sensitivity", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsParam);
		clsParam = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objParam, fid, (jint)pParam->sensitivity);


	(*env)->DeleteLocalRef(env, clsParam);
	clsParam = NULL;

	return HVCW_SUCCESS;
}

/*
 * objDetectionParams -> pDetectionParams
 */
HVCW_INT32 JNUGetDetectionParamArray(JNIEnv *env, jobjectArray objDetectionParams, HVCW_DETECTIONPARAM *pDetectionParams, HVCW_INT32 nLen)
{
	HVCW_INT32 nI = 0;
	HVCW_INT32 nRet = 0;
	HVCW_DETECTIONPARAM *pParamArr;
	jobject objParam;


	if(pDetectionParams == NULL){
		return HVCW_INVALID_PARAM;
	}

	pParamArr = pDetectionParams;
	for(nI = 0; nI < nLen; nI++){
		objParam = NULL;
		objParam = (*env)->GetObjectArrayElement(env, objDetectionParams, nI);
		if(NULL == objParam){
			return HVCW_INVALID_PARAM;
		}

		nRet = JNUGetDetectionParam(env, &pParamArr[nI], objParam);

		(*env)->DeleteLocalRef(env, objParam);
		objParam = NULL;

		if(HVCW_SUCCESS != nRet){
			return nRet;
		}
	}

	return HVCW_SUCCESS;
}

/*
 * pDetectionParams -> objDetectionParams
 */
HVCW_INT32 JNUSetDetectionParamArray(JNIEnv *env, jobjectArray objDetectionParams, HVCW_DETECTIONPARAM *pDetectionParams, HVCW_INT32 nLen)
{
	HVCW_INT32 nI = 0;
	HVCW_INT32 nRet = 0;
	HVCW_DETECTIONPARAM *pParamArr;
	jobject objParam;

	if(pDetectionParams == NULL){
		return HVCW_INVALID_PARAM;
	}

	pParamArr = pDetectionParams;
	for(nI = 0; nI < nLen; nI++){
		objParam = NULL;
		objParam = (*env)->GetObjectArrayElement(env, objDetectionParams, nI);
		if(NULL == objParam){
			return HVCW_INVALID_PARAM;
		}

		nRet = JNUSetDetectionParam(env, objParam, &pParamArr[nI]);

		(*env)->DeleteLocalRef(env, objParam);
		objParam = NULL;

		if(HVCW_SUCCESS != nRet){
			return nRet;
		}
	}

	return HVCW_SUCCESS;
}

/*
 * pStorageInfo -> objStorageInfo
 */
HVCW_INT32 JNUSetStorageInfo(JNIEnv *env, jobject objStorageInfo, HVCW_STORAGEINFO *pStorageInfo)
{
	jclass   cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objStorageInfo);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nTotalSize", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objStorageInfo, fid, (jint)(pStorageInfo->ucTotalSize));


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nUsedSize", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objStorageInfo, fid, (jint)(pStorageInfo->ucUsedSize));


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nFreeSize", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objStorageInfo, fid, (jint)(pStorageInfo->ucFreeSize));


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nStorageStatus", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objStorageInfo, fid, (jint)(pStorageInfo->storageStatus));

	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}

/*
 * pVideoFrame -> objVideoFrame
 */
HVCW_INT32 JNUSetVideoFrame(JNIEnv *env, jbyteArray arrY, jbyteArray arrU, jbyteArray arrV, HVCW_VIDEOFRAME *pVideoFrame) {
	jint nLength = 0;
	unsigned int i = 0;
	unsigned char *p  = NULL;
	unsigned char *pU = NULL;
	unsigned char *pV = NULL;
	jbyte *pBuffer  = NULL;
	jbyte *pBufferU = NULL;
	jbyte *pBufferV = NULL;

	nLength = pVideoFrame->stride[0] * pVideoFrame->height;
	p = pVideoFrame->buffer[0];
	pBuffer = (*env)->GetByteArrayElements(env, arrY, NULL);
	for(i = 0; i<nLength; i++){
		pBuffer[i] = p[i];
	}
	(*env)->ReleaseByteArrayElements(env, arrY, pBuffer, 0);


	nLength = pVideoFrame->stride[1] * (pVideoFrame->height / 2);
	pU = pVideoFrame->buffer[1];
	pV = pVideoFrame->buffer[2];
	pBufferU = (*env)->GetByteArrayElements(env, arrU, NULL);
	pBufferV = (*env)->GetByteArrayElements(env, arrV, NULL);
	for(i = 0; i<nLength; i++){
		pBufferU[i] = pU[i];
		pBufferV[i] = pV[i];
	}
	(*env)->ReleaseByteArrayElements(env, arrU, pBufferU, 0);
	(*env)->ReleaseByteArrayElements(env, arrV, pBufferV, 0);

	return HVCW_SUCCESS;
}

/*
 * pSoundData -> objSoundData
 */
HVCW_INT32 JNUSetSoundData(JNIEnv *env, jbyteArray arrSoundData, HVCW_BYTE *pSoundData, jlong len) {
	jbyte *pData = NULL;
	unsigned int i = 0;

	pData = (*env)->GetByteArrayElements(env, arrSoundData, NULL);
	for(i = 0; i<len; i++){
		pData[i] = pSoundData[i];
	}
	(*env)->SetByteArrayRegion(env, arrSoundData, 0, len, pData);

	(*env)->ReleaseByteArrayElements(env, arrSoundData, pData, 0);

	return HVCW_SUCCESS;
}

/*
 * objFileInfo -> pFileInfo
 */
HVCW_INT32 JNUGetFileInfo(JNIEnv *env, HVCW_FILEINFO *pFileInfo, jobject objFileInfo)
{
	HVCW_INT32 nRet    = 0;
	jclass clsFileInfo = NULL;
	jfieldID fid       = NULL;
	jstring jstr       = NULL;

	clsFileInfo = (*env)->GetObjectClass(env, objFileInfo);
	if(NULL == clsFileInfo){
		  return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsFileInfo, "stName", "Ljava/lang/String;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsFileInfo);
		clsFileInfo = NULL;
		return HVCW_INVALID_PARAM;
	}
	jstr = (jstring)(*env)->GetObjectField(env, objFileInfo, fid);

	const char *c = (*env)->GetStringUTFChars(env, jstr, 0);
	strcpy(pFileInfo->acName, c);
//	pFileInfo->acName = (HVCW_CHAR)(*env)->GetStringUTFChars(env, jstr, 0);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsFileInfo, "nSize", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsFileInfo);
		clsFileInfo = NULL;
		return HVCW_INVALID_PARAM;
	}
	pFileInfo->nSize = (*env)->GetIntField(env, objFileInfo, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsFileInfo, "Reserved", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsFileInfo);
		clsFileInfo = NULL;
		return HVCW_INVALID_PARAM;
	}
	pFileInfo->Reserved = (*env)->GetIntField(env, objFileInfo, fid);


	(*env)->DeleteLocalRef(env, clsFileInfo);
	clsFileInfo = NULL;

	return HVCW_SUCCESS;
}

/*
 * pFileInfo -> objFileInfo
 */
HVCW_INT32 JNUSetFileInfo(JNIEnv *env, jobject objFileInfo, HVCW_FILEINFO *pFileInfo)
{
	HVCW_INT32 nRet    = 0;
	jclass clsFileInfo = NULL;
	jstring jstr       = NULL;
	jfieldID fid       = NULL;

	clsFileInfo = (*env)->GetObjectClass(env, objFileInfo);
	if(NULL == clsFileInfo){
		  return HVCW_INVALID_PARAM;
	}

//	strcpy(pFileInfo->acName, "xyzあいうえおかきくけこabcde");

//	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetFileInfo Start pFileInfo->acName:%s\n", pFileInfo->acName);
//	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetFileInfo Start pFileInfo->nSize:%d\n", pFileInfo->nSize);
//	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetFileInfo Start pFileInfo->Reserved:%x\n", pFileInfo->Reserved);

	/* ファイルが存在しない */
	if((pFileInfo->Reserved == 0xFFFFFFFF) || (pFileInfo->nSize == 0)){
		memset(pFileInfo->acName, 0x00, 40);	/* File Name クリア   */
		pFileInfo->nSize = 0;					/* File Size 0 セット */
	}

//	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetFileInfo Start pFileInfo->acName:%s\n", pFileInfo->acName);
//	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetFileInfo Start pFileInfo->nSize:%d\n", pFileInfo->nSize);
//	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetFileInfo Start pFileInfo->Reserved:%x\n", pFileInfo->Reserved);

	/* 文字列リソースにサロゲートペアが必要な文字を使うと実行時エラーになる */
	/* 空ファイルの場合危険… 対策が必要 */
	/* 変更後の UTF-8 エンコーディングによる文字配列から新しい java.lang.String オブジェクトを構築 */
	jstr = (*env)->NewStringUTF(env, pFileInfo->acName);
	/* Unicode 文字配列から新しい java.lang.String オブジェクトを構築 */
//	jstr = (*env)->NewString(env, (jchar *)(pFileInfo->acName), 40);
	if(NULL == jstr){
		(*env)->DeleteLocalRef(env, clsFileInfo);
		clsFileInfo = NULL;
		return HVCW_INVALID_PARAM;
	}


	//__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetFileInfo 001\n");
	fid = NULL;
	fid = (*env)->GetFieldID(env, clsFileInfo, "stName", "Ljava/lang/String;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsFileInfo);
		clsFileInfo = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetObjectField(env, objFileInfo, fid, jstr);


	//__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetFileInfo 002\n");
	fid = NULL;
	fid = (*env)->GetFieldID(env, clsFileInfo, "nSize", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsFileInfo);
		clsFileInfo = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objFileInfo, fid, (jint)pFileInfo->nSize);


	//__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetFileInfo 003\n");
	fid = NULL;
	fid = (*env)->GetFieldID(env, clsFileInfo, "Reserved", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsFileInfo);
		clsFileInfo = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objFileInfo, fid, (jint)pFileInfo->Reserved);


	//__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetFileInfo 004\n");
	(*env)->DeleteLocalRef(env, clsFileInfo);
	clsFileInfo = NULL;

	//__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetFileInfo End\n");
	return HVCW_SUCCESS;
}

/*
 * FaceResult -> objFaceResult
 */
HVCW_INT32 JNUSetResultDetection(JNIEnv *env, jobject objFaceResult, HVCW_OKAO_RESULT_DETECTION *pFaceResult)
{
	HVCW_INT32 nRet      = 0;
	jclass clsFaceResult = NULL;
	jfieldID fid         = NULL;
	jobject objPoint     = NULL;

	clsFaceResult = (*env)->GetObjectClass(env, objFaceResult);
	if(NULL == clsFaceResult){
		  return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsFaceResult, "ptCenter", "Ljp/co/omron/hvcw/Point;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsFaceResult);
		clsFaceResult = NULL;
		return HVCW_INVALID_PARAM;
	}
	objPoint = (*env)->GetObjectField(env, objFaceResult, fid);

	nRet = JNUSetPoint(env, objPoint, &(pFaceResult->center));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, clsFaceResult);
		clsFaceResult = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objFaceResult, fid, objPoint);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsFaceResult, "nSize", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsFaceResult);
		clsFaceResult = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objFaceResult, fid, (jint)pFaceResult->nSize);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsFaceResult, "nConfidence", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsFaceResult);
		clsFaceResult = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objFaceResult, fid, (jint)pFaceResult->nConfidence);


	(*env)->DeleteLocalRef(env, clsFaceResult);
	clsFaceResult = NULL;

	return HVCW_SUCCESS;
}


/*
 * pResultPet -> objResultPet
 */
HVCW_INT32 JNUSetResultPet(JNIEnv *env, jobject objResultPet, HVCW_OKAO_RESULT_PET *pResultPet)
{
	HVCW_INT32 nRet     = 0;
	jclass clsResultPet = NULL;
	jfieldID fid        = NULL;
	jobject objPoint    = NULL;

	clsResultPet = (*env)->GetObjectClass(env, objResultPet);
	if(NULL == clsResultPet){
		  return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsResultPet, "ptCenter", "Ljp/co/omron/hvcw/Point;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsResultPet);
		clsResultPet = NULL;
		return HVCW_INVALID_PARAM;
	}
	objPoint = (*env)->GetObjectField(env, objResultPet, fid);

	nRet = JNUSetPoint(env, objPoint, &(pResultPet->ptCenter));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, clsResultPet);
		clsResultPet = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objResultPet, fid, objPoint);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsResultPet, "nSize", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsResultPet);
		clsResultPet = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultPet, fid, (jint)pResultPet->nSize);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsResultPet, "nConfidence", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsResultPet);
		clsResultPet = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultPet, fid, (jint)pResultPet->nConfidence);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsResultPet, "nPetType", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsResultPet);
		clsResultPet = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultPet, fid, (jint)pResultPet->nPetType);


	(*env)->DeleteLocalRef(env, clsResultPet);
	clsResultPet = NULL;

	return HVCW_SUCCESS;
}


/*
 * pResultDirection -> objResultDirection
 */
HVCW_INT32 JNUSetResultDirection(JNIEnv *env, jobject objResultDirection, HVCW_OKAO_RESULT_DIRECTION *pResultDirection)
{
	jclass   cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objResultDirection);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nLR", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultDirection, fid, (jint)pResultDirection->nLR);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nUD", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultDirection, fid, (jint)pResultDirection->nUD);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nRoll", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultDirection, fid, (jint)pResultDirection->nRoll);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pResultAge -> objResultAge
 */
HVCW_INT32 JNUSetResultAge(JNIEnv *env, jobject objResultAge, HVCW_OKAO_RESULT_AEG *pResultAge)
{
	jclass   cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objResultAge);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nAge", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultAge, fid, (jint)pResultAge->nAge);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nConfidence", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultAge, fid, (jint)pResultAge->nConfidence);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pResultGender -> objResultGender
 */
HVCW_INT32 JNUSetResultGender(JNIEnv *env, jobject objResultGender, HVCW_OKAO_RESULT_GENDER *pResultGender)
{
	jclass   cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objResultGender);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nGender", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultGender, fid, (jint)pResultGender->nGender);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nConfidence", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultGender, fid, (jint)pResultGender->nConfidence);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pResultGaze -> objResultGaze
 */
HVCW_INT32 JNUSetResultGaze(JNIEnv *env, jobject objResultGaze, HVCW_OKAO_RESULT_GAZE *pResultGaze)
{
	jclass   cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objResultGaze);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nLR", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultGaze, fid, (jint)pResultGaze->nLR);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nUD", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultGaze, fid, (jint)pResultGaze->nUD);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pResultBlink -> objResultBlink
 */
HVCW_INT32 JNUSetResultBlink(JNIEnv *env, jobject objResultBlink, HVCW_OKAO_RESULT_BLINK *pResultBlink)
{
	jclass   cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objResultBlink);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nLeftEye", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultBlink, fid, (jint)pResultBlink->nLeftEye);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nRightEye", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultBlink, fid, (jint)pResultBlink->nRightEye);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pResultExpression -> objResultExpression
 */
HVCW_INT32 JNUSetResultExpression(JNIEnv *env, jobject objResultExpression, HVCW_OKAO_RESULT_EXPRESSION *pResultExpression)
{
	jclass    cls      = NULL;
	jfieldID  fid      = NULL;
	jintArray arrScore = NULL;
	jint      *pnScore = NULL;
	jint      nLength  = 0;
	int       i        = 0;

	cls = (*env)->GetObjectClass(env, objResultExpression);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "anScore", "[I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	arrScore = (jintArray)(*env)->GetObjectField(env, objResultExpression, fid);

	nLength = (*env)->GetArrayLength(env, arrScore);

	pnScore = (*env)->GetIntArrayElements(env, arrScore, NULL);
	for(i = 0; i<nLength; i++){
		pnScore[i] = pResultExpression->anScore[i];
	}
	(*env)->SetIntArrayRegion(env, arrScore, 0, nLength, pnScore);

	(*env)->ReleaseIntArrayElements(env, arrScore, pnScore, 0);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nDegree", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultExpression, fid, (jint)pResultExpression->nDegree);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pResultRecognition -> objResultRecognition
 */
HVCW_INT32 JNUSetResultRecognition(JNIEnv *env, jobject objResultRecognition, HVCW_OKAO_RESULT_RECOGNITION *pResultRecognition)
{
	jclass   cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objResultRecognition);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nUID", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultRecognition, fid, (jint)pResultRecognition->nUID);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nScore", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultRecognition, fid, (jint)pResultRecognition->nScore);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pResultFace -> objResultFace
 */
HVCW_INT32 JNUSetResultFace(JNIEnv *env, jobject objResultFace, HVCW_OKAO_RESULT_FACE *pResultFace)
{
	HVCW_INT32 nRet                 = 0;
	jclass     cls                  = NULL;
	jfieldID   fid                  = NULL;
	jobject    objPoint             = NULL;
	jobject    objResultDirection   = NULL;
	jobject    objResultAeg         = NULL;
	jobject    objResultGender      = NULL;
	jobject    objResultGaze        = NULL;
	jobject    objResultBlink       = NULL;
	jobject    objResultExpression  = NULL;
	jobject    objResultRecognition = NULL;

	cls = (*env)->GetObjectClass(env, objResultFace);
	if(NULL == cls){
		  return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "ptCenter", "Ljp/co/omron/hvcw/Point;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objPoint = (*env)->GetObjectField(env, objResultFace, fid);

	nRet = JNUSetPoint(env, objPoint, &(pResultFace->center));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objResultFace, fid, objPoint);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nSize", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultFace, fid, (jint)pResultFace->nSize);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nConfidence", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultFace, fid, (jint)pResultFace->nConfidence);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "direction", "Ljp/co/omron/hvcw/ResultDirection;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objResultDirection = (*env)->GetObjectField(env, objResultFace, fid);

	nRet = JNUSetResultDirection(env, objResultDirection, &(pResultFace->direction));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objResultFace, fid, objResultDirection);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "age", "Ljp/co/omron/hvcw/ResultAeg;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objResultAeg = (*env)->GetObjectField(env, objResultFace, fid);

	nRet = JNUSetResultAge(env, objResultAeg, &(pResultFace->age));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objResultFace, fid, objResultAeg);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "gender", "Ljp/co/omron/hvcw/ResultGender;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objResultGender = (*env)->GetObjectField(env, objResultFace, fid);

	nRet = JNUSetResultGender(env, objResultGender, &(pResultFace->gender));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objResultFace, fid, objResultGender);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "gaze", "Ljp/co/omron/hvcw/ResultGaze;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objResultGaze = (*env)->GetObjectField(env, objResultFace, fid);

	nRet = JNUSetResultGaze(env, objResultGaze, &(pResultFace->gaze));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objResultFace, fid, objResultGaze);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "blink", "Ljp/co/omron/hvcw/ResultBlink;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objResultBlink = (*env)->GetObjectField(env, objResultFace, fid);

	nRet = JNUSetResultBlink(env, objResultBlink, &(pResultFace->blink));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objResultFace, fid, objResultBlink);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "expression", "Ljp/co/omron/hvcw/ResultExpression;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objResultExpression = (*env)->GetObjectField(env, objResultFace, fid);

	nRet = JNUSetResultExpression(env, objResultExpression, &(pResultFace->expression));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objResultFace, fid, objResultExpression);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "recognition", "Ljp/co/omron/hvcw/ResultRecognition;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objResultRecognition = (*env)->GetObjectField(env, objResultFace, fid);

	nRet = JNUSetResultRecognition(env, objResultRecognition, &(pResultFace->recognition));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objResultFace, fid, objResultRecognition);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pResultBodys -> objResultBodys
 */
HVCW_INT32 JNUSetResultBodys(JNIEnv *env, jobject objResultBodys, HVCW_OKAO_RESULT_BODYS *pResultBodys)
{
	jclass       cls          = NULL;
	jfieldID     fid          = NULL;
	jobjectArray objArrResult = NULL;
	jobject      objResult    = NULL;
	int          nLength      = 0;
	int          i            = 0;

	cls = (*env)->GetObjectClass(env, objResultBodys);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nCount", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultBodys, fid, (jint)pResultBodys->nCount);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "body", "[Ljp/co/omron/hvcw/ResultDetection;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objArrResult = (*env)->GetObjectField(env, objResultBodys, fid);

	nLength = (*env)->GetArrayLength(env, objArrResult);

	for(i = 0; i<nLength; i++){
		objResult = (*env)->GetObjectArrayElement(env, objArrResult, i);

		JNUSetResultDetection(env, objResult, &(pResultBodys->body[i]));

		(*env)->SetObjectArrayElement(env, objArrResult, i, objResult);
		/* ローカル参照は512まで */
		(*env)->DeleteLocalRef(env, objResult);
		objResult = NULL;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pResultHands -> objResultHands
 */
HVCW_INT32 JNUSetResultHands(JNIEnv *env, jobject objResultHands, HVCW_OKAO_RESULT_HANDS *pResultHands)
{
	jclass       cls          = NULL;
	jfieldID     fid          = NULL;
	jobjectArray objArrResult = NULL;
	jobject      objResult    = NULL;
	int          nLength      = 0;
	int          i            = 0;

	cls = (*env)->GetObjectClass(env, objResultHands);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nCount", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultHands, fid, (jint)pResultHands->nCount);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "hand", "[Ljp/co/omron/hvcw/ResultDetection;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objArrResult = (*env)->GetObjectField(env, objResultHands, fid);

	nLength = (*env)->GetArrayLength(env, objArrResult);

	for(i = 0; i<nLength; i++){
		objResult = (*env)->GetObjectArrayElement(env, objArrResult, i);

		JNUSetResultDetection(env, objResult, &(pResultHands->hand[i]));

		(*env)->SetObjectArrayElement(env, objArrResult, i, objResult);

		(*env)->DeleteLocalRef(env, objResult);
		objResult = NULL;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pResultPets -> objResultPets
 */
HVCW_INT32 JNUSetResultPets(JNIEnv *env, jobject objResultPets, HVCW_OKAO_RESULT_PETS *pResultPets)
{
	jclass       cls          = NULL;
	jfieldID     fid          = NULL;
	jobjectArray objArrResult = NULL;
	jobject      objResult    = NULL;
	int          nLength      = 0;
	int          i            = 0;

	cls = (*env)->GetObjectClass(env, objResultPets);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nCount", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultPets, fid, (jint)pResultPets->nCount);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "pet", "[Ljp/co/omron/hvcw/ResultPet;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objArrResult = (*env)->GetObjectField(env, objResultPets, fid);

	nLength = (*env)->GetArrayLength(env, objArrResult);

	for(i = 0; i<nLength; i++){
		objResult = (*env)->GetObjectArrayElement(env, objArrResult, i);

		JNUSetResultPet(env, objResult, &(pResultPets->pet[i]));

		(*env)->SetObjectArrayElement(env, objArrResult, i, objResult);

		(*env)->DeleteLocalRef(env, objResult);
		objResult = NULL;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pResultFaces -> objResultFaces
 */
HVCW_INT32 JNUSetResultFaces(JNIEnv *env, jobject objResultFaces, HVCW_OKAO_RESULT_FACES *pResultFaces)
{
	jclass       cls          = NULL;
	jfieldID     fid          = NULL;
	jobjectArray objArrResult = NULL;
	jobject      objResult    = NULL;
	int          nLength      = 0;
	int          i            = 0;

	cls = (*env)->GetObjectClass(env, objResultFaces);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nCount", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objResultFaces, fid, (jint)pResultFaces->nCount);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "face", "[Ljp/co/omron/hvcw/ResultFace;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objArrResult = (*env)->GetObjectField(env, objResultFaces, fid);

	nLength = (*env)->GetArrayLength(env, objArrResult);

	for(i = 0; i<nLength; i++){
		objResult = (*env)->GetObjectArrayElement(env, objArrResult, i);

		JNUSetResultFace(env, objResult, &(pResultFaces->face[i]));

		(*env)->SetObjectArrayElement(env, objArrResult, i, objResult);

		(*env)->DeleteLocalRef(env, objResult);
		objResult = NULL;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pOkaoResult -> objOkaoResult
 */
HVCW_INT32 JNUSetOkaoResult(JNIEnv *env, jobject objOkaoResult, HVCW_OKAO_RESULT *pOkaoResult)
{
	HVCW_INT32 nRet;
	jclass cls             = NULL;
	jfieldID fid           = NULL;
	jobject objResultBodys = NULL;
	jobject objResultHands = NULL;
	jobject objResultPets  = NULL;
	jobject objResultFaces = NULL;

	cls = (*env)->GetObjectClass(env, objOkaoResult);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "bodys", "Ljp/co/omron/hvcw/ResultBodys;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objResultBodys = (*env)->GetObjectField(env, objOkaoResult, fid);

	nRet = JNUSetResultBodys(env, objResultBodys, &(pOkaoResult->bodys));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objOkaoResult, fid, objResultBodys);


	fid = (*env)->GetFieldID(env, cls, "hands", "Ljp/co/omron/hvcw/ResultHands;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objResultHands = (*env)->GetObjectField(env, objOkaoResult, fid);

	nRet = JNUSetResultHands(env, objResultHands, &(pOkaoResult->hands));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objOkaoResult, fid, objResultHands);


	fid = (*env)->GetFieldID(env, cls, "pets", "Ljp/co/omron/hvcw/ResultPets;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objResultPets = (*env)->GetObjectField(env, objOkaoResult, fid);

	nRet = JNUSetResultPets(env, objResultPets, &(pOkaoResult->pets));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objOkaoResult, fid, objResultPets);


	fid = (*env)->GetFieldID(env, cls, "faces", "Ljp/co/omron/hvcw/ResultFaces;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objResultFaces = (*env)->GetObjectField(env, objOkaoResult, fid);

	nRet = JNUSetResultFaces(env, objResultFaces, &(pOkaoResult->faces));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objOkaoResult, fid, objResultFaces);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objScheduleTime -> pScheduleTime
 */
HVCW_INT32 JNUGetScheduleTime(JNIEnv *env, HVCW_SCHEDULE_TIME *pScheduleTime, jobject objScheduleTime)
{
	jclass clsScheduleTime = NULL;
	jfieldID fid           = NULL;

	clsScheduleTime = (*env)->GetObjectClass(env, objScheduleTime);
	if(clsScheduleTime == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsScheduleTime, "nYear", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsScheduleTime);
		clsScheduleTime = NULL;
		return HVCW_INVALID_PARAM;
	}
	pScheduleTime->nYear = (*env)->GetIntField(env, objScheduleTime, fid);

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsScheduleTime, "nMonth", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsScheduleTime);
		clsScheduleTime = NULL;
		return HVCW_INVALID_PARAM;
	}
	pScheduleTime->nMonth = (*env)->GetIntField(env, objScheduleTime, fid);

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsScheduleTime, "nDay", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsScheduleTime);
		clsScheduleTime = NULL;
		return HVCW_INVALID_PARAM;
	}
	pScheduleTime->nDay = (*env)->GetIntField(env, objScheduleTime, fid);

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsScheduleTime, "nHour", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsScheduleTime);
		clsScheduleTime = NULL;
		return HVCW_INVALID_PARAM;
	}
	pScheduleTime->nHour = (*env)->GetIntField(env, objScheduleTime, fid);

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsScheduleTime, "nMinute", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsScheduleTime);
		clsScheduleTime = NULL;
		return HVCW_INVALID_PARAM;
	}
	pScheduleTime->nMinute = (*env)->GetIntField(env, objScheduleTime, fid);

	(*env)->DeleteLocalRef(env, clsScheduleTime);
	clsScheduleTime = NULL;

	return HVCW_SUCCESS;
}


/*
 * pScheduleTime -> objScheduleTime
 */
HVCW_INT32 JNUSetScheduleTime(JNIEnv *env, jobject objScheduleTime, HVCW_SCHEDULE_TIME *pScheduleTime)
{
	jclass clsScheduleTime = NULL;
	jfieldID fid           = NULL;

	clsScheduleTime = (*env)->GetObjectClass(env, objScheduleTime);
	if(clsScheduleTime == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsScheduleTime, "nYear", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsScheduleTime);
		clsScheduleTime = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objScheduleTime, fid, (jint)(pScheduleTime->nYear));


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsScheduleTime, "nMonth", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsScheduleTime);
		clsScheduleTime = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objScheduleTime, fid, (jint)(pScheduleTime->nMonth));


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsScheduleTime, "nDay", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsScheduleTime);
		clsScheduleTime = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objScheduleTime, fid, (jint)(pScheduleTime->nDay));


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsScheduleTime, "nHour", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsScheduleTime);
		clsScheduleTime = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objScheduleTime, fid, (jint)(pScheduleTime->nHour));


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsScheduleTime, "nMinute", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsScheduleTime);
		clsScheduleTime = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objScheduleTime, fid, (jint)(pScheduleTime->nMinute));


	(*env)->DeleteLocalRef(env, clsScheduleTime);
	clsScheduleTime = NULL;

	return HVCW_SUCCESS;
}


/*
 * objSchedule -> pSchedule
 */
HVCW_INT32 JNUGetScheduleInfo(JNIEnv *env, HVCW_SCHEDULE_INFO *pSchedule, jobject objSchedule)
{
	HVCW_INT32 nRet;
	jclass clsSchedule    = NULL;
	jfieldID fid          = NULL;
	jintArray arrWeekday  = NULL;
	jintArray arrFunction = NULL;
	jint *pnWeekday       = NULL;
	jint *pnFunction      = NULL;
	jobject objStartTime  = NULL;
	jobject objEndTime    = NULL;
	int i                 = 0;
	jint nLength          = 0;

	clsSchedule = (*env)->GetObjectClass(env, objSchedule);
	if(clsSchedule == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "nIndex", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	pSchedule->nIndex = (*env)->GetIntField(env, objSchedule, fid);

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "nFrequency", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	pSchedule->frequency = (HVCW_SCHEDULE_FREQUENCY)(*env)->GetIntField(env, objSchedule, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "aBooleanWeekday", "[I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	arrWeekday = (jintArray)(*env)->GetObjectField(env, objSchedule, fid);

	nLength = (*env)->GetArrayLength(env, arrWeekday);

	pnWeekday = (*env)->GetIntArrayElements(env, arrWeekday, NULL);
	for(i = 0; i<nLength; i++){
		pSchedule->bWeekday[i] = (HVCW_BOOL)pnWeekday[i];
	}
	(*env)->ReleaseIntArrayElements(env, arrWeekday, pnWeekday, 0);


	fid = (*env)->GetFieldID(env, clsSchedule, "startTime", "Ljp/co/omron/hvcw/ScheduleTime;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}

	objStartTime = (*env)->GetObjectField(env, objSchedule, fid);

	nRet = JNUGetScheduleTime(env, &(pSchedule->startTime), objStartTime);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, clsSchedule, "endTime", "Ljp/co/omron/hvcw/ScheduleTime;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}

	objEndTime = (*env)->GetObjectField(env, objSchedule, fid);

	nRet = JNUGetScheduleTime(env, &(pSchedule->endTime), objEndTime);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return nRet;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "nInterval", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	pSchedule->nInterval = (*env)->GetIntField(env, objSchedule, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "aBooleanFunction", "[I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	arrFunction = (jintArray)(*env)->GetObjectField(env, objSchedule, fid);

	nLength = (*env)->GetArrayLength(env, arrFunction);

	pnFunction = (*env)->GetIntArrayElements(env, arrFunction, NULL);
	for(i = 0; i<nLength; i++){
		pSchedule->abFunction[i] = (HVCW_BOOL)pnFunction[i];
	}
	(*env)->ReleaseIntArrayElements(env, arrFunction, pnFunction, 0);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "nSaveLog", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	pSchedule->saveLog = (HVCW_SAVE_RESULT)(*env)->GetIntField(env, objSchedule, fid);

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "nSaveImage", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	pSchedule->saveImage = (HVCW_SAVE_RESULT)(*env)->GetIntField(env, objSchedule, fid);

	(*env)->DeleteLocalRef(env, clsSchedule);
	clsSchedule = NULL;

	return HVCW_SUCCESS;
}


/*
 * pSchedule -> objSchedule
 */
HVCW_INT32 JNUSetScheduleInfo(JNIEnv *env, jobject objSchedule, HVCW_SCHEDULE_INFO *pSchedule)
{
	HVCW_INT32 nRet;
	jclass clsSchedule    = NULL;
	jfieldID fid          = NULL;
	jobject objScheduleTime = NULL;
	jintArray arrWeekday  = NULL;
	jintArray arrFunction = NULL;
	jint *pnWeekday       = NULL;
	jint *pnFunction      = NULL;
	jobject objStartTime  = NULL;
	jobject objEndTime    = NULL;
	int i                 = 0;
	jint nLength          = 0;

	clsSchedule = (*env)->GetObjectClass(env, objSchedule);
	if(NULL == clsSchedule){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "nIndex", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objSchedule, fid, (jint)pSchedule->nIndex);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "nFrequency", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objSchedule, fid, (jint)pSchedule->frequency);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "aBooleanWeekday", "[I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	arrWeekday = (jintArray)(*env)->GetObjectField(env, objSchedule, fid);

	nLength = (*env)->GetArrayLength(env, arrWeekday);

	pnWeekday = (*env)->GetIntArrayElements(env, arrWeekday, NULL);
	for(i = 0; i<nLength; i++){
		pnWeekday[i] = (jint)pSchedule->bWeekday[i];
	}
	(*env)->ReleaseIntArrayElements(env, arrWeekday, pnWeekday, 0);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "startTime", "Ljp/co/omron/hvcw/ScheduleTime;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	objScheduleTime = (*env)->GetObjectField(env, objSchedule, fid);

	nRet = JNUSetScheduleTime(env, objScheduleTime, &(pSchedule->startTime));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objSchedule, fid, objScheduleTime);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "endTime", "Ljp/co/omron/hvcw/ScheduleTime;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	objScheduleTime = (*env)->GetObjectField(env, objSchedule, fid);

	nRet = JNUSetScheduleTime(env, objScheduleTime, &(pSchedule->endTime));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objSchedule, fid, objScheduleTime);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "nInterval", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objSchedule, fid, (jint)pSchedule->nInterval);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "aBooleanFunction", "[I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	arrFunction = (jintArray)(*env)->GetObjectField(env, objSchedule, fid);

	nLength = (*env)->GetArrayLength(env, arrFunction);

	pnFunction = (*env)->GetIntArrayElements(env, arrFunction, NULL);
	for(i = 0; i<nLength; i++){
		pnFunction[i] = (jint)pSchedule->abFunction[i];
	}
	(*env)->ReleaseIntArrayElements(env, arrFunction, pnFunction, 0);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "nSaveLog", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objSchedule, fid, (jint)pSchedule->saveLog);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSchedule, "nSaveImage", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSchedule);
		clsSchedule = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objSchedule, fid, (jint)pSchedule->saveImage);


	(*env)->DeleteLocalRef(env, clsSchedule);
	clsSchedule = NULL;

	return HVCW_SUCCESS;
}


/*
 * objBody -> pBody
 */
HVCW_INT32 JNUGetEpBody(JNIEnv *env, HVCW_EP_BODY *pBody, jobject objBody)
{
	jclass cls   = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objBody);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pBody->bEnable = (*env)->GetIntField(env, objBody, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nCount", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pBody->nCount = (*env)->GetIntField(env, objBody, fid);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pBody -> objBody
 */
HVCW_INT32 JNUSetEpBody(JNIEnv *env, jobject objBody, HVCW_EP_BODY *pBody)
{
	jclass cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objBody);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objBody, fid, (jint)pBody->bEnable);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nCount", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objBody, fid, (jint)pBody->nCount);

	(*env)->DeleteLocalRef(env,cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objPet -> pPet
 */
HVCW_INT32 JNUGetEpPet(JNIEnv *env, HVCW_EP_PET *pPet, jobject objPet)
{
	jclass cls   = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objPet);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pPet->bEnable = (*env)->GetIntField(env, objPet, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nCount", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pPet->nCount = (*env)->GetIntField(env, objPet, fid);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pPet -> objPet
 */
HVCW_INT32 JNUSetEpPet(JNIEnv *env, jobject objPet, HVCW_EP_PET *pPet)
{
	jclass cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objPet);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objPet, fid, (jint)pPet->bEnable);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nCount", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objPet, fid, (jint)pPet->nCount);

	(*env)->DeleteLocalRef(env,cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objFace -> pFace
 */
HVCW_INT32 JNUGetEpFace(JNIEnv *env, HVCW_EP_FACE *pFace, jobject objFace)
{
	jclass cls   = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objFace);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pFace->bEnable = (*env)->GetIntField(env, objFace, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nCount", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pFace->nCount = (*env)->GetIntField(env, objFace, fid);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pFace -> objFace
 */
HVCW_INT32 JNUSetEpFace(JNIEnv *env, jobject objFace, HVCW_EP_FACE *pFace)
{
	jclass cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objFace);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objFace, fid, (jint)pFace->bEnable);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nCount", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objFace, fid, (jint)pFace->nCount);

	(*env)->DeleteLocalRef(env,cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objAge -> pAge
 */
HVCW_INT32 JNUGetEpAge(JNIEnv *env, HVCW_EP_AGE *pAge, jobject objAge)
{
	HVCW_INT32 nRet;
	jclass cls       = NULL;
	jfieldID fid     = NULL;
	jobject objRange = NULL;

	cls = (*env)->GetObjectClass(env, objAge);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pAge->bEnable = (*env)->GetIntField(env, objAge, fid);


	fid = (*env)->GetFieldID(env, cls, "ageRange", "Ljp/co/omron/hvcw/Range;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}

	objRange = (*env)->GetObjectField(env, objAge, fid);

	nRet = JNUGetRange(env, &(pAge->stAgeRange), objRange);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nConfidence", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pAge->nConfidence = (*env)->GetIntField(env, objAge, fid);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pAge -> objAge
 */
HVCW_INT32 JNUSetEpAge(JNIEnv *env, jobject objAge, HVCW_EP_AGE *pAge)
{
	HVCW_INT32 nRet;
	jclass cls       = NULL;
	jobject objRange = NULL;
	jfieldID fid     = NULL;

	cls = (*env)->GetObjectClass(env, objAge);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objAge, fid, (jint)pAge->bEnable);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "ageRange", "Ljp/co/omron/hvcw/Range;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objRange = (*env)->GetObjectField(env, objAge, fid);

	nRet = JNUSetRange(env, objRange, &(pAge->stAgeRange));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objAge, fid, objRange);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nConfidence", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objAge, fid, (jint)pAge->nConfidence);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objGender -> pGender
 */
HVCW_INT32 JNUGetEpGender(JNIEnv *env, HVCW_EP_GENDER *pGender, jobject objGender)
{
	jclass cls   = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objGender);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pGender->bEnable = (*env)->GetIntField(env, objGender, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nGender", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pGender->nGender = (*env)->GetIntField(env, objGender, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nConfidence", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pGender->nConfidence = (*env)->GetIntField(env, objGender, fid);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pGender -> objGender
 */
HVCW_INT32 JNUSetEpGender(JNIEnv *env, jobject objGender, HVCW_EP_GENDER *pGender)
{
	jclass cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objGender);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objGender, fid, (jint)pGender->bEnable);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nGender", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objGender, fid, (jint)pGender->nGender);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nConfidence", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objGender, fid, (jint)pGender->nConfidence);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objExpression -> pExpression
 */
HVCW_INT32 JNUGetEpExpression(JNIEnv *env, HVCW_EP_EXPRESSION *pExpression, jobject objExpression)
{
	HVCW_INT32 nRet;
	jclass cls       = NULL;
	jfieldID fid     = NULL;
	jobject objRange = NULL;

	cls = (*env)->GetObjectClass(env, objExpression);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pExpression->bEnable = (*env)->GetIntField(env, objExpression, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nExpression", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pExpression->expression = (HVCW_EXPRESSION)(*env)->GetIntField(env, objExpression, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nScore", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pExpression->nScore = (*env)->GetIntField(env, objExpression, fid);


	fid = (*env)->GetFieldID(env, cls, "degreeRange", "Ljp/co/omron/hvcw/Range;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}

	objRange = (*env)->GetObjectField(env, objExpression, fid);

	nRet = JNUGetRange(env, &(pExpression->degreeRange), objRange);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pExpression -> objExpression
 */
HVCW_INT32 JNUSetEpExpression(JNIEnv *env, jobject objExpression, HVCW_EP_EXPRESSION *pExpression)
{
	HVCW_INT32 nRet;
	jclass cls       = NULL;
	jobject objRange = NULL;
	jfieldID fid     = NULL;

	cls = (*env)->GetObjectClass(env, objExpression);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objExpression, fid, (jint)pExpression->bEnable);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nExpression", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objExpression, fid, (jint)pExpression->expression);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nScore", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objExpression, fid, (jint)pExpression->nScore);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "degreeRange", "Ljp/co/omron/hvcw/Range;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objRange = (*env)->GetObjectField(env, objExpression, fid);

	nRet = JNUSetRange(env, objRange, &(pExpression->degreeRange));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objExpression, fid, objRange);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objRecognition -> pRecognition
 */
HVCW_INT32 JNUGetEpRecognition(JNIEnv *env, HVCW_EP_RECOGNITION *pRecognition, jobject objRecognition)
{
	jclass cls   = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objRecognition);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pRecognition->bEnable = (*env)->GetIntField(env, objRecognition, fid);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pRecognition -> objRecognition
 */
HVCW_INT32 JNUSetEpRecognition(JNIEnv *env, jobject objRecognition, HVCW_EP_RECOGNITION *pRecognition)
{
	jclass cls = NULL;
	jfieldID fid = NULL;

	cls = (*env)->GetObjectClass(env, objRecognition);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objRecognition, fid, (jint)pRecognition->bEnable);


	(*env)->DeleteLocalRef(env,cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objOkaoProcess -> pOkaoProcess
 */
HVCW_INT32 JNUGetEpOkaoProcess(JNIEnv *env, HVCW_EP_OKAO_PROCESS *pOkaoProcess, jobject objOkaoProcess)
{
	HVCW_INT32 nRet;
	jclass cls             = NULL;
	jfieldID fid           = NULL;
	jobject objBody        = NULL;
	jobject objPet         = NULL;
	jobject objFace        = NULL;
	jobject objAge         = NULL;
	jobject objGender      = NULL;
	jobject objExpression  = NULL;
	jobject objRecognition = NULL;

	cls = (*env)->GetObjectClass(env, objOkaoProcess);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "body", "Ljp/co/omron/hvcw/EpBody;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objBody = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUGetEpBody(env, &(pOkaoProcess->body), objBody);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "pet", "Ljp/co/omron/hvcw/EpPet;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objPet = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUGetEpPet(env, &(pOkaoProcess->pet), objPet);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "face", "Ljp/co/omron/hvcw/EpFace;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objFace = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUGetEpFace(env, &(pOkaoProcess->face), objFace);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "age", "Ljp/co/omron/hvcw/EpAge;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objAge = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUGetEpAge(env, &(pOkaoProcess->age), objAge);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "gender", "Ljp/co/omron/hvcw/EpGender;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objGender = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUGetEpGender(env, &(pOkaoProcess->gender), objGender);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "expression", "Ljp/co/omron/hvcw/EpExpression;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objExpression = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUGetEpExpression(env, &(pOkaoProcess->expression), objExpression);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "recognition", "Ljp/co/omron/hvcw/EpRecognition;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objRecognition = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUGetEpRecognition(env, &(pOkaoProcess->recognition), objRecognition);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pOkaoProcess -> objOkaoProcess
 */
HVCW_INT32 JNUSetEpOkaoProcess(JNIEnv *env, jobject objOkaoProcess, HVCW_EP_OKAO_PROCESS *pOkaoProcess)
{
	HVCW_INT32 nRet;
	jclass cls             = NULL;
	jfieldID fid           = NULL;
	jobject objBody        = NULL;
	jobject objPet         = NULL;
	jobject objFace        = NULL;
	jobject objAge         = NULL;
	jobject objGender      = NULL;
	jobject objExpression  = NULL;
	jobject objRecognition = NULL;

	cls = (*env)->GetObjectClass(env, objOkaoProcess);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "body", "Ljp/co/omron/hvcw/EpBody;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objBody = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUSetEpBody(env, objBody, &(pOkaoProcess->body));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objOkaoProcess, fid, objBody);


	fid = (*env)->GetFieldID(env, cls, "pet", "Ljp/co/omron/hvcw/EpPet;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objPet = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUSetEpPet(env, objPet, &(pOkaoProcess->pet));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objOkaoProcess, fid, objPet);


	fid = (*env)->GetFieldID(env, cls, "face", "Ljp/co/omron/hvcw/EpFace;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objFace = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUSetEpFace(env, objFace, &(pOkaoProcess->face));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objOkaoProcess, fid, objFace);


	fid = (*env)->GetFieldID(env, cls, "age", "Ljp/co/omron/hvcw/EpAge;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objAge = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUSetEpAge(env, objAge, &(pOkaoProcess->age));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objOkaoProcess, fid, objAge);


	fid = (*env)->GetFieldID(env, cls, "gender", "Ljp/co/omron/hvcw/EpGender;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objGender = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUSetEpGender(env, objGender, &(pOkaoProcess->gender));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objOkaoProcess, fid, objGender);


	fid = (*env)->GetFieldID(env, cls, "expression", "Ljp/co/omron/hvcw/EpExpression;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objExpression = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUSetEpExpression(env, objExpression, &(pOkaoProcess->expression));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objOkaoProcess, fid, objExpression);


	fid = (*env)->GetFieldID(env, cls, "recognition", "Ljp/co/omron/hvcw/EpRecognition;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objRecognition = (*env)->GetObjectField(env, objOkaoProcess, fid);

	nRet = JNUSetEpRecognition(env, objRecognition, &(pOkaoProcess->recognition));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objOkaoProcess, fid, objRecognition);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objPushAlert -> pPushAlert
 */
HVCW_INT32 JNUGetEpPushAlert(JNIEnv *env, HVCW_EP_PUSH_ALERT *pPushAlert, jobject objPushAlert)
{
	HVCW_INT32 nRet;
	jclass cls          = NULL;
	jfieldID fid        = NULL;
	jobject objFileInfo = NULL;

	cls = (*env)->GetObjectClass(env, objPushAlert);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pPushAlert->bEnable = (*env)->GetIntField(env, objPushAlert, fid);


	fid = (*env)->GetFieldID(env, cls, "fileInfo", "Ljp/co/omron/hvcw/FileInfo;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}

	objFileInfo = (*env)->GetObjectField(env, objPushAlert, fid);

	nRet = JNUGetFileInfo(env, &(pPushAlert->fileInfo), objFileInfo);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pPushAlert -> objPushAlert
 */
HVCW_INT32 JNUSetEpPushAlert(JNIEnv *env, jobject objPushAlert, HVCW_EP_PUSH_ALERT *pPushAlert)
{
	HVCW_INT32 nRet;
	jclass cls          = NULL;
	jfieldID fid        = NULL;
	jobject objFileInfo = NULL;

	cls = (*env)->GetObjectClass(env, objPushAlert);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objPushAlert, fid, (jint)pPushAlert->bEnable);


	fid = (*env)->GetFieldID(env, cls, "fileInfo", "Ljp/co/omron/hvcw/FileInfo;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objFileInfo = (*env)->GetObjectField(env, objPushAlert, fid);

	nRet = JNUSetFileInfo(env, objFileInfo, &(pPushAlert->fileInfo));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objPushAlert, fid, objFileInfo);


	(*env)->DeleteLocalRef(env,cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objSound -> pSound
 */
HVCW_INT32 JNUGetEpSound(JNIEnv *env, HVCW_EP_SOUND *pSound, jobject objSound)
{
	HVCW_INT32 nRet;
	jclass cls          = NULL;
	jfieldID fid        = NULL;
	jobject objFileInfo = NULL;

	cls = (*env)->GetObjectClass(env, objSound);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pSound->bEnable = (*env)->GetIntField(env, objSound, fid);


	fid = (*env)->GetFieldID(env, cls, "fileInfo", "Ljp/co/omron/hvcw/FileInfo;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}

	objFileInfo = (*env)->GetObjectField(env, objSound, fid);

	nRet = JNUGetFileInfo(env, &(pSound->fileInfo), objFileInfo);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pSound -> objSound
 */
HVCW_INT32 JNUSetEpSound(JNIEnv *env, jobject objSound, HVCW_EP_SOUND *pSound)
{
	HVCW_INT32 nRet;
	jclass cls = NULL;
	jfieldID fid = NULL;
	jobject objFileInfo = NULL;

	cls = (*env)->GetObjectClass(env, objSound);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "booleanEnable", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objSound, fid, (jint)pSound->bEnable);


	fid = (*env)->GetFieldID(env, cls, "fileInfo", "Ljp/co/omron/hvcw/FileInfo;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objFileInfo = (*env)->GetObjectField(env, objSound, fid);

	nRet = JNUSetFileInfo(env, objFileInfo, &(pSound->fileInfo));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objSound, fid, objFileInfo);


	(*env)->DeleteLocalRef(env,cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objNotification -> pNotification
 */
HVCW_INT32 JNUGetEpNotification(JNIEnv *env, HVCW_EP_NOTIFICATION *pNotification, jobject objNotification)
{
	HVCW_INT32 nRet;
	jclass cls           = NULL;
	jfieldID fid         = NULL;
	jobject objPushAlert = NULL;
	jobject objSound     = NULL;

	cls = (*env)->GetObjectClass(env, objNotification);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "pushAlert", "Ljp/co/omron/hvcw/EpPushAlert;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}

	objPushAlert = (*env)->GetObjectField(env, objNotification, fid);

	nRet = JNUGetEpPushAlert(env, &(pNotification->pushAlert), objPushAlert);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "sound", "Ljp/co/omron/hvcw/EpSound;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}

	objSound = (*env)->GetObjectField(env, objNotification, fid);

	nRet = JNUGetEpSound(env, &(pNotification->sound), objSound);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pNotification -> objNotification
 */
HVCW_INT32 JNUSetEpNotification(JNIEnv *env, jobject objNotification, HVCW_EP_NOTIFICATION *pNotification)
{
	HVCW_INT32 nRet;
	jclass cls           = NULL;
	jfieldID fid         = NULL;
	jobject objPushAlert = NULL;
	jobject objSound     = NULL;

	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetEpNotification 001\n");
	cls = (*env)->GetObjectClass(env, objNotification);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = (*env)->GetFieldID(env, cls, "pushAlert", "Ljp/co/omron/hvcw/EpPushAlert;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objPushAlert = (*env)->GetObjectField(env, objNotification, fid);

	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetEpNotification 002\n");
	nRet = JNUSetEpPushAlert(env, objPushAlert, &(pNotification->pushAlert));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objNotification, fid, objPushAlert);


	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetEpNotification 003\n");
	fid = (*env)->GetFieldID(env, cls, "sound", "Ljp/co/omron/hvcw/EpSound;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objSound = (*env)->GetObjectField(env, objNotification, fid);

	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetEpNotification 004\n");
	nRet = JNUSetEpSound(env, objSound, &(pNotification->sound));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objNotification, fid, objSound);


	(*env)->DeleteLocalRef(env,cls);
	cls = NULL;

	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetEpNotification End\n");
	return HVCW_SUCCESS;
}

/*
 * objEpPostProcess -> pEpPostProcess
 */
HVCW_INT32 JNUGetEpPostProcess(JNIEnv *env, HVCW_EP_POST_PROCESS *pEpPostProcess, jobject objEpPostProcess)
{
	HVCW_INT32 nRet;
	jclass cls   = NULL;
	jfieldID fid = NULL;
	jobject obj  = NULL;

	cls = (*env)->GetObjectClass(env, objEpPostProcess);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nSaveLog", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pEpPostProcess->saveLog = (*env)->GetIntField(env, objEpPostProcess, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nSaveImage", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pEpPostProcess->saveImage = (*env)->GetIntField(env, objEpPostProcess, fid);


	fid = (*env)->GetFieldID(env, cls, "notification", "Ljp/co/omron/hvcw/EpNotification;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	obj = (*env)->GetObjectField(env, objEpPostProcess, fid);

	nRet = JNUGetEpNotification(env, &(pEpPostProcess->notification), obj);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pEpPostProcess -> objEpPostProcess
 */
HVCW_INT32 JNUSetEpPostProcess(JNIEnv *env, jobject objEpPostProcess, HVCW_EP_POST_PROCESS *pEpPostProcess)
{
	HVCW_INT32 nRet;
	jclass cls   = NULL;
	jfieldID fid = NULL;
	jobject obj  = NULL;

	cls = (*env)->GetObjectClass(env, objEpPostProcess);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nSaveLog", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objEpPostProcess, fid, (jint)pEpPostProcess->saveLog);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nSaveImage", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objEpPostProcess, fid, (jint)pEpPostProcess->saveImage);


	fid = (*env)->GetFieldID(env, cls, "notification", "Ljp/co/omron/hvcw/EpNotification;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	obj = (*env)->GetObjectField(env, objEpPostProcess, fid);

	nRet = JNUSetEpNotification(env, obj, &(pEpPostProcess->notification));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEpPostProcess, fid, obj);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objEpKnownuser -> pEpKnownuser
 */
HVCW_INT32 JNUGetEpKnownuser(JNIEnv *env, HVCW_EP_KNOWNUSER *pEpKnownuser, jobject objEpKnownuser)
{
	HVCW_INT32 nRet;
	jclass cls          = NULL;
	jfieldID fid        = NULL;
	jobject objFileInfo = NULL;

	cls = (*env)->GetObjectClass(env, objEpKnownuser);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nUserID", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pEpKnownuser->nUserID = (*env)->GetIntField(env, objEpKnownuser, fid);


	fid = (*env)->GetFieldID(env, cls, "fileInfo", "Ljp/co/omron/hvcw/FileInfo;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objFileInfo = (*env)->GetObjectField(env, objEpKnownuser, fid);

	nRet = JNUGetFileInfo(env, &(pEpKnownuser->fileInfo), objFileInfo);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pEpKnownuser -> objEpKnownuser
 */
HVCW_INT32 JNUSetEpKnownuser(JNIEnv *env, jobject objEpKnownuser, HVCW_EP_KNOWNUSER *pEpKnownuser)
{
	HVCW_INT32 nRet;
	jclass cls          = NULL;
	jfieldID fid        = NULL;
	jobject objFileInfo = NULL;

	cls = (*env)->GetObjectClass(env, objEpKnownuser);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nUserID", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objEpKnownuser, fid, (jint)pEpKnownuser->nUserID);


	fid = (*env)->GetFieldID(env, cls, "fileInfo", "Ljp/co/omron/hvcw/FileInfo;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objFileInfo = (*env)->GetObjectField(env, objEpKnownuser, fid);

	nRet = JNUSetFileInfo(env, objFileInfo, &(pEpKnownuser->fileInfo));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEpKnownuser, fid, objFileInfo);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objPushAlert -> pPushAlert
 */
HVCW_INT32 JNUGetEpFrPushAlert(JNIEnv *env, HVCW_EP_FR_PUSH_ALERT *pFrPushAlert, jobject objFfPushAlert)
{
	HVCW_INT32   nRet;
	jclass       cls             = NULL;
	jfieldID     fid             = NULL;
	jobjectArray objArrKnownuser = NULL;
	jobject      objKnownuser    = NULL;
	jobject      objPushAlert    = NULL;
	int          nLength         = 0;
	int          i               = 0;

	cls = (*env)->GetObjectClass(env, objFfPushAlert);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "knownUser", "[Ljp/co/omron/hvcw/EpKnownuser;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objArrKnownuser = (*env)->GetObjectField(env, objFfPushAlert, fid);

	nLength = (*env)->GetArrayLength(env, objArrKnownuser);

	for(i = 0; i<nLength; i++){
		objKnownuser = (*env)->GetObjectArrayElement(env, objArrKnownuser, i);

		JNUGetEpKnownuser(env, &(pFrPushAlert->knownUser[i]), objKnownuser);

		(*env)->DeleteLocalRef(env, objKnownuser);
		objKnownuser = NULL;
	}


	fid = (*env)->GetFieldID(env, cls, "unknownUser", "Ljp/co/omron/hvcw/EpPushAlert;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objPushAlert = (*env)->GetObjectField(env, objFfPushAlert, fid);

	nRet = JNUGetEpPushAlert(env, &(pFrPushAlert->unknownUser), objPushAlert);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pPushAlert -> objPushAlert
 */
HVCW_INT32 JNUSetEpFrPushAlert(JNIEnv *env, jobject objFfPushAlert, HVCW_EP_FR_PUSH_ALERT *pFrPushAlert)
{
	HVCW_INT32   nRet;
	jclass       cls             = NULL;
	jfieldID     fid             = NULL;
	jobjectArray objArrKnownuser = NULL;
	jobject      objKnownuser    = NULL;
	jobject      objPushAlert    = NULL;
	int          nLength         = 0;
	int          i               = 0;

	cls = (*env)->GetObjectClass(env, objFfPushAlert);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "knownUser", "[Ljp/co/omron/hvcw/EpKnownuser;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objArrKnownuser = (*env)->GetObjectField(env, objFfPushAlert, fid);

	nLength = (*env)->GetArrayLength(env, objArrKnownuser);

	for(i = 0; i<nLength; i++){
		objKnownuser = (*env)->GetObjectArrayElement(env, objArrKnownuser, i);

		JNUSetEpKnownuser(env, objKnownuser, &(pFrPushAlert->knownUser[i]));

		(*env)->SetObjectArrayElement(env, objArrKnownuser, i, objKnownuser);

		(*env)->DeleteLocalRef(env, objKnownuser);
		objKnownuser = NULL;
	}


	fid = (*env)->GetFieldID(env, cls, "unknownUser", "Ljp/co/omron/hvcw/EpPushAlert;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objPushAlert = (*env)->GetObjectField(env, objFfPushAlert, fid);

	nRet = JNUSetEpPushAlert(env, objPushAlert, &(pFrPushAlert->unknownUser));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objFfPushAlert, fid, objPushAlert);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objFrSound -> pFrSound
 */
HVCW_INT32 JNUGetEpFrSound(JNIEnv *env, HVCW_EP_FR_SOUND *pFrSound, jobject objFrSound)
{
	HVCW_INT32   nRet;
	jclass       cls             = NULL;
	jfieldID     fid             = NULL;
	jobjectArray objArrKnownuser = NULL;
	jobject      objKnownuser    = NULL;
	jobject      objSound        = NULL;
	int          nLength         = 0;
	int          i               = 0;

	cls = (*env)->GetObjectClass(env, objFrSound);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "knownUser", "[Ljp/co/omron/hvcw/EpKnownuser;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objArrKnownuser = (*env)->GetObjectField(env, objFrSound, fid);

	nLength = (*env)->GetArrayLength(env, objArrKnownuser);

	for(i = 0; i<nLength; i++){
		objKnownuser = (*env)->GetObjectArrayElement(env, objArrKnownuser, i);

		JNUGetEpKnownuser(env, &(pFrSound->knownUser[i]), objKnownuser);

		(*env)->DeleteLocalRef(env, objKnownuser);
		objKnownuser = NULL;
	}


	fid = (*env)->GetFieldID(env, cls, "unknownUser", "Ljp/co/omron/hvcw/EpSound;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objSound = (*env)->GetObjectField(env, objFrSound, fid);

	nRet = JNUGetEpSound(env, &(pFrSound->unknownUser), objSound);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pFrSound -> objFrSound
 */
HVCW_INT32 JNUSetEpFrSound(JNIEnv *env, jobject objFrSound, HVCW_EP_FR_SOUND *pFrSound)
{
	HVCW_INT32   nRet;
	jclass       cls             = NULL;
	jfieldID     fid             = NULL;
	jobjectArray objArrKnownuser = NULL;
	jobject      objKnownuser    = NULL;
	jobject      objSound        = NULL;
	int          nLength         = 0;
	int          i               = 0;

	cls = (*env)->GetObjectClass(env, objFrSound);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "knownUser", "[Ljp/co/omron/hvcw/EpKnownuser;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objArrKnownuser = (*env)->GetObjectField(env, objFrSound, fid);

	nLength = (*env)->GetArrayLength(env, objArrKnownuser);

	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetEpFrSound 001 Length:%d\n", nLength);
	for(i = 0; i<nLength; i++){
		objKnownuser = (*env)->GetObjectArrayElement(env, objArrKnownuser, i);

		JNUSetEpKnownuser(env, objKnownuser, &(pFrSound->knownUser[i]));

		(*env)->SetObjectArrayElement(env, objArrKnownuser, i, objKnownuser);

		(*env)->DeleteLocalRef(env, objKnownuser);
		objKnownuser = NULL;
		__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetEpFrSound i:%d\n", i);
	}
	__android_log_print(ANDROID_LOG_INFO, "Debug", "JNUSetEpFrSound END\n");


	fid = (*env)->GetFieldID(env, cls, "unknownUser", "Ljp/co/omron/hvcw/EpSound;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objSound = (*env)->GetObjectField(env, objFrSound, fid);

	nRet = JNUSetEpSound(env, objSound, &(pFrSound->unknownUser));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objFrSound, fid, objSound);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}

/*
 * objFrNotification -> pFrNotification
 */
HVCW_INT32 JNUGetEpFrNotification(JNIEnv *env, HVCW_EP_FR_NOTIFICATION *pFrNotification, jobject objFrNotification)
{
	HVCW_INT32 nRet;
	jclass cls             = NULL;
	jfieldID fid           = NULL;
	jobject objFrPushAlert = NULL;
	jobject objFrSound     = NULL;

	cls = (*env)->GetObjectClass(env, objFrNotification);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "pushAlert", "Ljp/co/omron/hvcw/EpFrPushAlert;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objFrPushAlert = (*env)->GetObjectField(env, objFrNotification, fid);

	nRet = JNUGetEpFrPushAlert(env, &(pFrNotification->pushAlert), objFrPushAlert);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "sound", "Ljp/co/omron/hvcw/EpFrSound;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objFrSound = (*env)->GetObjectField(env, objFrNotification, fid);

	nRet = JNUGetEpFrSound(env, &(pFrNotification->sound), objFrSound);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pFrNotification -> objFrNotification
 */
HVCW_INT32 JNUSetEpFrNotification(JNIEnv *env, jobject objFrNotification, HVCW_EP_FR_NOTIFICATION *pFrNotification)
{
	HVCW_INT32 nRet;
	jclass cls             = NULL;
	jfieldID fid           = NULL;
	jobject objFrPushAlert = NULL;
	jobject objFrSound     = NULL;

	cls = (*env)->GetObjectClass(env, objFrNotification);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "pushAlert", "Ljp/co/omron/hvcw/EpFrPushAlert;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objFrPushAlert = (*env)->GetObjectField(env, objFrNotification, fid);

	nRet = JNUSetEpFrPushAlert(env, objFrPushAlert, &(pFrNotification->pushAlert));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objFrNotification, fid, objFrPushAlert);


	fid = (*env)->GetFieldID(env, cls, "sound", "Ljp/co/omron/hvcw/EpFrSound;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objFrSound = (*env)->GetObjectField(env, objFrNotification, fid);

	nRet = JNUSetEpFrSound(env, objFrSound, &(pFrNotification->sound));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objFrNotification, fid, objFrSound);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objFrPostProcess -> pFrPostProcess
 */
HVCW_INT32 JNUGetEpFrPostProcess(JNIEnv *env, HVCW_EP_FR_POST_PROCESS *pFrPostProcess, jobject objFrPostProcess)
{
	HVCW_INT32 nRet;
	jclass cls   = NULL;
	jfieldID fid = NULL;
	jobject obj  = NULL;

	cls = (*env)->GetObjectClass(env, objFrPostProcess);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nSaveImage", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	pFrPostProcess->saveImage = (HVCW_SAVE_RESULT)(*env)->GetIntField(env, objFrPostProcess, fid);


	fid = (*env)->GetFieldID(env, cls, "notification", "Ljp/co/omron/hvcw/EpFrNotification;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	obj = (*env)->GetObjectField(env, objFrPostProcess, fid);

	nRet = JNUGetEpFrNotification(env, &(pFrPostProcess->notification), obj);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pFrPostProcess -> objFrPostProcess
 */
HVCW_INT32 JNUSetEpFrPostProcess(JNIEnv *env, jobject objFrPostProcess, HVCW_EP_FR_POST_PROCESS *pFrPostProcess)
{
	HVCW_INT32 nRet;
	jclass cls   = NULL;
	jfieldID fid = NULL;
	jobject obj  = NULL;

	cls = (*env)->GetObjectClass(env, objFrPostProcess);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nSaveImage", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objFrPostProcess, fid, (jint)pFrPostProcess->saveImage);


	fid = (*env)->GetFieldID(env, cls, "notification", "Ljp/co/omron/hvcw/EpFrNotification;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	obj = (*env)->GetObjectField(env, objFrPostProcess, fid);

	nRet = JNUSetEpFrNotification(env, obj, &(pFrPostProcess->notification));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objFrPostProcess, fid, obj);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objSoundEvent -> pSoundEvent
 */
HVCW_INT32 JNUGetEpSoundEvent(JNIEnv *env, HVCW_EP_SOUND_EVENT *pSoundEvent, jobject objSoundEvent)
{
	jclass clsSoundEvent = NULL;
	jfieldID fid         = NULL;

	clsSoundEvent = (*env)->GetObjectClass(env, objSoundEvent);
	if(clsSoundEvent == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSoundEvent, "nSensitivity", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSoundEvent);
		clsSoundEvent = NULL;
		return HVCW_INVALID_PARAM;
	}
	pSoundEvent->nSensitivity = (*env)->GetIntField(env, objSoundEvent, fid);

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSoundEvent, "nDuration", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSoundEvent);
		clsSoundEvent = NULL;
		return HVCW_INVALID_PARAM;
	}
	pSoundEvent->unDuration = (*env)->GetIntField(env, objSoundEvent, fid);

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSoundEvent, "nRatio", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSoundEvent);
		clsSoundEvent = NULL;
		return HVCW_INVALID_PARAM;
	}
	pSoundEvent->unRatio = (*env)->GetIntField(env, objSoundEvent, fid);

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSoundEvent, "nOffPeriod", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSoundEvent);
		clsSoundEvent = NULL;
		return HVCW_INVALID_PARAM;
	}
	pSoundEvent->unOffPeriod = (*env)->GetIntField(env, objSoundEvent, fid);

	(*env)->DeleteLocalRef(env, clsSoundEvent);
	clsSoundEvent = NULL;

	return HVCW_SUCCESS;
}


/*
 * pSoundEvent -> objSoundEvent
 */
HVCW_INT32 JNUSetEpSoundEvent(JNIEnv *env, jobject objSoundEvent, HVCW_EP_SOUND_EVENT *pSoundEvent)
{
	jclass clsSoundEvent = NULL;
	jfieldID fid         = NULL;

	clsSoundEvent = (*env)->GetObjectClass(env, objSoundEvent);
	if(clsSoundEvent == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSoundEvent, "nSensitivity", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSoundEvent);
		clsSoundEvent = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objSoundEvent, fid, (jint)pSoundEvent->nSensitivity);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSoundEvent, "nDuration", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSoundEvent);
		clsSoundEvent = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objSoundEvent, fid, (jint)pSoundEvent->unDuration);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSoundEvent, "nRatio", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSoundEvent);
		clsSoundEvent = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objSoundEvent, fid, (jint)pSoundEvent->unRatio);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsSoundEvent, "nOffPeriod", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsSoundEvent);
		clsSoundEvent = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objSoundEvent, fid, (jint)pSoundEvent->unOffPeriod);

	(*env)->DeleteLocalRef(env, clsSoundEvent);
	clsSoundEvent = NULL;

	return HVCW_SUCCESS;
}


/*
 * objEventProgramSound -> pEventProgramSound
 */
HVCW_INT32 JNUGetEventProgramSound(JNIEnv *env, HVCW_EVENT_PROGRAM_SOUND *pEventProgramSound, jobject objEventProgramSound)
{
	HVCW_INT32 nRet;
	jclass cls                 = NULL;
	jfieldID fid               = NULL;
	jobject objEpSoundEvent    = NULL;
	jobject objEpOkaoProcess   = NULL;
	jobject objEpPostProcess   = NULL;
	jobject objEpFrPostProcess = NULL;

	cls = (*env)->GetObjectClass(env, objEventProgramSound);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "soundEvent", "Ljp/co/omron/hvcw/EpSoundEvent;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpSoundEvent = (*env)->GetObjectField(env, objEventProgramSound, fid);

	nRet = JNUGetEpSoundEvent(env, &(pEventProgramSound->soundEvent), objEpSoundEvent);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "okaoProcess", "Ljp/co/omron/hvcw/EpOkaoProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpOkaoProcess = (*env)->GetObjectField(env, objEventProgramSound, fid);

	nRet = JNUGetEpOkaoProcess(env, &(pEventProgramSound->okaoProcess), objEpOkaoProcess);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "postProcess", "Ljp/co/omron/hvcw/EpPostProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpPostProcess = (*env)->GetObjectField(env, objEventProgramSound, fid);

	nRet = JNUGetEpPostProcess(env, &(pEventProgramSound->postProcess), objEpPostProcess);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "frPostProcess", "Ljp/co/omron/hvcw/EpFrPostProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpFrPostProcess = (*env)->GetObjectField(env, objEventProgramSound, fid);

	nRet = JNUGetEpFrPostProcess(env, &(pEventProgramSound->frPostProcess), objEpFrPostProcess);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pEventProgramSound -> objEventProgramSound
 */
HVCW_INT32 JNUSetEventProgramSound(JNIEnv *env, jobject objEventProgramSound, HVCW_EVENT_PROGRAM_SOUND *pEventProgramSound)
{
	HVCW_INT32 nRet;
	jclass cls                 = NULL;
	jfieldID fid               = NULL;
	jobject objEpSoundEvent    = NULL;
	jobject objEpOkaoProcess   = NULL;
	jobject objEpPostProcess   = NULL;
	jobject objEpFrPostProcess = NULL;

	cls = (*env)->GetObjectClass(env, objEventProgramSound);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "soundEvent", "Ljp/co/omron/hvcw/EpSoundEvent;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpSoundEvent = (*env)->GetObjectField(env, objEventProgramSound, fid);

	nRet = JNUSetEpSoundEvent(env, objEpSoundEvent, &(pEventProgramSound->soundEvent));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEventProgramSound, fid, objEpSoundEvent);


	fid = (*env)->GetFieldID(env, cls, "okaoProcess", "Ljp/co/omron/hvcw/EpOkaoProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpOkaoProcess = (*env)->GetObjectField(env, objEventProgramSound, fid);

	nRet = JNUSetEpOkaoProcess(env, objEpOkaoProcess, &(pEventProgramSound->okaoProcess));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEventProgramSound, fid, objEpOkaoProcess);


	fid = (*env)->GetFieldID(env, cls, "postProcess", "Ljp/co/omron/hvcw/EpPostProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpPostProcess = (*env)->GetObjectField(env, objEventProgramSound, fid);

	nRet = JNUSetEpPostProcess(env, objEpPostProcess, &(pEventProgramSound->postProcess));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEventProgramSound, fid, objEpPostProcess);


	fid = (*env)->GetFieldID(env, cls, "frPostProcess", "Ljp/co/omron/hvcw/EpFrPostProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpFrPostProcess = (*env)->GetObjectField(env, objEventProgramSound, fid);

	nRet = JNUSetEpFrPostProcess(env, objEpFrPostProcess, &(pEventProgramSound->frPostProcess));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEventProgramSound, fid, objEpFrPostProcess);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objMotionEvent -> pMotionEvent
 */
HVCW_INT32 JNUGetEpMotionEvent(JNIEnv *env, HVCW_EP_MOTION_EVENT *pMotionEvent, jobject objMotionEvent)
{
	HVCW_INT32 nRet = 0;
	jclass clsParam = NULL;
	jfieldID fid    = NULL;
	jobject objRect = NULL;

	clsParam = (*env)->GetObjectClass(env, objMotionEvent);
	if(clsParam == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, clsParam, "rect", "Ljp/co/omron/hvcw/Rect;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsParam);
		clsParam = NULL;
		return HVCW_INVALID_PARAM;
	}
	objRect = (*env)->GetObjectField(env, objMotionEvent, fid);

	nRet = JNUGetRect(env, &(pMotionEvent->area), objRect);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, clsParam);
		clsParam = NULL;
		return nRet;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsParam, "nSensitivity", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsParam);
		clsParam = NULL;
		return HVCW_INVALID_PARAM;
	}
	pMotionEvent->nSensitivity = (*env)->GetIntField(env, objMotionEvent, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsParam, "nDuration", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsParam);
		clsParam = NULL;
		return HVCW_INVALID_PARAM;
	}
	pMotionEvent->unDuration = (*env)->GetIntField(env, objMotionEvent, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsParam, "nRatio", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsParam);
		clsParam = NULL;
		return HVCW_INVALID_PARAM;
	}
	pMotionEvent->unRatio = (*env)->GetIntField(env, objMotionEvent, fid);


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsParam, "nOffPeriod", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsParam);
		clsParam = NULL;
		return HVCW_INVALID_PARAM;
	}
	pMotionEvent->unOffPeriod = (*env)->GetIntField(env, objMotionEvent, fid);


	(*env)->DeleteLocalRef(env, clsParam);
	clsParam = NULL;

	return HVCW_SUCCESS;
}


/*
 * pMotionEvent -> objMotionEvent
 */
HVCW_INT32 JNUSetEpMotionEvent(JNIEnv *env, jobject objMotionEvent, HVCW_EP_MOTION_EVENT *pMotionEvent)
{
	HVCW_INT32 nRet = 0;
	jclass cls      = NULL;
	jfieldID fid    = NULL;
	jobject objRect = NULL;

	cls = (*env)->GetObjectClass(env, objMotionEvent);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "rect", "Ljp/co/omron/hvcw/Rect;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objRect = (*env)->GetObjectField(env, objMotionEvent, fid);

	nRet = JNUSetRect(env, objRect, &(pMotionEvent->area));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objMotionEvent, fid, objRect);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nSensitivity", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objMotionEvent, fid, (jint)pMotionEvent->nSensitivity);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nDuration", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objMotionEvent, fid, (jint)pMotionEvent->unDuration);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nRatio", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objMotionEvent, fid, (jint)pMotionEvent->unRatio);


	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nOffPeriod", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objMotionEvent, fid, (jint)pMotionEvent->unOffPeriod);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objEventProgramMotion -> pEventProgramMotion
 */
HVCW_INT32 JNUGetEventProgramMotion(JNIEnv *env, HVCW_EVENT_PROGRAM_MOTION *pEventProgramMotion, jobject objEventProgramMotion)
{
	HVCW_INT32 nRet;
	jclass cls                 = NULL;
	jfieldID fid               = NULL;
	jobject objEpMotionEvent   = NULL;
	jobject objEpOkaoProcess   = NULL;
	jobject objEpPostProcess   = NULL;
	jobject objEpFrPostProcess = NULL;

	cls = (*env)->GetObjectClass(env, objEventProgramMotion);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "motionEvent", "Ljp/co/omron/hvcw/EpMotionEvent;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpMotionEvent = (*env)->GetObjectField(env, objEventProgramMotion, fid);

	nRet = JNUGetEpMotionEvent(env, &(pEventProgramMotion->motionEvent), objEpMotionEvent);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "okaoProcess", "Ljp/co/omron/hvcw/EpOkaoProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpOkaoProcess = (*env)->GetObjectField(env, objEventProgramMotion, fid);

	nRet = JNUGetEpOkaoProcess(env, &(pEventProgramMotion->okaoProcess), objEpOkaoProcess);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "postProcess", "Ljp/co/omron/hvcw/EpPostProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpPostProcess = (*env)->GetObjectField(env, objEventProgramMotion, fid);

	nRet = JNUGetEpPostProcess(env, &(pEventProgramMotion->postProcess), objEpPostProcess);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "frPostProcess", "Ljp/co/omron/hvcw/EpFrPostProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpFrPostProcess = (*env)->GetObjectField(env, objEventProgramMotion, fid);

	nRet = JNUGetEpFrPostProcess(env, &(pEventProgramMotion->frPostProcess), objEpFrPostProcess);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pEventProgramMotion -> objEventProgramMotion
 */
HVCW_INT32 JNUSetEventProgramMotion(JNIEnv *env, jobject objEventProgramMotion, HVCW_EVENT_PROGRAM_MOTION *pEventProgramMotion)
{
	HVCW_INT32 nRet;
	jclass cls                 = NULL;
	jfieldID fid               = NULL;
	jobject objEpMotionEvent   = NULL;
	jobject objEpOkaoProcess   = NULL;
	jobject objEpPostProcess   = NULL;
	jobject objEpFrPostProcess = NULL;

	cls = (*env)->GetObjectClass(env, objEventProgramMotion);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "motionEvent", "Ljp/co/omron/hvcw/EpMotionEvent;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpMotionEvent = (*env)->GetObjectField(env, objEventProgramMotion, fid);

	nRet = JNUSetEpMotionEvent(env, objEpMotionEvent, &(pEventProgramMotion->motionEvent));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEventProgramMotion, fid, objEpMotionEvent);


	fid = (*env)->GetFieldID(env, cls, "okaoProcess", "Ljp/co/omron/hvcw/EpOkaoProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpOkaoProcess = (*env)->GetObjectField(env, objEventProgramMotion, fid);

	nRet = JNUSetEpOkaoProcess(env, objEpOkaoProcess, &(pEventProgramMotion->okaoProcess));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEventProgramMotion, fid, objEpOkaoProcess);


	fid = (*env)->GetFieldID(env, cls, "postProcess", "Ljp/co/omron/hvcw/EpPostProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpPostProcess = (*env)->GetObjectField(env, objEventProgramMotion, fid);

	nRet = JNUSetEpPostProcess(env, objEpPostProcess, &(pEventProgramMotion->postProcess));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEventProgramMotion, fid, objEpPostProcess);

/*
	fid = (*env)->GetFieldID(env, cls, "frPostProcess", "Ljp/co/omron/hvcw/EpFrPostProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpFrPostProcess = (*env)->GetObjectField(env, objEventProgramMotion, fid);

	nRet = JNUSetEpFrPostProcess(env, objEpFrPostProcess, &(pEventProgramMotion->frPostProcess));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEventProgramMotion, fid, objEpFrPostProcess);
*/

	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objTimerEvent -> pTimerEvent
 */
HVCW_INT32 JNUGetEpTimerEvent(JNIEnv *env, HVCW_EP_TIMER_EVENT *pTimerEvent, jobject objTimerEvent)
{
	HVCW_INT32 nRet = 0;
	jclass clsParam = NULL;
	jfieldID fid    = NULL;

	clsParam = (*env)->GetObjectClass(env, objTimerEvent);
	if(clsParam == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = NULL;
	fid = (*env)->GetFieldID(env, clsParam, "nInterval", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, clsParam);
		clsParam = NULL;
		return HVCW_INVALID_PARAM;
	}
	pTimerEvent->unInterval = (*env)->GetIntField(env, objTimerEvent, fid);


	(*env)->DeleteLocalRef(env, clsParam);
	clsParam = NULL;

	return HVCW_SUCCESS;
}


/*
 * pTimerEvent -> objTimerEvent
 */
HVCW_INT32 JNUSetEpTimerEvent(JNIEnv *env, jobject objTimerEvent, HVCW_EP_TIMER_EVENT *pTimerEvent)
{
	HVCW_INT32 nRet = 0;
	jclass     cls  = NULL;
	jfieldID   fid  = NULL;

	cls = (*env)->GetObjectClass(env, objTimerEvent);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}

	fid = NULL;
	fid = (*env)->GetFieldID(env, cls, "nInterval", "I");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	(*env)->SetIntField(env, objTimerEvent, fid, (jint)pTimerEvent->unInterval);

	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * objEventProgramTimer -> pEventProgramTimer
 */
HVCW_INT32 JNUGetEventProgramTimer(JNIEnv *env, HVCW_EVENT_PROGRAM_TIMER *pEventProgramTimer, jobject objEventProgramTimer)
{
	HVCW_INT32 nRet;
	jclass cls                 = NULL;
	jfieldID fid               = NULL;
	jobject objEpTimerEvent    = NULL;
	jobject objEpOkaoProcess   = NULL;
	jobject objEpPostProcess   = NULL;
	jobject objEpFrPostProcess = NULL;

	cls = (*env)->GetObjectClass(env, objEventProgramTimer);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "timerEvent", "Ljp/co/omron/hvcw/EpTimerEvent;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpTimerEvent = (*env)->GetObjectField(env, objEventProgramTimer, fid);

	nRet = JNUGetEpTimerEvent(env, &(pEventProgramTimer->timerEvent), objEpTimerEvent);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "okaoProcess", "Ljp/co/omron/hvcw/EpOkaoProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpOkaoProcess = (*env)->GetObjectField(env, objEventProgramTimer, fid);

	nRet = JNUGetEpOkaoProcess(env, &(pEventProgramTimer->okaoProcess), objEpOkaoProcess);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "postProcess", "Ljp/co/omron/hvcw/EpPostProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpPostProcess = (*env)->GetObjectField(env, objEventProgramTimer, fid);

	nRet = JNUGetEpPostProcess(env, &(pEventProgramTimer->postProcess), objEpPostProcess);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	fid = (*env)->GetFieldID(env, cls, "frPostProcess", "Ljp/co/omron/hvcw/EpFrPostProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpFrPostProcess = (*env)->GetObjectField(env, objEventProgramTimer, fid);

	nRet = JNUGetEpFrPostProcess(env, &(pEventProgramTimer->frPostProcess), objEpFrPostProcess);
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}


/*
 * pEventProgramTimer -> objEventProgramTimer
 */
HVCW_INT32 JNUSetEventProgramTimer(JNIEnv *env, jobject objEventProgramTimer, HVCW_EVENT_PROGRAM_TIMER *pEventProgramTimer)
{
	HVCW_INT32 nRet;
	jclass cls                 = NULL;
	jfieldID fid               = NULL;
	jobject objEpTimerEvent    = NULL;
	jobject objEpOkaoProcess   = NULL;
	jobject objEpPostProcess   = NULL;
	jobject objEpFrPostProcess = NULL;

	cls = (*env)->GetObjectClass(env, objEventProgramTimer);
	if(cls == NULL){
		return HVCW_INVALID_PARAM;
	}


	fid = (*env)->GetFieldID(env, cls, "timerEvent", "Ljp/co/omron/hvcw/EpTimerEvent;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpTimerEvent = (*env)->GetObjectField(env, objEventProgramTimer, fid);

	nRet = JNUSetEpTimerEvent(env, objEpTimerEvent, &(pEventProgramTimer->timerEvent));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEventProgramTimer, fid, objEpTimerEvent);


	fid = (*env)->GetFieldID(env, cls, "okaoProcess", "Ljp/co/omron/hvcw/EpOkaoProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpOkaoProcess = (*env)->GetObjectField(env, objEventProgramTimer, fid);

	nRet = JNUSetEpOkaoProcess(env, objEpOkaoProcess, &(pEventProgramTimer->okaoProcess));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEventProgramTimer, fid, objEpOkaoProcess);


	fid = (*env)->GetFieldID(env, cls, "postProcess", "Ljp/co/omron/hvcw/EpPostProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpPostProcess = (*env)->GetObjectField(env, objEventProgramTimer, fid);

	nRet = JNUSetEpPostProcess(env, objEpPostProcess, &(pEventProgramTimer->postProcess));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEventProgramTimer, fid, objEpPostProcess);


	fid = (*env)->GetFieldID(env, cls, "frPostProcess", "Ljp/co/omron/hvcw/EpFrPostProcess;");
	if(fid == NULL){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return HVCW_INVALID_PARAM;
	}
	objEpFrPostProcess = (*env)->GetObjectField(env, objEventProgramTimer, fid);

	nRet = JNUSetEpFrPostProcess(env, objEpFrPostProcess, &(pEventProgramTimer->frPostProcess));
	if(nRet != HVCW_SUCCESS){
		(*env)->DeleteLocalRef(env, cls);
		cls = NULL;
		return nRet;
	}
	(*env)->SetObjectField(env, objEventProgramTimer, fid, objEpFrPostProcess);


	(*env)->DeleteLocalRef(env, cls);
	cls = NULL;

	return HVCW_SUCCESS;
}

/**
 * pcName -> objName
 */
void ToStringBuffer(JNIEnv *env, HVCW_CHAR *pcName, jobject objName)
{
	jclass    jcstrbuf;
	jmethodID mid;
	jstring   stName;

	__android_log_print(ANDROID_LOG_INFO, "Debug", "ToStringBuffer 001 Name:%s\n", pcName);
	jcstrbuf = (*env)->GetObjectClass(env, objName);

	__android_log_print(ANDROID_LOG_INFO, "Debug", "ToStringBuffer 002\n");
	mid = (*env)->GetMethodID(env, jcstrbuf, "append", "(Ljava/lang/String;)Ljava/lang/StringBuffer;");

	__android_log_print(ANDROID_LOG_INFO, "Debug", "ToStringBuffer 003\n");
	stName = (*env)->NewStringUTF(env, pcName);

	__android_log_print(ANDROID_LOG_INFO, "Debug", "ToStringBuffer 004\n");
	(*env)->CallObjectMethod(env, objName, mid, stName);

	__android_log_print(ANDROID_LOG_INFO, "Debug", "ToStringBuffer 005\n");
}
