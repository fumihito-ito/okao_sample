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
 * 矩形
 */
public final class Rect
{
	/** 左上x座標 */
	private int x;
	/** 左上y座標 */
	private int y;
	/** 幅 */
	private int width;
	/** 高さ */
	private int height;

	/**
	 * コンストラクタ
	 */
	public Rect()
	{
		this.x      = 0;
		this.y      = 0;
		this.width  = 0;
		this.height = 0;
	}

	/**
	 * コンストラクタ
	 * @param nX 左上x座標
	 * @param nY 左上y座標
	 * @param nWidth 幅
	 * @param nHeight 高さ
	 */
	public Rect(int nX, int nY, int nWidth, int nHeight)
	{
		this.x      = nX;
		this.y      = nY;
		this.width  = nWidth;
		this.height = nHeight;
	}

	/**
	 * 左上x座標の取得
	 * @return 左上x座標
	 */
	public int getX()
	{
		return this.x;
	}

	/**
	 * 左上y座標の取得
	 * @return 左上y座標
	 */
	public int getY()
	{
		return this.y;
	}

	/**
	 * 幅の取得
	 * @return 幅
	 */
	public int getWidth()
	{
		return this.width;
	}

	/**
	 * 高さの取得
	 * @return 高さ
	 */
	public int getHeight()
	{
		return this.height;
	}

	/**
	 * 左上x座標の設定
	 * @param nX 左上x座標
	 */
	public void setX(int nX)
	{
		this.x = nX;
	}

	/**
	 * 左上y座標の設定
	 * @param nY 左上y座標
	 */
	public void setY(int nY)
	{
		this.y = nY;
	}

	/**
	 * 幅の設定
	 * @param nWidth 幅
	 */
	public void setWidth(int nWidth)
	{
		this.width = nWidth;
	}

	/**
	 * 高さの設定
	 * @param nHeight 高さ
	 */
	public void setHeight(int nHeight)
	{
		this.height = nHeight;
	}
}
