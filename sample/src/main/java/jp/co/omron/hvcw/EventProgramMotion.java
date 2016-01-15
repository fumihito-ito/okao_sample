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
 * 動体検知イベントプログラム
 */
public final class EventProgramMotion
{
	/** 動体検知イベント設定 */
	private EpMotionEvent   motionEvent;
	/** OKAO処理設定 */
	private EpOkaoProcess   okaoProcess;
	/** 通知処理設定 */
	private EpPostProcess   postProcess;
	/** 顔認証専用通知処理設定 */
	private EpFrPostProcess frPostProcess;

	/**
	 * コンストラクタ
	 */
	public EventProgramMotion()
	{
		this.motionEvent   = new EpMotionEvent();
		this.okaoProcess   = new EpOkaoProcess();
		this.postProcess   = new EpPostProcess();
		this.frPostProcess = new EpFrPostProcess();
	}

	/**
	 * コンストラクタ
	 * @param motionEvent 動体検知イベント設定
	 * @param okaoProcess OKAO処理設定
	 * @param postProcess 通知処理設定
	 * @param frPostProcess 顔認証専用通知処理設定
	 */
	public EventProgramMotion(EpMotionEvent motionEvent, EpOkaoProcess okaoProcess,
							EpPostProcess postProcess, EpFrPostProcess frPostProcess)
	{
		this.motionEvent   = new EpMotionEvent(motionEvent.getRect(), motionEvent.getSensitivity(),
												motionEvent.getDuration(), motionEvent.getRatio(), motionEvent.getOffPeriod());
		this.okaoProcess   = new EpOkaoProcess(okaoProcess.getEpBody(), okaoProcess.getEpPet(),
												okaoProcess.getEpFace(), okaoProcess.getEpAge(),
												okaoProcess.getEpGender(), okaoProcess.getEpExpression(), okaoProcess.getEpRecognition());
		this.postProcess   = new EpPostProcess(postProcess.getSaveLog(), postProcess.getSaveImage(), postProcess.getEpNotification());
		this.frPostProcess = new EpFrPostProcess(frPostProcess.getSaveImage(), frPostProcess.getEpFrNotification());
	}

	/**
	 * 動体検知イベント設定の取得
	 * @return 動体検知イベント設定
	 */
	public EpMotionEvent getEpMotionEvent()
	{
		return this.motionEvent;
	}

	/**
	 * OKAO処理設定の取得
	 * @return OKAO処理設定
	 */
	public EpOkaoProcess getEpOkaoProcess()
	{
		return this.okaoProcess;
	}

	/**
	 * 通知処理設定の取得
	 * @return 通知処理設定
	 */
	public EpPostProcess getEpPostProcess()
	{
		return this.postProcess;
	}

	/**
	 * 顔認証専用通知処理設定の取得
	 * @return 顔認証専用通知処理設定
	 */
	public EpFrPostProcess getEpFrPostProcess()
	{
		return this.frPostProcess;
	}

	/**
	 * 動体検知イベント設定の設定
	 * @param motionEvent 動体検知イベント設定
	 */
	public void setEpMotionEvent(EpMotionEvent motionEvent)
	{
		this.motionEvent = new EpMotionEvent(motionEvent.getRect(), motionEvent.getSensitivity(),
												motionEvent.getDuration(), motionEvent.getRatio(), motionEvent.getOffPeriod());
	}

	/**
	 * OKAO処理設定の設定
	 * @param okaoProcess OKAO処理設定
	 */
	public void setEpOkaoProcess(EpOkaoProcess okaoProcess)
	{
		this.okaoProcess = new EpOkaoProcess(okaoProcess.getEpBody(), okaoProcess.getEpPet(),
												okaoProcess.getEpFace(), okaoProcess.getEpAge(),
												okaoProcess.getEpGender(), okaoProcess.getEpExpression(), okaoProcess.getEpRecognition());
	}

	/**
	 * 通知処理設定の設定
	 * @param postProcess 通知処理設定
	 */
	public void setEpPostProcess(EpPostProcess postProcess)
	{
		this.postProcess = new EpPostProcess(postProcess.getSaveLog(), postProcess.getSaveImage(), postProcess.getEpNotification());
	}

	/**
	 * 顔認証専用通知処理設定の設定
	 * @param frPostProcess 顔認証専用通知処理設定
	 */
	public void setEpFrPostProcess(EpFrPostProcess frPostProcess)
	{
		this.frPostProcess = new EpFrPostProcess(frPostProcess.getSaveImage(), frPostProcess.getEpFrNotification());
	}
}
