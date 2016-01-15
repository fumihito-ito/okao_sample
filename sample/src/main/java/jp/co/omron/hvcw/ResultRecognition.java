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
 * 顔認証結果
 */
public final class ResultRecognition
{
	/** ユーザID */
	private int nUID;
	/** スコア */
	private int nScore;

	/**
	 * コンストラクタ
	 */
	public ResultRecognition()
	{
		this.nUID   = 0;
		this.nScore = 0;
	}

	/**
	 * コンストラクタ
	 * @param nUID ユーザID
	 * @param nScore スコア
	 */
	public ResultRecognition(int nUID, int nScore)
	{
		this.nUID   = nUID;
		this.nScore = nScore;
	}

	/**
	 * ユーザIDの取得
	 * @return ユーザID
	 */
	public int getUID()
	{
		return this.nUID;
	}

	/**
	 * スコアの取得
	 * @return スコア
	 */
	public int getScore()
	{
		return this.nScore;
	}

	/**
	 * ユーザIDの設定
	 * @param nUID ユーザID
	 */
	public void setUID(int nUID)
	{
		this.nUID = nUID;
	}

	/**
	 * スコアの設定
	 * @param nScore スコア
	 */
	public void setScore(int nScore)
	{
		this.nScore = nScore;
	}
}
