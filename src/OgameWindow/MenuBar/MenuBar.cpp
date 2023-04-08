#include "MenuBar.h"
#include "../../User/User.h"
#include "../../Judge/Judge.h"

namespace OgameWindow {
	void MenuBar::ButtonFunctionSetUp() {
		bool isJapanese = User::Setting::GetIsJapanese();
		MenuBox temp_menubox{ 150 , 0 };
		temp_menubox.SetPosition(Point(2, 20));
		temp_menubox.Append(OgameWindow::MenuButton(U"Save", (isJapanese) ? U"保存" : U"Save", temp_menubox.GetWidth()));
		temp_menubox.Append(OgameWindow::MenuButton(U"Exit", (isJapanese) ? U"終了" : U"Exit", temp_menubox.GetWidth()));
		temp_menubox.SetButtonFunction(0, []() {});
		temp_menubox.SetButtonFunction(1, []() { System::Exit(); });
		m_Buttons[0].SetFunction([this, temp_menubox]() { MenuBar::ToggleMenuBox(temp_menubox); });
	}

	void MenuBar::ToggleMenuBox(const MenuBox& box) {
		MenuBox menuBox = GetMenuBox();
		if (not m_IsMenuBoxON) {
			SetMenuBox(box);
			m_IsMenuBoxON = true;
		}
		else if(box.GetID() == menuBox.GetID()){
			RemoveMenuBox();
			m_IsMenuBoxON = false;
		}
		else {
			SetMenuBox(box);
			m_IsMenuBoxON = false;
		}
	}

	MenuBar::MenuBar() {
		m_isJapanese = User::Setting::GetIsJapanese();
		SetPosition(Point(0, 0));
		SetSize(Point(0, 0));
		m_Buttons = {
			MenuButton{U"File", (m_isJapanese) ? U"ファイル" : U"File"},
			MenuButton{U"Edit", (m_isJapanese) ? U"編集" : U"Edit"},
			MenuButton{U"View", (m_isJapanese) ? U"表示" : U"View"},
			MenuButton{U"Canvas", (m_isJapanese) ? U"キャンバス" : U"Canvas"},
			MenuButton{U"Mode", (m_isJapanese) ? U"入力" : U"Input"},
			MenuButton{U"Theme", (m_isJapanese) ? U"テーマ" : U"Theme"}
		};
		ButtonFunctionSetUp();
	}

	void MenuBar::Draw() {
		Rect rect{ 0, 0, Window::GetState().virtualSize.x, 25 };
		SetSize(Point(rect.w, rect.h));
		rect.draw(m_ThemePtr->MenuBarBackGroundColor);
		for (auto& button : m_Buttons) {
			button.Draw();
		}
		if (m_MenuBox.GetID() != -1) {
			m_MenuBox.Draw();
		}
	}

	void MenuBar::InputUpdate() {
		if (not m_IsMenuBoxON) {
			for (auto& button : m_Buttons) {
				button.InputUpdate();
			}
		}
		else {
			if (MouseL.down()) {
				if (Judge::isCursorInRect(m_MenuBox.GetOutline())) {
					m_MenuBox.InputUpdate();
				}
				else {
					RemoveMenuBox();
					m_IsMenuBoxON = false;
				}
			}
		}
	}

	void MenuBar::Update(const Point& pos) {
		int put_x = 0;
		for (auto& button : m_Buttons) {
			//Console << pos + Point(put_x + 2, 2);
			button.Update(pos + Point(put_x + 2, 2));
			put_x += button.GetSize().x;
		}
		if (m_MenuBox.GetID() != -1) {
			m_MenuBox.Update(m_MenuBox.GetPosition());
		}
		DisplayObject::Update(pos);
	}
}
