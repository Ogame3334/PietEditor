#pragma once

#include <Siv3D.hpp>
#include "MenuButton.h"
#include "MenuBox.h"

namespace OgameWindow {
	class MenuBar : public DisplayObject{
	private:
		bool m_isJapanese;
		Array<MenuButton> m_Buttons = {};

		bool m_IsMenuBoxON = false;
		MenuBox m_MenuBox{};

		void ButtonFunctionSetUp();
	public:
		MenuBar();

		void SetMenuBox(MenuBox box) { m_MenuBox = box; };
		void RemoveMenuBox() { m_MenuBox = MenuBox(); };
		MenuBox GetMenuBox() const { return m_MenuBox; };

		void ToggleMenuBox(MenuBox box);

		void Draw() override;
		void InputUpdate();
		void Update(Point pos) override;
	};
}
