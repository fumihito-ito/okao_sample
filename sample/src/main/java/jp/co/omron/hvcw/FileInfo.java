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
 * ファイル情報
 */
public final class FileInfo
{
	/** ファイル名 */
	private String stName;
	/** ファイルサイズ */
	private int    nSize;
	/** Reserved */
	private int    Reserved;

	/**
	 * コンストラクタ
	 */
	public FileInfo()
	{
		this.stName   = "";
		this.nSize    = 0;
		this.Reserved = 0;
	}

	/**
	 * コンストラクタ
	 * @param stName ファイル名
	 * @param nSize ファイルサイズ
	 * @param Reserved Reserved
	 */
	public FileInfo(String stName, int nSize, int Reserved)
	{
		this.stName   = new String(stName);
		this.nSize    = nSize;
		this.Reserved = Reserved;
	}

	/**
	 * ファイル名の取得
	 * @return ファイル名
	 */
	public String getName()
	{
		return this.stName;
	}

	/**
	 * ファイルサイズの取得
	 * @return ファイルサイズ
	 */
	public int getSize()
	{
		return this.nSize;
	}

	/**
	 * Reservedの取得
	 * @return Reserved
	 */
	public int getReserved()
	{
		return this.Reserved;
	}

	/**
	 * ファイル名の設定
	 * @param stName ファイル名
	 */
	public void setName(String stName)
	{
		this.stName = new String(stName);
	}

	/**
	 * ファイルサイズの設定
	 * @param nSize ファイルサイズ
	 */
	public void setSize(int nSize)
	{
		this.nSize = nSize;
	}

	/**
	 * Reservedの設定
	 * @param Reserved Reserved
	 */
	public void setReserved(int Reserved)
	{
		this.Reserved = Reserved;
	}
}
