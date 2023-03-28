#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/ClickableObject.h"

namespace OgameWindow {
	class UpDownButton : public ClickableObject {
	private:
		uint32 m_Width;
		bool m_IsUp;
		Shape2D m_Triangle;
	public:
		UpDownButton(uint32 width, bool isUp);
		void Update(const Point& pos) override;
		void Draw() override;
	};
}
