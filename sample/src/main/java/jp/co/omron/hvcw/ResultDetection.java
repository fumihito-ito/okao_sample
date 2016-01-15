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
 * 検出結果
 */
public final class ResultDetection
{
	/** 中心座標 */
	private Point ptCenter;
	/** 検出サイズ */
	private int nSize;
	/** 信頼度 */
	private int nConfidence;

	/**
	 * コンストラクタ
	 */
	public ResultDetection()
	{
		this.ptCenter    = new Point();
		this.nSize       = 0;
		this.nConfidence = 0;
	}

	/**
	 * コンストラクタ
	 * @param ptCenter 中心座標
	 * @param nSize 検出サイズ
	 * @param nConfidence 信頼度
	 */
	public ResultDetection(Point ptCenter, int nSize, int nConfidence)
	{
		this.ptCenter    = new Point(ptCenter.getX(), ptCenter.getY());
		this.nSize       = nSize;
		this.nConfidence = nConfidence;
	}

	/**
	 * 中心座標の取得
	 * @return 中心座標
	 */
	public Point getCenter()
	{
		return this.ptCenter;
	}

	/**
	 * 検出サイズの取得
	 * @return 検出サイズ
	 */
	public int getSize()
	{
		return this.nSize;
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
	 * 中心座標の設定
	 * @param ptCenter 中心座標
	 */
	public void setCenter(Point ptCenter)
	{
		this.ptCenter = new Point(ptCenter.getX(), ptCenter.getY());
	}

	/**
	 * 検出サイズの設定
	 * @param nSize 検出サイズ
	 */
	public void setSize(int nSize)
	{
		this.nSize = nSize;
	}

	/**
	 * 信頼度
	 * @param nConfidence 信頼度
	 */
	public void setConfidence(int nConfidence)
	{
		this.nConfidence = nConfidence;
	}
}
