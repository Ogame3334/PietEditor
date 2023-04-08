#include <Siv3D.hpp>
#include "Codel.h"
#include "../../Judge/Judge.h"
#include "../../User/User.h"
#include "../../Constants/Constants.h"

namespace OgameWindow {
	void Codel::LButtonPressed() {
		if (Judge::isCursorInRect(m_Tile)) {
			m_ColorID = User::State::GetDrawingColorID();
		}
	}
	void Codel::RButtonDown() {
		if (Judge::isCursorInRect(m_Tile))
			User::State::SetDrawingColorID(m_ColorID);
	}
	void Codel::Draw() {
		Point pos = DisplayObject::GetPosition();
		m_Tile = Rect{ pos.x, pos.y, CodelSize, CodelSize };
		m_Tile.draw(Constants::Colors[m_ColorID]);
		m_Tile.drawFrame(1, 0, Palette::Gray);
	}
	void Codel::Update(const Point& pos) {
		DisplayObject::SetSize(Point(m_Tile.w, m_Tile.h));
		ClickableObject::SetClickableRange(m_Tile);
		ClickableObject::Update(pos);
		if (User::State::GetMode() == Mode::DEBUG)
			SetEnable(false);
		else
			SetEnable(true);
	}
}
