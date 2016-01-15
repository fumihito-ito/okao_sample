/*-------------------------------------------------------------------*/
/*  Copyright(C) 2015 by OMRON Corporation                           */
/*  All Rights Reserved.                                             */
/*                                                                   */
/*   This source code is the Confidential and Proprietary Property   */
/*   of OMRON Corporation.  Any unauthorized use, reproduction or    */
/*   transfer of this software is strictly prohibited.               */
/*                                                                   */
/*-------------------------------------------------------------------*/
package jp.co.omron.hvcw;

/**
 * HVC-C2W SDK API
 */
public class HvcwApi
{
	/* 真偽値 */
	/** 真 */
	public final static int		HVCW_FALSE = 0;
	/** 偽 */
	public final static int		HVCW_TRUE  = 1;

	/* NightVisionモード */
	/** 自動設定 */
	public final static int		HVCW_NightVisionMode_Auto   = 0;
	/** 手動設定 */
	public final static int		HVCW_NightVisionMode_Manual = 1;

	/* NightVisionステータス */
	/** NightVision無効 */
	public final static int		HVCW_NightVisionStatus_Off  = 0;
	/** NightVision無効 */
	public final static int		HVCW_NightVisionStatus_On   = 1;

	/* イベント */
	/** カメラへの接続数が変更された場合に通知 */
	public final static int		HVCW_Event_ConnectionNum     = 0;
	/** カメラのライブストリーミング数が変更された場合に通知 */
	public final static int		HVCW_Event_StreamingNum      = 1;
	/** NightVisionモードが変更された場合に通知 */
	public final static int		HVCW_Event_NightVisionMode   = 6;
	/** NightVisionステータスが変更された場合に通知 */
	public final static int		HVCW_Event_NightVisionStatus = 7;
	/** カメラのスピーカーボリュームが変更された場合に通知 */
	public final static int		HVCW_Event_SpeakerVolume     = 9;
	/** カメラとの接続が切断された場合に通知 */
	public final static int		HVCW_Event_Disconnected      = 13;
	/** カメラとの接続が回復した場合に通知 */
	public final static int		HVCW_Event_Reconnected       = 14;
	/** カメラのストレージステータスが変更された場合に通知 */
	public final static int		HVCW_Event_StorageStatus     = 18;

	/* ストレージステータス */
	/** ストレージ未検出 */
	public final static int		HVCW_StorageStatus_NotInsert  = 0;
	/** ストレージ検出済みだが使用不可状態 */
	public final static int		HVCW_StorageStatus_NotReady   = 1;
	/** ストレージはフォーマットが必要な状態 */
	public final static int		HVCW_StorageStatus_NeedFormat = 2;
	/** ストレージ使用可能 */
	public final static int		HVCW_StorageStatus_Normal     = 3;
	/** ストレージにエラーが発生し使用不可能状態 */
	public final static int		HVCW_StorageStatus_Error      = 4;
	/** ストレージフォーマット中 */
	public final static int		HVCW_StorageStatus_Formatting = 6;
	/** サポート対象外ストレージ */
	public final static int		HVCW_StorageStatus_NotSupport = 7;

	/* ストレージフォーマット結果 */
	/** フォーマット成功 */
	public final static int		HVCW_StorageFormatResultCode_Success           = 0;
	/** フォーマット中にストレージが抜かれた */
	public final static int		HVCW_StorageFormatResultCode_RemovedStorage    = 1;
	/** サポートしていないストレージ */
	public final static int		HVCW_StorageFormatResultCode_NotSupportStorage = 2;
	/** フォーマット中にタイムアウトが発生 */
	public final static int		HVCW_StorageFormatResultCode_Timeout           = 3;
	/** 既にフォーマットを実行中 */
	public final static int		HVCW_StorageFormatResultCode_AlreadyRunning    = 4;
	/** チェックディスク実行中 */
	public final static int		HVCW_StorageFormatResultCode_CheckDisk         = 5;
	/** 致命的なエラー */
	public final static int		HVCW_StorageFormatResultCode_FatalError        = 6;

	/* 接続種別 */
	/** 未接続 */
	public final static int		HVCW_ConnectionType_Disconnect = 0;
	/** P2P接続 */
	public final static int		HVCW_ConnectionType_P2P        = 1;
	/** Relay接続 */
	public final static int		HVCW_ConnectionType_Relay      = 2;
	/** Local接続 */
	public final static int		HVCW_ConnectionType_Local      = 3;

	/* ライブストリーミングビデオ解像度 */
	/** 高解像度 (1280x720) */
	public final static int		HVCW_VideoResolution_High   = 0;
	/** 中解像度 (640x360) */
	public final static int		HVCW_VideoResolution_Middle = 1;
	/** 低解像度 (320x180) */
	public final static int		HVCW_VideoResolution_Low    = 2;

	/* ファイル拡張子 */
	/** ログファイル */
	public final static int		HVCW_FileExt_Log               = 2;
	/** メッセージテキストファイル */
	public final static int		HVCW_FileExt_MessageText       = 3;
	/** 音声ファイル */
	public final static int		HVCW_FileExt_Sound             = 4;
	/** JPEG画像ファイル */
	public final static int		HVCW_FileExt_JpgImage          = 6;
	/** YUV画像ファイル */
	public final static int		HVCW_FileExt_YUVImage          = 7;
	/** サムネイル画像ファイル */
	public final static int		HVCW_FileExt_ThumbnailJpgImage = 8;

