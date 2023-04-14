#include <Siv3D.hpp>
#include "Codel.h"
#include "../../Judge/Judge.h"
#include "../../User/User.h"
#include "../../Constants/Constants.h"

namespace OgameWindow {
	void Codel::LButtonPressed() {
		if (Judge::IsCursorInRect(this->tile)) {
			this->colorID = User::State::GetDrawingColorID();
		}
	}
	void Codel::RButtonDown() {
		if (Judge::IsCursorInRect(this->tile))
			User::State::SetDrawingColorID(this->colorID);
	}
	void Codel::draw() {
		Point pos = DisplayObject::getPosition();
		this->tile = Rect{ pos.x, pos.y, CodelSize, CodelSize };
		this->tile.draw(Constants::Colors[this->colorID]);
		this->tile.drawFrame(1, 0, Palette::Gray);
	}
	void Codel::update(const Point& _pos) {
		DisplayObject::setSize(Point(this->tile.w, this->tile.h));
		ClickableObject::setClickableRange(this->tile);
		ClickableObject::update(_pos);
		if (User::State::GetMode() == Mode::DEBUG)
			setEnable(false);
		else
			setEnable(true);
	}
}
