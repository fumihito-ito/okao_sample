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
 * OKAO処理
 */
public final class EpOkaoProcess
{
	/** 人体の判定値 */
	private EpBody        body;
	/** ペットの判定値 */
	private EpPet         pet;
	/** 顔の判定値 */
	private EpFace        face;
	/** 年齢の判定値 */
	private EpAge         age;
	/** 性別の判定値 */
	private EpGender      gender;
	/** 表情の判定値 */
	private EpExpression  expression;
	/** 認証の判定値 */
	private EpRecognition recognition;

	/** コンストラクタ */
	public EpOkaoProcess()
	{
		this.body        = new EpBody();
		this.pet         = new EpPet();
		this.face        = new EpFace();
		this.age         = new EpAge();
		this.gender      = new EpGender();
		this.expression  = new EpExpression();
		this.recognition = new EpRecognition();
	}

	/**
	 * コンストラクタ
	 * @param body 人体の判定値
	 * @param pet ペットの判定値
	 * @param face 顔の判定値
	 * @param age 年齢の判定値
	 * @param gender 性別の判定値
	 * @param expression 表情の判定値
	 * @param recognition 認証の判定値
	 */
	public EpOkaoProcess(EpBody body, EpPet pet, EpFace face, EpAge age, EpGender gender,
							EpExpression expression, EpRecognition recognition)
	{
		this.body        = new EpBody(body.getEnable(), body.getCount());
		this.pet         = new EpPet(pet.getEnable(), pet.getCount());
		this.face        = new EpFace(face.getEnable(), face.getCount());
		this.age         = new EpAge(age.getEnable(), age.getRange(), age.getConfidence());
		this.gender      = new EpGender(gender.getEnable(), gender.getGender(), gender.getConfidence());
		this.expression  = new EpExpression(expression.getEnable(), expression.getExpression(),
											expression.getScore(), expression.getRange());
		this.recognition = new EpRecognition(recognition.getEnable());
	}

	/**
	 * 人体の判定値の取得
	 * @return 人体の判定値
	 */
	public EpBody getEpBody()
	{
		return this.body;
	}

	/**
	 * ペットの判定値の取得
	 * @return ペットの判定値
	 */
	public EpPet getEpPet()
	{
		return this.pet;
	}

	/**
	 * 顔の判定値の取得
	 * @return 顔の判定値
	 */
	public EpFace getEpFace()
	{
		return this.face;
	}

	/**
	 * 年齢の判定値の取得
	 * @return 年齢の判定値
	 */
	public EpAge getEpAge()
	{
		return this.age;
	}

	/**
	 * 性別の判定値の取得
	 * @return 性別の判定値
	 */
	public EpGender getEpGender()
	{
		return this.gender;
	}

	/**
	 * 表情の判定値の取得
	 * @return 表情の判定値
	 */
	public EpExpression getEpExpression()
	{
		return this.expression;
	}

	/**
	 * 認証の判定値の取得
	 * @return 認証の判定値
	 */
	public EpRecognition getEpRecognition()
	{
		return this.recognition;
	}

	/**
	 * 人体の判定値の設定
	 * @param body 人体の判定値
	 */
	public void setEpBody(EpBody body)
	{
		this.body = new EpBody(body.getEnable(), body.getCount());
	}

	/**
	 * ペットの判定値の設定
	 * @param pet ペットの判定値
	 */
	public void setEpPet(EpPet pet)
	{
		this.pet = new EpPet(pet.getEnable(), pet.getCount());
	}

	/**
	 * 顔の判定値の設定
	 * @param face 顔の判定値
	 */
	public void setEpFace(EpFace face)
	{
		this.face = new EpFace(face.getEnable(), face.getCount());
	}

	/**
	 * 年齢の判定値の設定
	 * @param age 年齢の判定値
	 */
	public void setEpAge(EpAge age)
	{
		this.age = new EpAge(age.getEnable(), age.getRange(), age.getConfidence());
	}

	/**
	 * 性別の判定値の設定
	 * @param gender 性別の判定値
	 */
	public void setEpGender(EpGender gender)
	{
		this.gender = new EpGender(gender.getEnable(), gender.getGender(), gender.getConfidence());
	}

	/**
	 * 表情の判定値
	 * @param expression 表情の判定値
	 */
	public void setEpExpression(EpExpression expression)
	{
		this.expression = new EpExpression(expression.getEnable(), expression.getExpression(),
											expression.getScore(), expression.getRange());
	}

	/**
	 * 認証の判定値の設定
	 * @param recognition 認証の判定値
	 */
	public void setEpRecognition(EpRecognition recognition)
	{
		this.recognition = new EpRecognition(recognition.getEnable());
	}
}
