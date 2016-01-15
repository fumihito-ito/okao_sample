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
 * 性別推定結果
 */
public final class ResultGender
{
	/** 性別 */
	private int nGender;
	/** 信頼度 */
	private int nConfidence;

	/**
	 * コンストラクタ
	 */
	public ResultGender()
	{
		this.nGender     = 0;
		this.nConfidence = 0;
	}

	/**
	 * コンストラクタ
	 * @param nGender 性別
	 * @param nConfidence 信頼度
	 */
	public ResultGender(int nGender, int nConfidence)
	{
		this.nGender     = nGender;
		this.nConfidence = nConfidence;
	}

	/**
	 * 性別の取得
	 * @return 性別
	 */
	public int getGender()
	{
		return this.nGender;
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
	 * 性別の設定
	 * @param nGender 性別
	 */
	public void setGender(int nGender)
	{
		this.nGender = nGender;
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
