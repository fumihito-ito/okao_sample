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
 * 年齢推定イベントパラメータ
 */
public final class EpAge
{
	/** 実行フラグ */
	private int   booleanEnable;
	/** 年齢の判定値 */
	private Range ageRange;
	/** 信頼度しきい値 */
	private int   nConfidence;

	/**
	 * コンストラクタ
	 */
	public EpAge()
	{
		this.booleanEnable = 0;
		this.ageRange      = new Range();
		this.nConfidence   = 0;
	}

	/**
	 * コンストラクタ
	 * @param booleanEnable 実行フラグ
	 * @param ageRange 年齢の判定値
	 * @param nConfidence 信頼度しきい値
	 */
	public EpAge(int booleanEnable, Range ageRange, int nConfidence)
	{
		this.booleanEnable = booleanEnable;
		this.ageRange      = new Range(ageRange.getMin(), ageRange.getMax());
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
	 * 年齢の判定値の取得
	 * @return 年齢の判定値
	 */
	public Range getRange()
	{
		return this.ageRange;
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
	 * 年齢の判定値の設定
	 * @param ageRange 年齢の判定値
	 */
	public void setRange(Range ageRange)
	{
		this.ageRange = new Range(ageRange.getMin(), ageRange.getMax());
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
