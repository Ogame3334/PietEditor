#include "MenuButton.h"
#include "../../Judge/Judge.h"

namespace OgameWindow {
	void MenuButton::LButtonDown() {
		Clicked();
	}

	void MenuButton::Update(Point pos) {
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
			frame.draw(Color(215, 238, 255));
		}
		else if (Judge::isCursorInRect(frame)) {
			frame.draw(Color(230, 244, 255));
			frame.drawFrame(2, 0, Color(255, 255, 255));
			frame.drawFrame(1, 0, Color(215, 238, 255));
		}
		else {
			//Console << frame.pos;
			frame.draw();
		}

		//Console << GetPosition();
		word.draw(pos.x + 3, pos.y, Palette::Black);
	}
	void MenuButton::Clicked() {
		GetFunction()();
	}
	MenuButton::MenuButton(String id_name, String display_name) :
		m_IdName(id_name),
		m_DisplayName(display_name)
	{
		SetPosition(Point(0, 0));
		SetSize(Point(0, 0));
		SetClickableRange(Rect(0, 0, 0, 0));
		RemoveFunction();
	}

	MenuButton::MenuButton(String id_name, String display_name, int width) :
		m_IdName(id_name),
		m_DisplayName(display_name),
		m_Width(width)
	{
		SetPosition(Point(0, 0));
		SetSize(Point(0, 0));
		SetClickableRange(Rect(0, 0, 0, 0));
		RemoveFunction();
	}
}
