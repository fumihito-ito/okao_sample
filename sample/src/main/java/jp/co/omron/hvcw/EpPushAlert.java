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
 * プッシュ通知
 */
public final class EpPushAlert
{
	/** 通知フラグ */
	private int      booleanEnable;
	/** メッセージファイル */
	private FileInfo fileInfo;

	/**
	 * コンストラクタ
	 */
	public EpPushAlert()
	{
		this.booleanEnable = 0;
		this.fileInfo      = new FileInfo();
	}

	/**
	 * コンストラクタ
	 * @param booleanEnable 通知フラグ
	 * @param fileInfo メッセージファイル
	 */
	public EpPushAlert(int booleanEnable, FileInfo fileInfo)
	{
		this.booleanEnable = booleanEnable;
		this.fileInfo      = new FileInfo(fileInfo.getName(), fileInfo.getSize(), fileInfo.getReserved());
	}

	/**
	 * 通知フラグの取得
	 * @return 通知フラグ
	 */
	public int getEnable()
	{
		return this.booleanEnable;
	}

	/**
	 * メッセージファイルの取得
	 * @return メッセージファイル
	 */
	public FileInfo getFileInfo()
	{
		return this.fileInfo;
	}

	/**
	 * 通知フラグの設定
	 * @param booleanEnable 通知フラグ
	 */
	public void setEnable(int booleanEnable)
	{
		this.booleanEnable = booleanEnable;
	}

	/**
	 * メッセージファイルの設定
	 * @param fileInfo メッセージファイル
	 */
	public void setFileInfo(FileInfo fileInfo)
	{
		this.fileInfo = new FileInfo(fileInfo.getName(), fileInfo.getSize(), fileInfo.getReserved());
	}
}
