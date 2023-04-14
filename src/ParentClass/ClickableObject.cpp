#include <Siv3D.hpp>
#include "ClickableObject.h"
#include "../User/User.h"
#include "../Judge/Judge.h"

void ClickableObject::inputUpdate() {
	if (User::State::GetNowSelectObjectID() == this->getObjectID() and this->enable) {
		changeCursorStyle();
		if (MouseL.down()) LButtonDown();
		if (MouseL.pressed()) LButtonPressed();
		if (MouseL.up()) LButtonUp();
		if (MouseR.down()) RButtonDown();
		if (MouseR.pressed()) RButtonPressed();
		if (MouseR.up()) RButtonUp();
		if (MouseM.down()) MButtonDown();
		if (MouseM.pressed()) MButtonPressed();
		if (MouseM.up()) MButtonUp();
	}
}

void ClickableObject::update(const Point& _pos) {
	DisplayObject::update(_pos);
	if (Judge::IsCursorInRect(this->clickableRange)) {
		User::State::SetNowSelectObjectID(this->getObjectID());
	}
}
