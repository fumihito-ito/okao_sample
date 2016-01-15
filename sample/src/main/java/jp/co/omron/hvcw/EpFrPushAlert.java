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
 * 顔認証プッシュ通知
 */
public final class EpFrPushAlert
{
	/** 登録している人物の場合の処理 */
	private EpKnownuser[] knownUser;
	/** 登録していない人物の場合の処理 */
	private EpPushAlert   unknownUser;

	/**
	 * コンストラクタ
	 */
	public EpFrPushAlert()
	{
		this.knownUser = new EpKnownuser[20];
		for(int i=0; i<knownUser.length; i++)
		{
			this.knownUser[i] = new EpKnownuser();
		}
		this.unknownUser = new EpPushAlert();
	}

	/**
	 * コンストラクタ
	 * @param knownUser 登録している人物の場合の処理
	 * @param unknownUser 登録していない人物の場合の処理
	 */
	public EpFrPushAlert(EpKnownuser[] knownUser, EpPushAlert unknownUser)
	{
		this.knownUser = new EpKnownuser[20];
		for(int i=0; i<knownUser.length; i++)
		{
			this.knownUser[i] = new EpKnownuser(knownUser[i].getUserID(), knownUser[i].getFileInfo());
		}
		this.unknownUser = new EpPushAlert(unknownUser.getEnable(), unknownUser.getFileInfo());
	}

	/**
	 * 登録している人物の場合の処理の取得
	 * @return 登録している人物の場合の処理
	 */
	public EpKnownuser[] getEpKnownuser()
	{
		return this.knownUser;
	}

	/**
	 * 登録していない人物の場合の処理の取得
	 * @return 登録していない人物の場合の処理
	 */
	public EpPushAlert getEpPushAlert()
	{
		return this.unknownUser;
	}

	/**
	 * 登録している人物の場合の処理の設定
	 * @param knownUser 登録している人物の場合の処理
	 */
	public void setEpKnownuser(EpKnownuser[] knownUser)
	{
		this.knownUser = new EpKnownuser[20];
		for(int i=0; i<knownUser.length; i++)
		{
			this.knownUser[i] = new EpKnownuser(knownUser[i].getUserID(), knownUser[i].getFileInfo());
		}
	}

	/**
	 * 登録していない人物の場合の処理の設定
	 * @param unknownUser 登録していない人物の場合の処理
	 */
	public void setEpPushAlert(EpPushAlert unknownUser)
	{
		this.unknownUser = new EpPushAlert(unknownUser.getEnable(), unknownUser.getFileInfo());
	}
}
