#include "MenuBar.h"
#include "../../User/User.h"

namespace OgameWindow {
	MenuBar::MenuBar() {
		m_isJapanese = User::Setting::GetIsJapanese();
		buttons = {
			MenuButton{U"File", (m_isJapanese) ? U"ファイル" : U"File"},
			MenuButton{U"Edit", (m_isJapanese) ? U"編集" : U"Edit"},
			MenuButton{U"View", (m_isJapanese) ? U"表示" : U"View"},
			MenuButton{U"Canvas", (m_isJapanese) ? U"キャンバス" : U"Canvas"},
			MenuButton{U"Mode", (m_isJapanese) ? U"モード" : U"Mode"},
			MenuButton{U"Theme", (m_isJapanese) ? U"テーマ" : U"Theme"}
		};
	}

	void MenuBar::Draw(void) {
		Rect{ 0, 0, Window::GetState().virtualSize.x, 25 }.draw();
		int put_x = 0;
		for (auto button : buttons) {
			int temp = button.Put(Point(put_x + 2, 2));
			put_x += temp + 10;
		}
	}
}
