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
 * イベント通知コールバック
 */
public interface EventCallbackInterface
{
	/**
	 * イベント通知コールバック
	 * @param nEventId イベントID
	 * @param userParam ユーザーパラメータ
	 * @param eventInfo イベント付加情報
	 * @return HVCW_SUCCESS 正常終了
	 */
	public int eventCallback(int nEventId, long userParam, long eventInfo);
}
