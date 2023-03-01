#pragma once

#include<Siv3D.hpp>
#include"../User/User.h"
#include"../OgameWindow/ColorPalette/ColorSelect.h"

namespace Debug {
	inline bool isDebugMode = false;

	/// @brief デバッグ情報を表示
	/// @param pos 座標
	/// @param debugFont フォント
	void Display(Point& pos, const Font& debugFont);
}
