#pragma once

#include <Siv3D.hpp>
#include "MenuButton.h"
#include "../../ParentClass/DisplayObject.h"

namespace OgameWindow {
	class MenuBox : public DisplayObject{
	private:
		Array<MenuButton> m_Buttons;
		Rect m_Outline;

		int m_ID;

		int MaxWidth();

		int CalcHeight();

	public:
		MenuBox();
		MenuBox(int width, int id);

		int GetWidth() const { return m_Outline.w; }
		int GetID() const { return m_ID; }
		Rect GetOutline() const { return m_Outline; }

		Array<MenuButton> GetButtons() const { return m_Buttons; }

		void Append(MenuButton button);

		void Draw() override;
		void InputUpdate();
		void Update(Point pos) override;
	};
}
