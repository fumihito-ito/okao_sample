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
 * 登録ユーザイベントパラメータ
 */
public final class EpKnownuser
{
	/** ユーザID */
	private int      nUserID;
	/** 通知ファイル情報 */
	private FileInfo fileInfo;

	/**
	 * コンストラクタ
	 */
	public EpKnownuser()
	{
		this.nUserID  = 0;
		this.fileInfo = new FileInfo();
	}

	/**
	 * コンストラクタ
	 * @param nUserID ユーザID
	 * @param fileInfo 通知ファイル情報
	 */
	public EpKnownuser(int nUserID, FileInfo fileInfo)
	{
		this.nUserID  = nUserID;
		this.fileInfo = new FileInfo(fileInfo.getName(), fileInfo.getSize(), fileInfo.getReserved());
	}

	/**
	 * ユーザIDの取得
	 * @return ユーザID
	 */
	public int getUserID()
	{
		return this.nUserID;
	}

	/**
	 * 通知ファイル情報の取得
	 * @return 通知ファイル情報
	 */
	public FileInfo getFileInfo()
	{
		return this.fileInfo;
	}

	/**
	 * ユーザIDの設定
	 * @param nUserID ユーザID
	 */
	public void setUserID(int nUserID)
	{
		this.nUserID = nUserID;
	}

	/**
	 * 通知ファイル情報の設定
	 * @param fileInfo 通知ファイル情報
	 */
	public void setFileInfo(FileInfo fileInfo)
	{
		this.fileInfo = new FileInfo(fileInfo.getName(), fileInfo.getSize(), fileInfo.getReserved());
	}
}
