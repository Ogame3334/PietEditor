#include "ColorDish.h"
#include "../../User/User.h"
#include "../../Judge/Judge.h"
#include "../../Constants/Constants.h"
#include "../../Constants/Calc.h"
#include "ColorSelect.h"

namespace OgameWindow {

	void ColorDish::LButtonDown() {
		if (m_id != 20) {
			User::State::SetDrawingColorID(m_id);
			/*if (User::Setting::GetInputMode() == 1) {
				ColorSelect::SetNowCursorPos(m_id);
			}*/
		}
	}
	void ColorDish::RButtonDown() {
		if (m_id < 18) {
			User::State::SetSelectedColorID(m_id);
		}
	}

	void ColorDish::WriteOrder(Point pos, Font font) {
		font(m_Order).draw(TextStyle::Outline(0.30, Palette::White), Arg::center = Point(pos.x + Size / 2, pos.y + Size / 2), Palette::Black);
	}

	void ColorDish::Draw() {
		Point pos = DisplayObject::GetPosition();
		m_outline = Rect{ pos.x, pos.y, Size - 2, Size - 2 };
		Rect color{ pos.x + 3, pos.y + 3, Size - 8, Size - 8 };
		m_outline.drawFrame(1, 0, Palette::Black);
		color.draw(m_Color);
		WriteOrder(pos, m_Font);
	}
	void ColorDish::Update(Point pos) {
		if (m_id < 18)
			m_Order = Constants::Orders[Constants::Calc::ColorIDSub(m_id)];
		if (m_id == 20) {
			int id = User::State::GetDrawingColorID();
			m_Color = Constants::Colors[id];
			m_Order = U"";
		}
		SetClickableRange(m_outline);
		ClickableObject::Update(pos);
	}
}
