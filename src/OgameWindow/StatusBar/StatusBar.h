#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/DisplayObject.h"
#include "../../OgameWindow/Canvas/Canvas.h"
#include "../../User/User.h"

namespace OgameWindow {
	class StatusBar : DisplayObject {
	private:
		String m_RightString = U"";
		Font m_Font{ 15, User::Setting::GetTheme().GetStatusBarFont() };

		void ChangeRightString(const Canvas& canvas);
	public:
		/// @brief コンストラクタ
		StatusBar();

		static const int Height = 25;

		/// @brief 描画する
		void Draw() override;
		/// @brief 更新する
		void Update(const Canvas& canvas);
	};
}
