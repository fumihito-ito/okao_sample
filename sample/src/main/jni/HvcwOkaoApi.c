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

#include "HvcwUtils.h"

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setAppID
 * Signature: (JILjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setAppID
(JNIEnv *env, jobject obj, jlong handle, jint appID, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;

	if(returnStatus == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_SetAppID(hHVC, appID, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getAppID
 * Signature: (JLjp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getAppID
(JNIEnv *env, jobject obj, jlong handle, jobject appID, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_INT32 nAppID;

	if((appID == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetAppID(hHVC, &nAppID, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, appID, nAppID);

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setOkaoMode
 * Signature: (JILjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setOkaoMode
(JNIEnv *env, jobject obj, jlong handle, jint okaoMode, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;

	if(returnStatus == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_SetOkaoMode(hHVC, (HVCW_BOOL)okaoMode, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getOkaoMode
 * Signature: (JLjp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getOkaoMode
(JNIEnv *env, jobject obj, jlong handle, jobject okaoMode, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_BOOL  bOkaoMode;

	if((okaoMode == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetOkaoMode(hHVC, &bOkaoMode, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, okaoMode, (HVCW_INT32)bOkaoMode);

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getFileCount
 * Signature: (JILjp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getFileCount
(JNIEnv *env, jobject obj, jlong handle, jint fileExt, jobject fileCount, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_UINT32 nFileCount;

	if((fileCount == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetFileCount(hHVC, (HVCW_FILE_EXT)fileExt, &nFileCount, (HVCW_UINT8*)&nReturnStatus);

	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, fileCount, (HVCW_INT32)nFileCount);

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getFileInfo
 * Signature: (JIILjp/co/omron/hvcw/FileInfo;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getFileInfo
(JNIEnv *env, jobject obj, jlong handle, jint fileExt, jint fileIndex, jobject objFileInfo, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_FILEINFO FileInfo;

	if((objFileInfo == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	/* クリア */
	memset(FileInfo.acName, 0x00, 40);
	FileInfo.Reserved == 0xFFFFFFFF;
	FileInfo.nSize = 0;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetFileInfo(hHVC, (HVCW_FILE_EXT)fileExt, fileIndex, &FileInfo, (HVCW_UINT8*)&nReturnStatus);

	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetFileInfo(env, objFileInfo, &FileInfo);

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    downloadFile
 * Signature: (JLjp/co/omron/hvcw/FileInfo;[BLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_downloadFile
(JNIEnv *env, jobject obj, jlong handle, jobject objFileInfo, jbyteArray byArrBuffer, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_FILEINFO FileInfo;
//	HVCW_UINT8 *pucBuffer;
	jboolean   b;
	jbyte      *pbyBuffer;

	if((objFileInfo == NULL) || (byArrBuffer == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	nRet = JNUGetFileInfo(env, &FileInfo, objFileInfo);
	if(HVCW_SUCCESS != nRet){
		return nRet;
	}

//	pucBuffer = (HVCW_UINT8 *)malloc((HVCW_UINT32)(FileInfo.nSize * sizeof(HVCW_UINT8)));
//	if(pucBuffer == NULL){
//		return HVCW_INVALID_PARAM;
//	}
	pbyBuffer =(*env)->GetByteArrayElements(env, byArrBuffer, &b);


	HHVC hHVC = (HHVC)((long)handle);

//	nRet = HVCW_DownloadFile(hHVC, &FileInfo, pucBuffer, (HVCW_UINT8*)&nReturnStatus);
	nRet = HVCW_DownloadFile(hHVC, &FileInfo, (HVCW_UINT8*)pbyBuffer, (HVCW_UINT8*)&nReturnStatus);

	if(HVCW_SUCCESS == nRet){
		/* pucBuffer -> byArrBuffer */
//		(*env)->SetByteArrayRegion(env, byArrBuffer, 0, FileInfo.nSize, (jbyte*)pucBuffer);
//		if((*env)->ExceptionOccurred(env) != NULL){
//			(*env)->ExceptionClear(env);
//			free(pucBuffer);
//			return HVCW_INVALID_PARAM;
//		}

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

//	free(pucBuffer);
	(*env)->ReleaseByteArrayElements(env, byArrBuffer, pbyBuffer, 0);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    uploadFile
 * Signature: (JLjava/lang/String;I[BLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_uploadFile
(JNIEnv *env, jobject obj, jlong handle, jstring stFileName, jint nBufferSize, jbyteArray byArrBuffer, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	const char *pcFileName;
//	HVCW_UINT8 *pucBuffer;
	jboolean   b;
	jbyte      *pbyBuffer;

	if((byArrBuffer == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

//	pucBuffer = (HVCW_UINT8 *)malloc((HVCW_UINT32)(nBufferSize * sizeof(HVCW_UINT8)));
//	if(pucBuffer == NULL){
//		return HVCW_INVALID_PARAM;
//	}

//	(*env)->GetByteArrayRegion(env, byArrBuffer, 0, nBufferSize, (jbyte*)pucBuffer);
//	if((*env)->ExceptionOccurred(env) != NULL){
//		(*env)->ExceptionClear(env);
//		free(pucBuffer);
//		return HVCW_INVALID_PARAM;
//	}
	pbyBuffer =(*env)->GetByteArrayElements(env, byArrBuffer, &b);

	pcFileName = (*env)->GetStringUTFChars(env, stFileName, 0);

	HHVC hHVC = (HHVC)((long)handle);

//	nRet = HVCW_UploadFile(hHVC, (HVCW_CHAR*)pcFileName, nBufferSize, pucBuffer, (HVCW_UINT8*)&nReturnStatus);
	nRet = HVCW_UploadFile(hHVC, (HVCW_CHAR*)pcFileName, nBufferSize, (HVCW_UINT8*)pbyBuffer, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

//	free(pucBuffer);
	(*env)->ReleaseStringUTFChars(env, stFileName, pcFileName);
	(*env)->ReleaseByteArrayElements(env, byArrBuffer, pbyBuffer, 0);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    deleteFile
 * Signature: (JLjp/co/omron/hvcw/FileInfo;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_deleteFile
(JNIEnv *env, jobject obj, jlong handle, jobject objFileInfo, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_FILEINFO FileInfo;
	
	if((objFileInfo == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	nRet = JNUGetFileInfo(env, &FileInfo, objFileInfo);
	if(HVCW_SUCCESS != nRet){
		return nRet;
	}


	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_DeleteFile(hHVC, &FileInfo, (HVCW_UINT8*)&nReturnStatus);


	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getLastOkaoImageSize
 * Signature: (JLjp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getLastOkaoImageSize
(JNIEnv *env, jobject obj, jlong handle, jobject imageSize, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_INT32 nImageSize;

	if((imageSize == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetLastOkaoImageSize(hHVC, &nImageSize, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, imageSize, nImageSize);

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getLastOkaoImage
 * Signature: (JI[BLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getLastOkaoImage
(JNIEnv *env, jobject obj, jlong handle, jint imgBufSize, jbyteArray byArrImage, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
//	HVCW_UINT8 *pucImage;
	jboolean   b;
	jbyte      *pbyImage;

	if((byArrImage == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

//	pucImage = (HVCW_UINT8 *)malloc((HVCW_UINT32)(imgBufSize * sizeof(HVCW_UINT8)));
//	if(pucImage == NULL){
//		return HVCW_INVALID_PARAM;
//	}
	pbyImage =(*env)->GetByteArrayElements(env, byArrImage, &b);


	HHVC hHVC = (HHVC)((long)handle);

//	nRet = HVCW_GetLastOkaoImage(hHVC, imgBufSize, pucImage, (HVCW_UINT8*)&nReturnStatus);
	nRet = HVCW_GetLastOkaoImage(hHVC, imgBufSize, (HVCW_UINT8*)pbyImage, (HVCW_UINT8*)&nReturnStatus);

	if(HVCW_SUCCESS == nRet){
		/* pucImage -> byArrImage */
//		(*env)->SetByteArrayRegion(env, byArrImage, 0, imgBufSize, (jbyte*)pucImage);
//		if((*env)->ExceptionOccurred(env) != NULL){
//			(*env)->ExceptionClear(env);
//			free(pucImage);
//			return HVCW_INVALID_PARAM;
//		}

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

//	free(pucImage);
	(*env)->ReleaseByteArrayElements(env, byArrImage, pbyImage, 0);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    takePicture
 * Signature: (JLjp/co/omron/hvcw/FileInfo;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_takePicture
(JNIEnv *env, jobject obj, jlong handle, jobject objFileInfo, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_FILEINFO FileInfo;

	if((objFileInfo == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	/* クリア */
	memset(FileInfo.acName, 0x00, 40);
	FileInfo.Reserved == 0xFFFFFFFF;
	FileInfo.nSize = 0;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_TakePicture(hHVC, &FileInfo, (HVCW_UINT8*)&nReturnStatus);

	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetFileInfo(env, objFileInfo, &FileInfo);

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setThreshold
 * Signature: (JIIIIILjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setThreshold
(JNIEnv *env, jobject obj, jlong handle, jint nBody, jint nHand, jint nPet, jint nFace, jint nRecognition, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_OKAO_THRESHOLD Threshold;

	if(returnStatus == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

    Threshold.nBody        = nBody;
    Threshold.nHand        = nHand;
    Threshold.nPet         = nPet;
    Threshold.nFace        = nFace;
    Threshold.nRecognition = nRecognition;

	nRet = HVCW_OKAO_SetThreshold(hHVC, &Threshold, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getThreshold
 * Signature: (JLjp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getThreshold
(JNIEnv *env, jobject obj, jlong handle, jobject body, jobject hand, jobject pet, jobject face, jobject recognition, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_OKAO_THRESHOLD Threshold;

	if((body == NULL) || (hand == NULL) || (pet == NULL) || (face == NULL)  || (recognition == NULL)|| (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_OKAO_GetThreshold(hHVC, &Threshold, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, body, Threshold.nBody);
		nRet = JNUSetInt(env, hand, Threshold.nHand);
		nRet = JNUSetInt(env, pet, Threshold.nPet);
		nRet = JNUSetInt(env, face, Threshold.nFace);
		nRet = JNUSetInt(env, recognition, Threshold.nRecognition);

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setSizeRange
 * Signature: (JIIIIIIIILjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setSizeRange
(JNIEnv *env, jobject obj, jlong handle, jint nMinBody, jint nMaxBody, jint nMinHand, jint nMaxHand,
							jint nMinPet, jint nMaxPet, jint nMinFace, jint nMaxFace, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_OKAO_SIZE_RANGE SizeRange;

	if(returnStatus == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

    SizeRange.body.nMin = nMinBody;
    SizeRange.body.nMax = nMaxBody;
    SizeRange.hand.nMin = nMinHand;
    SizeRange.hand.nMax = nMaxHand;
    SizeRange.pet.nMin  = nMinPet;
    SizeRange.pet.nMax  = nMaxPet;
    SizeRange.face.nMin = nMinFace;
    SizeRange.face.nMax = nMaxFace;

	nRet = HVCW_OKAO_SetSizeRange(hHVC, &SizeRange, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getSizeRange
 * Signature: (JLjp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getSizeRange
(JNIEnv *env, jobject obj, jlong handle, jobject minBody, jobject maxBody, jobject minHand, jobject maxHand,
							jobject minPet, jobject maxPet, jobject minFace, jobject maxFace, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_OKAO_SIZE_RANGE SizeRange;

	if((minBody == NULL) || (maxBody == NULL) || (minHand == NULL) || (maxHand == NULL) ||
		(minPet == NULL) || (maxPet == NULL) || (minFace == NULL) || (maxFace == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_OKAO_GetSizeRange(hHVC, &SizeRange, (HVCW_UINT8*)&nReturnStatus);

	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, minBody, SizeRange.body.nMin);
		nRet = JNUSetInt(env, maxBody, SizeRange.body.nMax);
		nRet = JNUSetInt(env, minHand, SizeRange.hand.nMin);
		nRet = JNUSetInt(env, maxHand, SizeRange.hand.nMax);
		nRet = JNUSetInt(env, minPet, SizeRange.pet.nMin);
		nRet = JNUSetInt(env, maxPet, SizeRange.pet.nMax);
		nRet = JNUSetInt(env, minFace, SizeRange.face.nMin);
		nRet = JNUSetInt(env, maxFace, SizeRange.face.nMax);

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setDetectionAngle
 * Signature: (JIIIIILjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setDetectionAngle
(JNIEnv *env, jobject obj, jlong handle, jint nBody, jint nHand, jint nPet, jint nFacePose, jint nFaceAngle, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_OKAO_DETECTION_ANGLE DetectionAngle;

	if(returnStatus == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

    DetectionAngle.nBody       = nBody;
    DetectionAngle.nHand       = nHand;
    DetectionAngle.nPet        = nPet;
    DetectionAngle.face.nPose  = nFacePose;
    DetectionAngle.face.nAngle = nFaceAngle;

	nRet = HVCW_OKAO_SetDetectionAngle(hHVC, &DetectionAngle, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getDetectionAngle
 * Signature: (JLjp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getDetectionAngle
(JNIEnv *env, jobject obj, jlong handle, jobject body, jobject hand, jobject pet, jobject facePose, jobject faceAngle, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_OKAO_DETECTION_ANGLE DetectionAngle;

	if((body == NULL) || (hand == NULL) || (pet == NULL) || (facePose == NULL)  || (faceAngle == NULL)|| (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_OKAO_GetDetectionAngle(hHVC, &DetectionAngle, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, body, DetectionAngle.nBody);
		nRet = JNUSetInt(env, hand, DetectionAngle.nHand);
		nRet = JNUSetInt(env, pet, DetectionAngle.nPet);
		nRet = JNUSetInt(env, facePose, DetectionAngle.face.nPose);
		nRet = JNUSetInt(env, faceAngle, DetectionAngle.face.nAngle);

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    okaoExecute
 * Signature: (J[ILjp/co/omron/hvcw/OkaoResult;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_okaoExecute
(JNIEnv *env, jobject obj, jlong handle, jintArray byUseFunction, jobject objResult, jobject returnStatus)
{
	HVCW_INT32       nRet;
	HVCW_INT32       nReturnStatus;
	HVCW_OKAO_RESULT Result;
	HVCW_BOOL        abUseFunction[HVCW_OkaoFunction_Max];
	jint             *pUseFunction;
	int              i;

	if((objResult == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	pUseFunction = (*env)->GetIntArrayElements(env, byUseFunction, NULL);
	for(i = 0; i<HVCW_OkaoFunction_Max; i++){
		abUseFunction[i] = pUseFunction[i];
	}
	(*env)->ReleaseIntArrayElements(env, byUseFunction, pUseFunction, 0);


	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_OKAO_Execute(hHVC, abUseFunction, &Result, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);

		nRet = JNUSetOkaoResult(env, objResult, &Result);
	}

	return nRet;
}


/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    albumRegister
 * Signature: (JIILjp/co/omron/hvcw/ResultDetection;Ljp/co/omron/hvcw/FileInfo;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_albumRegister
(JNIEnv *env, jobject obj, jlong handle, jint nUserID, jint nDataID, jobject objFaceResult, jobject objFileInfo, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_OKAO_RESULT_DETECTION FaceResult;
	HVCW_FILEINFO FileInfo;

	if((objFaceResult == NULL) || (objFileInfo == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	/* クリア */
	memset(FileInfo.acName, 0x00, 40);
	FileInfo.Reserved == 0xFFFFFFFF;
	FileInfo.nSize = 0;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_ALBUM_Register(hHVC, nUserID, nDataID, &FaceResult, &FileInfo, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetResultDetection(env, objFaceResult, &FaceResult);

		nRet = JNUSetFileInfo(env, objFileInfo, &FileInfo);

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    albumSetUserName
 * Signature: (JILjava/lang/String;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_albumSetUserName
(JNIEnv *env, jobject obj, jlong handle, jint nUserID, jstring stName, jobject returnStatus)
{
	HVCW_INT32  nRet;
	HVCW_INT32  nReturnStatus;
	const char* pcName;
	HVCW_CHAR acName[44];

	if(returnStatus == NULL){
		return HVCW_INVALID_PARAM;
	}

	pcName = (*env)->GetStringUTFChars(env, stName, 0);
	__android_log_print(ANDROID_LOG_INFO, "Debug", "albumSetUserName 001 UserID:%d\n", nUserID);
	__android_log_print(ANDROID_LOG_INFO, "Debug", "albumSetUserName 001 Name:%s\n", pcName);

	memcpy(&acName[0], pcName, 44);
	__android_log_print(ANDROID_LOG_INFO, "Debug", "albumSetUserName 001 Name:%s\n", acName);

	HHVC hHVC = (HHVC)((long)handle);

//	nRet = HVCW_ALBUM_SetUserName(hHVC, nUserID, pcName, (HVCW_UINT8*)&nReturnStatus);
	nRet = HVCW_ALBUM_SetUserName(hHVC, nUserID, acName, (HVCW_UINT8*)&nReturnStatus);
	__android_log_print(ANDROID_LOG_INFO, "Debug", "albumSetUserName 002 nRet:%d\n", nRet);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}
	__android_log_print(ANDROID_LOG_INFO, "Debug", "albumSetUserName 003 nRet:%d\n", nRet);

	(*env)->ReleaseStringUTFChars(env, stName, pcName);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    albumGetUserName
 * Signature: (JILjava/lang/StringBuffer;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_albumGetUserName
(JNIEnv *env, jobject obj, jlong handle, jint nUserID, jobject objName, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_CHAR acName[44];
	jclass jcstrbuf;
	jmethodID mid;
	jstring stName;

	if(returnStatus == NULL){
		return HVCW_INVALID_PARAM;
	}

	memset(acName, 0x00, 44); /* クリア */

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_ALBUM_GetUserName(hHVC, nUserID, acName, (HVCW_UINT8*)&nReturnStatus);
	__android_log_print(ANDROID_LOG_INFO, "Debug", "albumGetUserName 001 nRet:%d\n", nRet);
	__android_log_print(ANDROID_LOG_INFO, "Debug", "albumGetUserName 002 Name:%s\n", acName);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	ToStringBuffer(env, acName, objName);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    albumDeleteData
 * Signature: (JIILjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_albumDeleteData
(JNIEnv *env, jobject obj, jlong handle, jint nUserID, jint nDataID, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;

	if(returnStatus == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_ALBUM_DeleteData(hHVC, nUserID, nDataID, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    albumDeleteAllData
 * Signature: (JLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_albumDeleteAllData
(JNIEnv *env, jobject obj, jlong handle, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;

	if(returnStatus == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_ALBUM_DeleteAllData(hHVC, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    albumGetRegistrationStatus
 * Signature: (JI[ILjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_albumGetRegistrationStatus
(JNIEnv *env, jobject obj, jlong handle, jint nUserID, jintArray byExist, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_BOOL abExist[10];
	jint *pExist;
	int i;

	if(returnStatus == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_ALBUM_GetRegistrationStatus(hHVC, nUserID, abExist, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	pExist = (*env)->GetIntArrayElements(env, byExist, NULL);
	for(i = 0; i<10; i++){
		pExist[i] = abExist[i];
	}
	(*env)->ReleaseIntArrayElements(env, byExist, pExist, 0);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    albumGetSize
 * Signature: (JLjp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_albumGetSize
(JNIEnv *env, jobject obj, jlong handle, jobject albumSize, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_INT32 nAlbumSize;

	if((albumSize == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_ALBUM_GetSize(hHVC, &nAlbumSize, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, albumSize, nAlbumSize);

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    albumDownload
 * Signature: (J[BLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_albumDownload
(JNIEnv *env, jobject obj, jlong handle, jbyteArray byArrAlbum, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
//	HVCW_UINT8 *pucAlbum;
//	HVCW_INT32 nAlbumSize;
	jboolean   b;
	jbyte      *pbyAlbum;

	if((byArrAlbum == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

//	nAlbumSize = (*env)->GetArrayLength(env, byArrAlbum);

//	pucAlbum = (HVCW_UINT8 *)malloc((HVCW_UINT32)(nAlbumSize * sizeof(HVCW_UINT8)));
//	if(pucAlbum == NULL){
//		return HVCW_INVALID_PARAM;
//	}
	pbyAlbum =(*env)->GetByteArrayElements(env, byArrAlbum, &b);


	HHVC hHVC = (HHVC)((long)handle);

//	nRet = HVCW_ALBUM_Download(hHVC, pucAlbum, (HVCW_UINT8*)&nReturnStatus));
	nRet = HVCW_ALBUM_Download(hHVC, (HVCW_UINT8*)pbyAlbum, (HVCW_UINT8*)&nReturnStatus);

	if(HVCW_SUCCESS == nRet){
		/* pucAlbum -> byArrAlbum */
//		(*env)->SetByteArrayRegion(env, byArrAlbum, 0, nAlbumSize, (jbyte*)pucAlbum);
//		if((*env)->ExceptionOccurred(env) != NULL){
//			(*env)->ExceptionClear(env);
//			free(pucAlbum);
//			return HVCW_INVALID_PARAM;
//		}

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

//	free(pucAlbum);
	(*env)->ReleaseByteArrayElements(env, byArrAlbum, pbyAlbum, 0);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    albumUpload
 * Signature: (JI[BLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_albumUpload
(JNIEnv *env, jobject obj, jlong handle, jint nAlbumSize, jbyteArray byAlbum, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	jboolean   b;
	jbyte      *arrAlbum;

	if((byAlbum == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	arrAlbum =(*env)->GetByteArrayElements(env, byAlbum, &b);


	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_ALBUM_Upload(hHVC, nAlbumSize, (HVCW_UINT8*)arrAlbum, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	(*env)->ReleaseByteArrayElements(env, byAlbum, arrAlbum, 0);

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    albumSave
 * Signature: (JLjp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_albumSave
(JNIEnv *env, jobject obj, jlong handle, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;

	if(returnStatus == NULL){
		return HVCW_INVALID_PARAM;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_ALBUM_Save(hHVC, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setScheduler
 * Signature: (JIILjp/co/omron/hvcw/ScheduleInfo;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setScheduler
(JNIEnv *env, jobject obj, jlong handle, jint nSchedulerType, jint nEnable, jobject objSchedule, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_SCHEDULE_INFO Schedule;

	if((objSchedule == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	nRet = JNUGetScheduleInfo(env, &Schedule, objSchedule);
	if(HVCW_SUCCESS != nRet){
		return nRet;
	}


	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_SetScheduler(hHVC, (HVCW_SCHEDULER_TYPE)nSchedulerType, (HVCW_BOOL)nEnable, &Schedule, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getScheduler
 * Signature: (JILjp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/ScheduleInfo;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getScheduler
(JNIEnv *env, jobject obj, jlong handle, jint nSchedulerType, jobject objEnable, jobject objSchedule, jobject returnStatus)
{
	HVCW_INT32 nRet;
	HVCW_INT32 nReturnStatus;
	HVCW_BOOL bEnable;
	HVCW_SCHEDULE_INFO Schedule;

	if((objEnable == NULL) || (objSchedule == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	nRet = JNUGetScheduleInfo(env, &Schedule, objSchedule);
	if(HVCW_SUCCESS != nRet){
		return nRet;
	}

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetScheduler(hHVC, (HVCW_SCHEDULER_TYPE)nSchedulerType, &bEnable, &Schedule, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, objEnable, (HVCW_INT32)bEnable);

		nRet = JNUSetScheduleInfo(env, objSchedule, &Schedule);

		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setSoundEventProgram
 * Signature: (JILjp/co/omron/hvcw/EventProgramSound;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setSoundEventProgram
(JNIEnv *env, jobject obj, jlong handle, jint nEnable, jobject objEventProgram, jobject returnStatus)
{
	HVCW_INT32               nRet;
	HVCW_INT32               nReturnStatus;
	HVCW_EVENT_PROGRAM       EventProgram;
	HVCW_EVENT_PROGRAM_SOUND EventProgramSound;

	if((objEventProgram == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	memset(&EventProgramSound, 0x00, sizeof(EventProgramSound)); /* クリア */
	
	nRet = JNUGetEventProgramSound(env, &EventProgramSound, objEventProgram);
	if(HVCW_SUCCESS != nRet){
		return nRet;
	}
	
	/* イベントプログラムへ音声検知イベント設定 */
	EventProgram.nIndex       = 0;	/* 音声検知では未使用 */
	EventProgram.eventProgram = &EventProgramSound;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_SetEventProgram(hHVC, HVCW_EventProgramType_Sound, (HVCW_BOOL)nEnable, &EventProgram, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setMotionEventProgram
 * Signature: (JIILjp/co/omron/hvcw/EventProgramMotion;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setMotionEventProgram
(JNIEnv *env, jobject obj, jlong handle, jint nEnable, jint nIndex, jobject objEventProgram, jobject returnStatus)
{
	HVCW_INT32                nRet;
	HVCW_INT32                nReturnStatus;
	HVCW_EVENT_PROGRAM        EventProgram;
	HVCW_EVENT_PROGRAM_MOTION EventProgramMotion;

	if((objEventProgram == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	memset(&EventProgramMotion, 0x00, sizeof(EventProgramMotion)); /* クリア */
	
	nRet = JNUGetEventProgramMotion(env, &EventProgramMotion, objEventProgram);
	if(HVCW_SUCCESS != nRet){
		return nRet;
	}
	
	/* イベントプログラムへ動体検知イベント設定 */
	EventProgram.nIndex       = nIndex;
	EventProgram.eventProgram = &EventProgramMotion;

	HHVC hHVC = (HHVC)((long)handle);

	__android_log_print(ANDROID_LOG_INFO, "Debug", "setMotionEventProgram 000 nEnable:%d\n", nEnable);
	nRet = HVCW_SetEventProgram(hHVC, HVCW_EventProgramType_Motion, (HVCW_BOOL)nEnable, &EventProgram, (HVCW_UINT8*)&nReturnStatus);
	__android_log_print(ANDROID_LOG_INFO, "Debug", "setMotionEventProgram 001 Ret:%d\n", nRet);
	__android_log_print(ANDROID_LOG_INFO, "Debug", "setMotionEventProgram 001 ReturnStatus:%d\n", nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}


/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    setTimerEventProgram
 * Signature: (JILjp/co/omron/hvcw/EventProgramTimer;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_setTimerEventProgram
(JNIEnv *env, jobject obj, jlong handle, jint nEnable, jobject objEventProgram, jobject returnStatus)
{
	HVCW_INT32               nRet;
	HVCW_INT32               nReturnStatus;
	HVCW_EVENT_PROGRAM       EventProgram;
	HVCW_EVENT_PROGRAM_TIMER EventProgramTimer;

	if((objEventProgram == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	memset(&EventProgramTimer, 0x00, sizeof(EventProgramTimer)); /* クリア */
	
	nRet = JNUGetEventProgramTimer(env, &EventProgramTimer, objEventProgram);
	if(HVCW_SUCCESS != nRet){
		return nRet;
	}
	
	/* イベントプログラムへタイマーイベント設定 */
	EventProgram.nIndex       = 0;	/* タイマーイベントでは未使用 */
	EventProgram.eventProgram = &EventProgramTimer;

	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_SetEventProgram(hHVC, HVCW_EventProgramType_Timer, (HVCW_BOOL)nEnable, &EventProgram, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);
	}

	return nRet;
}


/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getSoundEventProgram
 * Signature: (JLjp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/EventProgramSound;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getSoundEventProgram
(JNIEnv *env, jobject obj, jlong handle, jobject objEnable, jobject objEventProgram, jobject returnStatus)
{
	HVCW_INT32               nRet;
	HVCW_INT32               nReturnStatus;
	HVCW_BOOL                bEnable;
	HVCW_EVENT_PROGRAM       EventProgram;
	HVCW_EVENT_PROGRAM_SOUND EventProgramSound;

	if((objEnable == NULL) || (objEventProgram == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	memset(&EventProgramSound, 0x00, sizeof(EventProgramSound)); /* クリア */

	/* 構造体を設定 */
	EventProgram.eventProgram = &EventProgramSound;


	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetEventProgram(hHVC, HVCW_EventProgramType_Sound, &bEnable, &EventProgram, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);

		nRet = JNUSetInt(env, objEnable, (HVCW_INT32)bEnable);

		nRet = JNUSetEventProgramSound(env, objEventProgram, EventProgram.eventProgram);
	}

	return nRet;
}


/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getMotionEventProgram
 * Signature: (JLjp/co/omron/hvcw/Int;ILjp/co/omron/hvcw/EventProgramMotion;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getMotionEventProgram
(JNIEnv *env, jobject obj, jlong handle, jobject objEnable, jint nIndex, jobject objEventProgram, jobject returnStatus)
{
	HVCW_INT32                nRet;
	HVCW_INT32                nReturnStatus;
	HVCW_BOOL                 bEnable;
	HVCW_EVENT_PROGRAM        EventProgram;
	HVCW_EVENT_PROGRAM_MOTION EventProgramMotion;

	if((objEnable == NULL) || (objEventProgram == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	memset(&EventProgramMotion, 0x00, sizeof(EventProgramMotion)); /* クリア */

	/* 構造体へnIndexと実体を設定 */
	EventProgram.nIndex = nIndex;
	EventProgram.eventProgram = &EventProgramMotion;


	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetEventProgram(hHVC, HVCW_EventProgramType_Motion, &bEnable, &EventProgram, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		__android_log_print(ANDROID_LOG_INFO, "Debug", "getMotionEventProgram 001 Ret:%d\n", nRet);
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);

		__android_log_print(ANDROID_LOG_INFO, "Debug", "getMotionEventProgram 002 Ret:%d\n", nRet);
		nRet = JNUSetInt(env, objEnable, (HVCW_INT32)bEnable);

		__android_log_print(ANDROID_LOG_INFO, "Debug", "getMotionEventProgram 003 Ret:%d\n", nRet);
		nRet = JNUSetEventProgramMotion(env, objEventProgram, EventProgram.eventProgram);

		__android_log_print(ANDROID_LOG_INFO, "Debug", "getMotionEventProgram 004 Ret:%d\n", nRet);
	}

	return nRet;
}

/*
 * Class:     jp_co_omron_hvcw_HvcwApi
 * Method:    getTimerEventProgram
 * Signature: (JLjp/co/omron/hvcw/Int;Ljp/co/omron/hvcw/EventProgramTimer;Ljp/co/omron/hvcw/Int;)I
 */
JNIEXPORT jint JNICALL Java_jp_co_omron_hvcw_HvcwApi_getTimerEventProgram
(JNIEnv *env, jobject obj, jlong handle, jobject objEnable, jobject objEventProgram, jobject returnStatus)
{
	HVCW_INT32               nRet;
	HVCW_INT32               nReturnStatus;
	HVCW_BOOL                bEnable;
	HVCW_EVENT_PROGRAM       EventProgram;
	HVCW_EVENT_PROGRAM_TIMER EventProgramTimer;

	if((objEnable == NULL) || (objEventProgram == NULL) || (returnStatus == NULL)){
		return HVCW_INVALID_PARAM;
	}

	memset(&EventProgramTimer, 0x00, sizeof(EventProgramTimer)); /* クリア */

	/* 構造体を設定 */
	EventProgram.eventProgram = &EventProgramTimer;


	HHVC hHVC = (HHVC)((long)handle);

	nRet = HVCW_GetEventProgram(hHVC, HVCW_EventProgramType_Timer, &bEnable, &EventProgram, (HVCW_UINT8*)&nReturnStatus);
	if(HVCW_SUCCESS == nRet){
		nRet = JNUSetInt(env, returnStatus, (HVCW_UINT8)nReturnStatus);

		nRet = JNUSetInt(env, objEnable, (HVCW_INT32)bEnable);

		nRet = JNUSetEventProgramTimer(env, objEventProgram, EventProgram.eventProgram);
	}

	return nRet;
}