	/* スケジュールタイプ */
	/** One Timeスケジュール */
	public final static int		HVCW_ScheduleType_OneTime = 0;
	/** Repeatスケジュール */
	public final static int		HVCW_ScheduleType_Repeat  = 1;
	/** スケジュールタイプ数 */
	public final static int		HVCW_ScheduleType_Max     = 2;

	/* イベントタイプ */
	/** 音声検知イベント */
	public final static int		HVCW_EventProgramType_Sound  = 0;
	/** 動体検知イベント */
	public final static int		HVCW_EventProgramType_Motion = 1;
	/** タイマーイベント */
	public final static int		HVCW_EventProgramType_Timer  = 2;
	/** イベントタイプ数 */
	public final static int		HVCW_EventProgramType_Max    = 3;

	/* 画像サイズ */
	/** FullHD */
	public final static int		HVCW_ImageSize_FullHD = 0;
	/** HD*/
	public final static int		HVCW_ImageSize_HD     = 1;
	/** WVGA */
	public final static int		HVCW_ImageSize_WVGA   = 2;
	/** WQVGA */
	public final static int		HVCW_ImageSize_WQVGA  = 3;
	/** 画像サイズ数 */
	public final static int		HVCW_ImageSize_Max    = 4;

	/* 繰り返し周期タイプ */
	/** 一度きり */
	public final static int		HVCW_ScheduleFrequency_Once    = 0;
	/** 毎日 */
	public final static int		HVCW_ScheduleFrequency_Daily   = 1;
	/** 毎週 */
	public final static int		HVCW_ScheduleFrequency_Weekday = 2;
	/** 繰り返し周期タイプ数 */
	public final static int		HVCW_ScheduleFrequency_Max     = 3;

	/* 保存フラグ */
	/** 保存しない */
	public final static int		HVCW_SaveResult_None      = 0;
	/** 全て保存 */
	public final static int		HVCW_SaveResult_All       = 1;
	/** 検出時に保存 */
	public final static int		HVCW_SaveResult_Detection = 2;
	/** 保存フラグ数 */
	public final static int		HVCW_SaveResult_Max       = 3;

	/* イベント発生時顔認証画像保存フラグ */
	/** 保存しない */
	public final static int		HVCW_FRSaveResult_None    = 0;
	/** 全て保存 */
	public final static int		HVCW_FRSaveResult_All     = 1;
	/** 本人認証時保存 */
	public final static int		HVCW_FRSaveResult_Known   = 2;
	/** 他人認証時保存 */
	public final static int		HVCW_FRSaveResult_Unknown = 3;
	/** イベント発生時顔認証画像保存フラグ数 */
	public final static int		HVCW_FRSaveResult_Max     = 4;

	/* Roll Angle Definitions */
	/** Upward Front +/- 15 degree */
	public static final int		ROLL_ANGLE_0  = 0x00001001;
	/** Upward Left  +/- 15 degree */
	public static final int		ROLL_ANGLE_1  = 0x00002002;
	/** Rightward Right +/- 15 degree */
	public static final int		ROLL_ANGLE_2  = 0x00004004;
	/** Rightward Front +/- 15 degree */
	public static final int		ROLL_ANGLE_3  = 0x00008008;
	/** Rightward Left  +/- 15 degree */
	public static final int		ROLL_ANGLE_4  = 0x00010010;
	/** Downward Right +/- 15 degree */
	public static final int		ROLL_ANGLE_5  = 0x00020020;
	/** Downward Front +/- 15 degree */
	public static final int		ROLL_ANGLE_6  = 0x00040040;
	/** Downward Left  +/- 15 degree */
	public static final int		ROLL_ANGLE_7  = 0x00080080;
	/** Leftward Right +/- 15 degree */
	public static final int		ROLL_ANGLE_8  = 0x00100100;
	/** Leftward Front +/- 15 degree */
	public static final int		ROLL_ANGLE_9  = 0x00200200;
	/** Leftward Left  +/- 15 degree */
	public static final int		ROLL_ANGLE_10 = 0x00400400;
	/** Upward Right +/- 15 degree */
	public static final int		ROLL_ANGLE_11 = 0x00800800;

	/** All angles are detected */
	public static final int		ROLL_ANGLE_ALL  = 0x00ffffff;
	/** None of the angles will be detected */
	public static final int		ROLL_ANGLE_NONE = 0x00000000;
	/** Up +/- 15 degree only will be detected */
	public static final int		ROLL_ANGLE_U15  = ROLL_ANGLE_0;
	/** Right +/- 15 degree only will be detected */
	public static final int		ROLL_ANGLE_R15  = ROLL_ANGLE_3;
	/** Down +/- 15 degree only will be detected */
	public static final int		ROLL_ANGLE_D15  = ROLL_ANGLE_6;
	/** Left +/- 15 degree only will be detected */
	public static final int		ROLL_ANGLE_L15  = ROLL_ANGLE_9;

	/** Up +/- 15 degree only will be detected */
	public static final int		ROLL_ANGLE_UP    = ROLL_ANGLE_U15;
	/** Right +/- 15 degree only will be detected */
	public static final int		ROLL_ANGLE_RIGHT = ROLL_ANGLE_R15;
	/** Down +/- 15 degree only will be detected */
	public static final int		ROLL_ANGLE_DOWN  = ROLL_ANGLE_D15;
	/** Left +/- 15 degree only will be detected */
	public static final int		ROLL_ANGLE_LEFT  = ROLL_ANGLE_L15;

