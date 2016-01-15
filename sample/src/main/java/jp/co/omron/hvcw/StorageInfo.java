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
 * ストレージ情報
 */
public final class StorageInfo
{
	/** total_size ストレージ総容量（単位:バイト） */
	private int nTotalSize;
	/** used_size 使用済みストレージ容量（単位:バイト） */
	private int nUsedSize;
	/** free_size 空きストレージ容量（単位:バイト） */
	private int nFreeSize;
	/** storage_status ストレージステータス */
	private int nStorageStatus;

	/**
	 * コンストラクタ
	 */
	public StorageInfo()
	{
		this.nTotalSize     = 0;
		this.nUsedSize      = 0;
		this.nFreeSize      = 0;
		this.nStorageStatus = 0;
	}

	/**
	 * コンストラクタ
	 * @param nTotalSize total_size ストレージ総容量（単位:バイト）
	 * @param nUsedSize used_size 使用済みストレージ容量（単位:バイト）
	 * @param nFreeSize free_size 空きストレージ容量（単位:バイト）
	 * @param nStorageStatus storage_status ストレージステータス
	 */
	public StorageInfo(int nTotalSize, int nUsedSize, int nFreeSize, int nStorageStatus)
	{
		this.nTotalSize     = nTotalSize;
		this.nUsedSize      = nUsedSize;
		this.nFreeSize      = nFreeSize;
		this.nStorageStatus = nStorageStatus;
	}

	/**
	 * total_size ストレージ総容量（単位:バイト）の取得
	 * @return total_size ストレージ総容量（単位:バイト）
	 */
	public int getTotalSize()
	{
		return this.nTotalSize;
	}

	/**
	 * used_size 使用済みストレージ容量（単位:バイト）の取得
	 * @return used_size 使用済みストレージ容量（単位:バイト）
	 */
	public int getUsedSize()
	{
		return this.nUsedSize;
	}

	/**
	 * free_size 空きストレージ容量（単位:バイト）の取得
	 * @return free_size 空きストレージ容量（単位:バイト）
	 */
	public int getFreeSize()
	{
		return this.nFreeSize;
	}

	/**
	 * free_size storage_status ストレージステータスの取得
	 * @return storage_status ストレージステータス
	 */
	public int getStorageStatus()
	{
		return this.nStorageStatus;
	}

	/**
	 * total_size ストレージ総容量（単位:バイト）の設定
	 * @param nTotalSize total_size ストレージ総容量（単位:バイト）
	 */
	public void setTotalSize(int nTotalSize)
	{
		this.nTotalSize = nTotalSize;
	}

	/**
	 * used_size 使用済みストレージ容量（単位:バイト）の設定
	 * @param nUsedSize used_size 使用済みストレージ容量（単位:バイト）
	 */
	public void setUsedSize(int nUsedSize)
	{
		this.nUsedSize = nUsedSize;
	}

	/**
	 * free_size 空きストレージ容量（単位:バイト）の設定
	 * @param nFreeSize free_size 空きストレージ容量（単位:バイト）
	 */
	public void setFreeSize(int nFreeSize)
	{
		this.nFreeSize = nFreeSize;
	}

	/**
	 * storage_status ストレージステータスの設定
	 * @param nStorageStatus storage_status ストレージステータス
	 */
	public void setStorageStatus(int nStorageStatus)
	{
		this.nStorageStatus = nStorageStatus;
	}
}
