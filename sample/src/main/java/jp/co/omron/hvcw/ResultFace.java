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
 * 顔検出結果詳細
 */
public final class ResultFace
{
	/** 中心点 */
	private Point             ptCenter;
	/** サイズ */
	private int               nSize;
	/** 信頼度 */
	private int               nConfidence;
	/** 顔向き推定結果 */
	private ResultDirection   direction;
	/** 年齢推定結果 */
	private ResultAeg         age;
	/** 性別推定結果 */
	private ResultGender      gender;
	/** 視線推定結果 */
	private ResultGaze        gaze;
	/** 目つむり推定結果 */
	private ResultBlink       blink;
	/** 表情推定結果 */
	private ResultExpression  expression;
	/** 顔認証結果 */
	private ResultRecognition recognition;

	/**
	 * コンストラクタ
	 */
	public ResultFace()
	{
		this.ptCenter    = new Point();
		this.nSize       = 0;
		this.nConfidence = 0;
		this.direction   = new ResultDirection();
		this.age         = new ResultAeg();
		this.gender      = new ResultGender();
		this.gaze        = new ResultGaze();
		this.blink       = new ResultBlink();
		this.expression  = new ResultExpression();
		this.recognition = new ResultRecognition();
	}

	/**
	 * コンストラクタ
	 * @param ptCenter 中心点
	 * @param nSize サイズ
	 * @param nConfidence 信頼度
	 * @param direction 顔向き推定結果
	 * @param age 年齢推定結果
	 * @param gender 性別推定結果
	 * @param gaze 視線推定結果
	 * @param blink 目つむり推定結果
	 * @param expression 表情推定結果
	 * @param recognition 顔認証結果
	 */
	public ResultFace(Point ptCenter,
						int nSize,
						int nConfidence,
						ResultDirection direction,
						ResultAeg age,
						ResultGender gender,
						ResultGaze gaze,
						ResultBlink blink,
						ResultExpression expression,
						ResultRecognition recognition)
	{
		this.ptCenter    = new Point(ptCenter.getX(), ptCenter.getY());
		this.nSize       = nSize;
		this.nConfidence = nConfidence;
		this.direction   = new ResultDirection(direction.getLR(), direction.getUD(), direction.getRoll());
		this.age         = new ResultAeg(age.getAge(), age.getConfidence());
		this.gender      = new ResultGender(gender.getGender(), gender.getConfidence());
		this.gaze        = new ResultGaze(gaze.getLR(), gaze.getUD());
		this.blink       = new ResultBlink(blink.getLeftEye(), blink.getRightEye());
		this.expression  = new ResultExpression(expression.getScore(), expression.getDegree());
		this.recognition = new ResultRecognition(recognition.getUID(), recognition.getScore());
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
	 * 顔向き推定結果の取得
	 * @return 顔向き推定結果
	 */
	public ResultDirection getDirection()
	{
		return this.direction;
	}

	/**
	 * 年齢推定結果の取得
	 * @return 年齢推定結果
	 */
	public ResultAeg getAge()
	{
		return this.age;
	}

	/**
	 * 性別推定結果の取得
	 * @return 性別推定結果
	 */
	public ResultGender getGender()
	{
		return this.gender;
	}

	/**
	 * 視線推定結果の取得
	 * @return 視線推定結果
	 */
	public ResultGaze getGaze()
	{
		return this.gaze;
	}

	/**
	 * 目つむり推定結果の取得
	 * @return 目つむり推定結果
	 */
	public ResultBlink getBlink()
	{
		return this.blink;
	}

	/**
	 * 表情推定結果の取得
	 * @return 表情推定結果
	 */
	public ResultExpression getExpression()
	{
		return this.expression;
	}

	/**
	 * 顔認証結果の取得
	 * @return 顔認証結果
	 */
	public ResultRecognition getRecognition()
	{
		return this.recognition;
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
	 * 顔向き推定結果の設定
	 * @param direction 顔向き推定結果
	 */
	public void setDirection(ResultDirection direction)
	{
		this.direction = new ResultDirection(direction.getLR(), direction.getUD(), direction.getRoll());
	}

	/**
	 * 年齢推定結果の設定
	 * @param age 年齢推定結果
	 */
	public void setAge(ResultAeg age)
	{
		this.age = new ResultAeg(age.getAge(), age.getConfidence());
	}

	/**
	 * 性別推定結果の設定
	 * @param gender 性別推定結果
	 */
	public void setGender(ResultGender gender)
	{
		this.gender = new ResultGender(gender.getGender(), gender.getConfidence());
	}

	/**
	 * 視線推定結果の設定
	 * @param gaze 視線推定結果
	 */
	public void setGaze(ResultGaze gaze)
	{
		this.gaze = new ResultGaze(gaze.getLR(), gaze.getUD());
	}

	/**
	 * 目つむり推定結果の設定
	 * @param blink 目つむり推定結果
	 */
	public void setBlink(ResultBlink blink)
	{
		this.blink = new ResultBlink(blink.getLeftEye(), blink.getRightEye());
	}

	/**
	 * 表情推定結果の設定
	 * @param expression 表情推定結果
	 */
	public void setExpression(ResultExpression expression)
	{
		this.expression = new ResultExpression(expression.getScore(), expression.getDegree());
	}

	/**
	 * 顔認証結果の設定
	 * @param recognition 顔認証結果
	 */
	public void setRecognition(ResultRecognition recognition)
	{
		this.recognition = new ResultRecognition(recognition.getUID(), recognition.getScore());
	}
}
