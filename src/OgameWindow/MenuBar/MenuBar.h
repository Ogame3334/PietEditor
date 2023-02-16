#pragma once

#include <Siv3D.hpp>
#include "MenuButton.h"

namespace OgameWindow {
	class MenuBar {

	private:
		bool m_isJapanese;
		Array<MenuButton> buttons = {};
	public:
		MenuBar();

		void Draw(void);
	};
}
