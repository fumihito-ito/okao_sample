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
 * 最小値/最大値
 */
public final class Range
{
	/** 最小値 */
	private int nMin;
	/** 最大値 */
	private int nMax;

	/**
	 * コンストラクタ
	 */
	public Range()
	{
		this.nMin = 0;
		this.nMax = 0;
	}

	/**
	 * コンストラクタ
	 * @param nMin 最小値
	 * @param nMax 最大値
	 */
	public Range(int nMin, int nMax)
	{
		this.nMin = nMin;
		this.nMax = nMax;
	}

	/**
	 * 最小値の取得
	 * @return 最小値
	 */
	public int getMin()
	{
		return this.nMin;
	}

	/**
	 * 最大値の取得
	 * @return 最大値
	 */
	public int getMax()
	{
		return this.nMax;
	}

	/**
	 * 最小値の設定
	 * @param nMin 最小値
	 */
	public void setMin(int nMin)
	{
		this.nMin = nMin;
	}

	/**
	 * 最大値
	 * @param nMax 最大値
	 */
	public void setMax(int nMax)
	{
		this.nMax = nMax;
	}
}
