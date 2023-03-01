#pragma once

#include <Siv3D.hpp>
#include "MenuButton.h"
#include "MenuBox.h"

namespace OgameWindow {
	class MenuBar : public DisplayObject{
	private:
		bool m_isJapanese;
		Array<MenuButton> m_Buttons = {};

		bool m_IsMenuBoxON = false;
		MenuBox m_MenuBox{};

		/// @brief メニューボタンの挙動を設定する
		void ButtonFunctionSetUp();
	public:
		/// @brief コンストラクタ
		MenuBar();

		/// @brief メニューボックスを設定する
		/// @param box メニューボックス
		void SetMenuBox(const MenuBox& box) { m_MenuBox = box; }

		/// @brief メニューボックスを削除する
		void RemoveMenuBox() { m_MenuBox = MenuBox(); }

		/// @brief メニューボックスを取得する
		/// @return メニューボックス
		MenuBox GetMenuBox() const { return m_MenuBox; }

		/// @brief メニューボックスを表示、削除などを切り替える
		/// @param box 
		void ToggleMenuBox(const MenuBox& box);

		/// @brief オブジェクトを画面に表示する関数
		/// @brief whileでUpdate, InputUpdateの後に呼び出される
		void Draw() override;

		/// @brief ユーザーの入力を受け付ける
		/// @brief whileでUpdateの後に呼ばれる
		void InputUpdate();

		/// @brief オブジェクトの状態を更新するメソッド
		/// @param pos オブジェクトの座標
		void Update(const Point& pos) override;
	};
}
