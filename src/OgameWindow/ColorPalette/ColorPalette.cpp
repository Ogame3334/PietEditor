#include "ColorPalette.h"
#include "ColorDish.h"
#include "ColorSelect.h"
#include "../../User/User.h"

namespace OgameWindow {
	ColorPalette::ColorPalette(const Point& _pos)
	{
		setPosition(_pos);
		for (int i = 0; i < 21; i++) {
			this->colorDishes.push_back(ColorDish(i));
		}
		setSize(Point(ColorDish::GetSize() * 7 + 6, ColorDish::GetSize() * 3 + 6));
	}

	void ColorPalette::draw() {
		Point pos = getPosition();
		Point size = getSize();
		Rect outline{ pos.x, pos.y, size.x, size.y };
		outline.drawFrame(1, 0, this->themePtr->ColorPaletteOutlineColor);

		for (int i = 0; i < 21; i++) {
			this->colorDishes[i].draw();
		}
		
		if (User::Setting::GetInputMode() == 1)
			ColorSelect::draw(pos);
	};

	void ColorPalette::inputUpdate() {
		for (int i = 0; i < 21; i++) {
			this->colorDishes[i].inputUpdate();
		}
	}

	void ColorPalette::update(const Point& _pos) {
		int colorDishSize = ColorDish::GetSize();
		for (int i = 0; i < 21; i++) {
			if (i < 18) {
				this->colorDishes[i].update(Point(_pos.x + colorDishSize * (i % 6) + 4, _pos.y + colorDishSize * (int)(i / 6) + 4));
			}
			else {
				this->colorDishes[i].update(Point(_pos.x + colorDishSize * 6 + 4, _pos.y + colorDishSize * (int)(i - 18) + 4));
			}
		}

		if (User::Setting::GetInputMode() == 1) {
			ColorSelect::SetColorDishSize(colorDishSize);
			ColorSelect::update(_pos);
		}

		DisplayObject::update(_pos);
	}
}
