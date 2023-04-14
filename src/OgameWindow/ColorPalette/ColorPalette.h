#pragma once
#include <Siv3D.hpp>
#include "ColorDish.h"
#include "../../ParentClass/DisplayObject.h"

namespace OgameWindow {
	class ColorPalette : public DisplayObject{
	private:
		Array<ColorDish> colorDishes;
		Font font;
	public:
		/// @brief コンストラクタ
		/// @param pos 座標
		ColorPalette(const Point& _pos);

		/// @brief オブジェクトを画面に表示する関数
		/// @brief whileでUpdate, InputUpdateの後に呼び出される
		void draw() override;

		/// @brief ユーザーの入力を受け付ける
		/// @brief whileでUpdateの後に呼ばれる
		void inputUpdate();

		/// @brief オブジェクトの状態を更新するメソッド
		/// @param pos オブジェクトの座標
		void update(const Point& _pos) override;
	};
}
