#pragma once

#include<Siv3D.hpp>
#include"../User/User.h"
#include"../OgameWindow/ColorPalette/ColorSelect.h"

namespace Debug {
	inline bool isDebugMode = false;

	void Display(Point& pos, Font debugFont);
}
