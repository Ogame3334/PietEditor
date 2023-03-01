#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/DisplayObject.h"

namespace OgameWindow {
	class CanvasBackground : public DisplayObject{
	private:
		Rect m_outline;
	public:
		/// @brief 標準コンストラクタ
		CanvasBackground() {};
		/// @brief コンストラクタ
		/// @param pos 座標
		CanvasBackground(Point pos) {
			SetPosition(pos);
		}
		/// @brief 背景の範囲をRectで取得
		/// @return 背景の範囲
		Rect GetOutline() const { return m_outline; }

		/// @brief オブジェクトを画面に表示する関数
		/// @brief whileでUpdate, InputUpdateの後に呼び出される
		void Draw() override;
	};
}
