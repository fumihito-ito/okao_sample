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
public final class ResultPets
{
	/** 検出数 */
	private int nCount;
	/** ペット検出結果詳細 */
	private ResultPet[] pet;

	/**
	 * コンストラクタ
	 */
	public ResultPets()
	{
		this.nCount = 0;
		this.pet    = new ResultPet[10];
		for(int i=0; i<pet.length; i++)
		{
			this.pet[i] = new ResultPet();
		}
	}

	/**
	 * コンストラクタ
	 * @param nCount 検出数
	 * @param pet ペット検出結果詳細
	 */
	public ResultPets(int nCount, ResultPet[] pet)
	{
		this.nCount = nCount;
		this.pet    = new ResultPet[10];
		for(int i=0; i<this.pet.length; i++)
		{
			this.pet[i] = new ResultPet(pet[i].getCenter(),
										pet[i].getSize(),
										pet[i].getConfidence(),
										pet[i].getPetType());
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
	 * ペット検出結果詳細の取得
	 * @return ペット検出結果詳細
	 */
	public ResultPet[] getResultPet()
	{
		return this.pet;
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
	 * ペット検出結果詳細の設定
	 * @param pet ペット検出結果詳細
	 */
	public void setResultPet(ResultPet[] pet)
	{
		this.pet   = new ResultPet[10];
		for(int i=0; i<this.pet.length; i++)
		{
			this.pet[i] = new ResultPet(pet[i].getCenter(),
										pet[i].getSize(),
										pet[i].getConfidence(),
										pet[i].getPetType());
		}
	}
}
