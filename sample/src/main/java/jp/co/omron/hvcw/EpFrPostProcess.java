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
 * 顔認証ポスト処理
 */
public final class EpFrPostProcess
{
	/** 画像保存フラグ */
	private int              nSaveImage;
	/** 顔認証通知設定 */
	private EpFrNotification notification;

	/**
	 * コンストラクタ
	 */
	public EpFrPostProcess()
	{
		this.nSaveImage   = 0;
		this.notification = new EpFrNotification();
	}

	/**
	 * コンストラクタ
	 * @param nSaveImage 画像保存フラグ
	 * @param notification 顔認証通知設定
	 */
	public EpFrPostProcess(int nSaveImage, EpFrNotification notification)
	{
		this.nSaveImage   = nSaveImage;
		this.notification = new EpFrNotification(notification.getEpFrPushAlert(), notification.getEpFrSound());
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
	 * 顔認証通知設定の取得
	 * @return 顔認証通知設定
	 */
	public EpFrNotification getEpFrNotification()
	{
		return this.notification;
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
	 * 顔認証通知設定の設定
	 * @param notification 顔認証通知設定
	 */
	public void setEpFrNotification(EpFrNotification notification)
	{
		this.notification = new EpFrNotification(notification.getEpFrPushAlert(), notification.getEpFrSound());
	}
}
