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
 * スケジュール時間
 */
public final class ScheduleTime
{
	/** 年 */
	private int nYear;
	/** 月 */
	private int nMonth;
	/** 日 */
	private int nDay;
	/** 時 */
	private int nHour;
	/** 分 */
	private int nMinute;

	/**
	 * コンストラクタ
	 */
	public ScheduleTime()
	{
		this.nYear   = 0;
		this.nMonth  = 0;
		this.nDay    = 0;
		this.nHour   = 0;
		this.nMinute = 0;
	}

	/**
	 * コンストラクタ
	 * @param nYear 年
	 * @param nMonth 月
	 * @param nDay 日
	 * @param nHour 時
	 * @param nMinute 分
	 */
	public ScheduleTime(int nYear, int nMonth, int nDay, int nHour, int nMinute)
	{
		this.nYear   = nYear;
		this.nMonth  = nMonth;
		this.nDay    = nDay;
		this.nHour   = nHour;
		this.nMinute = nMinute;
	}

	/**
	 * 年の取得
	 * @return 年
	 */
	public int getYear()
	{
		return this.nYear;
	}

	/**
	 * 月の取得
	 * @return 月
	 */
	public int getMonth()
	{
		return this.nMonth;
	}

	/**
	 * 日の取得
	 * @return 日
	 */
	public int getDay()
	{
		return this.nDay;
	}

	/**
	 * 時の取得
	 * @return 時
	 */
	public int getHour()
	{
		return this.nHour;
	}

	/**
	 * 分の取得
	 * @return 分
	 */
	public int getMinute()
	{
		return this.nMinute;
	}

	/**
	 * 年の設定
	 * @param nYear 年
	 */
	public void setYear(int nYear)
	{
		this.nYear = nYear;
	}

	/**
	 * 月の設定
	 * @param nMonth 月
	 */
	public void setMonth(int nMonth)
	{
		this.nMonth = nMonth;
	}

	/**
	 * 日の設定
	 * @param nDay 日
	 */
	public void setDay(int nDay)
	{
		this.nDay = nDay;
	}

	/**
	 * 時の取得
	 * @param nHour 時
	 */
	public void setHour(int nHour)
	{
		this.nHour = nHour;
	}

	/**
	 * 分の取得
	 * @param nMinute 分
	 */
	public void setMinute(int nMinute)
	{
		this.nMinute = nMinute;
	}
}
