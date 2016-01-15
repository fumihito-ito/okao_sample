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
 * ポスト処理
 */
public final class EpPostProcess
{
	/** ログ保存フラグ */
	private int            nSaveLog;
	/** 画像保存フラグ */
	private int            nSaveImage;
	/** 通知設定 */
	private EpNotification notification;

	/**
	 * コンストラクタ
	 */
	public EpPostProcess()
	{
		this.nSaveLog     = 0;
		this.nSaveImage   = 0;
		this.notification = new EpNotification();
	}

	/**
	 * コンストラクタ
	 * @param nSaveLog ログ保存フラグ
	 * @param nSaveImage 画像保存フラグ
	 * @param notification 通知設定
	 */
	public EpPostProcess(int nSaveLog, int nSaveImage, EpNotification notification)
	{
		this.nSaveLog     = nSaveLog;
		this.nSaveImage   = nSaveImage;
		this.notification = new EpNotification(notification.getEpPushAlert(), notification.getEpSound());
	}

	/**
	 * ログ保存フラグの取得
	 * @return ログ保存フラグ
	 */
	public int getSaveLog()
	{
		return this.nSaveLog;
	}

	/**
	 * 画像保存フラグの取得
	 * @return 画像保存フラグ
	 */
	public int getSaveImage()
	{
		return this.nSaveImage;
	}

	/**
	 * 通知設定の取得
	 * @return 通知設定
	 */
	public EpNotification getEpNotification()
	{
		return this.notification;
	}

	/**
	 * ログ保存フラグの設定
	 * @param nSaveLog ログ保存フラグ
	 */
	public void setSaveLog(int nSaveLog)
	{
		this.nSaveLog = nSaveLog;
	}

	/**
	 * 画像保存フラグの設定
	 * @param nSaveImage 画像保存フラグ
	 */
	public void setSaveImage(int nSaveImage)
	{
		this.nSaveImage = nSaveImage;
	}

	/**
	 * 通知設定の設定
	 * @param notification 通知設定
	 */
	public void setEpNotification(EpNotification notification)
	{
		this.notification = new EpNotification(notification.getEpPushAlert(), notification.getEpSound());
	}
}
