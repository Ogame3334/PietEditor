#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/DisplayObject.h"
#include "ScrollBar.h"
#include "../../User/User.h"

namespace OgameWindow {
	class TextBoxMultipleLines : public DisplayObject {
	private:
		ScrollBar scrollBar;
		Rect textBox;

		int textHeight;
		int displayHeight;
		int Padding = 5;
		int line = 0;

		bool isSelected = false;
		bool canEdit;

		Vec2 textBasePos;
		Vec2 textPenPos;
		Vec2 textCursorPos;

		String title = U"";
		String text = U"";
		String previousText = U"";
		String editingText = U"";

		int editIndex = 0;
		double cursorTimer = 0;
		double keyPressTimer = 0;

		Font font;

		void LButtonDown() override;

		void setEditIndex(int _index);

		bool judgeTextChange();
		void whenTextChange();
		void eraseText();
		void deleteText();
		void clipboardPaste();
		void keyInput(Input _key, std::function<void()> _func);
		void keyInput(InputCombination _key, std::function<void()> _func);
		void textInput();
		void drawCursor(Vec2 _penPos);
		void drawText();
		void changeCursorStyle() override;
	public:
		TextBoxMultipleLines(bool _canEdit, String _title);

		String getText() const { return this->text; }

		bool getIsSelected() const { return this->isSelected; }

		void reload(const Point&, const Size&) override;
		void draw() override;
		void inputUpdate() override;
		//void update(const Point& _pos, const Point& _size);
		void update() override;
	};
}
