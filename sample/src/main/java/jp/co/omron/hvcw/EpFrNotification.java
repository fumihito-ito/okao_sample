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
 * 顔認証通知設定
 */
public final class EpFrNotification
{
	/** プッシュ通知設定 */
	private EpFrPushAlert pushAlert;
	/** 音声出力設定 */
	private EpFrSound     sound;

	/**
	 * コンストラクタ
	 */
	public EpFrNotification()
	{
		this.pushAlert = new EpFrPushAlert();
		this.sound     = new EpFrSound();
	}

	/**
	 * コンストラクタ
	 * @param pushAlert プッシュ通知設定
	 * @param sound 音声出力設定
	 */
	public EpFrNotification(EpFrPushAlert pushAlert, EpFrSound sound)
	{
		this.pushAlert = new EpFrPushAlert(pushAlert.getEpKnownuser(), pushAlert.getEpPushAlert());
		this.sound     = new EpFrSound(sound.getEpKnownuser(), sound.getEpSound());
	}

	/**
	 * プッシュ通知設定の取得
	 * @return プッシュ通知設定
	 */
	public EpFrPushAlert getEpFrPushAlert()
	{
		return this.pushAlert;
	}

	/**
	 * 音声出力設定の取得
	 * @return 音声出力設定
	 */
	public EpFrSound getEpFrSound()
	{
		return this.sound;
	}

	/**
	 * プッシュ通知設定の設定
	 * @param pushAlert プッシュ通知設定
	 */
	public void setEpFrPushAlert(EpFrPushAlert pushAlert)
	{
		this.pushAlert = new EpFrPushAlert(pushAlert.getEpKnownuser(), pushAlert.getEpPushAlert());
	}

	/**
	 * 音声出力設定の設定
	 * @param sound 音声出力設定
	 */
	public void setEpFrSound(EpFrSound sound)
	{
		this.sound = new EpFrSound(sound.getEpKnownuser(), sound.getEpSound());
	}
}
