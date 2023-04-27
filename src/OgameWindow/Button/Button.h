#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/DisplayObject.h"

namespace OgameWindow {
	class Button : public DisplayObject
	{
	private:
		String idName;
		String displayName;
		int fontSize;

		std::function<void()> function;

		Font font;

		//bool isDown = false;
		//bool isUp = false;

		/// @brief ボタンが押された時の挙動
		void clicked();
	public:
		/// @brief コンストラクタ
		/// @param _idName ID名
		/// @param _displayName 表示名
		/// @param _size サイズ
		Button(const String& _idName, const String& _displayName, const Point& _size, int _fontSize);

		/// @brief ボタンの機能を設定
		/// @param function ボタンの機能
		void setFunction(std::function<void()> _function) { this->function = _function; }

		/// @brief ボタンの機能を取得
		/// @return ボタンの機能
		std::function<void()> getFunction() { return this->function; }

		/// @brief ボタンの機能を削除
		void removeFunction() { this->function = []() { return; }; }

		/// @brief ID名を取得
		/// @return ID名
		String setIDName() const { return this->idName; }

		/// @brief 表示名を取得
		/// @return 表示名
		String getDisplayName() const { return this->displayName; }

		/// @brief 左クリックを押した瞬間
		void LButtonDown() override;

		void reload(const Point&, const Size&) override;

		/// @brief オブジェクトを画面に表示する関数
		/// @brief whileでUpdate, InputUpdateの後に呼び出される
		void draw() override;

		/// @brief オブジェクトの状態を更新するメソッド
		/// @param pos オブジェクトの座標
		void update() override;
	};
}
