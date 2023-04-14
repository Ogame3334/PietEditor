#include "MenuBar.h"
#include "../../User/User.h"
#include "../../Judge/Judge.h"

namespace OgameWindow {
	void MenuBar::buttonFunctionSetUp() {
		bool isJapanese = User::Setting::GetIsJapanese();
		MenuBox temp_menubox{ 150 , 0 };
		temp_menubox.setPosition(Point(2, 20));
		temp_menubox.append(OgameWindow::MenuButton(U"Save", (isJapanese) ? U"保存" : U"Save", temp_menubox.getWidth()));
		temp_menubox.append(OgameWindow::MenuButton(U"Exit", (isJapanese) ? U"終了" : U"Exit", temp_menubox.getWidth()));
		temp_menubox.setButtonFunction(0, []() {});
		temp_menubox.setButtonFunction(1, []() { System::Exit(); });
		this->buttons[0].setFunction([this, temp_menubox]() { MenuBar::toggleMenuBox(temp_menubox); });
	}

	void MenuBar::toggleMenuBox(const MenuBox& _box) {
		MenuBox menuBox = getMenuBox();
		if (not this->isMenuBoxON) {
			setMenuBox(_box);
			this->isMenuBoxON = true;
		}
		else if(_box.getID() == menuBox.getID()){
			removeMenuBox();
			this->isMenuBoxON = false;
		}
		else {
			setMenuBox(_box);
			this->isMenuBoxON = false;
		}
	}

	MenuBar::MenuBar() {
		this->isJapanese = User::Setting::GetIsJapanese();
		setPosition(Point(0, 0));
		setSize(Point(0, 0));
		this->buttons = {
			MenuButton{U"File", (this->isJapanese) ? U"ファイル" : U"File"},
			MenuButton{U"Edit", (this->isJapanese) ? U"編集" : U"Edit"},
			MenuButton{U"View", (this->isJapanese) ? U"表示" : U"View"},
			MenuButton{U"Canvas", (this->isJapanese) ? U"キャンバス" : U"Canvas"},
			MenuButton{U"Mode", (this->isJapanese) ? U"入力" : U"Input"},
			MenuButton{U"Theme", (this->isJapanese) ? U"テーマ" : U"Theme"}
		};
		buttonFunctionSetUp();
	}

	void MenuBar::draw() {
		Rect rect{ 0, 0, Window::GetState().virtualSize.x, 25 };
		setSize(Point(rect.w, rect.h));
		rect.draw(this->themePtr->MenuBarBackGroundColor);
		for (auto& button : this->buttons) {
			button.draw();
		}
		if (this->menuBox.getID() != -1) {
			this->menuBox.draw();
		}
	}

	void MenuBar::inputUpdate() {
		if (not this->isMenuBoxON) {
			for (auto& button : this->buttons) {
				button.inputUpdate();
			}
		}
		else {
			if (MouseL.down()) {
				if (Judge::IsCursorInRect(this->menuBox.getOutline())) {
					this->menuBox.inputUpdate();
				}
				else {
					removeMenuBox();
					this->isMenuBoxON = false;
				}
			}
		}
	}

	void MenuBar::update(const Point& _pos) {
		int put_x = 0;
		for (auto& button : this->buttons) {
			//Console << pos + Point(put_x + 2, 2);
			button.update(_pos + Point(put_x + 2, 2));
			put_x += button.getSize().x;
		}
		if (this->menuBox.getID() != -1) {
			this->menuBox.update(this->menuBox.getPosition());
		}
		DisplayObject::update(_pos);
	}
}
