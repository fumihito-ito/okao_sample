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
 * 表情推定イベントパラメータ
 */
public final class EpExpression
{
	/** 実行フラグ */
	private int   booleanEnable;
	/** 表情の判定 */
	private int   nExpression;
	/** スコアの判定しきい値 */
	private int   nScore;
	/** ネガポジの判定値 */
	private Range degreeRange;

	/**
	 * コンストラクタ
	 */
	public EpExpression()
	{
		this.booleanEnable = 0;
		this.nExpression   = 0;
		this.nScore        = 0;
		this.degreeRange   = new Range();
	}

	/**
	 * コンストラクタ
	 * @param booleanEnable 実行フラグ
	 * @param nExpression 表情の判定
	 * @param nScore スコアの判定しきい値
	 * @param degreeRange ネガポジの判定値
	 */
	public EpExpression(int booleanEnable, int nExpression, int nScore, Range degreeRange)
	{
		this.booleanEnable = booleanEnable;
		this.nExpression   = nExpression;
		this.nScore        = nScore;
		this.degreeRange   = new Range(degreeRange.getMin(), degreeRange.getMax());
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
	 * 表情の判定の取得
	 * @return 表情の判定
	 */
	public int getExpression()
	{
		return this.nExpression;
	}

	/**
	 * スコアの判定しきい値の取得
	 * @return スコアの判定しきい値
	 */
	public int getScore()
	{
		return this.nScore;
	}

	/**
	 * ネガポジの判定値の取得
	 * @return ネガポジの判定値
	 */
	public Range getRange()
	{
		return this.degreeRange;
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
	 * 表情の判定の設定
	 * @param nExpression 表情の判定
	 */
	public void setExpression(int nExpression)
	{
		this.nExpression = nExpression;
	}

	/**
	 * スコアの判定しきい値の設定
	 * @param nScore スコアの判定しきい値
	 */
	public void setScore(int nScore)
	{
		this.nScore = nScore;
	}

	/**
	 * ネガポジの判定値の設定
	 * @param degreeRange ネガポジの判定値
	 */
	public void setRange(Range degreeRange)
	{
		this.degreeRange = new Range(degreeRange.getMin(), degreeRange.getMax());
	}
}
