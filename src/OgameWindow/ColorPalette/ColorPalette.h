#pragma once
#include <Siv3D.hpp>
#include "ColorDish.h"
#include "../../ParentClass/DisplayObject.h"

namespace OgameWindow {
	class ColorPalette : public DisplayObject{
	private:
		Array<ColorDish> m_colorDishes;
		Font m_Font;
	public:
		ColorPalette(Point pos);

		void Draw() override;
		void InputUpdate();
		void Update(Point pos) override;
	};
}
