#include "TextBoxMultipleLines.h"

namespace OgameWindow {
	void TextBoxMultipleLines::LButtonDown() {
		if (this->canEdit) {
			this->isSelected = true;
		}
	}

	void TextBoxMultipleLines::setEditIndex(int _index) {
		this->editIndex = _index;
		if (this->editIndex < 0) {
			this->editIndex = 0;
		}
		else if (this->editIndex > this->text.length()) {
			this->editIndex = (int)this->text.length();
		}
		else {
			this->cursorTimer = 0;
		}
	}

	TextBoxMultipleLines::TextBoxMultipleLines(bool _canEdit, String _title) :
		scrollBar(ScrollBar{ 16, 10, 10, 20 }),
		textBox(Rect(0, 0, 0, 0)),
		textHeight(0),
		canEdit(_canEdit),
		title(_title)
	{
		this->font = Font(15, this->themePtr->TextBoxFont);
		setSize(Point(0, 0));
		setPosition(Point(0, 0));
		setClickableRange(Rect(0, 0, Point(0, 0)));
		this->textBox.setSize(0, this->font.height());
	}

	bool TextBoxMultipleLines::judgeTextChange() {
		bool return_bool;
		if (this->text != this->previousText)
			return_bool = true;
		else
			return_bool = false;
		this->previousText = this->text;
		return return_bool;
	}

	void TextBoxMultipleLines::whenTextChange() {
		if (judgeTextChange()) {
			this->cursorTimer = 0;
			if (this->textCursorPos.y + (int)this->font.height() * 2 > getClickableRange().y + getClickableRange().h) {
				this->scrollBar.setValue(1);
			}
		}
	}

	void TextBoxMultipleLines::eraseText() {
		if (this->editIndex > 0) {
			this->text.erase(this->editIndex - 1);
			this->editIndex--;
		}
	}

	void TextBoxMultipleLines::deleteText() {
		this->text.erase(this->editIndex);
	}

	void TextBoxMultipleLines::clipboardPaste() {
		String temp;
		if (Clipboard::GetText(temp)) {
			this->text.append(temp);
			this->editIndex += (int)temp.length();
		}
	}

	void TextBoxMultipleLines::keyInput(Input _key, std::function<void()> _func) {
		if (_key.pressed()) {
			Duration dur = _key.pressedDuration();
			if (_key.down()) {
				_func();
				this->keyPressTimer = 0;
			}
			if (dur.count() > 0.5) {
				this->keyPressTimer += Scene::DeltaTime();
				if (this->keyPressTimer > 0.03) {
					_func();
					this->keyPressTimer -= 0.03;
				}
			}
		}
	}
	void TextBoxMultipleLines::keyInput(InputCombination _key, std::function<void()> _func) {
		if (_key.pressed()) {
			Duration dur = _key.pressedDuration();
			if (_key.down()) {
				_func();
				this->keyPressTimer = 0;
			}
			if (dur.count() > 0.5) {
				this->keyPressTimer += Scene::DeltaTime();
				if (this->keyPressTimer > 0.03) {
					_func();
					this->keyPressTimer -= 0.03;
				}
			}
		}
	}

	void TextBoxMultipleLines::textInput() {
		if (this->isSelected) {
			String chara = U"";
			TextInput::UpdateText(chara);

			if (chara != U"") {
				this->text.insert(this->editIndex, chara);
				this->editIndex += (int)chara.length();
				chara = U"";
			}

			if (this->editingText == U"") {
				keyInput(KeyBackspace, [this]() { eraseText(); });
				keyInput(KeyDelete, [this]() { deleteText(); });
				keyInput(KeyLeft, [this]() { setEditIndex(editIndex - 1); });
				keyInput(KeyRight, [this]() { setEditIndex(editIndex + 1); });
			}
			keyInput((KeyControl + KeyV), [this]() { clipboardPaste(); });
		}
	}

	void TextBoxMultipleLines::drawCursor(Vec2 _penPos) {
		this->cursorTimer += Scene::DeltaTime();
		if (this->cursorTimer > 0 and this->cursorTimer <= 0.6) {
			Line _line{ _penPos + Point(0, 2), _penPos + Point(0, (int)this->font.height() - 2) };
			_line.draw(1, this->themePtr->TextBoxCursorColor);
		}
		else if (this->cursorTimer > 1.2) {
			this->cursorTimer -= 1.2;
		}
	}

