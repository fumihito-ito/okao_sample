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
  *  符号付き整数型
  */
public final class Int
{
	/** 符号付き整数値 */
	private int value;

	/**
	 * コンストラクタ
	 */
	public Int()
	{
		this.value = 0;
	}

	/**
	 * コンストラクタ
	 * @param value 符号付き整数値
	 */
	public Int(int value)
	{
		this.value = value;
	}

	/**
	 * 符号付き整数値の取得
	 * @return 符号付き整数値
	 */
	public int getIntValue()
	{
		return this.value;
	}

	/**
	 * 符号付き整数の設定
	 * @param value 符号付き整数値
	 */
	public void setIntValue(int value)
	{
		this.value = value;
	}
}
