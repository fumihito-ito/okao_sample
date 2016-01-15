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
 * 目つむり推定結果
 */
public final class ResultBlink
{
	/** 左目の目つむり度合 */
	private int nLeftEye;
	/** 右目の目つむり度合 */
	private int nRightEye;

	/**
	 * コンストラクタ
	 */
	public ResultBlink()
	{
		this.nLeftEye  = 0;
		this.nRightEye = 0;
	}

	/**
	 * コンストラクタ
	 * @param nLeftEye 左目の目つむり度合
	 * @param nRightEye 右目の目つむり度合
	 */
	public ResultBlink(int nLeftEye, int nRightEye)
	{
		this.nLeftEye  = nLeftEye;
		this.nRightEye = nRightEye;
	}

	/**
	 * 左目の目つむり度合の取得
	 * @return 左目の目つむり度合
	 */
	public int getLeftEye()
	{
		return this.nLeftEye;
	}

	/**
	 * 右目の目つむり度合の取得
	 * @return 右目の目つむり度合
	 */
	public int getRightEye()
	{
		return this.nRightEye;
	}

	/**
	 * 左目の目つむり度合の設定
	 * @param nLeftEye 左目の目つむり度合
	 */
	public void setLeftEye(int nLeftEye)
	{
		this.nLeftEye = nLeftEye;
	}

	/**
	 * 右目の目つむり度合の設定
	 * @param nRightEye 右目の目つむり度合
	 */
	public void setRightEye(int nRightEye)
	{
		this.nRightEye = nRightEye;
	}
}