	/* 実行機能フラグ */
	/** 人体検出 */
	public final static int		HVCW_OkaoFunction_Body        = 0;
	/** 手検出 */
	public final static int		HVCW_OkaoFunction_Hand        = 1;
	/** ペット検出 */
	public final static int		HVCW_OkaoFunction_Pet         = 2;
	/** 顔検出 */
	public final static int		HVCW_OkaoFunction_Face        = 3;
	/** 顔向き推定 */
	public final static int		HVCW_OkaoFunction_Direction   = 4;
	/** 年齢推定 */
	public final static int		HVCW_OkaoFunction_Age         = 5;
	/** 性別推定 */
	public final static int		HVCW_OkaoFunction_Gender      = 6;
	/** 視線推定 */
	public final static int		HVCW_OkaoFunction_Gaze        = 7;
	/** 目つむり推定 */
	public final static int		HVCW_OkaoFunction_Blink       = 8;
	/** 表情推定 */
	public final static int		HVCW_OkaoFunction_Expression  = 9;
	/** 顔認証 */
	public final static int		HVCW_OkaoFunction_Recognition = 10;
	/** 実行機能数 */
	public final static int		HVCW_OkaoFunction_Max         = 11;

	/* 表情 */
	/** 無視 */
	public final static int		HVCW_Expression_Ignore        = -1;
	/** 無表情 */
	public final static int		HVCW_Expression_Neutral       = 0;
	/** 喜び */
	public final static int		HVCW_Expression_Happiness     = 1;
	/** 驚き */
	public final static int		HVCW_Expression_Surprise      = 2;
	/** 怒り */
	public final static int		HVCW_Expression_Anger         = 3;
	/** 悲しみ */
	public final static int		HVCW_Expression_Sadness       = 4;
	/** 表情数 */
	public final static int		HVCW_Expression_Max           = 5;

	private long handle = 0;

//	public long getHandle()
//	{
//		return handle;
//	}

	/**
	 * コンストラクタ
	 */
	private HvcwApi()
	{
	}

	/**
	 * SDKバージョン取得
	 * @param Major メジャーバージョン
	 * @param Minor マイナーバージョン
	 * @param Release リリースバージョン
	 * @return エラーコード
	 */
	public native static int getVersion(Int Major, Int Minor, Int Release);

	private native long createHandleNative();

	private native int initLibrary();

	/**
	 * ハンドル作成
	 * @return 成功時はハンドル、失敗時はnullを返す
	 */
	public static HvcwApi createHandle()
	{
		HvcwApi hvcwapi = new HvcwApi();
		hvcwapi.initLibrary();
		hvcwapi.handle = hvcwapi.createHandleNative();
		if(hvcwapi.handle == 0)
		{
			hvcwapi = null;
		}

		return hvcwapi;
	}

	private native int deleteHandle(long hHVC);

	/**
	 * ハンドル削除
	 * @return エラーコード
	 */
	public int deleteHandle()
	{
		return deleteHandle(handle);
	}

	private native int setCameraHandle(long hHVC, long hCameraHandle);

	/**
	 * カメラハンドルの設定
	 * @param hCameraHandle カメラハンドル
	 * @return エラーコード
	 */
	public int setCameraHandle(long hCameraHandle)
	{
		return setCameraHandle(handle, hCameraHandle);
	}

	private native int connect(long hHVC, String stCameraId, String stAccessToken);

	/**
	 * カメラに接続
	 * @param stCameraId カメラ識別子
	 * @param stAccessToken アクセストークン
	 * @return エラーコード
	 */
	public int connect(String stCameraId, String stAccessToken)
	{
		return connect(handle, stCameraId, stAccessToken);
	}

	private native int disconnect(long hHVC);

	/**
	 * カメラとの接続を切断
	 * @return エラーコード
	 */
	public int disconnect()
	{
		return disconnect(handle);
	}

	private native int getCameraVersion(long hHVC, StringBuffer sbVersion);

	/**
	 * カメラのファームウェアバージョンの取得
	 * @param sbVersion ファームウェアバージョン
	 * @return エラーコード
	 */
	public int getCameraVersion(StringBuffer sbVersion)
	{
		return getCameraVersion(handle, sbVersion);
	}

	private native int updateFirmware(long hHVC);

	/**
	 * カメラにファームウェア更新を指示
	 * @return エラーコード
	 */
	public int updateFirmware()
	{
		return updateFirmware(handle);
	}

	private native int setNightVisionMode(long hHVC, int nMode);

	/**
	 * カメラの NightVision モード（手動・自動）を設定
	 * @param nMode NightVision モード
	 * @return エラーコード
	 */
	public int setNightVisionMode(int nMode)
	{
		return setNightVisionMode(handle, nMode);
	}

	private native int getNightVisionMode(long hHVC, Int mode);

	/**
	 * カメラの NightVision モード（手動・自動）を取得
	 * @param mode NightVision モード
	 * @return エラーコード
	 */
	public int getNightVisionMode(Int mode)
	{
		return getNightVisionMode(handle, mode);
	}

	private native int setNightVisionStatus(long hHVC, int nStatus);

	/**
	 * カメラの NightVision ステータス（有効・無効）を設定
	 * @param nStatus NightVision ステータス
	 * @return エラーコード
	 */
	public int setNightVisionStatus(int nStatus)
	{
		return setNightVisionStatus(handle, nStatus);
	}

	private native int getNightVisionStatus(long hHVC, Int status);

	/**
	 * カメラの NightVision ステータス（有効・無効）を取得
	 * @param status NightVision ステータス
	 * @return エラーコード
	 */
	public int getNightVisionStatus(Int status)
	{
		return getNightVisionStatus(handle, status);
	}

