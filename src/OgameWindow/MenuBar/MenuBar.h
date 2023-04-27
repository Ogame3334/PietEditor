#pragma once

#include <Siv3D.hpp>
#include "MenuButton.h"
#include "MenuBox.h"

namespace OgameWindow {
	class MenuBar : public DisplayObject{
	private:
		bool isJapanese;
		Array<MenuButton> buttons = {};

		bool isMenuBoxON = false;
		MenuBox menuBox{};

		/// @brief メニューボタンの挙動を設定する
		void buttonFunctionSetUp();
	public:
		/// @brief コンストラクタ
		MenuBar();

		/// @brief メニューボックスを設定する
		/// @param box メニューボックス
		void setMenuBox(const MenuBox& _box) { this->menuBox = _box; }

		/// @brief メニューボックスを削除する
		void removeMenuBox() { this->menuBox = MenuBox(); }

		/// @brief メニューボックスを取得する
		/// @return メニューボックス
		MenuBox getMenuBox() const { return this->menuBox; }

		/// @brief メニューボックスを表示、削除などを切り替える
		/// @param box 
		void toggleMenuBox(const MenuBox& _box);

		void reload(const Point&, const Size&) override;

		/// @brief オブジェクトを画面に表示する関数
		/// @brief whileでUpdate, InputUpdateの後に呼び出される
		void draw() override;

		/// @brief ユーザーの入力を受け付ける
		/// @brief whileでUpdateの後に呼ばれる
		void inputUpdate();

		/// @brief オブジェクトの状態を更新するメソッド
		/// @param pos オブジェクトの座標
		void update() override;
	};
}
