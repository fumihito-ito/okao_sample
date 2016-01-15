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
 * 性別推定イベントパラメータ
 */
public final class EpGender
{
	/** 実行フラグ */
	private int booleanEnable;
	/** 性別の判定値 */
	private int nGender;
	/** 信頼度しきい値 */
	private int nConfidence;

	/**
	 * コンストラクタ
	 */
	public EpGender()
	{
		this.booleanEnable = 0;
		this.nGender       = 0;
		this.nConfidence   = 0;
	}

	/**
	 * コンストラクタ
	 * @param booleanEnable 実行フラグ
	 * @param nGender 性別の判定値
	 * @param nConfidence 信頼度しきい値
	 */
	public EpGender(int booleanEnable, int nGender, int nConfidence)
	{
		this.booleanEnable = booleanEnable;
		this.nGender       = nGender;
		this.nConfidence   = nConfidence;
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
	 * 性別の判定値の取得
	 * @return 性別の判定値
	 */
	public int getGender()
	{
		return this.nGender;
	}

	/**
	 * 信頼度しきい値の取得
	 * @return 信頼度しきい値
	 */
	public int getConfidence()
	{
		return this.nConfidence;
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
	 * 性別の判定値の設定
	 * @param nGender 性別の判定値
	 */
	public void setGender(int nGender)
	{
		this.nGender = nGender;
	}

	/**
	 * 信頼度しきい値の設定
	 * @param nConfidence 信頼度しきい値
	 */
	public void setConfidence(int nConfidence)
	{
		this.nConfidence = nConfidence;
	}
}
