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
 * 座標点
 */
public final class Point
{
	/** X座標 */
	private int x;
	/** Y座標 */
	private int y;

	/**
	 * コンストラクタ
	 */
	public Point()
	{
		x = 0;
		y = 0;
	}

	/**
	 * コンストラクタ
	 * @param nX X座標
	 * @param nY Y座標
	 */
	public Point(int nX, int nY)
	{
		x = nX;
		y = nY;
	}

	/**
	 * X座標の取得
	 * @return X座標
	 */
	public int getX()
	{
		return this.x;
	}

	/**
	 * Y座標の設定
	 * @return Y座標
	 */
	public int getY()
	{
		return this.y;
	}

	/**
	 * X座標の設定
	 * @param nX X座標
	 */
	public void setX(int nX)
	{
		this.x = nX;
	}

	/**
	 * Y座標
	 * @param nY Y座標
	 */
	public void setY(int nY)
	{
		this.y = nY;
	}
}
