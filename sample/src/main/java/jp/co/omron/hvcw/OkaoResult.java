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
 * OKAO処理結果
 */
public final class OkaoResult
{
	/** 人体検出結果 */
	private ResultBodys bodys;
	/** 手検出結果 */
	private ResultHands hands;
	/** ペット検出結果 */
	private ResultPets  pets;
	/** 顔検出結果 */
	private ResultFaces faces;

	/**
	 * コンストラクタ
	 */
	public OkaoResult()
	{
		this.bodys = new ResultBodys();
		this.hands = new ResultHands();
		this.pets  = new ResultPets();
		this.faces = new ResultFaces();
	}

	/**
	 * コンストラクタ
	 * @param bodys 人体検出結果
	 * @param hands 手検出結果
	 * @param pets ペット検出結果
	 * @param faces 顔検出結果
	 */
	public OkaoResult(ResultBodys bodys, ResultHands hands, ResultPets pets, ResultFaces faces)
	{
		this.bodys = new ResultBodys(bodys.getCount(), bodys.getResultDetection());
		this.hands = new ResultHands(hands.getCount(), hands.getResultDetection());
		this.pets  = new ResultPets(pets.getCount(), pets.getResultPet());
		this.faces = new ResultFaces(faces.getCount(), faces.getResultFace());
	}

	/**
	 * 人体検出結果の取得
	 * @return 人体検出結果
	 */
	public ResultBodys getResultBodys()
	{
		return this.bodys;
	}

	/**
	 * 手検出結果の取得
	 * @return 手検出結果
	 */
	public ResultHands getResultHands()
	{
		return this.hands;
	}

	/**
	 * ペット検出結果の取得
	 * @return ペット検出結果
	 */
	public ResultPets getResultPets()
	{
		return this.pets;
	}

	/**
	 * 顔検出結果の取得
	 * @return 顔検出結果
	 */
	public ResultFaces getResultFaces()
	{
		return this.faces;
	}

	/**
	 * 人体検出結果の設定
	 * @param bodys 人体検出結果
	 */
	public void setResultBodys(ResultBodys bodys)
	{
		this.bodys = new ResultBodys(bodys.getCount(), bodys.getResultDetection());
	}

	/**
	 * 手検出結果の設定
	 * @param hands 手検出結果
	 */
	public void setResultHands(ResultHands hands)
	{
		this.hands = new ResultHands(hands.getCount(), hands.getResultDetection());
	}

	/**
	 * ペット検出結果の設定
	 * @param pets ペット検出結果
	 */
	public void setResultPets(ResultPets pets)
	{
		this.pets = new ResultPets(pets.getCount(), pets.getResultPet());
	}

	/**
	 * 顔検出結果の設定
	 * @param faces 顔検出結果
	 */
	public void setResultFaces(ResultFaces faces)
	{
		this.faces = new ResultFaces(faces.getCount(), faces.getResultFace());
	}
}
