﻿#include "ColorSelect.h"

namespace OgameWindow {
	int ColorSelect::PositiveMod(int _x, int _y) {
		int divisor = _y; /* 除数 */
		int dividend = _x; /* 被除数 */

		while (dividend < 0) {
			dividend += divisor;
		}

		return dividend % divisor;
	}
	void ColorSelect::AddNowCursorPos(int _num) {
		int temp = NowCursorPos + _num;
		NowCursorPos = PositiveMod(temp, 21);
	}
	void ColorSelect::UserInput(void) {
		if (KeyW.down()) {
			AddNowCursorPos(-7);
		}
		if (KeyS.down()) {
			AddNowCursorPos(7);
		}
		if (KeyA.down()) {
			if (NowCursorPos % 7 == 0)
				AddNowCursorPos(6);
			else
				AddNowCursorPos(-1);
		}
		if (KeyD.down()) {
			if (NowCursorPos % 7 == 6)
				AddNowCursorPos(-6);
			else
				AddNowCursorPos(1);
		}
	}
	void ColorSelect::NowColorSet() {
		if (NowCursorPos < 6)
			User::State::SetNowColorID(NowCursorPos);
		else if (NowCursorPos == 6)
			User::State::SetDrawingColorID(18);
		else if (NowCursorPos < 13)
			User::State::SetNowColorID(NowCursorPos - 1);
		else if (NowCursorPos == 13)
			User::State::SetDrawingColorID(19);
		else if (NowCursorPos < 20)
			User::State::SetNowColorID(NowCursorPos - 2);
	}
	/*void ColorSelect::SetNowCursorPos(int id) {
		if (id < 6)
			NowCursorPos = id;
		else if (id < 13)
			NowCursorPos = id + 1;
		else if (id < 20)
			NowCursorPos = id + 2;
		else if (id == 20)
			NowCursorPos = 6;
		else if (id == 21)
			NowCursorPos = 12;
	}*/
	void ColorSelect::CursorDraw(const Point& _pos, int _size) {
		Rect grayLine = Rect{ _pos.x + 10, _pos.y + 10, _size - 14, _size - 14 };
		grayLine.drawFrame(2, 1, Palette::Darkgray);
		Rect outline = Rect{ _pos.x + 10, _pos.y + 10, _size - 14, _size - 14 };
		outline.drawFrame(1, 0, Palette::Black);
	}
	void ColorSelect::draw(const Point& _pos) {
		CursorDraw(Point(_pos.x + ColorDish::GetSize() * (NowCursorPos % 7), _pos.y + ColorDish::GetSize() * ((int)(NowCursorPos / 7))), ColorDishSize);
	}
	void ColorSelect::update(const Point& _pos) {
		UserInput();
		NowColorSet();
		draw(_pos);
	}
}
