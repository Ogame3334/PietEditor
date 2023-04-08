#include "TextBoxMultipleLines.h"

namespace OgameWindow {
	void TextBoxMultipleLines::LButtonDown() {
		if (m_CanEdit) {
			m_IsSelected = true;
		}
	}

	void TextBoxMultipleLines::SetEditIndex(int index) {
		m_EditIndex = index;
		if (m_EditIndex < 0) {
			m_EditIndex = 0;
		}
		else if (m_EditIndex > m_Text.length()) {
			m_EditIndex = (int)m_Text.length();
		}
		else {
			m_CursorTimer = 0;
		}
	}

	TextBoxMultipleLines::TextBoxMultipleLines(bool canEdit, String title) :
		m_ScrollBar(ScrollBar{ 16, 10, 10, 20 }),
		m_TextBox(Rect(0, 0, 0, 0)),
		m_TextHeight(0),
		m_CanEdit(canEdit),
		m_Title(title)
	{
		m_Font = Font(15, m_ThemePtr->TextBoxFont);
		SetSize(Point(0, 0));
		SetPosition(Point(0, 0));
		SetClickableRange(Rect(0, 0, Point(0, 0)));
		m_TextBox.setSize(0, m_Font.height());
	}

	bool TextBoxMultipleLines::JudgeTextChange() {
		bool return_bool;
		if (m_Text != m_PreviousText)
			return_bool = true;
		else
			return_bool = false;
		m_PreviousText = m_Text;
		return return_bool;
	}

	void TextBoxMultipleLines::WhenTextChange() {
		if (JudgeTextChange()) {
			m_CursorTimer = 0;
			if (m_TextCursorPos.y + (int)m_Font.height() * 2 > GetClickableRange().y + GetClickableRange().h) {
				m_ScrollBar.SetValue(1);
			}
		}
	}

	void TextBoxMultipleLines::EraseText() {
		if (m_EditIndex > 0) {
			m_Text.erase(m_EditIndex - 1);
			m_EditIndex--;
		}
	}

	void TextBoxMultipleLines::DeleteText() {
		m_Text.erase(m_EditIndex);
	}

	void TextBoxMultipleLines::ClipboardPaste() {
		String temp;
		if (Clipboard::GetText(temp)) {
			m_Text.append(temp);
			m_EditIndex += (int)temp.length();
		}
	}

	void TextBoxMultipleLines::KeyInput(Input key, std::function<void()> func) {
		if (key.pressed()) {
			Duration dur = key.pressedDuration();
			if (key.down()) {
				func();
				m_KeyPressTimer = 0;
			}
			if (dur.count() > 0.5) {
				m_KeyPressTimer += Scene::DeltaTime();
				if (m_KeyPressTimer > 0.03) {
					func();
					m_KeyPressTimer -= 0.03;
				}
			}
		}
	}
	void TextBoxMultipleLines::KeyInput(InputCombination key, std::function<void()> func) {
		if (key.pressed()) {
			Duration dur = key.pressedDuration();
			if (key.down()) {
				func();
				m_KeyPressTimer = 0;
			}
			if (dur.count() > 0.5) {
				m_KeyPressTimer += Scene::DeltaTime();
				if (m_KeyPressTimer > 0.03) {
					func();
					m_KeyPressTimer -= 0.03;
				}
			}
		}
	}

	void TextBoxMultipleLines::TextInput() {
		if (m_IsSelected) {
			String chara = U"";
			TextInput::UpdateText(chara);

			if (chara != U"") {
				m_Text.insert(m_EditIndex, chara);
				m_EditIndex += (int)chara.length();
				chara = U"";
			}

			if (m_EditingText == U"") {
				KeyInput(KeyBackspace, [this]() { EraseText(); });
				KeyInput(KeyDelete, [this]() { DeleteText(); });
				KeyInput(KeyLeft, [this]() { SetEditIndex(m_EditIndex - 1); });
				KeyInput(KeyRight, [this]() { SetEditIndex(m_EditIndex + 1); });
			}
			KeyInput((KeyControl + KeyV), [this]() { ClipboardPaste(); });
		}
	}

	void TextBoxMultipleLines::DrawCursor(Vec2 penPos) {
		m_CursorTimer += Scene::DeltaTime();
		if (m_CursorTimer > 0 and m_CursorTimer <= 0.6) {
			Line line{ penPos + Point(0, 2), penPos + Point(0, (int)m_Font.height() - 2) };
			line.draw(1, m_ThemePtr->TextBoxCursorColor);
		}
		else if (m_CursorTimer > 1.2) {
			m_CursorTimer -= 1.2;
		}
	}

