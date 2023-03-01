#pragma once

#include <Siv3D.hpp>
#include "MenuButton.h"
#include "../../ParentClass/DisplayObject.h"

namespace OgameWindow {
	class MenuBox : public DisplayObject{
	private:
		Array<MenuButton> m_Buttons;
		Rect m_Outline;

		int m_ID;
 
		//int MaxWidth();

		/// @brief ボタンの数からボックスの高さを計算する
		/// @return ボックスの高さ
		int CalcHeight();

	public:
		/// @brief 標準のコンストラクタ
		MenuBox();
		/// @brief コンストラクタ
		/// @param width ボックスの幅
		/// @param id ボックスID
		MenuBox(int width, int id);

		/// @brief ボックスの幅を取得する
		/// @return ボックスの幅
		int GetWidth() const { return m_Outline.w; }

		/// @brief ボックスIDを取得する
		/// @return ボックスID
		int GetID() const { return m_ID; }

		/// @brief ボックスの範囲を取得する
		/// @return ボックスの範囲
		Rect GetOutline() const { return m_Outline; }

		//Array<MenuButton> GetButtons() const { return m_Buttons; }

		/// @brief ボタンを追加する
		/// @param button メニューボタン
		void Append(MenuButton button);

		/// @brief ボタンの機能を追加する
		/// @param num ボタンの配列番号
		/// @param func ボタンの機能
		void SetButtonFunction(int num, std::function<void()> func);

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
