#include "Button.h"
#include "../../Judge/Judge.h"
#include "../../User/User.h"

namespace OgameWindow {
	Button::Button(const String& id_name, const String& display_name, const Point& size, int font_size) :
		m_IdName(id_name),
		m_DisplayName(display_name),
		m_FontSize(font_size)
	{
		SetPosition(Point(0, 0));
		SetClickableRange(Rect(0, 0, 0, 0));
		RemoveFunction();
		SetSize(size);
		m_Font = Font(m_FontSize, Typeface::CJK_Regular_JP);
	}

	void Button::LButtonDown() {
		Clicked();
		Console << U"\"" << m_DisplayName << U"\"が押された";
	}

	void Button::Clicked() {
		GetFunction()();
	}

	void Button::Update(const Point& pos) {
		ClickableObject::Update(pos);
		Point size = GetSize();
		Rect frame{ pos, size };
		SetClickableRange(frame);
		//Console << GetPosition();
	}

	void Button::Draw() {
		auto word = m_Font(m_DisplayName);
		Point size = GetSize();
		Rect frame = GetClickableRange();
		Point pos = GetPosition();
		if (Judge::IsCursorInRect(frame) and MouseL.pressed()) {
			frame.draw(m_ThemePtr->MenuButtonBackDownColor);
		}
		else if (Judge::IsCursorInRect(frame)) {
			frame.draw(m_ThemePtr->MenuButtonBackActiveColor);
			frame.drawFrame(2, 0, m_ThemePtr->MenuButtonBackColor);
			//frame.drawFrame(1, 0, m_Theme.MenuButtonBackDownColor());
		}
		else {
			//Console << frame.pos;
			frame.draw(m_ThemePtr->MenuButtonBackColor);
		}
		frame.drawFrame(1, 0, Palette::Black);

		//Console << GetPosition();
		word.drawAt(pos.x + size.x / 2, pos.y + size.y / 2, m_ThemePtr->MenuButtonFontColor);
	}
}
