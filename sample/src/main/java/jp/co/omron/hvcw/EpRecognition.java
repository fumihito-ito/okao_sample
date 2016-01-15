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
 * 顔認証イベントパラメータ
 */
public final class EpRecognition
{
	/** 実行フラグ */
	private int booleanEnable;

	/**
	 * コンストラクタ
	 */
	public EpRecognition()
	{
		this.booleanEnable = 0;
	}

	/**
	 * コンストラクタ
	 * @param booleanEnable 実行フラグ
	 */
	public EpRecognition(int booleanEnable)
	{
		this.booleanEnable = booleanEnable;
	}

	/**
	 * 実行フラグの取得
	 * @return 実行フラグ
	 */
	public int getEnable()
	{
		return this.booleanEnable;
	}

	/**
	 * 実行フラグの設定
	 * @param booleanEnable 実行フラグ
	 */
	public void setEnable(int booleanEnable)
	{
		this.booleanEnable = booleanEnable;
	}
}
