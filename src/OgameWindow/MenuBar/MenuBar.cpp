#include "MenuBar.h"
#include "../../User/User.h"
#include "../../Judge/Judge.h"

namespace OgameWindow {
	void MenuBar::ButtonFunctionSetUp() {
		bool isJapanese = User::Setting::GetIsJapanese();
		MenuBox temp_menubox{ 150 , 0 };
		temp_menubox.SetPosition(Point(0, 20));
		temp_menubox.Append(OgameWindow::MenuButton(U"Save", (isJapanese) ? U"保存" : U"Save", temp_menubox.GetWidth()));
		temp_menubox.Append(OgameWindow::MenuButton(U"Exit", (isJapanese) ? U"終了" : U"Exit", temp_menubox.GetWidth()));
		Console << temp_menubox.GetOutline().size;
		Array<MenuButton> buttons = temp_menubox.GetButtons();
		buttons[0].SetFunction([]() { Console << U"保存"; });
		buttons[1].SetFunction([]() { System::Exit(); });
		m_Buttons[0].SetFunction([this, temp_menubox]() { MenuBar::ToggleMenuBox(temp_menubox); });
		m_Buttons[1].SetFunction([]() { Console << U"やあ"; });
	}

	void MenuBar::ToggleMenuBox(MenuBox box) {
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
			MenuButton{U"Mode", (m_isJapanese) ? U"モード" : U"Mode"},
			MenuButton{U"Theme", (m_isJapanese) ? U"テーマ" : U"Theme"}
		};
		ButtonFunctionSetUp();
	}

	void MenuBar::Draw() {
		Rect rect{ 0, 0, Window::GetState().virtualSize.x, 25 };
		SetSize(Point(rect.w, rect.h));
		rect.draw();
		for (auto& button : m_Buttons) {
			button.Draw();
		}
		if (m_MenuBox.GetWidth() != -1) {
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
					for (auto& button : m_Buttons) {
						button.InputUpdate();
					}
					Console << U"ボタン押した";
				}
				else {
					//RemoveMenuBox();
					//m_IsMenuBoxON = false;
					Console << m_MenuBox.GetOutline().size;
				}
			}
		}
	}

	void MenuBar::Update(Point pos) {
		int put_x = 0;
		for (auto& button : m_Buttons) {
			//Console << pos + Point(put_x + 2, 2);
			button.Update(pos + Point(put_x + 2, 2));
			put_x += button.GetSize().x;
		}
		if (m_MenuBox.GetWidth() != -1) {
			m_MenuBox.Update(m_MenuBox.GetPosition());
		}
		DisplayObject::Update(pos);
	}
}
