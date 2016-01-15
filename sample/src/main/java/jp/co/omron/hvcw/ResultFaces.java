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
 * 顔検出結果
 */
public final class ResultFaces
{
	/** 検出数 */
	private int nCount;
	/** 顔検出結果詳細 */
	private ResultFace[] face;

	/**
	 * コンストラクタ
	 */
	public ResultFaces()
	{
		this.nCount = 0;
		this.face   = new ResultFace[35];
		for(int i=0; i<face.length; i++)
		{
			this.face[i] = new ResultFace();
		}
	}

	/**
	 * コンストラクタ
	 * @param nCount 検出数
	 * @param face 顔検出結果詳細
	 */
	public ResultFaces(int nCount, ResultFace[] face)
	{
		this.nCount = nCount;
		this.face   = new ResultFace[35];
		for(int i=0; i<this.face.length; i++)
		{
			this.face[i] = new ResultFace(face[i].getCenter(),
											face[i].getSize(),
											face[i].getConfidence(),
											face[i].getDirection(),
											face[i].getAge(),
											face[i].getGender(),
											face[i].getGaze(),
											face[i].getBlink(),
											face[i].getExpression(),
											face[i].getRecognition());
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
	 * 顔検出結果詳細の取得
	 * @return 顔検出結果詳細
	 */
	public ResultFace[] getResultFace()
	{
		return this.face;
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
	 * 顔検出結果詳細の設定
	 * @param face 顔検出結果詳細
	 */
	public void setResultFace(ResultFace[] face)
	{
		this.face = new ResultFace[35];
		for(int i=0; i<this.face.length; i++)
		{
			this.face[i] = new ResultFace(face[i].getCenter(),
											face[i].getSize(),
											face[i].getConfidence(),
											face[i].getDirection(),
											face[i].getAge(),
											face[i].getGender(),
											face[i].getGaze(),
											face[i].getBlink(),
											face[i].getExpression(),
											face[i].getRecognition());
		}
	}
}
