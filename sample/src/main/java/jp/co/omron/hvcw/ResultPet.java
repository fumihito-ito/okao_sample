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
 * ペット検出結果
 */
public final class ResultPet
{
	/** 中心点 */
	private Point ptCenter;
	/** サイズ */
	private int nSize;
	/** 信頼度 */
	private int nConfidence;
	/** ペット種別 */
	private int nPetType;

	/**
	 * コンストラクタ
	 */
	public ResultPet()
	{
		this.ptCenter    = new Point();
		this.nSize       = 0;
		this.nConfidence = 0;
		this.nPetType    = 0;
	}

	/**
	 * コンストラクタ
	 * @param ptCenter 中心点
	 * @param nSize サイズ
	 * @param nConfidence 信頼度
	 * @param nPetType ペット種別
	 */
	public ResultPet(Point ptCenter, int nSize, int nConfidence, int nPetType)
	{
		this.ptCenter    = new Point(ptCenter.getX(), ptCenter.getY());
		this.nSize       = nSize;
		this.nConfidence = nConfidence;
		this.nPetType    = nPetType;
	}

	/**
	 * 中心点の取得
	 * @return 中心点
	 */
	public Point getCenter()
	{
		return this.ptCenter;
	}

	/**
	 * サイズの取得
	 * @return サイズ
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
	 * ペット種別の取得
	 * @return ペット種別
	 */
	public int getPetType()
	{
		return this.nPetType;
	}

	/**
	 * 中心点の設定
	 * @param ptCenter 中心点
	 */
	public void setCenter(Point ptCenter)
	{
		this.ptCenter = new Point(ptCenter.getX(), ptCenter.getY());
	}

	/**
	 * サイズの設定
	 * @param nSize サイズ
	 */
	public void setSize(int nSize)
	{
		this.nSize = nSize;
	}

	/**
	 * 信頼度の設定
	 * @param nConfidence 信頼度
	 */
	public void setConfidence(int nConfidence)
	{
		this.nConfidence = nConfidence;
	}

	/**
	 * ペット種別の設定
	 * @param nPetType ペット種別
	 */
	public void setPetType(int nPetType)
	{
		this.nPetType = nPetType;
	}
}
