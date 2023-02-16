#pragma once
#include <Siv3D.hpp>
#include "../../User/User.h"
#include "ColorDish.h"

namespace OgameWindow {
	class ColorSelect {
	private:
		inline static int NowCursorPos = 0;
		inline static int ColorDishSize = 0;
		static int PositiveMod(int x, int y);
		static void AddNowCursorPos(int num);
		static void SetNowID(int num) { NowCursorPos = num; }
		static void UserInput(void);
		static void NowColorSet(void);
		static void CursorDraw(Point pos, int size);


	public:
		static int GetNowCursorPos(void) { return NowCursorPos; }
		static void SetColorDishSize(int size) { ColorDishSize = size; }
		static void SetNowCursorPos(int id);
		static void Draw(Point pos);
		static void Update(Point pos);
	};
}
