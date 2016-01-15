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
 * タイマーイベント
 */
public final class EpTimerEvent
{
	/** イベントインターバル */
	private int nInterval;

	/**
	 * コンストラクタ
	 */
	public EpTimerEvent()
	{
		this.nInterval = 0;
	}

	/**
	 * コンストラクタ
	 * @param nInterval イベントインターバル
	 */
	public EpTimerEvent(int nInterval)
	{
		this.nInterval = nInterval;
	}

	/**
	 * イベントインターバルの取得
	 * @return イベントインターバル
	 */
	public int getInterval()
	{
		return this.nInterval;
	}

	/**
	 * イベントインターバルの設定
	 * @param nInterval イベントインターバル
	 */
	public void setInterval(int nInterval)
	{
		this.nInterval = nInterval;
	}
}
