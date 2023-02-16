#include "ColorSelect.h"

namespace OgameWindow {
	int ColorSelect::PositiveMod(int x, int y) {
		int divisor = y; /* 除数 */
		int dividend = x; /* 被除数 */

		while (dividend < 0) {
			dividend += divisor;
		}

		return dividend % divisor;
	}
	void ColorSelect::AddNowCursorPos(int num) {
		int temp = NowCursorPos + num;
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
	void ColorSelect::NowColorSet(void) {
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
	void ColorSelect::CursorDraw(Point pos, int size) {
		Rect grayLine = Rect{ pos.x + 10, pos.y + 10, size - 14, size - 14 };
		grayLine.drawFrame(2, 1, Palette::Darkgray);
		Rect outline = Rect{ pos.x + 10, pos.y + 10, size - 14, size - 14 };
		outline.drawFrame(1, 0, Palette::Black);
	}
	void ColorSelect::Draw(Point pos) {
		CursorDraw(Point(pos.x + ColorDish::GetSize() * (NowCursorPos % 7), pos.y + ColorDish::GetSize() * ((int)(NowCursorPos / 7))), ColorDishSize);
	}
	void ColorSelect::Update(Point pos) {
		UserInput();
		NowColorSet();
		Draw(pos);
	}
}
