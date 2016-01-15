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

import java.util.Arrays;

/**
 * 表情推定結果
 */
public final class ResultExpression
{
	/** 表情ごとのスコア */
	private int[] anScore;
	/** ネガティブ/ポジティブ度合 */
	private int nDegree;

	/**
	 * コンストラクタ
	 */
	public ResultExpression()
	{
		this.anScore = new int[HvcwApi.HVCW_Expression_Max];
		this.nDegree = 0;
	}

	/**
	 * コンストラクタ
	 * @param anScore 表情ごとのスコア
	 * @param nDegree ネガティブ/ポジティブ度合
	 */
	public ResultExpression(int[] anScore, int nDegree)
	{
		this.anScore = Arrays.copyOf(anScore, anScore.length);
		this.nDegree = nDegree;
	}

	/**
	 * 表情ごとのスコアの取得
	 * @return 表情ごとのスコア
	 */
	public int[] getScore()
	{
		return this.anScore;
	}

	/**
	 * ネガティブ/ポジティブ度合の取得
	 * @return ネガティブ/ポジティブ度合
	 */
	public int getDegree()
	{
		return this.nDegree;
	}

	/**
	 * 表情ごとのスコアの設定
	 * @param anScore 表情ごとのスコア
	 */
	public void setScore(int[] anScore)
	{
		this.anScore = Arrays.copyOf(anScore, anScore.length);
	}

	/**
	 * ネガティブ/ポジティブ度合の設定
	 * @param nDegree ネガティブ/ポジティブ度合
	 */
	public void setDegree(int nDegree)
	{
		this.nDegree = nDegree;
	}
}
