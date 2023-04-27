#include "DisplayObject.h"

void DisplayObject::inputUpdate() {
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
