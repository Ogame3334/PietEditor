#include "MenuButton.h"
#include "../../Judge/Judge.h"

namespace OgameWindow {
	int MenuButton::Draw(Point pos) {
		auto word = m_font(m_displayName);
		Print << m_displayName;
		Rect frame{ pos.x, pos.y, m_size.x, m_size.y };
		Print << U"x: " << (int)word.region().size.x;
		if (Judge::isCursorInRect(frame) and MouseL.pressed()) {
			frame.draw(Color(215, 238, 255));
		}
		else if (Judge::isCursorInRect(frame)) {
			frame.draw(Color(230, 244, 255));
			frame.drawFrame(2, 0, Color(255, 255, 255));
			frame.drawFrame(1, 0, Color(215, 238, 255));
		}
		else {
			frame.draw();
		}

		word.draw(pos.x + 3, pos.y, Palette::Black);

		return (int)word.region().size.x;
	}
	void MenuButton::Clicked() {

	}
	MenuButton::MenuButton(String id_name, String display_name) :
		m_idName(id_name),
		m_displayName(display_name)
	{
		auto word = m_font(m_displayName);
		m_size = Point{ (int)word.region().size.x + 6, (int)word.region().size.y };
	}

	int MenuButton::Put(Point pos) {
		return Draw(pos);
	}
}
