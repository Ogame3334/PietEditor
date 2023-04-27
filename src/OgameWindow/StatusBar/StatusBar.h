#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/DisplayObject.h"
#include "../../OgameWindow/Canvas/Canvas.h"
#include "../../User/User.h"

namespace OgameWindow {
	class StatusBar : public DisplayObject {
	private:
		String rightString = U"";
		Font font{ 15, themePtr->StatusBarFont };

		inline static Canvas canvas{};

		void changeRightString();
	public:
		/// @brief コンストラクタ
		StatusBar();

		static const int Height = 25;

		static void SetCanvas(const Canvas& _canvas) {
			canvas = _canvas;
		}

		void reload(const Point&, const Size&) override;

		/// @brief 描画する
		void draw() override;
		/// @brief 更新する
		//void update(const Canvas& _canvas);
		void update() override;
	};
}
