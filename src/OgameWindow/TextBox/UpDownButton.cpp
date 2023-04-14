#include "UpDownButton.h"
#include "../../Judge/Judge.h"
#include "../../User/User.h"

namespace OgameWindow {
	UpDownButton::UpDownButton(uint32 _width, bool _isUp) {
		if(_isUp)
			this->triangle = Shape2D::Ngon(3, _width / 2, Point(0, 0));
		else
			this->triangle = Shape2D::Ngon(3, _width / 2, Point(0, 0), 180_deg);
		this->isUp = _isUp;
		this->width = _width;
		setPosition(Point(0, 0));
		setClickableRange(Rect(0, 0, _width, _width));
		setSize(Point(_width, _width));
	}

	void UpDownButton::update(const Point& _pos) {
		ClickableObject::update(_pos);
		if (this->isUp)
			this->triangle = Shape2D::Ngon(3, this->width * 3 / 8, _pos + Point(this->width / 2, this->width / 2));
		else
			this->triangle = Shape2D::Ngon(3, this->width * 3 / 8, _pos + Point(this->width / 2, this->width / 2), 180_deg);
		setPosition(_pos);
		setClickableRange(Rect(_pos, this->width, this->width));
	}

	void UpDownButton::draw() {
		getClickableRange().draw(this->themePtr->ScrollBarButtonBackColor);
		if (Judge::IsCursorInRect(getClickableRange())) {
			this->triangle.draw(this->themePtr->ScrollBarButtonTriangleActiveColor);
		}
		else {
			this->triangle.draw(this->themePtr->ScrollBarButtonTriangleColor);
		}
	}
}
