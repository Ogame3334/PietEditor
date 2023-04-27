#include "MenuButton.h"
#include "../../Judge/Judge.h"
#include "../../User/User.h"

namespace OgameWindow {
	void MenuButton::LButtonDown() {
		clicked();
		Console << U"\"" << this->displayName << U"\"が押された";
	}

	/*void MenuButton::update(const Point& _pos) {
		ClickableObject::update(_pos);
		auto word = this->font(this->displayName);
		Point size{ (int)word.region().size.x + 6, (int)word.region().size.y };
		Rect frame;
		if (this->width == 0)
			frame = Rect{ _pos.x, _pos.y, size.x, size.y };
		else {
			frame = Rect{ _pos.x, _pos.y, this->width, size.y };
		}
		setSize(Point(frame.w, frame.h));
		setClickableRange(frame);
		//Console << GetPosition();
	}*/

	void MenuButton::reload(const Point& _pos, const Size& _size) {
		DisplayObject::reload(_pos, _size);
		auto word = this->font(this->displayName);
		Point _size_00{ (int)word.region().size.x + 6, (int)word.region().size.y };
		Rect frame;
		if (this->width == 0)
			frame = Rect{ _pos.x, _pos.y, _size_00.x, _size_00.y };
		else {
			frame = Rect{ _pos.x, _pos.y, this->width, _size_00.y };
		}
		setSize(Point(frame.w, frame.h));
		setClickableRange(frame);
		//Console << GetPosition();
	}

	void MenuButton::draw() {
		//Console << GetPosition();
		auto word = this->font(this->displayName);
		//Point size = getSize();
		Rect frame = getClickableRange();
		Point pos = getPosition();
		if (Judge::IsCursorInRect(frame) and MouseL.pressed()) {
			frame.draw(this->themePtr->MenuButtonBackDownColor);
		}
		else if (Judge::IsCursorInRect(frame)) {
			frame.draw(this->themePtr->MenuButtonBackActiveColor);
			frame.drawFrame(2, 0, this->themePtr->MenuButtonBackColor);
			frame.drawFrame(1, 0, this->themePtr->MenuButtonBackDownColor);
		}
		else {
			//Console << frame.pos;
			frame.draw(this->themePtr->MenuButtonBackColor);
		}

		//Console << GetPosition();
		word.draw(pos.x + 3, pos.y, this->themePtr->MenuButtonFontColor);
	}
	void MenuButton::clicked() {
		getFunction()();
	}
	MenuButton::MenuButton(const String& _idName, const String& _displayName) :
		idName(_idName),
		displayName(_displayName)
	{
		setPosition(Point(0, 0));
		setClickableRange(Rect(0, 0, 0, 0));
		removeFunction();
		this->width = (int)this->font(this->displayName).region().size.x + 6;
		setSize(Point(this->width, (int)this->font(this->displayName).region().size.y));
	}

	MenuButton::MenuButton(const String& _idName, const String& _displayName, int _width) :
		idName(_idName),
		displayName(_displayName),
		width(_width)
	{
		setPosition(Point(0, 0));
		setClickableRange(Rect(0, 0, 0, 0));
		removeFunction();
		setSize(Point(_width, (int)this->font(this->displayName).region().size.y));
	}

	void MenuButton::update() {

	}
}
