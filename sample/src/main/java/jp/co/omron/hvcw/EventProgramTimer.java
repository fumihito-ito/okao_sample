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
 * タイマーイベントプログラム
 */
public final class EventProgramTimer
{
	/** タイマーイベント設定 */
	private EpTimerEvent    timerEvent;
	/** OKAO処理設定 */
	private EpOkaoProcess   okaoProcess;
	/** 通知処理設定 */
	private EpPostProcess   postProcess;
	/** 顔認証専用通知処理設定 */
	private EpFrPostProcess frPostProcess;

	/**
	 * コンストラクタ
	 */
	public EventProgramTimer()
	{
		this.timerEvent    = new EpTimerEvent();
		this.okaoProcess   = new EpOkaoProcess();
		this.postProcess   = new EpPostProcess();
		this.frPostProcess = new EpFrPostProcess();
	}

	/**
	 * コンストラクタ
	 * @param timerEvent タイマーイベント設定
	 * @param okaoProcess OKAO処理設定
	 * @param postProcess 通知処理設定
	 * @param frPostProcess 顔認証専用通知処理設定
	 */
	public EventProgramTimer(EpTimerEvent timerEvent, EpOkaoProcess okaoProcess,
							EpPostProcess postProcess, EpFrPostProcess frPostProcess)
	{
		this.timerEvent    = new EpTimerEvent(timerEvent.getInterval());
		this.okaoProcess   = new EpOkaoProcess(okaoProcess.getEpBody(), okaoProcess.getEpPet(),
												okaoProcess.getEpFace(), okaoProcess.getEpAge(),
												okaoProcess.getEpGender(), okaoProcess.getEpExpression(), okaoProcess.getEpRecognition());
		this.postProcess   = new EpPostProcess(postProcess.getSaveLog(), postProcess.getSaveImage(), postProcess.getEpNotification());
		this.frPostProcess = new EpFrPostProcess(frPostProcess.getSaveImage(), frPostProcess.getEpFrNotification());
	}

	/**
	 * タイマーイベント設定の取得
	 * @return タイマーイベント設定
	 */
	public EpTimerEvent getEpTimerEvent()
	{
		return this.timerEvent;
	}

	/**
	 * OKAO処理設定の設定
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
	 * タイマーイベント設定の設定
	 * @param timerEvent タイマーイベント設定
	 */
	public void setEpTimerEvent(EpTimerEvent timerEvent)
	{
		this.timerEvent = new EpTimerEvent(timerEvent.getInterval());
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
