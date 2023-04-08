#include "ColorPalette.h"
#include "ColorDish.h"
#include "ColorSelect.h"
#include "../../User/User.h"

namespace OgameWindow {
	ColorPalette::ColorPalette(const Point& pos)
	{
		SetPosition(pos);
		for (int i = 0; i < 21; i++) {
			m_colorDishes.push_back(ColorDish(i));
		}
		SetSize(Point(ColorDish::GetSize() * 7 + 6, ColorDish::GetSize() * 3 + 6));
	}

	void ColorPalette::Draw() {
		Point pos = GetPosition();
		Point size = GetSize();
		Rect outline{ pos.x, pos.y, size.x, size.y };
		outline.drawFrame(1, 0, m_ThemePtr->ColorPaletteOutlineColor);

		for (int i = 0; i < 21; i++) {
			m_colorDishes[i].Draw();
		}
		
		if (User::Setting::GetInputMode() == 1)
			ColorSelect::Draw(pos);
	};

	void ColorPalette::InputUpdate() {
		for (int i = 0; i < 21; i++) {
			m_colorDishes[i].InputUpdate();
		}
	}

	void ColorPalette::Update(const Point& pos) {
		int colorDishSize = ColorDish::GetSize();
		for (int i = 0; i < 21; i++) {
			if (i < 18) {
				m_colorDishes[i].Update(Point(pos.x + colorDishSize * (i % 6) + 4, pos.y + colorDishSize * (int)(i / 6) + 4));
			}
			else {
				m_colorDishes[i].Update(Point(pos.x + colorDishSize * 6 + 4, pos.y + colorDishSize * (int)(i - 18) + 4));
			}
		}

		if (User::Setting::GetInputMode() == 1) {
			ColorSelect::SetColorDishSize(colorDishSize);
			ColorSelect::Update(pos);
		}

		DisplayObject::Update(pos);
	}
}
