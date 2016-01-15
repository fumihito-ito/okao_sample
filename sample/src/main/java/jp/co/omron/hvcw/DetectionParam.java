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
 * 動体検知パラメータ
 */
public final class DetectionParam
{
	/** 矩形 */
	private Rect rect;
	/** 感度 */
	private int  sensitivity;


	/**
	 * コンストラクタ
	 */
	public DetectionParam()
	{
		this.rect        = new Rect();
		this.sensitivity = 0;
	}

	/**
	 * コンストラクタ
	 * @param rect 矩形
	 * @param nSensitivity 感度
	 */
	public DetectionParam(Rect rect, int nSensitivity)
	{
		this.rect        = new Rect(rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight());
		this.sensitivity = nSensitivity;
	}

	/**
	 * 矩形を取得
	 * @return 矩形
	 */
	public Rect getRect()
	{
		return this.rect;
	}

	/**
	 * 感度を取得
	 * @return 感度
	 */
	public int getSensitivity()
	{
		return this.sensitivity;
	}

	/**
	 * 矩形を設定
	 * @param rect 矩形
	 */
	public void setRect(Rect rect)
	{
		this.rect.setX(rect.getX());
		this.rect.setY(rect.getY());
		this.rect.setWidth(rect.getWidth());
		this.rect.setHeight(rect.getHeight());
	}

	/**
	 * 感度を設定
	 * @param nSensitivity 感度
	 */
	public void setSensitivity(int nSensitivity)
	{
		this.sensitivity = nSensitivity;
	}
}
