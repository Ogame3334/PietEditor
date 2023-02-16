#pragma once

#include <Siv3D.hpp>

namespace OgameWindow {
	class MenuButton {
	private:
		String m_idName;
		String m_displayName;
		Point m_size;

		Font m_font{ 12 , Typeface::CJK_Regular_JP };

		//bool isDown = false;
		//bool isUp = false;

		int Draw(Point pos);

		void Clicked();
	public:
		MenuButton(String id_name, String display_name);

		String GetIDName(void) const { return m_idName; }
		String GetDisplayName(void) const { return m_displayName; }
		Point GetSize(void) const { return m_size; }

		int Put(Point pos);
	};
}
