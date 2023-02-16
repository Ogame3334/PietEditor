#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/DisplayObject.h"

namespace OgameWindow {
	class CanvasBackground : public DisplayObject{
	private:
		Rect m_outline;
	public:
		CanvasBackground() {};
		CanvasBackground(Point pos) {
			SetPosition(pos);
		}
		Rect GetOutline() const { return m_outline; }

		void Draw() override;
		void Update(Point pos) override;
	};
}
