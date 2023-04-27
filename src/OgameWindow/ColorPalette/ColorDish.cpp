#include "ColorDish.h"
#include "../../User/User.h"
#include "../../Judge/Judge.h"
#include "../../Constants/Constants.h"
#include "../../Constants/Calc.h"
#include "ColorSelect.h"

namespace OgameWindow {

	void ColorDish::LButtonDown() {
		if (this->id != 20) {
			User::State::SetDrawingColorID(this->id);
			/*if (User::Setting::GetInputMode() == 1) {
				ColorSelect::SetNowCursorPos(m_id);
			}*/
		}
	}
	void ColorDish::RButtonDown() {
		if (this->id < 18) {
			User::State::SetSelectedColorID(this->id);
		}
	}

	void ColorDish::writeOrder(const Point& _pos, const Font& _font) {
		_font(this->order).draw(TextStyle::Outline(0.30, Palette::White), Arg::center = Point(_pos.x + DishSize / 2, _pos.y + DishSize / 2), this->themePtr->ColorDishFontColor);
	}

	void ColorDish::reload(const Point& _pos, const Size& _size) {
		DisplayObject::reload(_pos, _size);
		if (this->id < 18)
			order = Constants::Orders[Constants::Calc::ColorIDSub(id)];
		if (this->id == 20) {
			int _id = User::State::GetDrawingColorID();
			this->color = Constants::Colors[_id];
			this->order = U"";
		}
		setClickableRange(this->outline);
		//ClickableObject::update(_pos);
	}

	void ColorDish::draw() {
		Point pos = DisplayObject::getPosition();
		this->outline = Rect{ pos.x, pos.y, DishSize - 2, DishSize - 2 };
		Rect _color{ pos.x + 3, pos.y + 3, DishSize - 8, DishSize - 8 };
		this->outline.drawFrame(1, 0, this->themePtr->ColorDishOutlineColor);
		_color.draw(this->color);
		writeOrder(pos, this->font);
	}
	/*void ColorDish::update(const Point& _pos) {
		if (this->id < 18)
			order = Constants::Orders[Constants::Calc::ColorIDSub(id)];
		if (this->id == 20) {
			int id = User::State::GetDrawingColorID();
			this->color = Constants::Colors[id];
			this->order = U"";
		}
		setClickableRange(this->outline);
		ClickableObject::update(_pos);
	}*/
	void ColorDish::update() {

	}
}
