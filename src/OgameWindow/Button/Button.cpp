#include "Button.h"
#include "../../Judge/Judge.h"
#include "../../User/User.h"

namespace OgameWindow {
	Button::Button(const String& _idName, const String& _displayName, const Point& _size, int _fontSize) :
		idName(_idName),
		displayName(_displayName),
		fontSize(_fontSize)
	{
		setPosition(Point(0, 0));
		setClickableRange(Rect(0, 0, 0, 0));
		removeFunction();
		setSize(_size);
		font = Font(_fontSize, Typeface::CJK_Regular_JP);
	}

	void Button::LButtonDown() {
		clicked();
		Console << U"\"" << displayName << U"\"が押された";
	}

	void Button::clicked() {
		getFunction()();
	}

	void Button::reload(const Point& _pos, const Size& _size) {

	}

	void Button::update(){}

	/*void Button::update(const Point& _pos) {
		ClickableObject::update(_pos);
		Point size = getSize();
		Rect frame{ _pos, size };
		setClickableRange(frame);
		//Console << GetPosition();
	}*/

	void Button::draw() {
		auto word = this->font(this->displayName);
		Point _size = getSize();
		Rect frame = getClickableRange();
		Point pos = getPosition();
		if (Judge::IsCursorInRect(frame) and MouseL.pressed()) {
			frame.draw(this->themePtr->MenuButtonBackDownColor);
		}
		else if (Judge::IsCursorInRect(frame)) {
			frame.draw(this->themePtr->MenuButtonBackActiveColor);
			frame.drawFrame(2, 0, this->themePtr->MenuButtonBackColor);
			//frame.drawFrame(1, 0, m_Theme.MenuButtonBackDownColor());
		}
		else {
			//Console << frame.pos;
			frame.draw(this->themePtr->MenuButtonBackColor);
		}
		frame.drawFrame(1, 0, Palette::Black);

		//Console << GetPosition();
		word.drawAt(pos.x + _size.x / 2, pos.y + _size.y / 2, this->themePtr->MenuButtonFontColor);
	}
}
