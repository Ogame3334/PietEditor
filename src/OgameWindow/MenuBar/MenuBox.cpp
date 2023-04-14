#include "MenuBox.h"
#include "../../User/User.h"
#include "MenuButton.h"

namespace OgameWindow {
	/*int MenuBox::MaxWidth() {
		int max = 0;
		for (const auto& button : m_Buttons) {
			if (max < button.GetSize().x) {
				max = button.GetSize().x;
			}
		}
		return max;
	}*/

	int MenuBox::calcHeight() {
		int temp = 0;
		for (const auto& button : this->buttons) {
			temp += button.getSize().y;
		}
		return temp;
	}

	void MenuBox::append(MenuButton _button) {
		this->buttons << _button;
		this->outline.setSize(outline.w, calcHeight());
	}

	void MenuBox::setButtonFunction(int _num, std::function<void()> _func) {
		auto& button = this->buttons[_num];
		button.setFunction(_func);
	}

	MenuBox::MenuBox() {
		this->outline = Rect{ 0, 0, 0, 0 };
		this->id = -1;
	}

	MenuBox::MenuBox(int _width, int _id) {
		//bool isJapanese = User::Setting::GetIsJapanese();
		//m_Buttons.push_back(MenuButton(U"Save", (isJapanese) ? U"保存" : U"Save", width));
		//m_Buttons.push_back(MenuButton(U"Exit", (isJapanese) ? U"終了" : U"Exit", width));
		this->outline = Rect{ 0, 0, _width, 0 };
		this->id = _id;
	}

	void MenuBox::draw() {
		Point pos = getPosition();
		//m_Outline.draw(Palette::Lightgray);
		//m_Outline.drawFrame(1, 0, Palette::Black);
		
		for (auto& button : this->buttons) {
			button.draw();
		}
	}

	void MenuBox::inputUpdate() {
		for (auto& button : this->buttons) {
			button.inputUpdate();
		}
	}

	void MenuBox::update(const Point& _pos) {
		DisplayObject::update(_pos);
		this->outline.pos = _pos;
		int i = 0;
		for (auto& button : this->buttons) {
			button.update(_pos + Point(0, button.getSize().y * i + 3));
			i++;
		}
	}
}
