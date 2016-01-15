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
 * 年齢推定結果
 */
public final class ResultAeg
{
	/** 年齢 */
	private int nAge;
	/** 信頼度 */
	private int nConfidence;

	/**
	 * コンストラクタ
	 */
	public ResultAeg()
	{
		this.nAge        = 0;
		this.nConfidence = 0;
	}

	/**
	 * コンストラクタ
	 * @param nAge 年齢
	 * @param nConfidence 信頼度
	 */
	public ResultAeg(int nAge, int nConfidence)
	{
		this.nAge        = nAge;
		this.nConfidence = nConfidence;
	}

	/**
	 * 年齢の取得
	 * @return 年齢
	 */
	public int getAge()
	{
		return this.nAge;
	}

	/**
	 * 信頼度の取得
	 * @return 信頼度
	 */
	public int getConfidence()
	{
		return this.nConfidence;
	}

	/**
	 * 年齢の設定
	 * @param nAge 年齢
	 */
	public void setAge(int nAge)
	{
		this.nAge = nAge;
	}

	/**
	 * 信頼度の設定
	 * @param nConfidence 信頼度
	 */
	public void setConfidence(int nConfidence)
	{
		this.nConfidence = nConfidence;
	}
}
