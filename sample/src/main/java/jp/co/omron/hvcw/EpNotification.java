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
 * 通知設定
 */
public final class EpNotification
{
	/** プッシュ通知設定 */
	private EpPushAlert pushAlert;
	/** 音声出力設定 */
	private EpSound     sound;

	/**
	 * コンストラクタ
	 */
	public EpNotification()
	{
		this.pushAlert = new EpPushAlert();
		this.sound     = new EpSound();
	}

	/**
	 * コンストラクタ
	 * @param pushAlert プッシュ通知設定
	 * @param sound 音声出力設定
	 */
	public EpNotification(EpPushAlert pushAlert, EpSound sound)
	{
		this.pushAlert = new EpPushAlert(pushAlert.getEnable(), pushAlert.getFileInfo());
		this.sound     = new EpSound(sound.getEnable(), sound.getFileInfo());
	}

	/**
	 * プッシュ通知設定の取得
	 * @return プッシュ通知設定
	 */
	public EpPushAlert getEpPushAlert()
	{
		return this.pushAlert;
	}

	/**
	 * 音声出力設定の取得
	 * @return 音声出力設定
	 */
	public EpSound getEpSound()
	{
		return this.sound;
	}

	/**
	 * プッシュ通知設定の設定
	 * @param pushAlert プッシュ通知設定
	 */
	public void setEpPushAlert(EpPushAlert pushAlert)
	{
		this.pushAlert = new EpPushAlert(pushAlert.getEnable(), pushAlert.getFileInfo());
	}

	/**
	 * 音声出力設定の設定
	 * @param sound 音声出力設定
	 */
	public void setEpSound(EpSound sound)
	{
		this.sound = new EpSound(sound.getEnable(), sound.getFileInfo());
	}
}
