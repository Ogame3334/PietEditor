#include "ScrollBar.h"
#include "../../Judge/Judge.h"
#include "../../User/User.h"

namespace OgameWindow {
	void ScrollBar::LButtonDown() {
		m_IsHolding = true;
	}

	void ScrollBar::AddBarLocalPosY(int y) {
		m_BarLocalPosY += y;
		if (m_BarLocalPosY < 0)
			m_BarLocalPosY = 0;
		int temp = GetSize().y - 2 * Width - m_Bar.h;
		if (m_BarLocalPosY > temp)
			m_BarLocalPosY = temp;
	}

	void ScrollBar::SetValue(int value) {
		if (value == 0) {
			m_Value = value;
			m_BarLocalPosY = 0;
		}
		else if (value == 1) {
			m_Value = value;
			m_BarLocalPosY = GetSize().y - Width - m_Bar.h;
		}
		else {
			m_Value = value;
			m_BarLocalPosY = value * (GetSize().y - 2 * Width - m_Bar.h);
		}
	}

	ScrollBar::ScrollBar(uint32 width, int height, int displayHeight, int regionHeight) :
		Width(width),
		m_DisplayHeight(displayHeight),
		m_RegionHeight(regionHeight)
	{
		m_Region = Rect(GetPosition(), Width, height);
		m_Bar = Rect(GetPosition() + Point(2, Width * 11 / 10), Width - 4, (int)((height - 2 * Width) * ((float)displayHeight / regionHeight)));
		SetClickableRange(m_Bar);
		SetPosition(Point(0, 0));
		SetSize(Point(m_Region.w, m_Region.h));
	}

	void ScrollBar::Draw() {
		if (m_Enable) {
			m_Region.drawFrame(1, m_ThemePtr->ScrollBarOutlineColor);
			m_Region.draw(m_ThemePtr->ScrollBarBackColor);
			m_UpButton.Draw();
			m_DownButton.Draw();
			if (Judge::isCursorInRect(GetClickableRange()) or m_IsHolding)
				m_Bar.draw(m_ThemePtr->ScrollBarActiveColor);
			else
				m_Bar.draw(m_ThemePtr->ScrollBarColor);
		}
	}

	void ScrollBar::InputUpdate() {
		if (m_Enable) {
			ClickableObject::InputUpdate();
			m_UpButton.InputUpdate();
			m_DownButton.InputUpdate();
			if (m_IsHolding) {
				Cursor::RequestStyle(CursorStyle::Hand);
				AddBarLocalPosY(Cursor::Delta().y);
			}
		}
	}

	double ScrollBar::UpdateDouble(const Point& pos, int height) {
		ClickableObject::Update(pos);
		SetSize(Point(GetSize().x, height));
		if (MouseL.up())
			m_IsHolding = false;
		//uint32 height = GetSize().y;
		m_Region = Rect(GetPosition(), Width, height);
		m_UpButton.Update(pos);
		m_DownButton.Update(pos + Point(0, height - Width));
		m_Bar = Rect(GetPosition() + Point(2, Width * 11 / 10 + m_BarLocalPosY), Width - 4, (int)((height - 2 * Width) * ((float)m_DisplayHeight / m_RegionHeight)));
		SetClickableRange(m_Bar);

		if (m_Enable) {

			int temp = GetSize().y - 2 * Width - m_Bar.h;

			if (m_DisplayHeight < m_RegionHeight) {
				if (m_BarLocalPosY > temp)
					m_BarLocalPosY = temp;
			}

			return (double)m_BarLocalPosY / temp;
		}
		else {
			return 0;
		}
	}
}
