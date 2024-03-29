﻿#pragma once
#include <Siv3D.hpp>
#include "../../User/User.h"
#include "ColorDish.h"

namespace OgameWindow {
	class ColorSelect {
	private:
		inline static int NowCursorPos = 0;
		inline static int ColorDishSize = 0;

		/// @brief 正の余りを求める
		/// @param x 割られる数
		/// @param y 割る数
		/// @return 正の余り
		static int PositiveMod(int _x, int _y);

		/// @brief セレクターの位置を加算する
		/// @param num 加算する数
		static void AddNowCursorPos(int _num);

		/// @brief 現在のセレクター位置を設定する
		/// @param num セレクター位置
		static void SetNowID(int _num) { NowCursorPos = _num; }

		/// @brief ユーザー入力を受け付ける  
		static void UserInput();

		/// @brief 現在のセレクターの位置を取得してユーザーの選択している色を設定する
		static void NowColorSet();

		/// @brief セレクターを表示する
		/// @param pos セレクターの座標
		/// @param size セレクターの表示サイズ
		static void CursorDraw(const Point& _pos, int _size);


	public:
		/// @brief 現在のセレクターの座標を取得する
		/// @return 現在のセレクター座標
		static int GetNowCursorPos() { return NowCursorPos; }

		/// @brief カラーディッシュのサイズを設定する
		/// @param size カラーディッシュのサイズ
		static void SetColorDishSize(int _size) { ColorDishSize = _size; }
		//static void SetNowCursorPos(int id);

		/// @brief セレクターを描画する
		/// @param pos 座標
		static void draw(const Point& _pos);

		/// @brief セレクターを更新する
		/// @param pos 座標
		static void update(const Point& _pos);
	};
}