	void TextBoxMultipleLines::DrawText() {
		if (m_IsSelected) {
			{
				Graphics2D::SetScissorRect(GetClickableRange());
				RasterizerState rs = RasterizerState::Default2D;
				// シザー矩形を有効化
				rs.scissorEnable = true;
				ScopedRenderStates2D rasterizer{ rs };
				m_TextBasePos = m_TextBox.pos;
				m_TextPenPos = m_TextBasePos;
				m_TextCursorPos = m_TextPenPos;
				int num = 0;
				//Console << m_EditIndex;
				if (m_Text == U"" and m_IsSelected) {
					DrawCursor(m_TextPenPos);
				}
				else {
					for (const auto& glyph : m_Font.getGlyphs(m_Text)) {
						if (glyph.codePoint == U'\n')
						{
							if (num == m_EditIndex and m_IsSelected) {
								m_TextPenPos.x += glyph.xAdvance;
								m_TextCursorPos = m_TextPenPos;
								DrawCursor(m_TextPenPos - Vec2(glyph.xAdvance, 0));
								//Console << num;
							}

							// ペンの X 座標をリセット
							m_TextPenPos.x = m_TextBasePos.x;

							// ペンの Y 座標をフォントの高さ分進める
							m_TextPenPos.y += m_Font.height();

							num++;
							continue;
						}

						if (m_TextPenPos.x + glyph.xAdvance > m_TextBox.x + m_TextBox.w) {
							m_TextPenPos.x = m_TextBasePos.x;
							m_TextPenPos.y += m_Font.height();
						}

						glyph.texture.draw(Math::Round(m_TextPenPos + glyph.getOffset()), Palette::Black);

						// ペンの X 座標を文字の幅の分進める
						m_TextPenPos.x += glyph.xAdvance;

						if (num == m_EditIndex and m_IsSelected) {
							m_TextCursorPos = m_TextPenPos;
							DrawCursor(m_TextPenPos - Vec2(glyph.xAdvance, 0));
							//Console << num;
						}

						num++;
					}
					if (num == m_EditIndex and m_IsSelected) {
						m_TextCursorPos = m_TextPenPos;
						DrawCursor(m_TextPenPos - Vec2(m_Font.getGlyph(m_Text.substr(m_Text.length())).xAdvance, 0));
						//Console << num;
					}
				}
				//Console << GetClickableRange().y + GetClickableRange().h;
				m_TextBox.setSize(m_TextBox.w, (int)(m_TextPenPos.y + m_Font.height() - m_TextBox.y));
				m_ScrollBar.SetRegionHeight(m_TextBox.h);
			}
			m_EditingText = TextInput::GetEditingText();
			auto text = m_Font(m_EditingText);
			text.region(m_TextPenPos).draw(m_ThemePtr->TextBoxBackColor);
			text.draw(m_TextPenPos, m_ThemePtr->TextBoxFontColor);
		}
	}

	void TextBoxMultipleLines::ChangeCursorStyle() {
		if (m_CanEdit) {
			Cursor::RequestStyle(CursorStyle::IBeam);
		}
	}

	void TextBoxMultipleLines::Draw() {
		if (GetClickableRange().h < m_TextBox.h) {
			m_ScrollBar.SetEnable(true);
		}
		else {
			m_ScrollBar.SetEnable(false);
		}
		m_ScrollBar.Draw();
		GetClickableRange().drawFrame(1, m_ThemePtr->TextBoxOutlineColor);
		GetClickableRange().draw(m_ThemePtr->TextBoxBackColor);
		if (m_IsSelected) {
			GetClickableRange().drawFrame(1, m_ThemePtr->TextBoxActiveOutlineColor);
		}
		//m_TextBox.draw(Palette::Red);
		DrawText();
		m_Font(m_Title).draw(GetPosition() + Point(10, -30), m_ThemePtr->TextBoxTitleFontColor);
	}

	void TextBoxMultipleLines::InputUpdate() {
		ClickableObject::InputUpdate();
		m_ScrollBar.InputUpdate();
	}

	void TextBoxMultipleLines::Update(const Point& pos, const Point& size) {
		ClickableObject::Update(pos);
		int scrollBarWidth = m_ScrollBar.GetSize().x;
		SetClickableRange(Rect(pos, Point(size.x - scrollBarWidth, size.y)));
		SetSize(GetClickableRange().size + Point(scrollBarWidth, 0));
		double value = m_ScrollBar.UpdateDouble(pos + Point(size.x - scrollBarWidth, 0), size.y);
		m_ScrollBar.SetDisplayHeight(size.y);
		m_TextBox.setSize(Point(size.x - 2 * Padding - scrollBarWidth, m_TextBox.size.y));
		m_TextBox.setPos(pos + Point(Padding, Padding - (int)(value * (m_TextBox.h - (size.y - 2 * Padding)))));
		Rect outOfRange{ pos, size + Point(scrollBarWidth, 0) };
		if (not outOfRange.mouseOver() and MouseL.down())
			m_IsSelected = false;
		TextInput();
		WhenTextChange();
		if (User::State::GetMode() == Mode::DEBUG)
			SetEnable(false);
		else
			SetEnable(true);
		//Console << value;
		//Console << m_EditIndex;
		/*m_TextBox = Rect(
			pos + Point(Padding, Padding),
			Point(size.x - 2 * Padding - m_ScrollBar.GetSize().x, m_TextBox.size.y)
		);*/
	}
}
