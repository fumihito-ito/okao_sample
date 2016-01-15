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
 * ペット検出イベントパラメータ
 */
public final class EpPet
{
	/** 実行フラグ */
	private int booleanEnable;
	/** 検出数の判定値 */
	private int nCount;

	/**
	 * コンストラクタ
	 */
	public EpPet()
	{
		this.booleanEnable = 0;
		this.nCount        = 0;
	}

	/**
	 * コンストラクタ
	 * @param booleanEnable 実行フラグ
	 * @param nCount 検出数の判定値
	 */
	public EpPet(int booleanEnable, int nCount)
	{
		this.booleanEnable = booleanEnable;
		this.nCount        = nCount;
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
	 * 検出数の判定値の取得
	 * @return 検出数の判定値
	 */
	public int getCount()
	{
		return this.nCount;
	}

	/**
	 * 実行フラグの設定
	 * @param booleanEnable 実行フラグ
	 */
	public void setEnable(int booleanEnable)
	{
		this.booleanEnable = booleanEnable;
	}

	/**
	 * 検出数の判定値の設定
	 * @param nCount 検出数の判定値
	 */
	public void setCount(int nCount)
	{
		this.nCount = nCount;
	}
}