	void TextBoxMultipleLines::drawText() {
		if (this->isSelected) {
			{
				Graphics2D::SetScissorRect(getClickableRange());
				RasterizerState rs = RasterizerState::Default2D;
				// シザー矩形を有効化
				rs.scissorEnable = true;
				ScopedRenderStates2D rasterizer{ rs };
				this->textBasePos = this->textBox.pos;
				this->textPenPos = this->textBasePos;
				this->textCursorPos = this->textPenPos;
				int num = 0;
				//Console << m_EditIndex;
				if (this->text == U"" and this->isSelected) {
					drawCursor(this->textPenPos);
				}
				else {
					for (const auto& glyph : this->font.getGlyphs(this->text)) {
						if (glyph.codePoint == U'\n')
						{
							if (num == this->editIndex and this->isSelected) {
								this->textPenPos.x += glyph.xAdvance;
								this->textCursorPos = this->textPenPos;
								drawCursor(this->textPenPos - Vec2(glyph.xAdvance, 0));
								//Console << num;
							}

							// ペンの X 座標をリセット
							this->textPenPos.x = this->textBasePos.x;

							// ペンの Y 座標をフォントの高さ分進める
							this->textPenPos.y += this->font.height();

							num++;
							continue;
						}

						if (this->textPenPos.x + glyph.xAdvance > this->textBox.x + this->textBox.w) {
							this->textPenPos.x = this->textBasePos.x;
							this->textPenPos.y += this->font.height();
						}

						glyph.texture.draw(Math::Round(this->textPenPos + glyph.getOffset()), Palette::Black);

						// ペンの X 座標を文字の幅の分進める
						this->textPenPos.x += glyph.xAdvance;

						if (num == this->editIndex and this->isSelected) {
							this->textCursorPos = this->textPenPos;
							drawCursor(this->textPenPos - Vec2(glyph.xAdvance, 0));
							//Console << num;
						}

						num++;
					}
					if (num == this->editIndex and this->isSelected) {
						this->textCursorPos = this->textPenPos;
						drawCursor(this->textPenPos - Vec2(this->font.getGlyph(this->text.substr(this->text.length())).xAdvance, 0));
						//Console << num;
					}
				}
				//Console << GetClickableRange().y + GetClickableRange().h;
				this->textBox.setSize(this->textBox.w, (int)(this->textPenPos.y + this->font.height() - this->textBox.y));
				this->scrollBar.setRegionHeight(this->textBox.h);
			}
			this->editingText = TextInput::GetEditingText();
			auto _text = this->font(this->editingText);
			_text.region(this->textPenPos).draw(this->themePtr->TextBoxBackColor);
			_text.draw(this->textPenPos, this->themePtr->TextBoxFontColor);
		}
	}

	void TextBoxMultipleLines::changeCursorStyle() {
		if (this->canEdit) {
			Cursor::RequestStyle(CursorStyle::IBeam);
		}
	}

	void TextBoxMultipleLines::reload(const Point& _pos, const Size& _size) {
		DisplayObject::reload(_pos, _size);
		int scrollBarWidth = this->scrollBar.getSize().x;
		setClickableRange(Rect(_pos, Point(_size.x - scrollBarWidth, _size.y)));
		setSize(getClickableRange().size + Point(scrollBarWidth, 0));
		double value = this->scrollBar.updateDouble(_pos + Point(_size.x - scrollBarWidth, 0), _size.y);
		this->scrollBar.setDisplayHeight(_size.y);
		this->textBox.setSize(Point(_size.x - 2 * Padding - scrollBarWidth, this->textBox.size.y));
		this->textBox.setPos(_pos + Point(Padding, Padding - (int)(value * (this->textBox.h - (_size.y - 2 * Padding)))));
		Rect outOfRange{ _pos, _size + Point(scrollBarWidth, 0) };
		if (not outOfRange.mouseOver() and MouseL.down())
			this->isSelected = false;
		textInput();
		whenTextChange();
		if (User::State::GetMode() == Mode::DEBUG)
			setEnable(false);
		else
			setEnable(true);
		//Console << value;
		//Console << m_EditIndex;
		this->textBox = Rect(
			_pos + Point(Padding, Padding),
			Point(size.x - 2 * Padding - this->scrollBar.getSize().x, this->textBox.size.y)
		);
	}

	void TextBoxMultipleLines::draw() {
		if (getClickableRange().h < this->textBox.h) {
			this->scrollBar.setEnable(true);
		}
		else {
			this->scrollBar.setEnable(false);
		}
		this->scrollBar.draw();
		getClickableRange().drawFrame(1, this->themePtr->TextBoxOutlineColor);
		getClickableRange().draw(this->themePtr->TextBoxBackColor);
		if (this->isSelected) {
			getClickableRange().drawFrame(1, this->themePtr->TextBoxActiveOutlineColor);
		}
		//m_TextBox.draw(Palette::Red);
		drawText();
		this->font(this->title).draw(getPosition() + Point(10, -30), this->themePtr->TextBoxTitleFontColor);
	}

	void TextBoxMultipleLines::inputUpdate() {
		DisplayObject::inputUpdate();
		this->scrollBar.inputUpdate();
	}

	void TextBoxMultipleLines::update() {

	}

	/*void TextBoxMultipleLines::update(const Point& _pos, const Point& _size) {
		DisplayObject::update();
		int scrollBarWidth = this->scrollBar.getSize().x;
		setClickableRange(Rect(_pos, Point(_size.x - scrollBarWidth, _size.y)));
		setSize(getClickableRange().size + Point(scrollBarWidth, 0));
		double value = this->scrollBar.updateDouble(_pos + Point(_size.x - scrollBarWidth, 0), _size.y);
		this->scrollBar.setDisplayHeight(_size.y);
		this->textBox.setSize(Point(_size.x - 2 * Padding - scrollBarWidth, this->textBox.size.y));
		this->textBox.setPos(_pos + Point(Padding, Padding - (int)(value * (this->textBox.h - (_size.y - 2 * Padding)))));
		Rect outOfRange{ _pos, _size + Point(scrollBarWidth, 0) };
		if (not outOfRange.mouseOver() and MouseL.down())
			this->isSelected = false;
		textInput();
		whenTextChange();
		if (User::State::GetMode() == Mode::DEBUG)
			setEnable(false);
		else
			setEnable(true);
		//Console << value;
		//Console << m_EditIndex;
		m_TextBox = Rect(
			pos + Point(Padding, Padding),
			Point(size.x - 2 * Padding - m_ScrollBar.GetSize().x, m_TextBox.size.y)
		);
	}*/
}
