#include "StatusBar.h"
#include "../../User/User.h"

namespace OgameWindow {
	void StatusBar::changeRightString() {
		this->rightString = U"Width: " + Format(canvas.getCanvasSize().x)
					+ U",  Height: " + Format(canvas.getCanvasSize().y)
					+ U",  CodelSize: " + Format(Codel::GetCodelSize())
					+ U",  CanvasPosition: " + Format(canvas.getLocalPosition());
	}

	StatusBar::StatusBar() {
		setSize(Point(Window::GetState().virtualSize.x, Height));
		setPosition(Point(0, Window::GetState().virtualSize.y - Height));
	}

	void StatusBar::reload(const Point& _pos, const Size& _size) {
		setSize(Point(Window::GetState().virtualSize.x, Height));
		setPosition(Point(0, Window::GetState().virtualSize.y - Height));
		changeRightString();
		_pos;
		_size;
	}

	void StatusBar::draw() {
		Point pos = getPosition();
		Point _size = getSize();
		Rect rect{ pos, _size };
		if(User::State::GetMode() == Mode::EDIT)
			rect.draw(this->themePtr->StatusBarBackColor);
		else
			rect.draw(this->themePtr->StatusBarBackDebugColor);
		auto right_word = this->font(this->rightString);
		right_word.draw(
			Window::GetState().virtualSize.x - right_word.region().size.x - 10,
			Window::GetState().virtualSize.y - Height,
			this->themePtr->StatusBarFontColor
		);
		String left_string = U"Mode: ";
		left_string += (User::State::GetMode() == Mode::DEBUG ? U"Debug" : U"Edit");
		auto left_word = font(left_string);
		left_word.draw(
			10, Window::GetState().virtualSize.y - Height,
			this->themePtr->StatusBarFontColor
		);

		//Console << right_word.region().size;
	}

	/*void StatusBar::update(const Canvas& canvas) {
		setSize(Point(Window::GetState().virtualSize.x, Height));
		setPosition(Point(0, Window::GetState().virtualSize.y - Height));
		changeRightString(canvas);
	}*/

	void StatusBar::update() {

	}
}
