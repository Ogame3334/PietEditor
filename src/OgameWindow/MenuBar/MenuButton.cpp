#include "MenuButton.h"
#include "../../Judge/Judge.h"
#include "../../User/User.h"

namespace OgameWindow {
	void MenuButton::LButtonDown() {
		Clicked();
		Console << U"\"" << m_DisplayName << U"\"が押された";
	}

	void MenuButton::Update(const Point& pos) {
		ClickableObject::Update(pos);
		auto word = m_Font(m_DisplayName);
		Point size{ (int)word.region().size.x + 6, (int)word.region().size.y };
		Rect frame;
		if (m_Width == 0)
			frame = Rect{ pos.x, pos.y, size.x, size.y };
		else {
			frame = Rect{ pos.x, pos.y, m_Width, size.y };
		}
		SetSize(Point(frame.w, frame.h));
		SetClickableRange(frame);
		//Console << GetPosition();
	}

	void MenuButton::Draw() {
		//Console << GetPosition();
		auto word = m_Font(m_DisplayName);
		Point size = GetSize();
		Rect frame = GetClickableRange();
		Point pos = GetPosition();
		if (Judge::isCursorInRect(frame) and MouseL.pressed()) {
			frame.draw(User::Setting::GetTheme().GetMenuButtonBackDownColor());
		}
		else if (Judge::isCursorInRect(frame)) {
			frame.draw(User::Setting::GetTheme().GetMenuButtonBackActiveColor());
			frame.drawFrame(2, 0, User::Setting::GetTheme().GetMenuButtonBackColor());
			frame.drawFrame(1, 0, User::Setting::GetTheme().GetMenuButtonBackDownColor());
		}
		else {
			//Console << frame.pos;
			frame.draw(User::Setting::GetTheme().GetMenuButtonBackColor());
		}

		//Console << GetPosition();
		word.draw(pos.x + 3, pos.y, User::Setting::GetTheme().GetMenuButtonFontColor());
	}
	void MenuButton::Clicked() {
		GetFunction()();
	}
	MenuButton::MenuButton(const String& id_name, const String& display_name) :
		m_IdName(id_name),
		m_DisplayName(display_name)
	{
		SetPosition(Point(0, 0));
		SetClickableRange(Rect(0, 0, 0, 0));
		RemoveFunction();
		m_Width = (int)m_Font(m_DisplayName).region().size.x + 6;
		SetSize(Point(m_Width, (int)m_Font(m_DisplayName).region().size.y));
	}

	MenuButton::MenuButton(const String& id_name, const String& display_name, int width) :
		m_IdName(id_name),
		m_DisplayName(display_name),
		m_Width(width)
	{
		SetPosition(Point(0, 0));
		SetClickableRange(Rect(0, 0, 0, 0));
		RemoveFunction();
		SetSize(Point(width, (int)m_Font(m_DisplayName).region().size.y));
	}
}