	private native int enableEventMonitor(long hHVC, Object userParam, EventCallbackInterface callbackFunc);

	/**
	 * イベントの受信開始
	 * @param userParam ユーザパラメータ
	 * @param callbackFunc イベント受信コールバック
	 * @return エラーコード
	 */
	public int enableEventMonitor(Object userParam, EventCallbackInterface callbackFunc)
	{
		return enableEventMonitor(handle, userParam, callbackFunc);
	}

	private native int disableEventMonitor(long hHVC);

	/**
	 * イベントの受信停止
	 * @return エラーコード
	 */
	public int disableEventMonitor()
	{
		return disableEventMonitor(handle);
	}

	private native int setSpeakerVolume(long hHVC, int nVolume);

	/**
	 * カメラのスピーカーボリュームを設定
	 * @param nVolume スピーカーボリューム
	 * @return エラーコード
	 */
	public int setSpeakerVolume(int nVolume)
	{
		return setSpeakerVolume(handle, nVolume);
	}

	private native int getSpeakerVolume(long hHVC, Int volume);

	/**
	 * カメラのスピーカーボリュームを取得
	 * @param volume スピーカーボリューム
	 * @return エラーコード
	 */
	public int getSpeakerVolume(Int volume)
	{
		return getSpeakerVolume(handle, volume);
	}

	private native int setMicSensitivity(long hHVC, int nSensitivity);

	/**
	 * カメラのマイク感度を設定
	 * @param nSensitivity カメラマイク感度
	 * @return エラーコード
	 */
	public int setMicSensitivity(int nSensitivity)
	{
		return setMicSensitivity(handle, nSensitivity);
	}

	private native int getMicSensitivity(long hHVC, Int sensitivity);

	/**
	 * カメラのマイク感度を取得
	 * @param sensitivity カメラマイク感度
	 * @return エラーコード
	 */
	public int getMicSensitivity(Int sensitivity)
	{
		return getMicSensitivity(handle, sensitivity);
	}

	private native int getWiFiRSSI(long hHVC, Int wifiRssi);

	/**
	 * カメラの WiFi-RSSI 値を取得
	 * @param wifiRssi カメラWi-Fi RSSI値
	 * @return エラーコード
	 */
	public int getWiFiRSSI(Int wifiRssi)
	{
		return getWiFiRSSI(handle, wifiRssi);
	}

	/**
	 * ネットワーク設定用音声ファイル作成
	 * @param stTargetFile 保存ファイル名
	 * @param stSSID ネットワーク名(SSID)
	 * @param stPassword パスワード
	 * @param stAccessToken アクセストークン
	 * @return エラーコード
	 */
	public native static int generateDataSoundFile(String stTargetFile, String stSSID, String stPassword, String stAccessToken);

	private native int requestStorageFormat(long hHVC, Int resultCode);

	/**
	 * カメラのストレージフォーマットを指示
	 * @param resultCode フォーマット結果
	 * @return エラーコード
	 */
	public int requestStorageFormat(Int resultCode)
	{
		return requestStorageFormat(handle, resultCode);
	}

	private native int getConnectionType(long hHVC, Int connType);

	/**
	 * カメラとの接続種別を取得
	 * @param connType 接続種別
	 * @return エラーコード
	 */
	public int getConnectionType(Int connType)
	{
		return getConnectionType(handle, connType);
	}

	private native int startLive(long hHVC, Object userParam, int nVideoResolution,
									RequestRenderingCallbackInterface renderingCallback,
									LiveEventCallbackInterface eventCallback);

	/**
	 * ライブストリーミングを開始
	 * @param userParam ユーザーパラメータ
	 * @param nVideoResolution 解像度
	 * @param renderingCallback ビデオフレーム
	 * @param eventCallback ライブイベント受信コールバック
	 * @return エラーコード
	 */
	public int startLive(Object userParam, int nVideoResolution,
									RequestRenderingCallbackInterface renderingCallback,
									LiveEventCallbackInterface eventCallback)
	{
		return startLive(handle, userParam, nVideoResolution, renderingCallback, eventCallback);
	}

	private native int stopLive(long hHVC);

	/**
	 * ライブストリーミングを停止
	 * @return エラーコード
	 */
	public int stopLive()
	{
		return stopLive(handle);
	}

	private native int enterTalkMode(long hHVC);

	/**
	 * トークモードを開始
	 * @return エラーコード
	 */
	public int enterTalkMode()
	{
		return enterTalkMode(handle);
	}

	private native int exitTalkMode(long hHVC);

	/**
	 * トークモードを終了
	 * @return エラーコード
	 */
	public int exitTalkMode()
	{
		return exitTalkMode(handle);
	}

	private native int transferSoundData(long hHVC, byte[] byTargetFile, int nSoundLen);

	/**
	 * 端末マイクからの入力音声をカメラに転送し、カメラ側にて再生
	 * @param byTargetFile 音声データ
	 * @param nSoundLen 音声データサイズ
	 * @return エラーコード
	 */
	public int transferSoundData(byte[] byTargetFile, int nSoundLen)
	{
		return transferSoundData(handle, byTargetFile, nSoundLen);
	}

	private native int setVideoResolution(long hHVC, int nVideoResolution);

	/**
	 * ライブストリーミングの解像度を変更
	 * @param nVideoResolution 解像度
	 * @return エラーコード
	 */
	public int setVideoResolution(int nVideoResolution)
	{
		return setVideoResolution(handle, nVideoResolution);
	}

