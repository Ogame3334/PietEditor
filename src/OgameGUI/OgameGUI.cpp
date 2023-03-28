#include "OgameGUI.h"

namespace s3d {
	namespace SimpleGUI {
		bool TextBoxMultipleLines(TextEditState& text, const Point& pos, const Point& size, const Optional<size_t>& maxChars, bool enabled) {
			return TextBoxMultipleLinesAt(text, pos + Point((int)(size.x / 2), (int)(size.y / 2)), size, maxChars, enabled);
		}

		bool TextBoxMultipleLinesAt(TextEditState& text, const Point& center, const Point& size, const Optional<size_t>& maxChars, bool enabled) {
			const int32 FontYOffset = -1;

			const Font font = GetFont();
			const Rect region{ center.x - size.x / 2, center.y - size.y /2, size.x, size.y };
			const Vec2 textPos{ (region.x + 8), (center.y - font.height() / 2 + FontYOffset - 0.5) };
			const ColorF textColor = GetTextColor(enabled);
			const String previousText = text.text;
			const String editingText = ((text.active && enabled) ? TextInput::GetEditingText() : U"");

			text.cursorPos = Min(text.cursorPos, text.text.size());
			text.tabKey = false;
			text.enterKey = false;

			region.draw();

			return true;
		}
	}
}
