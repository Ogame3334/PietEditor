#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/DisplayObject.h"

namespace OgameWindow {
	class CanvasBackground : public DisplayObject {
	private:
		Rect outline;
	public:
		/// @brief 標準コンストラクタ
		CanvasBackground() = default;
		/// @brief コンストラクタ
		/// @param _pos 座標
		CanvasBackground(Point _pos) {
			setPosition(_pos);
			setSize(Point(Scene::Size().x - _pos.x - 20, Scene::Size().y - _pos.y - 300));
		}
		/// @brief 背景の範囲をRectで取得
		/// @return 背景の範囲
		Rect getOutline() const { return this->outline; }

		/// @brief オブジェクトを画面に表示する関数
		/// @brief whileでUpdate, InputUpdateの後に呼び出される
		void draw() override;
	};
}
