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

import java.util.Arrays;

/**
 * スケジュール情報
 */
public final class ScheduleInfo
{
	/** インデックス */
	private int          nIndex;
	/** 繰り返し周期 */
	private int          nFrequency;
	/** 曜日指定 */
	private int[]        aBooleanWeekday;
	/** 開始時間 */
	private ScheduleTime startTime;
	/** 終了時間 */
	private ScheduleTime endTime;
	/** 実行間隔 */
	private int          nInterval;
	/** 実行機能 */
	private int[]        aBooleanFunction;
	/** ログ保存フラグ */
	private int          nSaveLog;
	/** 画像保存フラグ */
	private int          nSaveImage;

	/**
	 * コンストラクタ
	 */
	public ScheduleInfo()
	{
		this.nIndex           = 0;
		this.nFrequency       = 0;
		this.aBooleanWeekday  = new int[7];
		this.startTime        = new ScheduleTime();
		this.endTime          = new ScheduleTime();
		this.nInterval        = 0;
		this.aBooleanFunction = new int[HvcwApi.HVCW_OkaoFunction_Max];
		this.nSaveLog         = 0;
		this.nSaveImage       = 0;
	}

	/**
	 * コンストラクタ
	 * @param nIndex インデックス
	 * @param nFrequency 繰り返し周期
	 * @param aBooleanWeekday 曜日指定
	 * @param startTime 開始時間
	 * @param endTime 終了時間
	 * @param nInterval 実行間隔
	 * @param aBooleanFunction 実行機能
	 * @param nSaveLog ログ保存フラグ
	 * @param nSaveImage 画像保存フラグ
	 */
	public ScheduleInfo(int nIndex, int nFrequency, int[] aBooleanWeekday,
						ScheduleTime startTime, ScheduleTime endTime, int nInterval,
						int[] aBooleanFunction, int nSaveLog, int nSaveImage)
	{
		this.nIndex           = nIndex;
		this.nFrequency       = nFrequency;
		this.aBooleanWeekday  = Arrays.copyOf(aBooleanWeekday, aBooleanWeekday.length);
		this.startTime        = new ScheduleTime(startTime.getYear(),
													startTime.getMonth(),
													startTime.getDay(),
													startTime.getHour(),
													startTime.getMinute());
		this.endTime          = new ScheduleTime(endTime.getYear(),
													endTime.getMonth(),
													endTime.getDay(),
													endTime.getHour(),
													endTime.getMinute());
		this.nInterval        = nInterval;
		this.aBooleanFunction = Arrays.copyOf(aBooleanFunction, aBooleanFunction.length);
		this.nSaveLog         = nSaveLog;
		this.nSaveImage       = nSaveImage;
	}

	/**
	 * インデックスの取得
	 * @return インデックス
	 */
	public int getIndex()
	{
		return this.nIndex;
	}

	/**
	 * 繰り返し周期の取得
	 * @return 繰り返し周期
	 */
	public int getFrequency()
	{
		return this.nFrequency;
	}

	/**
	 * 曜日指定の取得
	 * @return 曜日指定
	 */
	public int[] getBooleanWeekday()
	{
		return this.aBooleanWeekday;
	}

	/**
	 * 開始時間の取得
	 * @return 開始時間
	 */
	public ScheduleTime getStartTime()
	{
		return this.startTime;
	}

	/**
	 * 終了時間の取得
	 * @return 終了時間
	 */
	public ScheduleTime getEndTime()
	{
		return this.endTime;
	}

	/**
	 * 実行間隔の取得
	 * @return 実行間隔
	 */
	public int getInterval()
	{
		return this.nInterval;
	}

	/**
	 * 実行機能の取得
	 * @return 実行機能
	 */
	public int[] getBooleanFunction()
	{
		return this.aBooleanFunction;
	}

	/**
	 * ログ保存フラグの取得
	 * @return ログ保存フラグ
	 */
	public int getSaveLog()
	{
		return this.nSaveLog;
	}

	/**
	 * 画像保存フラグの取得
	 * @return 画像保存フラグ
	 */
	public int getSaveImage()
	{
		return this.nSaveImage;
	}

	/**
	 * インデックスの設定
	 * @param nIndex インデックス
	 */
	public void setIndex(int nIndex)
	{
		this.nIndex = nIndex;
	}

	/**
	 * 繰り返し周期の設定
	 * @param nFrequency 繰り返し周期
	 */
	public void setFrequency(int nFrequency)
	{
		this.nFrequency = nFrequency;
	}

	/**
	 * 曜日指定の設定
	 * @param aBooleanWeekday 曜日指定
	 */
	public void setBooleanWeekday(int[] aBooleanWeekday)
	{
		this.aBooleanWeekday = Arrays.copyOf(aBooleanWeekday, aBooleanWeekday.length);
	}

	/**
	 * 開始時間の設定
	 * @param startTime 開始時間
	 */
	public void setStartTime(ScheduleTime startTime)
	{
		this.startTime = new ScheduleTime(startTime.getYear(),
											startTime.getMonth(),
											startTime.getDay(),
											startTime.getHour(),
											startTime.getMinute());
	}

	/**
	 * 終了時間の設定
	 * @param endTime 終了時間
	 */
	public void setEndTime(ScheduleTime endTime)
	{
		this.endTime = new ScheduleTime(endTime.getYear(),
										endTime.getMonth(),
										endTime.getDay(),
										endTime.getHour(),
										endTime.getMinute());
	}

	/**
	 * 実行間隔の設定
	 * @param nInterval 実行間隔
	 */
	public void setInterval(int nInterval)
	{
		this.nInterval = nInterval;
	}

	/**
	 * 実行機能の設定
	 * @param aBooleanFunction 実行機能
	 */
	public void setBooleanFunction(int[] aBooleanFunction)
	{
		this.aBooleanFunction = Arrays.copyOf(aBooleanFunction, aBooleanFunction.length);
	}

	/**
	 * ログ保存フラグの設定
	 * @param nSaveLog ログ保存フラグ
	 */
	public void setSaveLog(int nSaveLog)
	{
		this.nSaveLog = nSaveLog;
	}

	/**
	 * 画像保存フラグの設定
	 * @param nSaveImage 画像保存フラグ
	 */
	public void setSaveImage(int nSaveImage)
	{
		this.nSaveImage = nSaveImage;
	}

}
