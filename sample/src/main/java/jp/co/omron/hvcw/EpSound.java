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
 * 音声出力
 */
public final class EpSound
{
	/** 音声出力フラグ */
	private int      booleanEnable;
	/** 音声ファイル情報 */
	private FileInfo fileInfo;

	/**
	 * コンストラクタ
	 */
	public EpSound()
	{
		this.booleanEnable = 0;
		this.fileInfo      = new FileInfo();
	}

	/**
	 * コンストラクタ
	 * @param booleanEnable 音声出力フラグ
	 * @param fileInfo 音声ファイル情報
	 */
	public EpSound(int booleanEnable, FileInfo fileInfo)
	{
		this.booleanEnable = booleanEnable;
		this.fileInfo      = new FileInfo(fileInfo.getName(), fileInfo.getSize(), fileInfo.getReserved());
	}

	/**
	 * 音声出力フラグの取得
	 * @return 音声出力フラグ
	 */
	public int getEnable()
	{
		return this.booleanEnable;
	}

	/**
	 * 音声ファイル情報の取得
	 * @return 音声ファイル情報
	 */
	public FileInfo getFileInfo()
	{
		return this.fileInfo;
	}

	/**
	 * 音声出力フラグの設定
	 * @param booleanEnable 音声出力フラグ
	 */
	public void setEnable(int booleanEnable)
	{
		this.booleanEnable = booleanEnable;
	}

	/**
	 * 音声ファイル情報の設定
	 * @param fileInfo 音声ファイル情報
	 */
	public void setFileInfo(FileInfo fileInfo)
	{
		this.fileInfo = new FileInfo(fileInfo.getName(), fileInfo.getSize(), fileInfo.getReserved());
	}
}
