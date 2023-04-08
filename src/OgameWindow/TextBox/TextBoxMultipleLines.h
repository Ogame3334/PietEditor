#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/ClickableObject.h"
#include "ScrollBar.h"
#include "../../User/User.h"

namespace OgameWindow {
	class TextBoxMultipleLines : public ClickableObject {
	private:
		ScrollBar m_ScrollBar;
		Rect m_TextBox;

		int m_TextHeight;
		int m_DisplayHeight;
		int Padding = 5;
		int m_Line = 0;

		bool m_IsSelected = false;
		bool m_CanEdit;

		Vec2 m_TextBasePos;
		Vec2 m_TextPenPos;
		Vec2 m_TextCursorPos;

		String m_Title = U"";
		String m_Text = U"";
		String m_PreviousText = U"";
		String m_EditingText = U"";

		int m_EditIndex = 0;
		double m_CursorTimer = 0;
		double m_KeyPressTimer = 0;

		Font m_Font;

		void LButtonDown() override;

		void SetEditIndex(int index);

		bool JudgeTextChange();
		void WhenTextChange();
		void EraseText();
		void DeleteText();
		void ClipboardPaste();
		void KeyInput(Input key, std::function<void()> func);
		void KeyInput(InputCombination key, std::function<void()> func);
		void TextInput();
		void DrawCursor(Vec2 penPos);
		void DrawText();
		void ChangeCursorStyle() override;
	public:
		TextBoxMultipleLines(bool canEdit, String title);

		String GetText() const { return m_Text; }

		bool GetIsSelected() const { return m_IsSelected; }

		void Draw() override;
		void InputUpdate() override;
		void Update(const Point& pos, const Point& size);
	};
}
