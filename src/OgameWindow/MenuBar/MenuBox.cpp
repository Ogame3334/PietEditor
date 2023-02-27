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

	void MenuBox::Append(MenuButton button) {
		m_Buttons << button;
		m_Outline.setSize(m_Outline.w, CalcHeight());
	}

	MenuBox::MenuBox() {
		m_Outline = Rect{ 0, 0, -1, 0 };
		m_ID = -1;
	}

	MenuBox::MenuBox(int width, int id) {
		//bool isJapanese = User::Setting::GetIsJapanese();
		//m_Buttons.push_back(MenuButton(U"Save", (isJapanese) ? U"保存" : U"Save", width));
		//m_Buttons.push_back(MenuButton(U"Exit", (isJapanese) ? U"終了" : U"Exit", width));
		m_Outline = Rect{ 0, 0, width, 0 };
		m_ID = id;
	}

	void MenuBox::Draw() {
		Point pos = GetPosition();
		m_Outline.draw(Palette::Lightgray);
		m_Outline.drawFrame(1, 0, Palette::Black);
		
		for (auto& button : m_Buttons) {
			button.Draw();
		}
	}

	void MenuBox::InputUpdate() {
		for (auto& button : m_Buttons) {
			button.InputUpdate();
		}
	}

	void MenuBox::Update(Point pos) {
		DisplayObject::Update(pos);
		m_Outline.pos = pos;
		int i = 0;
		for (auto& button : m_Buttons) {
			button.Update(pos + Point(3, button.GetSize().y * i + 3));
			i++;
		}
	}
}
