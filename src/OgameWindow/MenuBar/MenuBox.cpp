#include "MenuBox.h"
#include "../../User/User.h"
#include "MenuButton.h"

namespace OgameWindow {
	int MenuBox::MaxWidth() {
		int max = 0;
		for (const auto& button : m_Buttons) {
			if (max < button.GetSize().x) {
				max = button.GetSize().x;
			}
		}
		return max;
	}

	int MenuBox::CalcHeight() {
		int temp = 0;
		for (const auto& button : m_Buttons) {
			temp += button.GetSize().y;
		}
		return temp;
	}

	MenuBox::MenuBox() {
		bool isJapanese = User::Setting::GetIsJapanese();
		m_Buttons.push_back(MenuButton(U"Save", (isJapanese) ? U"保存" : U"Save"));
		m_Buttons.push_back(MenuButton(U"Exit", (isJapanese) ? U"終了" : U"Exit"));
		m_Outline = Rect{ 0, 0, 80, CalcHeight() + 6 };
	}

	void MenuBox::Draw(Point pos) {
		m_Outline.x = pos.x;
		m_Outline.y = pos.y;
		m_Outline.draw(Palette::Lightgray);
		m_Outline.drawFrame(1, 0, Palette::Black);
		int i = 0;
		for (auto button : m_Buttons) {
			button.Put(pos + Point(3, button.GetSize().y * i + 3));
			i++;
		}
	}
}