	private native int getVideoResolution(long hHVC, Int videoResolution);

	/**
	 * ライブストリーミングの解像度を取得
	 * @param videoResolution 解像度
	 * @return エラーコード
	 */
	public int getVideoResolution(Int videoResolution)
	{
		return getVideoResolution(handle, videoResolution);
	}

	private native int enableSoundDetection(long hHVC, int nSensitivity);

	/**
	 * カメラの音声検知を開始
	 * @param nSensitivity 音声検知感度
	 * @return エラーコード
	 */
	public int enableSoundDetection(int nSensitivity)
	{
		return enableSoundDetection(handle, nSensitivity);
	}

	private native int disableSoundDetection(long hHVC);

	/**
	 * カメラの音声検知を停止
	 * @return エラーコード
	 */
	public int disableSoundDetection()
	{
		return disableSoundDetection(handle);
	}

	private native int getSoundDetection(long hHVC, Int booleanOn, Int sensitivity);

	/**
	 * カメラの音声検知設定を取得
	 * @param booleanOn 有効/無効
	 * @param sensitivity 音声検知感度
	 * @return エラーコード
	 */
	public int getSoundDetection(Int booleanOn, Int sensitivity)
	{
		return getSoundDetection(handle, booleanOn, sensitivity);
	}

	private native int enableMotionDetection(long hHVC, int nDetectionParamsCount, DetectionParam[] aDetectionParams);

	/**
	 * カメラの動体検知を開始
	 * @param nDetectionParamsCount 動体検知矩形数
	 * @param aDetectionParams 動体検知パラメータ
	 * @return エラーコード
	 */
	public int enableMotionDetection(int nDetectionParamsCount, DetectionParam[] aDetectionParams)
	{
		return enableMotionDetection(handle, nDetectionParamsCount, aDetectionParams);
	}

	private native int disableMotionDetection(long hHVC);

	/**
	 * カメラの動体検知を停止
	 * @return エラーコード
	 */
	public int disableMotionDetection()
	{
		return disableMotionDetection(handle);
	}

	private native int getMotionDetection(long hHVC, Int booleanOn, Int detectionParamsCount, DetectionParam[] aDetectionParams);

	/**
	 * カメラの動体検知設定を取得
	 * @param booleanOn 有効/無効
	 * @param detectionParamsCount 動体検知矩形数
	 * @param aDetectionParams 動体検知パラメータ
	 * @return エラーコード
	 */
	public int getMotionDetection(Int booleanOn, Int detectionParamsCount, DetectionParam[] aDetectionParams)
	{
		return getMotionDetection(handle, booleanOn, detectionParamsCount, aDetectionParams);
	}

	private native int getCameraMacAddress(long hHVC, StringBuffer sbMACAddress);

	/**
	 * カメラの MAC アドレスを取得
	 * @param sbMACAddress MAC アドレス
	 * @return エラーコード
	 */
	public int getCameraMacAddress(StringBuffer sbMACAddress)
	{
		return getCameraMacAddress(handle, sbMACAddress);
	}

	private native int checkNewFirmware(long hHVC, StringBuffer sbVersion);

	/**
	 * カメラファームウェアアップデートを確認
	 * @param sbVersion 最新バージョン情報
	 * @return エラーコード
	 */
	public int checkNewFirmware(StringBuffer sbVersion)
	{
		return checkNewFirmware(handle, sbVersion);
	}

	private native int getStorageInfo(long hHVC, StorageInfo storageInfo);

	/**
	 * ストレージ情報取得
	 * @param storageInfo ストレージ情報
	 * @return エラーコード
	 */
	public int getStorageInfo(StorageInfo storageInfo)
	{
		return getStorageInfo(handle, storageInfo);
	}

<<<<<<< HEAD
=======
	/**
	 * ビデオフレーム取得
	 * @param renderInfo レンダー情報
	 * @param videoFrame ビデオフレーム
	 * @return エラーコード
	 */
	public native int getVideoFrame(long renderInfo, VideoFrame videoFrame);

    /**
	 * 音声データ取得
	 * @param renderInfo レンダー情報
	 * @param soundData 音声データ
	 */
	public native int getSoundData(long renderInfo, long infoLen, byte[] soundData);


>>>>>>> 928b024d1bec35534cc881a9c7b78e871d53d658
	/********************/
	/*     OKAO API     */
	/********************/

	private native int setAppID(long hHVC, int nAppID, Int returnStatus);

	/**
	 * アプリケーションID設定
	 * @param nAppID アプリケーションID
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int setAppID(int nAppID, Int returnStatus)
	{
		return setAppID(handle, nAppID, returnStatus);
	}


	/**
	 * アプリケーションID取得
	 */
	private native int getAppID(long hHVC, Int appID, Int returnStatus);

