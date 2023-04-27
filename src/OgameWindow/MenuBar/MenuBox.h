#pragma once

#include <Siv3D.hpp>
#include "MenuButton.h"
#include "../../ParentClass/DisplayObject.h"

namespace OgameWindow {
	class MenuBox : public DisplayObject{
	private:
		Array<MenuButton> buttons;
		Rect outline;

		int id;
 
		//int MaxWidth();

		/// @brief ボタンの数からボックスの高さを計算する
		/// @return ボックスの高さ
		int calcHeight();

	public:
		/// @brief 標準のコンストラクタ
		MenuBox();
		/// @brief コンストラクタ
		/// @param width ボックスの幅
		/// @param id ボックスID
		MenuBox(int _width, int _id);

		/// @brief ボックスの幅を取得する
		/// @return ボックスの幅
		int getWidth() const { return this->outline.w; }

		/// @brief ボックスIDを取得する
		/// @return ボックスID
		int getID() const { return this->id; }

		/// @brief ボックスの範囲を取得する
		/// @return ボックスの範囲
		Rect getOutline() const { return this->outline; }

		//Array<MenuButton> GetButtons() const { return m_Buttons; }

		/// @brief ボタンを追加する
		/// @param button メニューボタン
		void append(MenuButton _button);

		/// @brief ボタンの機能を追加する
		/// @param num ボタンの配列番号
		/// @param func ボタンの機能
		void setButtonFunction(int _num, std::function<void()> _func);

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
