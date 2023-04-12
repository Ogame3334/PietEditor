namespace Judge {
	bool IsCursorInRect(Rect rect) {
		Point cursorPos = Cursor::Pos();
		if (cursorPos.x > rect.x and cursorPos.x < rect.x + rect.w and cursorPos.y > rect.y and cursorPos.y < rect.y + rect.h) {
			return true;
		}
		else {
			return false;
		}
	}
}