	/**
	 * アプリケーションID取得
	 * @param appID アプリケーションID
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int getAppID(Int appID, Int returnStatus)
	{
		return getAppID(handle, appID, returnStatus);
	}

	private native int setOkaoMode(long hHVC, int booleanOkaoMode, Int returnStatus);

	/**
	 * OKAOモード設定
	 * @param booleanOkaoMode OKAOモード
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int setOkaoMode(int booleanOkaoMode, Int returnStatus)
	{
		return setOkaoMode(handle, booleanOkaoMode, returnStatus);
	}

	private native int getOkaoMode(long hHVC, Int booleanOkaoMode, Int returnStatus);

	/**
	 * OKAOモード取得
	 * @param booleanOkaoMode OKAOモード
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int getOkaoMode(Int booleanOkaoMode, Int returnStatus)
	{
		return getOkaoMode(handle, booleanOkaoMode, returnStatus);
	}

	private native int getFileCount(long hHVC, int nFileExt, Int fileCount, Int returnStatus);

	/**
	 * ファイル数取得
	 * @param nFileExt ファイル拡張子
	 * @param fileCount ファイル数
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int getFileCount(int nFileExt, Int fileCount, Int returnStatus)
	{
		return getFileCount(handle, nFileExt, fileCount, returnStatus);
	}

	private native int getFileInfo(long hHVC, int nFileExt, int nFileIndex, FileInfo fileInfo, Int returnStatus);

	/**
	 * ファイル情報取得
	 * @param nFileExt ファイル拡張子
	 * @param nFileIndex ファイルインデックス
	 * @param fileInfo ファイル情報
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int getFileInfo(int nFileExt, int nFileIndex, FileInfo fileInfo, Int returnStatus)
	{
		return getFileInfo(handle, nFileExt, nFileIndex, fileInfo, returnStatus);
	}

	private native int downloadFile(long hHVC, FileInfo fileInfo, byte[] byBuffer, Int returnStatus);

	/**
	 * ファイルダウンロード
	 * @param fileInfo ファイル情報
	 * @param byBuffer ファイルデータ格納バッファ
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int downloadFile(FileInfo fileInfo, byte[] byBuffer, Int returnStatus)
	{
		return downloadFile(handle, fileInfo, byBuffer, returnStatus);
	}

	private native int uploadFile(long hHVC, String stFileName, int nBufferSize, byte[] byBuffer, Int returnStatus);

	/**
	 * ファイルアップロード
	 * @param stFileName ファイル名
	 * @param nBufferSize バッファサイズ
	 * @param byBuffer ファイルデータ格納バッファ
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int uploadFile(String stFileName, int nBufferSize, byte[] byBuffer, Int returnStatus)
	{
		return uploadFile(handle, stFileName, nBufferSize, byBuffer, returnStatus);
	}

	private native int deleteFile(long hHVC, FileInfo fileInfo, Int returnStatus);

	/**
	 * ファイルの削除
	 * @param fileInfo ファイル情報
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int deleteFile(FileInfo fileInfo, Int returnStatus)
	{
		return deleteFile(handle, fileInfo, returnStatus);
	}

	private native int getLastOkaoImageSize(long hHVC, Int imageSize, Int returnStatus);

	/**
	 * 最新のOKAO実行時の画像サイズ取得
	 * @param imageSize 画像サイズ
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int getLastOkaoImageSize(Int imageSize, Int returnStatus)
	{
		return getLastOkaoImageSize(handle, imageSize, returnStatus);
	}

	private native int getLastOkaoImage(long hHVC, int nImgBufSize, byte[] byImage, Int returnStatus);

	/**
	 * 最新のOKAO実行時の画像を取得
	 * @param nImgBufSize 画像格納バッファサイズ
	 * @param byImage 画像格納バッファ
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int getLastOkaoImage(int nImgBufSize, byte[] byImage, Int returnStatus)
	{
		return getLastOkaoImage(handle, nImgBufSize, byImage, returnStatus);
	}

	private native int takePicture(long hHVC, FileInfo fileInfo, Int returnStatus);

	/**
	 * 撮影
	 * @param fileInfo 撮影した画像ファイル情報
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int takePicture(FileInfo fileInfo, Int returnStatus)
	{
		return takePicture(handle, fileInfo, returnStatus);
	}


	/**
	 * しきい値設定
	 */
	private native int setThreshold(long hHVC, int nBody, int nHand, int nPet, int nFace, int nRecognition, Int returnStatus);

