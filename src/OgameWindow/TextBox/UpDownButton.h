#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/DisplayObject.h"

namespace OgameWindow {
	class UpDownButton : public DisplayObject {
	private:
		uint32 width;
		bool isUp;
		Shape2D triangle;
	public:
		UpDownButton(uint32 _width, bool _isUp);
		void update() override;
		void draw() override;
	};
}
