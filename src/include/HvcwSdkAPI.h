/*-------------------------------------------------------------------*/
/*  Copyright(C) 2015 by OMRON Corporation                           */
/*  All Rights Reserved.                                             */
/*                                                                   */
/*   This source code is the Confidential and Proprietary Property   */
/*   of OMRON Corporation.  Any unauthorized use, reproduction or    */
/*   transfer of this software is strictly prohibited.               */
/*                                                                   */
/*-------------------------------------------------------------------*/

#ifndef __HVCWSDKAPI_H
#define __HVCWSDKAPI_H

#define HVC_API

#ifdef __cplusplus
extern "C" {
#endif

#include "HvcwTypedef.h"

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                                 DEFINES                                     */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/* HVC Handle */
#ifndef SDK_DEF_HHVC
#define SDK_DEF_HHVC
    typedef HVCW_VOID*   HHVC;
#endif /* SDK_DEF_HHVC */

/* Roll Angle Definitions. */
#define HVCW_ROLL_ANGLE_0             (0x00001001)     /* Up            0 degree */
#define HVCW_ROLL_ANGLE_1             (0x00002002)     /* Upper Right  30 degree */
#define HVCW_ROLL_ANGLE_2             (0x00004004)     /* Upper Right  60 degree */
#define HVCW_ROLL_ANGLE_3             (0x00008008)     /* Right        90 degree */
#define HVCW_ROLL_ANGLE_4             (0x00010010)     /* Lower Right 120 degree */
#define HVCW_ROLL_ANGLE_5             (0x00020020)     /* Lower Right 150 degree */
#define HVCW_ROLL_ANGLE_6             (0x00040040)     /* Down        180 degree */
#define HVCW_ROLL_ANGLE_7             (0x00080080)     /* Lower Left  210 degree */
#define HVCW_ROLL_ANGLE_8             (0x00100100)     /* Lower Left  240 degree */
#define HVCW_ROLL_ANGLE_9             (0x00200200)     /* Left        270 degree */
#define HVCW_ROLL_ANGLE_10            (0x00400400)     /* Upper Left  300 degree */
#define HVCW_ROLL_ANGLE_11            (0x00800800)     /* Upper Left  330 degree */

#define HVCW_ROLL_ANGLE_UP            (ROLL_ANGLE_0)   /* Up    +/- 15 degree only will be detected */
#define HVCW_ROLL_ANGLE_RIGHT         (ROLL_ANGLE_3)   /* Right +/- 15 degree only will be detected */
#define HVCW_ROLL_ANGLE_DOWN          (ROLL_ANGLE_6)   /* Down  +/- 15 degree only will be detected */
#define HVCW_ROLL_ANGLE_LEFT          (ROLL_ANGLE_9)   /* Left  +/- 15 degree only will be detected */

/* Pose Angle Definitions. */
#define HVCW_POSE_ANGLE_FRONT         (0)              /* Front        */
#define HVCW_POSE_ANGLE_HALF_PROFILE  (1)              /* Half Profile */
#define HVCW_POSE_ANGLE_PROFILE       (2)              /* Profile      */

#define HVCW_PET_TYPE_DOG             (0)              /* �y�b�g���o���ʂ̃y�b�g���ʁF�� */
#define HVCW_PET_TYPE_CAT             (1)              /* �y�b�g���o���ʂ̃y�b�g���ʁF�L */

#define HVCW_GENDER_FEMALE            (0)              /* ���ʐ��茋�ʂ̐��ʁF���� */
#define HVCW_GENDER_MALE              (1)              /* ���ʐ��茋�ʂ̐��ʁF�j�� */

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                                 ENUM DEFINES                                */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/**
 * @enum HVCW_VideoResolution
 * ���C�u�X�g���[�~���O�r�f�I�𑜓x
 */
typedef enum HVCW_VideoResolution {
    HVCW_VideoResolution_High = 0,        /* 0=1280x720 */
    HVCW_VideoResolution_Middle,          /* 1= 640x360 */
    HVCW_VideoResolution_Low              /* 2= 320x180 */
} HVCW_VIDEO_RESOLUTION;

/**
 * @enum HVCW_NightVisionMode
 * NightVision���[�h
 */
typedef enum HVCW_NightVisionMode {
    HVCW_NightVisionMode_Auto = 0,        /* 0=NightVision�̗L���E���������̖͂��邳�ɂ���Ď������䂷�郂�[�h */
    HVCW_NightVisionMode_Manual           /* 1=NightVision�̗L���E�������蓮�ݒ肷�郂�[�h                     */
} HVCW_NIGHT_VISION_MODE;

/**
 * @enum HVCW_NightVisionStatus
 * NightVision�X�e�[�^�X
 */
typedef enum HVCW_NightVisionStatus {
    HVCW_NightVisionStatus_Off = 0,       /* 0=NightVision���� */
    HVCW_NightVisionStatus_On             /* 1=NightVision�L�� */
} HVCW_NIGHT_VISION_STATUS;

/**
 * @enum HVCW_Event
 * �C�x���g
 */
typedef enum HVCW_Event{
    HVCW_Event_ConnectionNum   = 0,       /*  0=�J�����ւ̐ڑ������ύX���ꂽ�ꍇ�ɒʒm����B               */
    HVCW_Event_StreamingNum,              /*  1=�J�����̃��C�u�X�g���[�~���O�����ύX���ꂽ�ꍇ�ɒʒm����B */
    HVCW_Event_NightVisionMode = 6,       /*  6=NightVision���[�h���ύX���ꂽ�ꍇ�ɒʒm����B              */
    HVCW_Event_NightVisionStatus,         /*  7=NightVision�X�e�[�^�X���ύX���ꂽ�ꍇ�ɒʒm����B          */
    HVCW_Event_SpeakerVolume   = 9,       /*  9=�J�����̃X�s�[�J�[�{�����[�����ύX���ꂽ�ꍇ�ɒʒm����B   */
    HVCW_Event_Disconnected    = 13,      /* 13=�J�����Ƃ̐ڑ����ؒf�����ꍇ�ɒʒm����B                   */
    HVCW_Event_Reconnected,               /* 14=�ؒf���ꂽ�J�����Ƃ̐ڑ����񕜂����ꍇ�ɒʒm����B         */
    HVCW_Event_StorageStatus   = 18       /* 18=�J�����̃X�g���[�W�X�e�[�^�X���ύX���ꂽ�ꍇ�ɒʒm����B   */
}HVCW_EVENT;

/**
 * @enum HVCW_StorageStatus
 * �X�g���[�W�X�e�[�^�X
 */
typedef enum HVCW_StorageStatus{
    HVCW_StorageStatus_NotInsert = 0,     /* 0=�X�g���[�W�����o                         */
    HVCW_StorageStatus_NotReady,          /* 1=�X�g���[�W���o�ς݂����g�p�s���       */
    HVCW_StorageStatus_NeedFormat,        /* 2=�X�g���[�W�̓t�H�[�}�b�g���K�v�ȏ��     */
    HVCW_StorageStatus_Normal,            /* 3=�X�g���[�W�g�p�\                       */
    HVCW_StorageStatus_Error,             /* 4=�X�g���[�W�ɃG���[���������g�p�s�\��� */
    HVCW_StorageStatus_Formatting = 6,    /* 6=�X�g���[�W�t�H�[�}�b�g��                 */
    HVCW_StorageStatus_NotSupport         /* 7=�T�|�[�g�ΏۊO�X�g���[�W                 */
} HVCW_STORAGE_STATUS;

/**
 * @enum HVCW_StorageFormatResultCode
 * �X�g���[�W�t�H�[�}�b�g����
 */
typedef enum HVCW_StorageFormatResultCode {
    HVCW_StorageFormatResultCode_Success = 0,        /* 0=�t�H�[�}�b�g����                     */
    HVCW_StorageFormatResultCode_RemovedStorage,     /* 1=�t�H�[�}�b�g���ɃX�g���[�W�������ꂽ */
    HVCW_StorageFormatResultCode_NotSupportStorage,  /* 2=�T�|�[�g���Ă��Ȃ��X�g���[�W         */
    HVCW_StorageFormatResultCode_Timeout,            /* 3=�t�H�[�}�b�g���Ƀ^�C���A�E�g������   */
    HVCW_StorageFormatResultCode_AlreadyRunning,     /* 4=���Ƀt�H�[�}�b�g�����s��             */
    HVCW_StorageFormatResultCode_CheckDisk,          /* 5=�`�F�b�N�f�B�X�N���s��               */
    HVCW_StorageFormatResultCode_FatalError          /* 6=��L�ȊO�̃G���[                     */
} HVCW_STORAGE_FORMAT_RESULT_CODE;

/**
 * @enum HVCW_ConnectionType
 * �ڑ����
 */
typedef enum HVCW_ConnectionType {
    HVCW_ConnectionType_Disconnect = 0,   /* 0=���ڑ�    */
    HVCW_ConnectionType_P2P,              /* 1=P2P�ڑ�   */
    HVCW_ConnectionType_Relay,            /* 2=Relay�ڑ� */
    HVCW_ConnectionType_Local             /* 3=Local�ڑ� */
} HVCW_CONNECTION_TYPE;

/**
 * @enum HVCW_LiveEvent
 * ���C�u�C�x���g
 */
typedef enum HVCW_LiveEvent{
    HVCW_LiveEvent_Started = 0,           /* 0=���C�u�X�g���[�~���O�J�n��A�r�f�I�̃f�R�[�h���J�n�����^�C�~���O�Œʒm����B                                                     */
    HVCW_LiveEvent_Stopped,               /* 1=���C�u�X�g���[�~���O��~���ɒʒm����B                                                                                           */
    HVCW_LiveEvent_Disconnected,          /* 2=�J�����Ƃ̐ڑ����ؒf���ꂽ�ꍇ�ɒʒm����BHVCW_StopLive()���g�p���ă��C�u�X�g���[�~���O���~����K�v������B                    */
    HVCW_LiveEvent_Error,                 /* 3=���C�u�X�g���[�~���O�p���s�\�ȃG���[�����������ꍇ�ɒʒm����BHVCW_StopLive()���g�p���ă��C�u�X�g���[�~���O���~����K�v������B*/
    HVCW_LiveEvent_FPS,                   /* 4=FPS����ʒm����B                                                                                                              */
    HVCW_LiveEvent_ChangeResolution       /* 5=���C�u�X�g���[�~���O�̉𑜓x���ύX���ꂽ�ꍇ�ɒʒm����B                                                                         */
}HVCW_LIVE_EVENT;

/* �X�P�W���[���^�C�v */
typedef enum HVCW_ScheduleType{
    HVCW_ScheduleType_OneTime = 0,        /* 0=Onetime�X�P�W���[��  */
    HVCW_ScheduleType_Repeat,             /* 1=Repeat�X�P�W���[��   */
    HVCW_ScheduleType_Max
} HVCW_SCHEDULER_TYPE;

/* �C�x���g�^�C�v */
typedef enum HVCW_EventProgramType{
    HVCW_EventProgramType_Sound = 0,      /* 0=�������m�C�x���g */
    HVCW_EventProgramType_Motion,         /* 1=���̌��m�C�x���g */
    HVCW_EventProgramType_Timer,          /* 2=�^�C�}�[�C�x���g */
    HVCW_EventProgramType_Max
} HVCW_EVENT_PROGRAM_TYPE;

typedef enum HVCW_ScheduleFrequency{
    HVCW_ScheduleFrequency_Once = 0,      /* 0=�����s     */
    HVCW_ScheduleFrequency_Daily,         /* 1=�������s     */
    HVCW_ScheduleFrequency_Weekday,       /* 2=�w��j�����s */
    HVCW_ScheduleFrequency_Max
} HVCW_SCHEDULE_FREQUENCY;

typedef enum HVCW_SaveResult{
   HVCW_SaveResult_None = 0,              /* 0=�ۑ��Ȃ�                       */
   HVCW_SaveResult_All,                   /* 1=���ׂĕۑ�                     */
   HVCW_SaveResult_Detection,             /* 2=OKAO�̏����𖞂������ꍇ�ɕۑ� */
   HVCW_SaveResult_Max
} HVCW_SAVE_RESULT;

typedef enum HVCW_FRSaveResult{
    HVCW_FRSaveResult_None = 0,           /* 0=�ۑ��Ȃ�       */
    HVCW_FRSaveResult_All,                /* 1=���ׂĕۑ�     */
    HVCW_FRSaveResult_Known,              /* 2=�{�l�̏ꍇ�ۑ� */
    HVCW_FRSaveResult_Unknown,            /* 3=���l�̏ꍇ�ۑ� */
    HVCW_FRSaveResult_Max
} HVCW_FR_SAVE_RESULT;

typedef enum HVCW_FileExt {
    HVCW_FileExt_Log = 2,                 /* 2=���O�t�@�C��                */
    HVCW_FileExt_MessageText,             /* 3=���b�Z�[�W�e�L�X�g�t�@�C��  */
    HVCW_FileExt_Sound,                   /* 4=�����t�@�C��                */
    HVCW_FileExt_JpgImage = 6,            /* 6=JPEG�摜�t�@�C��            */
    HVCW_FileExt_ThumbnailJpgImage = 8    /* 8=�T���l�C���摜�t�@�C��      */
} HVCW_FILE_EXT;

typedef enum HVCW_OkaoFunction{
    HVCW_OkaoFunction_Body = 0,           /*  0=�l�̌��o     */
    HVCW_OkaoFunction_Hand,               /*  1=�茟�o       */
    HVCW_OkaoFunction_Pet,                /*  2=�y�b�g���o   */
    HVCW_OkaoFunction_Face,               /*  3=�猟�o       */
    HVCW_OkaoFunction_Direction,          /*  4=���������   */
    HVCW_OkaoFunction_Age,                /*  5=�N���     */
    HVCW_OkaoFunction_Gender,             /*  6=���ʐ���     */
    HVCW_OkaoFunction_Gaze,               /*  7=��������     */
    HVCW_OkaoFunction_Blink,              /*  8=�ڂނ萄�� */
    HVCW_OkaoFunction_Expression,         /*  9=�\���     */
    HVCW_OkaoFunction_Recognition,        /* 10=��F��       */
    HVCW_OkaoFunction_Max
} HVCW_OKAO_FUNCTION;

/* �\�� */
typedef enum HVCW_Expression {
    HVCW_Expression_Ignore = -1,          /* -1=����         */
    HVCW_Expression_Neutral = 0,          /*  0=�\��F���\�� */
    HVCW_Expression_Happiness,            /*  1=�\��F���   */
    HVCW_Expression_Surprise,             /*  2=�\��F����   */
    HVCW_Expression_Anger,                /*  3=�\��F�{��   */
    HVCW_Expression_Sadness,              /*  4=�\��F�߂��� */
    HVCW_Expression_Max
} HVCW_EXPRESSION;


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              STRUCTURE DEFINES                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * HVCW �n���h��
 */
#ifndef HVCW_HANDLE
#define HVCW_HANDLE
    typedef HVCW_VOID* HHVC;
#endif /* HVCW_HANDLE */

#ifndef HVCW_C2W_HANDLE
#define HVCW_C2W_HANDLE
    typedef HVCW_VOID* C2W_HANDLE;
#endif /* HVCW_C2W_HANDLE */

/**
 * @struct HVCW_VideoFrame
 * YUV420P�r�f�I�t���[���i�[�\����
 */
typedef struct{
    HVCW_BYTE         *buffer[3];              /* �P�x���A�F�������i�[       */
    HVCW_UINT32        stride[3];              /* �ebuffer�̃X�g���C�h�����i�[ */
    HVCW_UINT32        width;                  /* ����                           */
    HVCW_UINT32        height;                 /* �c��                           */
} HVCW_VIDEOFRAME;

/**
 * @struct HVCW_Point
 * ���W�_�\����
 */
typedef struct {
    HVCW_INT32 nX;                             /* X���W       */
    HVCW_INT32 nY;                             /* Y���W       */
} HVCW_POINT;

/**
 * @struct HVCW_Rect
 * ��`�\���\����
 */
typedef struct {
    HVCW_INT32  nX;                            /* �N�_x���W */
    HVCW_INT32  nY;                            /* �N�_y���W */
    HVCW_INT32  nWidth;                        /* ����      */
    HVCW_INT32  nHeight;                       /* �c��      */
} HVCW_RECT;

/**
 * @struct HVCW_DetectionParam
 * ���̌��m�p�����[�^�\����
 */
typedef struct {
    HVCW_RECT   rect;                          /* ��` */
    HVCW_UINT8  sensitivity;                   /* ���x */
} HVCW_DETECTIONPARAM;

typedef struct {
    HVCW_INT32 nYear;                          /* �N(4�P�^) */
    HVCW_INT32 nMonth;                         /* ��        */
    HVCW_INT32 nDay;                           /* ��        */
    HVCW_INT32 nHour;                          /* ��        */
    HVCW_INT32 nMinute;                        /* ��        */
} HVCW_SCHEDULE_TIME;

typedef struct {
    HVCW_INT32 nIndex;                           /* Onetime�X�P�W���[���̃C���f�b�N�X�iOnetime�̏ꍇ�̂݁j*/
    HVCW_SCHEDULE_FREQUENCY frequency;           /* �X�P�W���[���̃T�C�N��                                */
    HVCW_BOOL bWeekday[7];                       /* �j���ݒ�ifrequency��"Weekday"�̏ꍇ�̂݁A�ݒ肪�L���j*/
    HVCW_SCHEDULE_TIME startTime;                /* �J�n����                                              */
    HVCW_SCHEDULE_TIME endTime;                  /* �I�����ԁiRepeat�̏ꍇ�̂݁j                          */
    HVCW_INT32 nInterval;                        /* �����̃C���^�[�o��                                    */
    HVCW_BOOL abFunction[HVCW_OkaoFunction_Max]; /* OKAO�̎g�p�@�\�t���O                                  */
    HVCW_SAVE_RESULT saveLog;                    /* ���O�̕ۑ����@                                        */
    HVCW_SAVE_RESULT saveImage;                  /* �摜�̕ۑ����@                                        */
} HVCW_SCHEDULE_INFO;

typedef struct {
    HVCW_INT32  nBody;                         /* �l�̌��o�̂������l   */
    HVCW_INT32  nHand;                         /* �茟�o�̂������l     */
    HVCW_INT32  nPet;                          /* �y�b�g���o�̂������l */
    HVCW_INT32  nFace;                         /* �猟�o�̂������l     */
    HVCW_INT32  nRecognition;                  /* �F�؂̂������l       */
} HVCW_OKAO_THRESHOLD;

typedef struct {
    HVCW_INT32  nMin;                          /* �ŏ��l */
    HVCW_INT32  nMax;                          /* �ő�l */
} HVCW_RANGE;

typedef struct {
    HVCW_RANGE  body;                          /* �l�̌��o�̌��o�T�C�Y   */
    HVCW_RANGE  hand;                          /* �茟�o�̌��o�T�C�Y     */
    HVCW_RANGE  pet;                           /* �y�b�g���o�̌��o�T�C�Y */
    HVCW_RANGE  face;                          /* �猟�o�̌��o�T�C�Y     */
} HVCW_OKAO_SIZE_RANGE;

typedef struct {
    HVCW_UINT32  nPose;                        /* ��̕��� */
    HVCW_UINT32  nAngle;                       /* ��p�x   */
} HVCW_OKAO_DETECTION_ANGLE_FACE;

typedef struct {
    HVCW_UINT32  nBody;                        /* �l�̌��o�̌��o�p�x   */
    HVCW_UINT32  nHand;                        /* �茟�o�̌��o�p�x     */
    HVCW_UINT32  nPet;                         /* �y�b�g���o�̌��o�p�x */
    HVCW_OKAO_DETECTION_ANGLE_FACE face;       /* �猟�o�̌��o�p�x     */
} HVCW_OKAO_DETECTION_ANGLE;

typedef struct {
    HVCW_INT32  nLR;                           /* ���E�p�x   */
    HVCW_INT32  nUD;                           /* �㉺�p�x   */
    HVCW_INT32  nRoll;                         /* ���[���p�x */
} HVCW_OKAO_RESULT_DIRECTION;

typedef struct {
    HVCW_INT32  nAge;                          /* �N��   */
    HVCW_INT32  nConfidence;                   /* �M���x */
} HVCW_OKAO_RESULT_AEG;

typedef struct {
    HVCW_INT32  nGender;                       /* ����   */
    HVCW_INT32  nConfidence;                   /* �M���x */
} HVCW_OKAO_RESULT_GENDER;

typedef struct {
    HVCW_INT32  nLR;                           /* ���E     */
    HVCW_INT32  nUD;                           /* �㉺�p�x */
} HVCW_OKAO_RESULT_GAZE;

typedef struct {
    HVCW_INT32  nLeftEye;                      /* ���ڂ̖ڂނ�x�� */
    HVCW_INT32  nRightEye;                     /* �E�ڂ̖ڂނ�x�� */
} HVCW_OKAO_RESULT_BLINK;

typedef struct {
    HVCW_INT32  anScore[HVCW_Expression_Max];  /* �\��Ƃ̃X�R�A          */
    HVCW_INT32  nDegree;                       /* �l�K�e�B�u/�|�W�e�B�u�x�� */
} HVCW_OKAO_RESULT_EXPRESSION;

typedef struct {
    HVCW_INT32  nUID;                          /* ���[�UID */
    HVCW_INT32  nScore;                        /* �X�R�A   */
} HVCW_OKAO_RESULT_RECOGNITION;

typedef struct {
    HVCW_POINT  ptCenter;                      /* ���S�_       */
    HVCW_INT32  nSize;                         /* �T�C�Y       */
    HVCW_INT32  nConfidence;                   /* �M���x       */
    HVCW_INT32  nPetType;                      /* �y�b�g�̎�� */
} HVCW_OKAO_RESULT_PET;

typedef struct {
    HVCW_POINT                   center;       /* ���S�_           */
    HVCW_INT32                   nSize;        /* �T�C�Y           */
    HVCW_INT32                   nConfidence;  /* �M���x           */
    HVCW_OKAO_RESULT_DIRECTION   direction;    /* ��������茋��   */
    HVCW_OKAO_RESULT_AEG         age;          /* �N��茋��     */
    HVCW_OKAO_RESULT_GENDER      gender;       /* ���ʐ��茋��     */
    HVCW_OKAO_RESULT_GAZE        gaze;         /* �������茋��     */
    HVCW_OKAO_RESULT_BLINK       blink;        /* �ڂނ萄�茋�� */
    HVCW_OKAO_RESULT_EXPRESSION  expression;   /* �\��茋��     */
    HVCW_OKAO_RESULT_RECOGNITION recognition;  /* ��F�،���       */
} HVCW_OKAO_RESULT_FACE;

typedef struct {
    HVCW_POINT  center;                        /* ���S�_ */
    HVCW_INT32  nSize;                         /* �T�C�Y */
    HVCW_INT32  nConfidence;                   /* �M���x */
} HVCW_OKAO_RESULT_DETECTION;

typedef struct {
    HVCW_INT32    nCount;                      /* �l�̌��o�� */
    HVCW_OKAO_RESULT_DETECTION  body[35];      /* �l�̂̌��� */
} HVCW_OKAO_RESULT_BODYS;

typedef struct {
    HVCW_INT32    nCount;                      /* �茟�o�� */
    HVCW_OKAO_RESULT_DETECTION  hand[35];      /* ��̌��� */
} HVCW_OKAO_RESULT_HANDS;

typedef struct {
    HVCW_INT32    nCount;                      /* �y�b�g���o�� */
    HVCW_OKAO_RESULT_PET    pet[10];           /* �y�b�g�̌��� */
} HVCW_OKAO_RESULT_PETS;

typedef struct {
    HVCW_INT32    nCount;                      /* �猟�o�� */
    HVCW_OKAO_RESULT_FACE   face[35];          /* ��̌��� */
} HVCW_OKAO_RESULT_FACES;

typedef struct {
    HVCW_OKAO_RESULT_BODYS  bodys;             /* �l�̂̌���   */
    HVCW_OKAO_RESULT_HANDS  hands;             /* ��̌���     */
    HVCW_OKAO_RESULT_PETS   pets;              /* �y�b�g�̌��� */
    HVCW_OKAO_RESULT_FACES  faces;             /* ��̌���     */
} HVCW_OKAO_RESULT;

typedef struct {
    HVCW_CHAR   acName[40];                    /* �t�@�C������     */
    HVCW_INT32  nSize;                         /* �t�@�C���̃T�C�Y */
    HVCW_UINT32 Reserved;                      /* Reserved         */
} HVCW_FILEINFO;

typedef struct {
    HVCW_RECT area;             /* ���̌��m�G���A         */
    HVCW_INT32 nSensitivity;    /* ���̌��m���x           */
    HVCW_UINT32 unDuration;     /* ���̌��m���莞��       */
    HVCW_UINT32 unRatio;        /* ���̌��m���芄��       */
    HVCW_UINT32 unOffPeriod;    /* �C�x���g�̃C���^�[�o�� */
} HVCW_EP_MOTION_EVENT;

typedef struct {
    HVCW_INT32  nSensitivity;   /* �������m���x           */
    HVCW_UINT32 unDuration;     /* �������m���莞��       */
    HVCW_UINT32 unRatio;        /* �������m���芄��       */
    HVCW_UINT32 unOffPeriod;    /* �C�x���g�̃C���^�[�o�� */
} HVCW_EP_SOUND_EVENT;

typedef struct {
    HVCW_UINT32 unInterval;     /* �C�x���g �C���^�[�o�� */
} HVCW_EP_TIMER_EVENT;

typedef struct {
    HVCW_BOOL bEnable;          /* �l�̌��o�̎��s�t���O */
    HVCW_INT32 nCount;          /* ���o���̔���l */
} HVCW_EP_BODY;

typedef struct {
    HVCW_BOOL bEnable;          /* �y�b�g���o�̎��s�t���O */
    HVCW_INT32 nCount;          /* ���o���̔���l */
} HVCW_EP_PET;

typedef struct {
    HVCW_BOOL bEnable;          /* �猟�o�̎��s�t���O */
    HVCW_INT32 nCount;          /* ���o���̔���l */
} HVCW_EP_FACE;

typedef struct {
    HVCW_BOOL bEnable;          /* �N���̎��s�t���O */
    HVCW_RANGE stAgeRange;      /* �N��̔���l */
    HVCW_INT32 nConfidence;     /* �M���x�������l */
} HVCW_EP_AGE;

typedef struct {
    HVCW_BOOL bEnable;          /* ���ʐ���̎��s�t���O */
    HVCW_INT32 nGender;         /* ���ʂ̔���l */
    HVCW_INT32 nConfidence;     /* �M���x�������l */
} HVCW_EP_GENDER;

typedef struct {
    HVCW_BOOL bEnable;          /* �\���̎��s�t���O */
    HVCW_EXPRESSION expression; /* �\��̔��� */
    HVCW_INT32 nScore;          /* �X�R�A�̔��肵�����l */
    HVCW_RANGE degreeRange;     /* �l�K�|�W�̔���l */
} HVCW_EP_EXPRESSION;

typedef struct {
    HVCW_BOOL bEnable;          /* ��F�؂̎��s�t���O  */
} HVCW_EP_RECOGNITION;

typedef struct {
    HVCW_BOOL bEnable;          /* �v�b�V���ʒm�t���O */
    HVCW_FILEINFO fileInfo;     /* �v�b�V���ʒm�̃��b�Z�[�W�t�@�C�� */
} HVCW_EP_PUSH_ALERT;

typedef struct {
    HVCW_BOOL bEnable;          /* �����o�̓t���O */
    HVCW_FILEINFO fileInfo;     /* �����o�͂̉����t�@�C�� */
} HVCW_EP_SOUND;

typedef struct {
    HVCW_EP_PUSH_ALERT pushAlert; /* �v�b�V���ʒm�ݒ� */
    HVCW_EP_SOUND sound;          /* �����o�͐ݒ� */
} HVCW_EP_NOTIFICATION;

typedef struct {
    HVCW_EP_BODY        body;           /* �l�̂̔���l */
    HVCW_EP_PET         pet;            /* �y�b�g�̔���l */
    HVCW_EP_FACE        face;           /* ��̔���l */
    HVCW_EP_AGE         age;            /* �N��̔���l */
    HVCW_EP_GENDER      gender;         /* ���ʂ̔���l */
    HVCW_EP_EXPRESSION  expression;     /* �\��̔���l */
    HVCW_EP_RECOGNITION recognition;    /* �F�؂̔���l */
} HVCW_EP_OKAO_PROCESS;

typedef struct {
    HVCW_SAVE_RESULT     saveLog;       /* ���O�̕ۑ� */
    HVCW_SAVE_RESULT     saveImage;     /* �摜�̕ۑ� */
    HVCW_EP_NOTIFICATION notification;  /* �ʒm�ݒ� */
} HVCW_EP_POST_PROCESS;

typedef struct {
    HVCW_INT32 nUserID;                     /* ���[�UID */
    HVCW_FILEINFO fileInfo;                 /* �Ώۂ̃t�@�C�� */
} HVCW_EP_KNOWNUSER;

typedef struct {
    HVCW_EP_KNOWNUSER knownUser[20];        /* �o�^���Ă���l���̏ꍇ�̏��� */
    HVCW_EP_PUSH_ALERT unknownUser;         /* �o�^���Ă��Ȃ��l���̏ꍇ�̏��� */
} HVCW_EP_FR_PUSH_ALERT;

typedef struct {
    HVCW_EP_KNOWNUSER knownUser[20];        /* �o�^���Ă���l�� */
    HVCW_EP_SOUND unknownUser;              /* �o�^���Ă��Ȃ��l�� */
} HVCW_EP_FR_SOUND;

typedef struct {
    HVCW_EP_FR_PUSH_ALERT pushAlert;        /* �v�b�V���ʒm�ݒ� */
    HVCW_EP_FR_SOUND      sound;            /* �����o�͐ݒ� */
} HVCW_EP_FR_NOTIFICATION;

typedef struct {
    HVCW_FR_SAVE_RESULT     saveImage;      /* �摜�̕ۑ� */
    HVCW_EP_FR_NOTIFICATION notification;   /* ��F�ؒʒm�ݒ� */
} HVCW_EP_FR_POST_PROCESS;

typedef struct {
    HVCW_INT32 nIndex;                      /* ���̌��m�C�x���g�̃C���f�b�N�X�i���̌��m�̏ꍇ�̂݁j*/
    HVCW_VOID* eventProgram;                /* �C�x���g�ݒ� */
} HVCW_EVENT_PROGRAM;

typedef struct {
    HVCW_EP_MOTION_EVENT motionEvent;       /* ���̌��m�C�x���g�ݒ� */
    HVCW_EP_OKAO_PROCESS okaoProcess;       /* OKAO�����ݒ� */
    HVCW_EP_POST_PROCESS postProcess;       /* �ʒm�����ݒ� */
    HVCW_EP_FR_POST_PROCESS frPostProcess;  /* FR��p�ʒm�����ݒ� */
} HVCW_EVENT_PROGRAM_MOTION;

typedef struct {
    HVCW_EP_SOUND_EVENT soundEvent;         /* �������m�C�x���g�ݒ� */
    HVCW_EP_OKAO_PROCESS okaoProcess;       /* OKAO�����ݒ� */
    HVCW_EP_POST_PROCESS postProcess;       /* �ʒm�����ݒ� */
    HVCW_EP_FR_POST_PROCESS frPostProcess;  /* FR��p�ʒm�����ݒ� */
} HVCW_EVENT_PROGRAM_SOUND;

typedef struct {
    HVCW_EP_TIMER_EVENT timerEvent;         /* �^�C�}�[�C�x���g�ݒ� */
    HVCW_EP_OKAO_PROCESS okaoProcess;       /* OKAO�����ݒ� */
    HVCW_EP_POST_PROCESS postProcess;       /* �ʒm�����ݒ� */
    HVCW_EP_FR_POST_PROCESS frPostProcess;  /* FR��p�ʒm�����ݒ� */
} HVCW_EVENT_PROGRAM_TIMER;

typedef struct {
    HVCW_UINT32          ucTotalSize;       /* �X�g���[�W���e��(KB)       */
    HVCW_UINT32          ucUsedSize;        /* �g�p�ς݃X�g���[�W�e��(KB) */
    HVCW_UINT32          ucFreeSize;        /* �󂫃X�g���[�W�e��(KB)     */
    HVCW_STORAGE_STATUS  storageStatus;     /* �X�g���[�W�X�e�[�^�X       */
} HVCW_STORAGEINFO;

/**********************************************************/
/* Callback API                                           */
/**********************************************************/
/* �����_�����O�v���R�[���o�b�N�֐� */
typedef HVCW_INT32 (*HVCW_RequestRenderingCallback)(HVCW_BOOL bVideo, HVCW_VOID *pUserParam, 
                                                    HVCW_VOID *pRenderInfo, HVCW_UINT32 unInfoLen, HVCW_UINT32 unTimeStamp);

/* ���C�u�C�x���g�ʒm�R�[���o�b�N�֐� */
typedef HVCW_INT32 (*HVCW_LiveEventCallback)(HVCW_INT32 nEventId, HVCW_VOID *pUserParam, HVCW_VOID *pEventInfo);

/* �C�x���g�ʒm�R�[���o�b�N�֐� */
typedef HVCW_INT32 (*HVCW_EventCallback)(HVCW_INT32 nEventId, HVCW_VOID *pUserParam, HVCW_VOID *pEventInfo);


/**********************************************************/
/* HVCW SDK API                                           */
/**********************************************************/
/* SDK�o�[�W�����擾�֐� */
HVC_API HVCW_INT32 HVCW_GetVersion(HVCW_UINT8 *pucMajor, HVCW_UINT8 *pucMinor, HVCW_UINT8 *pucRelease);

/* �J�����ڑ��֐� */
HVC_API HVCW_INT32 HVCW_Connect(HHVC hHVC, HVCW_UINT8 *pucCameraId, HVCW_UINT8 *pucAccessToken);
/* �J�����ؒf�֐� */
HVC_API HVCW_INT32 HVCW_Disconnect(HHVC hHVC);

/* �J�����n���h���̐ݒ� */
HVC_API HVCW_INT32 HVCW_SetCameraHandle(HHVC hHVC, C2W_HANDLE hCameraHandle);

/* �J�����t�@�[���E�F�A�o�[�W�����擾�֐� */
HVC_API HVCW_INT32 HVCW_GetCameraVersion(HHVC hHVC, HVCW_UINT8 aucVersion[128]);

/* �J�����t�@�[���E�F�A�A�b�v�f�[�g�v���֐� */
HVC_API HVCW_INT32 HVCW_UpdateFirmware(HHVC hHVC);

/* NightVision���[�h�ݒ�֐� */
HVC_API HVCW_INT32 HVCW_SetNightVisionMode(HHVC hHVC, HVCW_NIGHT_VISION_MODE mode);
/* NightVision���[�h�擾�֐� */
HVC_API HVCW_INT32 HVCW_GetNightVisionMode(HHVC hHVC, HVCW_NIGHT_VISION_MODE *pMode);

/* NightVision�X�e�[�^�X�ݒ�֐� */
HVC_API HVCW_INT32 HVCW_SetNightVisionStatus(HHVC hHVC, HVCW_NIGHT_VISION_STATUS status);
/* NightVision�X�e�[�^�X�擾�֐� */
HVC_API HVCW_INT32 HVCW_GetNightVisionStatus(HHVC hHVC, HVCW_NIGHT_VISION_STATUS *pStatus);

/* �C�x���g��M�ݒ�֐� */
HVC_API HVCW_INT32 HVCW_EnableEventMonitor(HHVC hHVC, HVCW_VOID *pUserParam, HVCW_EventCallback callbackFunc);
/* �C�x���g��M�����֐� */
HVC_API HVCW_INT32 HVCW_DisableEventMonitor(HHVC hHVC);

/* �X�s�[�J�[�{�����[���ݒ�֐� */
HVC_API HVCW_INT32 HVCW_SetSpeakerVolume(HHVC hHVC, HVCW_UINT32 unVolume);
/* �X�s�[�J�[�{�����[���擾�֐� */
HVC_API HVCW_INT32 HVCW_GetSpeakerVolume(HHVC hHVC, HVCW_UINT32 *punVolume);

/* �}�C�N���x�ݒ�֐� */
HVC_API HVCW_INT32 HVCW_SetMicSensitivity(HHVC hHVC, HVCW_UINT32 unSensitivity);
/* �}�C�N���x�擾�֐� */
HVC_API HVCW_INT32 HVCW_GetMicSensitivity(HHVC hHVC, HVCW_UINT32 *punSensitivity);

/* �J����WiFi-RSSI�l�擾�֐� */
HVC_API HVCW_INT32 HVCW_GetWiFiRSSI(HHVC hHVC, HVCW_INT32 *pnWifiRssi);

/* �l�b�g���[�N�ݒ�p�����t�@�C���쐬�֐� */
HVC_API HVCW_INT32 HVCW_GenerateDataSoundFile(HVCW_UINT8 *pucTargetFile, HVCW_UINT8 *pucSSID, HVCW_UINT8 *pucPassword, HVCW_UINT8 *pusAccessToken);

/* �X�g���[�W�t�H�[�}�b�g�֐� */
HVC_API HVCW_INT32 HVCW_RequestStorageFormat(HHVC hHVC, HVCW_STORAGE_FORMAT_RESULT_CODE *pResultCode);

/* �ڑ���ʎ擾�֐� */
HVC_API HVCW_INT32 HVCW_GetConnectionType(HHVC hHVC, HVCW_CONNECTION_TYPE *pConnType);

/* ���C�u�X�g���[�~���O�J�n�֐� */
HVC_API HVCW_INT32 HVCW_StartLive(HHVC hHVC,
                                  HVCW_VOID *pUserParam, 
                                  HVCW_VIDEO_RESOLUTION videoResolution, 
                                  HVCW_RequestRenderingCallback renderingCallback, 
                                  HVCW_LiveEventCallback eventCallback);
/* ���C�u�X�g���[�~���O��~�֐� */
HVC_API HVCW_INT32 HVCW_StopLive(HHVC hHVC);

/* �r�f�I�t���[���f�[�^����֐� */
HVC_API HVCW_INT32 HVCW_FreeDecodedVideoBuffer(HHVC hHVC, const HVCW_VOID *pBuffer);

/* �����f�[�^����֐� */
HVC_API HVCW_INT32 HVCW_FreeDecodedAudioBuffer(HHVC hHVC, const HVCW_VOID *pBuffer);

/* �g�[�N���[�h�J�n�֐� */
HVC_API HVCW_INT32 HVCW_EnterTalkMode(HHVC hHVC);
/* �g�[�N���[�h�I���֐� */
HVC_API HVCW_INT32 HVCW_ExitTalkMode(HHVC hHVC);

/* �����f�[�^�]���֐� */
HVC_API HVCW_INT32 HVCW_TransferSoundData(HHVC hHVC, HVCW_BYTE *pucSoundData, HVCW_UINT32 unSoundLen);

/* ���C�u�𑜓x�ύX�֐� */
HVC_API HVCW_INT32 HVCW_SetVideoResolution(HHVC hHVC, HVCW_VIDEO_RESOLUTION videoResolution);
/* ���C�u�𑜓x�擾�֐� */
HVC_API HVCW_INT32 HVCW_GetVideoResolution(HHVC hHVC, HVCW_VIDEO_RESOLUTION *pVideoResolution);

/* �������m�J�n�֐� */
HVC_API HVCW_INT32 HVCW_EnableSoundDetection(HHVC hHVC, HVCW_UINT32 unSensitivity);
/* �������m��~�֐� */
HVC_API HVCW_INT32 HVCW_DisableSoundDetection(HHVC hHVC);

/* �������m�ݒ�擾�֐� */
HVC_API HVCW_INT32 HVCW_GetSoundDetection(HHVC hHVC, HVCW_BOOL *pbOn, HVCW_UINT32 *punSensitivity);

/* ���̌��m�J�n�֐� */
HVC_API HVCW_INT32 HVCW_EnableMotionDetection(HHVC hHVC, HVCW_UINT32 unDetectionParamsCount, const HVCW_DETECTIONPARAM aDetectionParams[10]);
/* ���̌��m��~�֐� */
HVC_API HVCW_INT32 HVCW_DisableMotionDetection(HHVC hHVC);

/* ���̌��m�ݒ�擾�֐� */
HVC_API HVCW_INT32 HVCW_GetMotionDetection(HHVC hHVC,
                                           HVCW_BOOL *pbOn,
                                           HVCW_UINT32 *punDetectionParamCount,
                                           HVCW_DETECTIONPARAM aDetectionParams[10]);

/* �J����MAC�A�h���X�擾�֐� */
HVC_API HVCW_INT32 HVCW_GetCameraMacAddress(HHVC hHVC, HVCW_UINT8 aucMACAddress[32]);

/* �J����FW�A�b�v�f�[�g�m�F�֐� */
HVC_API HVCW_INT32 HVCW_CheckNewFirmware(HHVC hHVC, HVCW_UINT8 aucVersion[128]);

/* �X�g���[�W���擾�֐� */
HVC_API HVCW_INT32 HVCW_GetStorageInfo(HHVC hHVC, HVCW_STORAGEINFO *pStorageInfo);

/* �t�@�C���擾�Ή��m�F */
HVC_API HVCW_INT32 HVCW_IsSupportDownloadFileFast(HHVC hHVC, HVCW_BOOL *pbDownloadFileFast);

/* �t�@�C���_�E�����[�h�i�����Łj */
HVC_API HVCW_INT32 HVCW_DownloadFile_Fast(HHVC hHVC,
                                          HVCW_FILE_EXT fileExt, 
                                          const HVCW_CHAR *pcFileName,
                                          HVCW_UINT32 unFileNameLength,
                                          HVCW_INT32 *pnSize,
                                          HVCW_UINT8 **pucBuffer);

/* �t�@�C���f�[�^�i�[buffer��� */
HVC_API HVCW_INT32 HVCW_FreeFileBuffer(HHVC hHVC, const HVCW_UINT8 *pucBuffer);

/*--------------------------------------------------------*/
/* HVCW SDK OKAO API                                      */
/*--------------------------------------------------------*/
/* HVCW�n���h���쐬 */
HVC_API HHVC HVCW_CreateHandle(void);
/* HVCW�n���h���폜 */
HVC_API HVCW_INT32 HVCW_DeleteHandle(HHVC hHVC);

/* �A�v���P�[�V����ID�ݒ� */
HVC_API HVCW_INT32 HVCW_SetAppID(HHVC hHVC, HVCW_INT32 nAppID, HVCW_UINT8 *pucReturnStatus);
/* �A�v���P�[�V����ID�擾 */
HVC_API HVCW_INT32 HVCW_GetAppID(HHVC hHVC, HVCW_INT32 *pnAppID, HVCW_UINT8 *pucReturnStatus);

/* OKAO���[�h�ݒ� */
HVC_API HVCW_INT32 HVCW_SetOkaoMode(HHVC hHVC, HVCW_BOOL bOkaoMode, HVCW_UINT8 *pucReturnStatus);
/* OKAO���[�h�擾 */
HVC_API HVCW_INT32 HVCW_GetOkaoMode(HHVC hHVC, HVCW_BOOL *pbOkaoMode, HVCW_UINT8 *pucReturnStatus);

/* �t�@�C�����擾 */
HVC_API HVCW_INT32 HVCW_GetFileCount(HHVC hHVC, HVCW_FILE_EXT fileExt, HVCW_UINT32 *punFileCount, HVCW_UINT8 *pucReturnStatus);

/* �t�@�C�����擾 */
HVC_API HVCW_INT32 HVCW_GetFileInfo(HHVC hHVC, HVCW_FILE_EXT fileExt, HVCW_UINT32 unFileIndex, HVCW_FILEINFO *pFileInfo, HVCW_UINT8 *pucReturnStatus);

/* �t�@�C���_�E�����[�h */
HVC_API HVCW_INT32 HVCW_DownloadFile(HHVC hHVC, const HVCW_FILEINFO *pFileInfo, HVCW_UINT8 *pucBuffer, HVCW_UINT8 *pucReturnStatus);
/* �t�@�C���A�b�v���[�h */
HVC_API HVCW_INT32 HVCW_UploadFile(HHVC hHVC, HVCW_CHAR acFileName[40], HVCW_INT32 nBufferSize, const HVCW_UINT8 *pucBuffer, HVCW_UINT8 *pucReturnStatus);

/* �t�@�C���̍폜 */
HVC_API HVCW_INT32 HVCW_DeleteFile(HHVC hHVC, const HVCW_FILEINFO *pFileInfo, HVCW_UINT8 *pucReturnStatus);

/* OKAO���s�摜�T�C�Y�擾 */
HVC_API HVCW_INT32 HVCW_GetLastOkaoImageSize(HHVC hHVC, HVCW_INT32 *pnImgBufSize, HVCW_UINT8 *pucReturnStatus);

/* OKAO���s�摜�̎擾 */
HVC_API HVCW_INT32 HVCW_GetLastOkaoImage(HHVC hHVC, HVCW_INT32 nImgBufSize, HVCW_UINT8 *pucImage, HVCW_UINT8 *pucReturnStatus);

/* �B�e */
HVC_API HVCW_INT32 HVCW_TakePicture(HHVC hHVC, HVCW_FILEINFO *pFileInfo, HVCW_UINT8 *pucReturnStatus);

/* �������l�ݒ� */
HVC_API HVCW_INT32 HVCW_OKAO_SetThreshold(HHVC hHVC, const HVCW_OKAO_THRESHOLD *pThreshold, HVCW_UINT8 *pucReturnStatus);
/* �������l�擾 */
HVC_API HVCW_INT32 HVCW_OKAO_GetThreshold(HHVC hHVC, HVCW_OKAO_THRESHOLD *pThreshold, HVCW_UINT8 *pucReturnStatus);

/* ���o�T�C�Y�ݒ� */
HVC_API HVCW_INT32 HVCW_OKAO_SetSizeRange(HHVC hHVC, const HVCW_OKAO_SIZE_RANGE *pSizeRange, HVCW_UINT8 *pucReturnStatus);
/* ���o�T�C�Y�擾 */
HVC_API HVCW_INT32 HVCW_OKAO_GetSizeRange(HHVC hHVC, HVCW_OKAO_SIZE_RANGE *pSizeRange, HVCW_UINT8 *pucReturnStatus);

/* ���o�p�x�̐ݒ� */
HVC_API HVCW_INT32 HVCW_OKAO_SetDetectionAngle(HHVC hHVC, const HVCW_OKAO_DETECTION_ANGLE *pDetectionAngle, HVCW_UINT8 *pucReturnStatus);
/* ���o�p�x�̎擾 */
HVC_API HVCW_INT32 HVCW_OKAO_GetDetectionAngle(HHVC hHVC, HVCW_OKAO_DETECTION_ANGLE *pDetectionAngle, HVCW_UINT8 *pucReturnStatus);

/* OKAO���s */
HVC_API HVCW_INT32 HVCW_OKAO_Execute(HHVC hHVC, HVCW_BOOL abUseFunction[HVCW_OkaoFunction_Max], HVCW_OKAO_RESULT *pResult, HVCW_UINT8 *pucReturnStatus);

/* �A���o���o�^ */
HVC_API HVCW_INT32 HVCW_ALBUM_Register(HHVC hHVC, HVCW_INT32 nUserID, HVCW_INT32 nDataID, HVCW_OKAO_RESULT_DETECTION *pFaceResult, HVCW_FILEINFO *pFileInfo, HVCW_UINT8 *pucReturnStatus);

/* �o�^�Җ��ύX */
HVC_API HVCW_INT32 HVCW_ALBUM_SetUserName(HHVC hHVC, HVCW_INT32 nUserID, const HVCW_CHAR acName[44], HVCW_UINT8 *pucReturnStatus);

/* �o�^�Җ��擾 */
HVC_API HVCW_INT32 HVCW_ALBUM_GetUserName(HHVC hHVC, HVCW_INT32 nUserID, HVCW_CHAR acName[44], HVCW_UINT8 *pucReturnStatus);

/* �o�^�f�[�^�폜 */
HVC_API HVCW_INT32 HVCW_ALBUM_DeleteData(HHVC hHVC, HVCW_INT32 nUserID, HVCW_INT32 nDataID, HVCW_UINT8 *pucReturnStatus);

/* ���ׂĂ̓o�^�����N���A */
HVC_API HVCW_INT32 HVCW_ALBUM_DeleteAllData(HHVC hHVC, HVCW_UINT8 *pucReturnStatus);

/* �o�^��Ԏ擾 */
HVC_API HVCW_INT32 HVCW_ALBUM_GetRegistrationStatus (HHVC hHVC, HVCW_INT32 nUserID, HVCW_BOOL abExist[10], HVCW_UINT8 *pucReturnStatus);

/* �A���o���T�C�Y�擾 */
HVC_API HVCW_INT32 HVCW_ALBUM_GetSize(HHVC hHVC, HVCW_INT32 *pnAlbumSize, HVCW_UINT8 *pucReturnStatus);

/* �A���o���̃_�E�����[�h */
HVC_API HVCW_INT32 HVCW_ALBUM_Download(HHVC hHVC, HVCW_UINT8 *pucAlbum, HVCW_UINT8 *pucReturnStatus);
/* �A���o���̃A�b�v���[�h */
HVC_API HVCW_INT32 HVCW_ALBUM_Upload(HHVC hHVC, HVCW_INT32 nAlbumSize, const HVCW_UINT8 *pucAlbum, HVCW_UINT8 *pucReturnStatus);

/* �A���o����Flash�������� */
HVC_API HVCW_INT32 HVCW_ALBUM_Save(HHVC hHVC, HVCW_UINT8 *pucReturnStatus);

/* �X�P�W���[���ݒ� */
HVC_API HVCW_INT32 HVCW_SetScheduler(HHVC hHVC, HVCW_SCHEDULER_TYPE schedulerType, HVCW_BOOL bEnable, const HVCW_SCHEDULE_INFO *pSchedule, HVCW_UINT8 *pucReturnStatus);
/* �X�P�W���[���擾 */
HVC_API HVCW_INT32 HVCW_GetScheduler(HHVC hHVC, HVCW_SCHEDULER_TYPE schedulerType, HVCW_BOOL *pbEnable, HVCW_SCHEDULE_INFO *pSchedule, HVCW_UINT8 *pucReturnStatus);

/* �C�x���g�v���O�����ݒ� */
HVC_API HVCW_INT32 HVCW_SetEventProgram(HHVC hHVC, HVCW_EVENT_PROGRAM_TYPE eventProgramType, HVCW_BOOL bEnable, const HVCW_EVENT_PROGRAM *pEventProgram, HVCW_UINT8 *pucReturnStatus);
/* �C�x���g�v���O�����擾 */
HVC_API HVCW_INT32 HVCW_GetEventProgram(HHVC hHVC, HVCW_EVENT_PROGRAM_TYPE eventProgramType, HVCW_BOOL *pbEnable, HVCW_EVENT_PROGRAM *pEventProgram, HVCW_UINT8 *pucReturnStatus);


#ifdef __cplusplus
} /* closing brace for extern "C" */
#endif

#endif /* __HVCWSDKAPI_H */
