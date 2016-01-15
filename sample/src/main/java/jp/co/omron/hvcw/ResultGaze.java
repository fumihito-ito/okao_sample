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
 * 視線推定結果
 */
public final class ResultGaze
{
	/** 左右 */
	private int nLR;
	/** 上下 */
	private int nUD;

	/**
	 * コンストラクタ
	 */
	public ResultGaze()
	{
		this.nLR = 0;
		this.nUD = 0;
	}

	/**
	 * コンストラクタ
	 * @param nLR 左右
	 * @param nUD 上下
	 */
	public ResultGaze(int nLR, int nUD)
	{
		this.nLR = nLR;
		this.nUD = nUD;
	}

	/**
	 * 左右の取得
	 * @return 左右
	 */
	public int getLR()
	{
		return this.nLR;
	}

	/**
	 * 上下の取得
	 * @return 上下
	 */
	public int getUD()
	{
		return this.nUD;
	}

	/**
	 * 左右の設定
	 * @param nLR 左右
	 */
	public void setLR(int nLR)
	{
		this.nLR = nLR;
	}

	/**
	 * 上下の設定
	 * @param nUD 上下
	 */
	public void setUD(int nUD)
	{
		this.nUD = nUD;
	}
}
