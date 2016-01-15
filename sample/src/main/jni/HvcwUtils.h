/*-------------------------------------------------------------------*/
/*  Copyright(C) 2015 by OMRON Corporation                           */
/*  All Rights Reserved.                                             */
/*                                                                   */
/*   This source code is the Confidential and Proprietary Property   */
/*   of OMRON Corporation.  Any unauthorized use, reproduction or    */
/*   transfer of this software is strictly prohibited.               */
/*                                                                   */
/*-------------------------------------------------------------------*/
#ifndef __HVCWUTILS_H__
#define __HVCWUTILS_H__

#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "HvcwCommonDef.h"
#include "HvcwSdkAPI.h"
#include "HvcwTypedef.h"

#define MAX_DATA (10)

#ifdef __cplusplus
extern "C" {
#endif

/*
 * nValue -> objIntValue
 */
HVCW_INT32 JNUSetInt(JNIEnv *env, jobject objIntValue, HVCW_INT32 nValue);
/*
 * objRange -> pRange
 */
HVCW_INT32 JNUGetRange(JNIEnv *env, HVCW_RANGE *pRange, jobject objRange);
/*
 * pRange -> objRange
 */
HVCW_INT32 JNUSetRange(JNIEnv *env, jobject objRange, HVCW_RANGE *pRange);
/*
 * objPoint -> pPt
 */
HVCW_INT32 JNUGetPoint(JNIEnv *env, HVCW_POINT *pPt, jobject objPoint);
/*
 * pPt -> objPoint
 */
HVCW_INT32 JNUSetPoint(JNIEnv *env, jobject objPoint, HVCW_POINT *pPt);
/*
 * objRect -> pRect
 */
HVCW_INT32 JNUGetRect(JNIEnv *env, HVCW_RECT *pRect, jobject objRect);
/*
 * pRect -> objRect
 */
HVCW_INT32 JNUSetRect(JNIEnv *env, jobject objRect, HVCW_RECT *pRect);
/*
 * objParam -> pParam
 */
HVCW_INT32 JNUGetDetectionParam(JNIEnv *env, HVCW_DETECTIONPARAM *pParam, jobject objParam);
/*
 * pParam -> objParam
 */
HVCW_INT32 JNUSetDetectionParam(JNIEnv *env, jobject objParam, HVCW_DETECTIONPARAM *pParam);
/*
 * objDetectionParams -> pDetectionParams
 */
HVCW_INT32 JNUGetDetectionParamArray(JNIEnv *env, jobjectArray objDetectionParams, HVCW_DETECTIONPARAM *pDetectionParams, HVCW_INT32 nLen);
/*
 * pDetectionParams -> objDetectionParams
 */
HVCW_INT32 JNUSetDetectionParamArray(JNIEnv *env, jobjectArray objDetectionParams, HVCW_DETECTIONPARAM *pDetectionParams, HVCW_INT32 nLen);


/*
 * pStorageInfo -> objStorageInfo
 */
HVCW_INT32 JNUSetStorageInfo(JNIEnv *env, jobject objStorageInfo, HVCW_STORAGEINFO *pStorageInfo);
/*
 * objFileInfo -> pFileInfo
 */
HVCW_INT32 JNUGetFileInfo(JNIEnv *env, HVCW_FILEINFO *pFileInfo, jobject objFileInfo);
/*
 * pFileInfo -> objFileInfo
 */
HVCW_INT32 JNUSetFileInfo(JNIEnv *env, jobject objFileInfo, HVCW_FILEINFO *pFileInfo);
/*
 * FaceResult -> objFaceResult
 */
HVCW_INT32 JNUSetResultDetection(JNIEnv *env, jobject objFaceResult, HVCW_OKAO_RESULT_DETECTION *pFaceResult);
/*
 * pResultPet -> objResultPet
 */
HVCW_INT32 JNUSetResultPet(JNIEnv *env, jobject objResultPet, HVCW_OKAO_RESULT_PET *pResultPet);
/*
 * pResultDirection -> objResultDirection
 */
HVCW_INT32 JNUSetResultDirection(JNIEnv *env, jobject objResultDirection, HVCW_OKAO_RESULT_DIRECTION *pResultDirection);
/*
 * pResultAge -> objResultAge
 */
HVCW_INT32 JNUSetResultAge(JNIEnv *env, jobject objResultAge, HVCW_OKAO_RESULT_AEG *pResultAge);
/*
 * pResultGender -> objResultGender
 */
HVCW_INT32 JNUSetResultGender(JNIEnv *env, jobject objResultGender, HVCW_OKAO_RESULT_GENDER *pResultGender);
/*
 * pResultGaze -> objResultGaze
 */
HVCW_INT32 JNUSetResultGaze(JNIEnv *env, jobject objResultGaze, HVCW_OKAO_RESULT_GAZE *pResultGaze);
/*
 * pResultBlink -> objResultBlink
 */
HVCW_INT32 JNUSetResultBlink(JNIEnv *env, jobject objResultBlink, HVCW_OKAO_RESULT_BLINK *pResultBlink);
/*
 * pResultExpression -> objResultExpression
 */
HVCW_INT32 JNUSetResultExpression(JNIEnv *env, jobject objResultExpression, HVCW_OKAO_RESULT_EXPRESSION *pResultExpression);
/*
 * pResultRecognition -> objResultRecognition
 */
HVCW_INT32 JNUSetResultRecognition(JNIEnv *env, jobject objResultRecognition, HVCW_OKAO_RESULT_RECOGNITION *pResultRecognition);
/*
 * pResultFace -> objResultFace
 */
HVCW_INT32 JNUSetResultFace(JNIEnv *env, jobject objResultFace, HVCW_OKAO_RESULT_FACE *pResultFace);
/*
 * pResultBodys -> objResultBodys
 */
HVCW_INT32 JNUSetResultBodys(JNIEnv *env, jobject objResultBodys, HVCW_OKAO_RESULT_BODYS *pResultBodys);
/*
 * pResultHands -> objResultHands
 */
HVCW_INT32 JNUSetResultHands(JNIEnv *env, jobject objResultHands, HVCW_OKAO_RESULT_HANDS *pResultHands);
/*
 * pResultPets -> objResultPets
 */
HVCW_INT32 JNUSetResultPets(JNIEnv *env, jobject objResultPets, HVCW_OKAO_RESULT_PETS *pResultPets);
/*
 * pResultFaces -> objResultFaces
 */
HVCW_INT32 JNUSetResultFaces(JNIEnv *env, jobject objResultFaces, HVCW_OKAO_RESULT_FACES *pResultFaces);
/*
 * pOkaoResult -> objOkaoResult
 */
HVCW_INT32 JNUSetOkaoResult(JNIEnv *env, jobject objOkaoResult, HVCW_OKAO_RESULT *pOkaoResult);
/*
 * objScheduleTime -> pScheduleTime
 */
HVCW_INT32 JNUGetScheduleTime(JNIEnv *env, HVCW_SCHEDULE_TIME *pScheduleTime, jobject objScheduleTime);
/*
 * pScheduleTime -> objScheduleTime
 */
HVCW_INT32 JNUSetScheduleTime(JNIEnv *env, jobject objScheduleTime, HVCW_SCHEDULE_TIME *pScheduleTime);
/*
 * objSchedule -> pSchedule
 */
HVCW_INT32 JNUGetScheduleInfo(JNIEnv *env, HVCW_SCHEDULE_INFO *pSchedule, jobject objSchedule);
/*
 * pSchedule -> objSchedule
 */
HVCW_INT32 JNUSetScheduleInfo(JNIEnv *env, jobject objSchedule, HVCW_SCHEDULE_INFO *pSchedule);
/*
 * pVideoFrame -> objVideoFrame
 */
HVCW_INT32 JNUSetVideoFrame(JNIEnv *env, jbyteArray arrY, jbyteArray arrU, jbyteArray arrV, HVCW_VIDEOFRAME *pVideoFrame);
/*
 * pSoundData -> objSoundData
 */
HVCW_INT32 JNUSetSoundData(JNIEnv *env, jbyteArray arrSoundData, HVCW_BYTE *pSoundData, jlong len);
/*
 * objBody -> pBody
 */
HVCW_INT32 JNUGetEpBody(JNIEnv *env, HVCW_EP_BODY *pBody, jobject objBody);
/*
 * pBody -> objBody
 */
HVCW_INT32 JNUSetEpBody(JNIEnv *env, jobject objBody, HVCW_EP_BODY *pBody);
/*
 * objPet -> pPet
 */
HVCW_INT32 JNUGetEpPet(JNIEnv *env, HVCW_EP_PET *pPet, jobject objPet);
/*
 * pPet -> objPet
 */
HVCW_INT32 JNUSetEpPet(JNIEnv *env, jobject objPet, HVCW_EP_PET *pPet);
/*
 * objFace -> pFace
 */
HVCW_INT32 JNUGetEpFace(JNIEnv *env, HVCW_EP_FACE *pFace, jobject objFace);
/*
 * pFace -> objFace
 */
HVCW_INT32 JNUSetEpFace(JNIEnv *env, jobject objFace, HVCW_EP_FACE *pFace);
/*
 * objAge -> pAge
 */
HVCW_INT32 JNUGetEpAge(JNIEnv *env, HVCW_EP_AGE *pAge, jobject objAge);
/*
 * pAge -> objAge
 */
HVCW_INT32 JNUSetEpAge(JNIEnv *env, jobject objAge, HVCW_EP_AGE *pAge);
/*
 * objGender -> pGender
 */
HVCW_INT32 JNUGetEpGender(JNIEnv *env, HVCW_EP_GENDER *pGender, jobject objGender);
/*
 * pGender -> objGender
 */
HVCW_INT32 JNUSetEpGender(JNIEnv *env, jobject objGender, HVCW_EP_GENDER *pGender);
/*
 * objExpression -> pExpression
 */
HVCW_INT32 JNUGetEpExpression(JNIEnv *env, HVCW_EP_EXPRESSION *pExpression, jobject objExpression);
/*
 * pExpression -> objExpression
 */
HVCW_INT32 JNUSetEpExpression(JNIEnv *env, jobject objExpression, HVCW_EP_EXPRESSION *pExpression);
/*
 * objRecognition -> pRecognition
 */
HVCW_INT32 JNUGetEpRecognition(JNIEnv *env, HVCW_EP_RECOGNITION *pRecognition, jobject objRecognition);
/*
 * pRecognition -> objRecognition
 */
HVCW_INT32 JNUSetEpRecognition(JNIEnv *env, jobject objRecognition, HVCW_EP_RECOGNITION *pRecognition);
/*
 * objOkaoProcess -> pOkaoProcess
 */
HVCW_INT32 JNUGetEpOkaoProcess(JNIEnv *env, HVCW_EP_OKAO_PROCESS *pOkaoProcess, jobject objOkaoProcess);
/*
 * pOkaoProcess -> objOkaoProcess
 */
HVCW_INT32 JNUSetEpOkaoProcess(JNIEnv *env, jobject objOkaoProcess, HVCW_EP_OKAO_PROCESS *pOkaoProcess);
/*
 * objPushAlert -> pPushAlert
 */
HVCW_INT32 JNUGetEpPushAlert(JNIEnv *env, HVCW_EP_PUSH_ALERT *pPushAlert, jobject objPushAlert);
/*
 * pPushAlert -> objPushAlert
 */
HVCW_INT32 JNUSetEpPushAlert(JNIEnv *env, jobject objPushAlert, HVCW_EP_PUSH_ALERT *pPushAlert);
/*
 * objSound -> pSound
 */
HVCW_INT32 JNUGetEpSound(JNIEnv *env, HVCW_EP_SOUND *pSound, jobject objSound);
/*
 * pSound -> objSound
 */
HVCW_INT32 JNUSetEpSound(JNIEnv *env, jobject objSound, HVCW_EP_SOUND *pSound);
/*
 * objNotification -> pNotification
 */
HVCW_INT32 JNUGetEpNotification(JNIEnv *env, HVCW_EP_NOTIFICATION *pNotification, jobject objNotification);
/*
 * pNotification -> objNotification
 */
HVCW_INT32 JNUSetEpNotification(JNIEnv *env, jobject objNotification, HVCW_EP_NOTIFICATION *pNotification);
/*
 * objEpPostProcess -> pEpPostProcess
 */
HVCW_INT32 JNUGetEpPostProcess(JNIEnv *env, HVCW_EP_POST_PROCESS *pEpPostProcess, jobject objEpPostProcess);
/*
 * pEpPostProcess -> objEpPostProcess
 */
HVCW_INT32 JNUSetEpPostProcess(JNIEnv *env, jobject objEpPostProcess, HVCW_EP_POST_PROCESS *pEpPostProcess);
/*
 * objEpKnownuser -> pEpKnownuser
 */
HVCW_INT32 JNUGetEpKnownuser(JNIEnv *env, HVCW_EP_KNOWNUSER *pEpKnownuser, jobject objEpKnownuser);
/*
 * pEpKnownuser -> objEpKnownuser
 */
HVCW_INT32 JNUSetEpKnownuser(JNIEnv *env, jobject objEpKnownuser, HVCW_EP_KNOWNUSER *pEpKnownuser);
/*
 * objPushAlert -> pPushAlert
 */
HVCW_INT32 JNUGetEpFrPushAlert(JNIEnv *env, HVCW_EP_FR_PUSH_ALERT *pFrPushAlert, jobject objFfPushAlert);
/*
 * pPushAlert -> objPushAlert
 */
HVCW_INT32 JNUSetEpFrPushAlert(JNIEnv *env, jobject objFfPushAlert, HVCW_EP_FR_PUSH_ALERT *pFrPushAlert);
/*
 * objFrSound -> pFrSound
 */
HVCW_INT32 JNUGetEpFrSound(JNIEnv *env, HVCW_EP_FR_SOUND *pFrSound, jobject objFrSound);
/*
 * pFrSound -> objFrSound
 */
HVCW_INT32 JNUSetEpFrSound(JNIEnv *env, jobject objFrSound, HVCW_EP_FR_SOUND *pFrSound);
/*
 * objFrNotification -> pFrNotification
 */
HVCW_INT32 JNUGetEpFrNotification(JNIEnv *env, HVCW_EP_FR_NOTIFICATION *pFrNotification, jobject objFrNotification);
/*
 * pFrNotification -> objFrNotification
 */
HVCW_INT32 JNUSetEpFrNotification(JNIEnv *env, jobject objFrNotification, HVCW_EP_FR_NOTIFICATION *pFrNotification);
/*
 * objFrPostProcess -> pFrPostProcess
 */
HVCW_INT32 JNUGetEpFrPostProcess(JNIEnv *env, HVCW_EP_FR_POST_PROCESS *pFrPostProcess, jobject objFrPostProcess);
/*
 * pFrPostProcess -> objFrPostProcess
 */
HVCW_INT32 JNUSetEpFrPostProcess(JNIEnv *env, jobject objFrPostProcess, HVCW_EP_FR_POST_PROCESS *pFrPostProcess);
/*
 * objSoundEvent -> pSoundEvent
 */
HVCW_INT32 JNUGetEpSoundEvent(JNIEnv *env, HVCW_EP_SOUND_EVENT *pSoundEvent, jobject objSoundEvent);
/*
 * pSoundEvent -> objSoundEvent
 */
HVCW_INT32 JNUSetEpSoundEvent(JNIEnv *env, jobject objSoundEvent, HVCW_EP_SOUND_EVENT *pSoundEvent);
/*
 * objEventProgramSound -> pEventProgramSound
 */
HVCW_INT32 JNUGetEventProgramSound(JNIEnv *env, HVCW_EVENT_PROGRAM_SOUND *pEventProgramSound, jobject objEventProgramSound);
/*
 * pEventProgramSound -> objEventProgramSound
 */
HVCW_INT32 JNUSetEventProgramSound(JNIEnv *env, jobject objEventProgramSound, HVCW_EVENT_PROGRAM_SOUND *pEventProgramSound);
/*
 * objMotionEvent -> pMotionEvent
 */
HVCW_INT32 JNUGetEpMotionEvent(JNIEnv *env, HVCW_EP_MOTION_EVENT *pMotionEvent, jobject objMotionEvent);
/*
 * pMotionEvent -> objMotionEvent
 */
HVCW_INT32 JNUSetEpMotionEvent(JNIEnv *env, jobject objMotionEvent, HVCW_EP_MOTION_EVENT *pMotionEvent);
/*
 * objEventProgramMotion -> pEventProgramMotion
 */
HVCW_INT32 JNUGetEventProgramMotion(JNIEnv *env, HVCW_EVENT_PROGRAM_MOTION *pEventProgramMotion, jobject objEventProgramMotion);
/*
 * pEventProgramMotion -> objEventProgramMotion
 */
HVCW_INT32 JNUSetEventProgramMotion(JNIEnv *env, jobject objEventProgramMotion, HVCW_EVENT_PROGRAM_MOTION *pEventProgramMotion);
/*
 * objTimerEvent -> pTimerEvent
 */
HVCW_INT32 JNUGetEpTimerEvent(JNIEnv *env, HVCW_EP_TIMER_EVENT *pTimerEvent, jobject objTimerEvent);
/*
 * pTimerEvent -> objTimerEvent
 */
HVCW_INT32 JNUSetEpTimerEvent(JNIEnv *env, jobject objTimerEvent, HVCW_EP_TIMER_EVENT *pTimerEvent);
/*
 * objEventProgramTimer -> pEventProgramTimer
 */
HVCW_INT32 JNUGetEventProgramTimer(JNIEnv *env, HVCW_EVENT_PROGRAM_TIMER *pEventProgramTimer, jobject objEventProgramTimer);
/*
 * pEventProgramTimer -> objEventProgramTimer
 */
HVCW_INT32 JNUSetEventProgramTimer(JNIEnv *env, jobject objEventProgramTimer, HVCW_EVENT_PROGRAM_TIMER *pEventProgramTimer);

/**
 * pcName -> objName
 */
void ToStringBuffer(JNIEnv *env, HVCW_CHAR *pcName, jobject objName);

#ifdef __cplusplus
}
#endif
#endif /* __HVCWUTILS_H__ */
