#include "ScrollBar.h"
#include "../../Judge/Judge.h"
#include "../../User/User.h"

namespace OgameWindow {
	void ScrollBar::LButtonDown() {
		this->isHolding = true;
	}

	void ScrollBar::addBarLocalPosY(int y) {
		this->barLocalPosY += y;
		if (this->barLocalPosY < 0)
			this->barLocalPosY = 0;
		int temp = getSize().y - 2 * Width - bar.h;
		if (this->barLocalPosY > temp)
			this->barLocalPosY = temp;
	}

	void ScrollBar::setValue(int _value) {
		if (_value == 0) {
			this->value = _value;
			this->barLocalPosY = 0;
		}
		else if (_value == 1) {
			this->value = _value;
			this->barLocalPosY = getSize().y - Width - this->bar.h;
		}
		else {
			this->value = _value;
			this->barLocalPosY = _value * (getSize().y - 2 * Width - this->bar.h);
		}
	}

	ScrollBar::ScrollBar(uint32 _width, int _height, int _displayHeight, int _regionHeight) :
		Width(_width),
		displayHeight(_displayHeight),
		regionHeight(_regionHeight)
	{
		this->region = Rect(getPosition(), Width, _height);
		this->bar = Rect(getPosition() + Point(2, Width * 11 / 10), Width - 4, (int)((_height - 2 * Width) * ((float)_displayHeight / _regionHeight)));
		setClickableRange(this->bar);
		setPosition(Point(0, 0));
		setSize(Point(this->region.w, this->region.h));
	}

	void ScrollBar::draw() {
		if (this->enable) {
			this->region.drawFrame(1, themePtr->ScrollBarOutlineColor);
			this->region.draw(themePtr->ScrollBarBackColor);
			this->upButton.draw();
			this->downButton.draw();
			if (Judge::IsCursorInRect(getClickableRange()) or isHolding)
				this->bar.draw(themePtr->ScrollBarActiveColor);
			else
				this->bar.draw(themePtr->ScrollBarColor);
		}
	}

	void ScrollBar::inputUpdate() {
		if (this->enable) {
			ClickableObject::inputUpdate();
			this->upButton.inputUpdate();
			this->downButton.inputUpdate();
			if (this->isHolding) {
				Cursor::RequestStyle(CursorStyle::Hand);
				addBarLocalPosY(Cursor::Delta().y);
			}
		}
	}

	double ScrollBar::updateDouble(const Point& pos, int height) {
		ClickableObject::update(pos);
		setSize(Point(getSize().x, height));
		if (MouseL.up())
			this->isHolding = false;
		//uint32 height = GetSize().y;
		this->region = Rect(getPosition(), Width, height);
		this->upButton.update(pos);
		this->downButton.update(pos + Point(0, height - Width));
		this->bar = Rect(getPosition() + Point(2, Width * 11 / 10 + this->barLocalPosY), Width - 4, (int)((height - 2 * Width) * ((float)this->displayHeight / this->regionHeight)));
		setClickableRange(bar);

		if (this->enable) {

			int temp = getSize().y - 2 * Width - bar.h;

			if (this->displayHeight < this->regionHeight) {
				if (this->barLocalPosY > temp)
					this->barLocalPosY = temp;
			}

			return (double)this->barLocalPosY / temp;
		}
		else {
			return 0;
		}
	}
}
