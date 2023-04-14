#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/ClickableObject.h"

namespace OgameWindow {
	class UpDownButton : public ClickableObject {
	private:
		uint32 width;
		bool isUp;
		Shape2D triangle;
	public:
		UpDownButton(uint32 _width, bool _isUp);
		void update(const Point& _pos) override;
		void draw() override;
	};
}
