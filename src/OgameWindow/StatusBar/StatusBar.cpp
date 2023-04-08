#include "StatusBar.h"
#include "../../User/User.h"

namespace OgameWindow {
	void StatusBar::ChangeRightString(const Canvas& canvas) {
		m_RightString = U"Width: " + Format(canvas.GetCanvasSize().x)
					+ U",  Height: " + Format(canvas.GetCanvasSize().y)
					+ U",  CodelSize: " + Format(Codel::GetCodelSize())
					+ U",  CanvasPosition: " + Format(canvas.GetLocalPosition());
	}

	StatusBar::StatusBar() {
		SetSize(Point(Window::GetState().virtualSize.x, Height));
		SetPosition(Point(0, Window::GetState().virtualSize.y - Height));
	}

	void StatusBar::Draw() {
		Point pos = GetPosition();
		Point size = GetSize();
		Rect rect{ pos, size };
		if(User::State::GetMode() == Mode::EDIT)
			rect.draw(m_ThemePtr->StatusBarBackColor);
		else
			rect.draw(m_ThemePtr->StatusBarBackDebugColor);
		auto right_word = m_Font(m_RightString);
		right_word.draw(
			Window::GetState().virtualSize.x - right_word.region().size.x - 10,
			Window::GetState().virtualSize.y - Height,
			m_ThemePtr->StatusBarFontColor
		);
		String left_string = U"Mode: ";
		left_string += (User::State::GetMode() == Mode::DEBUG ? U"Debug" : U"Edit");
		auto left_word = m_Font(left_string);
		left_word.draw(
			10, Window::GetState().virtualSize.y - Height,
			m_ThemePtr->StatusBarFontColor
		);

		//Console << right_word.region().size;
	}

	void StatusBar::Update(const Canvas& canvas) {
		SetSize(Point(Window::GetState().virtualSize.x, Height));
		SetPosition(Point(0, Window::GetState().virtualSize.y - Height));
		ChangeRightString(canvas);
	}
}
