#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/DisplayObject.h"
#include "../../OgameWindow/Canvas/Canvas.h"
#include "../../User/User.h"

namespace OgameWindow {
	class StatusBar : DisplayObject {
	private:
		String rightString = U"";
		Font font{ 15, themePtr->StatusBarFont };

		void changeRightString(const Canvas& _canvas);
	public:
		/// @brief コンストラクタ
		StatusBar();

		static const int Height = 25;

		/// @brief 描画する
		void draw() override;
		/// @brief 更新する
		void update(const Canvas& _canvas);
	};
}
