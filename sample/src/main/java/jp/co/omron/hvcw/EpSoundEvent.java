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
 * 音声検知イベント
 */
public final class EpSoundEvent
{
	/** 感度 */
	private int nSensitivity;
	/** 判定時間 */
	private int nDuration;
	/** 判定割合 */
	private int nRatio;
	/** イベントのインターバル */
	private int nOffPeriod;

	/**
	 * コンストラクタ
	 */
	public EpSoundEvent()
	{
		this.nSensitivity = 0;
		this.nDuration    = 0;
		this.nRatio       = 0;
		this.nOffPeriod   = 0;
	}

	/**
	 * コンストラクタ
	 * @param nSensitivity 感度
	 * @param nDuration 判定時間
	 * @param nRatio 判定割合
	 * @param nOffPeriod イベントのインターバル
	 */
	public EpSoundEvent(int nSensitivity, int nDuration, int nRatio, int nOffPeriod)
	{
		this.nSensitivity = nSensitivity;
		this.nDuration    = nDuration;
		this.nRatio       = nRatio;
		this.nOffPeriod   = nOffPeriod;
	}

	/**
	 * 感度の取得
	 * @return 感度
	 */
	public int getSensitivity()
	{
		return this.nSensitivity;
	}

	/**
	 * 判定時間の取得
	 * @return 判定時間
	 */
	public int getDuration()
	{
		return this.nDuration;
	}

	/**
	 * 判定割合の取得
	 * @return 判定割合
	 */
	public int getRatio()
	{
		return this.nRatio;
	}

	/**
	 * イベントのインターバルの取得
	 * @return イベントのインターバル
	 */
	public int getOffPeriod()
	{
		return this.nOffPeriod;
	}

	/**
	 * 感度の設定
	 * @param nSensitivity 感度
	 */
	public void setSensitivity(int nSensitivity)
	{
		this.nSensitivity = nSensitivity;
	}

	/**
	 * 判定時間の設定
	 * @param nDuration 判定時間
	 */
	public void setDuration(int nDuration)
	{
		this.nDuration = nDuration;
	}

	/**
	 * 判定割合の設定
	 * @param nRatio 判定割合
	 */
	public void setRatio(int nRatio)
	{
		this.nRatio = nRatio;
	}

	/**
	 * イベントのインターバルの設定
	 * @param nOffPeriod イベントのインターバル
	 */
	public void setOffPeriod(int nOffPeriod)
	{
		this.nOffPeriod = nOffPeriod;
	}
}
