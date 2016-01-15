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
 * レンダリング要求コールバック
 */
public interface RequestRenderingCallbackInterface
{
	/**
	 * 音声データコールバック
	 * @param userParam ユーザーパラメータ
	 * @param sound 音声データ
	 * @param timeStamp タイムスタンプ
	 * @return HVCW_SUCCESS 正常終了
	 */
	public int soundDataCallback(long userParam, byte[] sound, long timeStamp);

	/**
	 * ビデオフレームコールバック
	 * @param userParam ユーザーパラメータ
	 * @param y 輝度Y
	 * @param u B-Y
	 * @param v R-Y
	 * @param width ビデオフレームの幅
	 * @param height ビデオフレームの高さ
	 * @param timeStamp タイムスタンプ
	 * @return HVCW_SUCCESS 正常終了
	 */
	public int videoFrameCallback(long userParam, byte[] y, byte[] u, byte[] v, long width, long height, long timeStamp);
}
