#include "UpDownButton.h"
#include "../../Judge/Judge.h"
#include "../../User/User.h"

namespace OgameWindow {
	UpDownButton::UpDownButton(uint32 width, bool isUp) {
		if(isUp)
			m_Triangle = Shape2D::Ngon(3, width / 2, Point(0, 0));
		else
			m_Triangle = Shape2D::Ngon(3, width / 2, Point(0, 0), 180_deg);
		m_IsUp = isUp;
		m_Width = width;
		SetPosition(Point(0, 0));
		SetClickableRange(Rect(0, 0, width, width));
		SetSize(Point(width, width));
	}

	void UpDownButton::Update(const Point& pos) {
		ClickableObject::Update(pos);
		if (m_IsUp)
			m_Triangle = Shape2D::Ngon(3, m_Width * 3 / 8, pos + Point(m_Width / 2, m_Width / 2));
		else
			m_Triangle = Shape2D::Ngon(3, m_Width * 3 / 8, pos + Point(m_Width / 2, m_Width / 2), 180_deg);
		SetPosition(pos);
		SetClickableRange(Rect(pos, m_Width, m_Width));
	}

	void UpDownButton::Draw() {
		GetClickableRange().draw(m_ThemePtr->ScrollBarButtonBackColor);
		if (Judge::isCursorInRect(GetClickableRange())) {
			m_Triangle.draw(m_ThemePtr->ScrollBarButtonTriangleActiveColor);
		}
		else {
			m_Triangle.draw(m_ThemePtr->ScrollBarButtonTriangleColor);
		}
	}
}
