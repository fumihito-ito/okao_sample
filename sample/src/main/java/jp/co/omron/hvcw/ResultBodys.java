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
 * 人体検出結果
 */
public final class ResultBodys
{
	/** 検出数 */
	private int nCount;
	/** 検出結果 */
	private ResultDetection[] body;

	/**
	 * コンストラクタ
	 */
	public ResultBodys()
	{
		this.nCount = 0;
		this.body   = new ResultDetection[35];
		for(int i=0; i<body.length; i++)
		{
			this.body[i] = new ResultDetection();
		}
	}

	/**
	 * コンストラクタ
	 * @param nCount 検出数
	 * @param body 検出結果
	 */
	public ResultBodys(int nCount, ResultDetection[] body)
	{
		this.nCount = nCount;
		this.body   = new ResultDetection[35];
		for(int i=0; i<this.body.length; i++)
		{
			this.body[i] = new ResultDetection(body[i].getCenter(),
												body[i].getSize(),
												body[i].getConfidence());
		}
	}

	/**
	 * 検出数の取得
	 * @return 検出数
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
		return this.body;
	}

	/**
	 * 検出数の設定
	 * @param nCount 検出数
	 */
	public void setCount(int nCount)
	{
		this.nCount = nCount;
	}

	/**
	 * 検出結果の設定
	 * @param body 検出結果
	 */
	public void setResultDetection(ResultDetection[] body)
	{
		this.body = new ResultDetection[35];
		for(int i=0; i<this.body.length; i++)
		{
			this.body[i] = new ResultDetection(body[i].getCenter(),
												body[i].getSize(),
												body[i].getConfidence());
		}
	}
}
