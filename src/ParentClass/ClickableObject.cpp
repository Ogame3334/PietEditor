#include <Siv3D.hpp>
#include "ClickableObject.h"
#include "../User/User.h"
#include "../Judge/Judge.h"

void ClickableObject::InputUpdate() {
	if (User::State::GetNowSelectObjectID() == GetObjectID()) {
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

void ClickableObject::Update(const Point& pos) {
	DisplayObject::Update(pos);
	if (Judge::isCursorInRect(m_ClickableRange)) {
		User::State::SetNowSelectObjectID(GetObjectID());
	}
}
