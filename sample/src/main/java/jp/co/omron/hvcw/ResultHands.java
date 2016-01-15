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
 * 手検出結果
 */
public final class ResultHands
{
	/** 検出数 */
	private int nCount;
	/** 検出結果 */
	private ResultDetection[] hand;

	/**
	 * コンストラクタ
	 */
	public ResultHands()
	{
		this.nCount = 0;
		this.hand   = new ResultDetection[35];
		for(int i=0; i<hand.length; i++)
		{
			this.hand[i] = new ResultDetection();
		}
	}

	/**
	 * コンストラクタ
	 * @param nCount 検出数
	 * @param hand 検出結果
	 */
	public ResultHands(int nCount, ResultDetection[] hand)
	{
		this.nCount = nCount;
		this.hand   = new ResultDetection[35];
		for(int i=0; i<this.hand.length; i++)
		{
			this.hand[i] = new ResultDetection(hand[i].getCenter(),
												hand[i].getSize(),
												hand[i].getConfidence());
		}
	}

	/**
	 * 検出集の取得
	 * @return 検出集
	 */
	public int getCount()
	{
		return this.nCount;
	}

	/**
	 * 検出結果の取得
	 * @return 検出結果
	 */
	public ResultDetection[] getResultDetection()
	{
		return this.hand;
	}

	/**
	 * 検出集の設定
	 * @param nCount 検出集
	 */
	public void setCount(int nCount)
	{
		this.nCount = nCount;
	}

	/**
	 * 検出結果の設定
	 * @param hand 検出結果
	 */
	public void setResultDetection(ResultDetection[] hand)
	{
		this.hand = new ResultDetection[35];
		for(int i=0; i<this.hand.length; i++)
		{
			this.hand[i] = new ResultDetection(hand[i].getCenter(),
												hand[i].getSize(),
												hand[i].getConfidence());
		}
	}
}
