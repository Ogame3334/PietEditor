#pragma once

#include <Siv3D.hpp>
#include "MenuButton.h"

namespace OgameWindow {
	class MenuBox {
	private:
		Array<MenuButton> m_Buttons;
		Rect m_Outline;

		int MaxWidth();

		int CalcHeight();

	public:
		MenuBox();

		void Draw(Point pos);
	};
}
