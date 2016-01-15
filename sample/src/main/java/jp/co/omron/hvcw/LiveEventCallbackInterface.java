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
 * ライブイベント通知コールバック
 */
public interface LiveEventCallbackInterface
{
	/**
	 * ライブイベント通知コールバック
	 * @param nEventId イベントID
	 * @param userParam ユーザーパラメータ
	 * @param eventInfo イベント付加情報
	 * @return HVCW_SUCCESS 正常終了
	 */
	public int liveEventCallback(int nEventId, long userParam, long eventInfo);
}