	/**
	 * しきい値設定
	 * @param nBody 人体検出しきい値
	 * @param nHand 手検出しきい値
	 * @param nPet ペット検出しきい値
	 * @param nFace 顔検出しきい値
	 * @param nRecognition 顔認証しきい値
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int setThreshold(int nBody, int nHand, int nPet, int nFace, int nRecognition, Int returnStatus)
	{
		return setThreshold(handle, nBody, nHand, nPet, nFace, nRecognition, returnStatus);
	}

	private native int getThreshold(long hHVC, Int body, Int hand, Int pet, Int face, Int recognition, Int returnStatus);

	/**
	 * しきい値取得
	 * @param body 人体検出しきい値
	 * @param hand 手検出しきい値
	 * @param pet ペット検出しきい値
	 * @param face 顔検出しきい値
	 * @param recognition 顔認証しきい値
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int getThreshold(Int body, Int hand, Int pet, Int face, Int recognition, Int returnStatus)
	{
		return getThreshold(handle, body, hand, pet, face, recognition, returnStatus);
	}

	private native int setSizeRange(long hHVC, int nMinBody, int nMaxBody, int nMinHand, int nMaxHand,
									int nMinPet, int nMaxPet, int nMinFace, int nMaxFace, Int returnStatus);

	/**
	 * 検出サイズ設定
	 * @param nMinBody 人体検出 最小サイズ
	 * @param nMaxBody 人体検出 最大サイズ
	 * @param nMinHand 手検出 最小サイズ
	 * @param nMaxHand 手検出 最大サイズ
	 * @param nMinPet ペット検出 最小サイズ
	 * @param nMaxPet ペット検出 最大サイズ
	 * @param nMinFace 顔検出 最小サイズ
	 * @param nMaxFace 顔検出 最大サイズ
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int setSizeRange(int nMinBody, int nMaxBody, int nMinHand, int nMaxHand,
									int nMinPet, int nMaxPet, int nMinFace, int nMaxFace, Int returnStatus)
	{
		return setSizeRange(handle, nMinBody, nMaxBody, nMinHand, nMaxHand,
									nMinPet, nMaxPet, nMinFace, nMaxFace, returnStatus);
	}

	private native int getSizeRange(long hHVC, Int minBody, Int maxBody, Int minHand, Int maxHand,
									Int minPet, Int maxPet, Int minFace, Int maxFace, Int returnStatus);

	/**
	 * 検出サイズ設定
	 * @param minBody 人体検出 最小サイズ
	 * @param maxBody 人体検出 最大サイズ
	 * @param minHand 手検出 最小サイズ
	 * @param maxHand 手検出 最大サイズ
	 * @param minPet ペット検出 最小サイズ
	 * @param maxPet ペット検出 最大サイズ
	 * @param minFace 顔検出 最小サイズ
	 * @param maxFace 顔検出 最大サイズ
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int getSizeRange(Int minBody, Int maxBody, Int minHand, Int maxHand,
									Int minPet, Int maxPet, Int minFace, Int maxFace, Int returnStatus)
	{
		return getSizeRange(handle, minBody, maxBody, minHand, maxHand,
									minPet, maxPet, minFace, maxFace, returnStatus);
	}

	private native int setDetectionAngle(long hHVC, int nBody, int nHand, int nPet, int nFacePose, int nFaceAngle, Int returnStatus);

	/**
	 * 検出角度設定
	 * @param nBody 人体検出角度
	 * @param nHand 手検出角度
	 * @param nPet ペット検出角度
	 * @param nFacePose 顔検出方向
	 * @param nFaceAngle 顔検出角度
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int setDetectionAngle(int nBody, int nHand, int nPet, int nFacePose, int nFaceAngle, Int returnStatus)
	{
		return setDetectionAngle(handle, nBody, nHand, nPet, nFacePose, nFaceAngle, returnStatus);
	}

	private native int getDetectionAngle(long hHVC, Int body, Int hand, Int pet, Int facePose, Int faceAngle, Int returnStatus);

	/**
	 * 検出角度取得
	 * @param body 人体検出角度
	 * @param hand 手検出角度
	 * @param pet ペット検出角度
	 * @param facePose 顔検出方向
	 * @param faceAngle 顔検出角度
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int getDetectionAngle(Int body, Int hand, Int pet, Int facePose, Int faceAngle, Int returnStatus)
	{
		return getDetectionAngle(handle, body, hand, pet, facePose, faceAngle, returnStatus);
	}

	private native int okaoExecute(long hHVC, int[] aBooleanUseFunction, OkaoResult result, Int returnStatus);

	/**
	 * OKAO実行
	 * @param aBooleanUseFunction 実行機能フラグ
	 * @param result 実行結果
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int okaoExecute(int[] aBooleanUseFunction, OkaoResult result, Int returnStatus)
	{
		return okaoExecute(handle, aBooleanUseFunction, result, returnStatus);
	}

	private native int albumRegister(long hHVC, int nUserID, int nDataID, ResultDetection faceResult, FileInfo fileInfo, Int returnStatus);

	/**
	 * アルバム登録
	 * @param nUserID ユーザID
	 * @param nDataID データID
	 * @param faceResult 顔検出結果
	 * @param fileInfo 登録した画像のファイル情報
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int albumRegister(int nUserID, int nDataID, ResultDetection faceResult, FileInfo fileInfo, Int returnStatus)
	{
		return albumRegister(handle, nUserID, nDataID, faceResult, fileInfo, returnStatus);
	}

	private native int albumSetUserName(long hHVC, int nUserID, String stName, Int returnStatus);

	/**
	 * アルバム登録者名変更
	 * @param nUserID ユーザID
	 * @param stName 登録者名
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int albumSetUserName(int nUserID, String stName, Int returnStatus)
	{
		return albumSetUserName(handle, nUserID, stName, returnStatus);
	}

	private native int albumGetUserName(long hHVC, int nUserID, StringBuffer sbName, Int returnStatus);

	/**
	 * アルバム登録者名取得
	 * @param nUserID ユーザID
	 * @param sbName 登録者名
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int albumGetUserName(int nUserID, StringBuffer sbName, Int returnStatus)
	{
		return albumGetUserName(handle, nUserID, sbName, returnStatus);
	}

	private native int albumDeleteData(long hHVC, int nUserID, int nDataID, Int returnStatus);

	/**
	 * アルバム登録データ削除
	 * @param nUserID ユーザID
	 * @param nDataID データID
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int albumDeleteData(int nUserID, int nDataID, Int returnStatus)
	{
		return albumDeleteData(handle, nUserID, nDataID, returnStatus);
	}

	private native int albumDeleteAllData(long hHVC, Int returnStatus);

	/**
	 * 全ての登録情報をクリア
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int albumDeleteAllData(Int returnStatus)
	{
		return albumDeleteAllData(handle, returnStatus);
	}

	private native int albumGetRegistrationStatus(long hHVC, int nUserID, int[] aBooleanExist, Int returnStatus);

	/**
	 * アルバム登録状態取得
	 * @param nUserID ユーザID
	 * @param aBooleanExist 登録状態フラグ
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int albumGetRegistrationStatus(int nUserID, int[] aBooleanExist, Int returnStatus)
	{
		return albumGetRegistrationStatus(handle, nUserID, aBooleanExist, returnStatus);
	}

	private native int albumGetSize(long hHVC, Int nAlbumSize, Int returnStatus);

	/**
	 * アルバムサイズ取得
	 * @param nAlbumSize アルバムサイズ
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int albumGetSize(Int nAlbumSize, Int returnStatus)
	{
		return albumGetSize(handle, nAlbumSize, returnStatus);
	}

	private native int albumDownload(long hHVC, byte[] byAlbum, Int returnStatus);

	/**
	 * アルバムのダウンロード
	 * @param byAlbum アルバム
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int albumDownload(byte[] byAlbum, Int returnStatus)
	{
		return albumDownload(handle, byAlbum, returnStatus);
	}

	private native int albumUpload(long hHVC, int nAlbumSize, byte[] byAlbum, Int returnStatus);

	/**
	 * アルバムのアップロード
	 * @param nAlbumSize アルバムサイズ
	 * @param byAlbum アルバム
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int albumUpload(int nAlbumSize, byte[] byAlbum, Int returnStatus)
	{
		return albumUpload(handle, nAlbumSize, byAlbum, returnStatus);
	}

	private native int albumSave(long hHVC, Int returnStatus);

	/**
	 * アルバムのFlash書き込み
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int albumSave(Int returnStatus)
	{
		return albumSave(handle, returnStatus);
	}

	private native int setScheduler(long hHVC, int nSchedulerType, int booleanEnable, ScheduleInfo schedule, Int returnStatus);

	/**
	 * スケジュール設定
	 * @param nSchedulerType スケジュールタイプ
	 * @param booleanEnable イベントタイプ
	 * @param schedule スケジュール
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int setScheduler(int nSchedulerType, int booleanEnable, ScheduleInfo schedule, Int returnStatus)
	{
		return setScheduler(handle, nSchedulerType, booleanEnable, schedule, returnStatus);
	}

	private native int getScheduler(long hHVC, int nSchedulerType, Int booleanEnable, ScheduleInfo schedule, Int returnStatus);

	/**
	 * スケジュール取得
	 * @param nSchedulerType スケジュールタイプ
	 * @param booleanEnable イベントタイプ
	 * @param schedule スケジュール
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int getScheduler(int nSchedulerType, Int booleanEnable, ScheduleInfo schedule, Int returnStatus)
	{
		return getScheduler(handle, nSchedulerType, booleanEnable, schedule, returnStatus);
	}

	private native int setSoundEventProgram(long hHVC, int booleanEnable, EventProgramSound eventProgram, Int returnStatus);

	/**
	 * 音声検知イベントプログラム設定
	 * @param booleanEnable イベント有効フラグ
	 * @param eventProgram イベントプログラム
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int setSoundEventProgram(int booleanEnable, EventProgramSound eventProgram, Int returnStatus)
	{
		return setSoundEventProgram(handle, booleanEnable, eventProgram, returnStatus);
	}

	private native int setMotionEventProgram(long hHVC, int booleanEnable, int nIndex, EventProgramMotion eventProgram, Int returnStatus);

	/**
	 * 動体検知イベントプログラム設定
	 * @param booleanEnable イベント有効フラグ
	 * @param nIndex インデックス
	 * @param eventProgram イベントプログラム
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int setMotionEventProgram(int booleanEnable, int nIndex, EventProgramMotion eventProgram, Int returnStatus)
	{
		return setMotionEventProgram(handle, booleanEnable, nIndex, eventProgram, returnStatus);
	}

	private native int setTimerEventProgram(long hHVC, int booleanEnable, EventProgramTimer eventProgram, Int returnStatus);

	/**
	 * タイマーイベントプログラム設定
	 * @param booleanEnable イベント有効フラグ
	 * @param eventProgram イベントプログラム
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int setTimerEventProgram(int booleanEnable, EventProgramTimer eventProgram, Int returnStatus)
	{
		return setTimerEventProgram(handle, booleanEnable, eventProgram, returnStatus);
	}

	private native int getSoundEventProgram(long hHVC, Int booleanEnable, EventProgramSound eventProgram, Int returnStatus);

	/**
	 * 音声検知イベントプログラム取得
	 * @param booleanEnable イベント有効フラグ
	 * @param eventProgram イベントプログラム
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int getSoundEventProgram(Int booleanEnable, EventProgramSound eventProgram, Int returnStatus)
	{
		return getSoundEventProgram(handle, booleanEnable, eventProgram, returnStatus);
	}

	private native int getMotionEventProgram(long hHVC, Int booleanEnable, int nIndex, EventProgramMotion eventProgram, Int returnStatus);

	/**
	 * 動体検知イベントプログラム取得
	 * @param booleanEnable イベント有効フラグ
	 * @param nIndex インデックス
	 * @param eventProgram イベントプログラム
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int getMotionEventProgram(Int booleanEnable, int nIndex, EventProgramMotion eventProgram, Int returnStatus)
	{
		return getMotionEventProgram(handle, booleanEnable, nIndex, eventProgram, returnStatus);
	}

	private native int getTimerEventProgram(long hHVC, Int booleanEnable, EventProgramTimer eventProgram, Int returnStatus);

	/**
	 * タイマーイベントプログラム取得
	 * @param booleanEnable イベント有効フラグ
	 * @param eventProgram イベントプログラム
	 * @param returnStatus コマンドステータス
	 * @return エラーコード
	 */
	public int getTimerEventProgram(Int booleanEnable, EventProgramTimer eventProgram, Int returnStatus)
	{
		return getTimerEventProgram(handle, booleanEnable, eventProgram, returnStatus);
	}
}
