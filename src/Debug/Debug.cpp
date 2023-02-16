#include "Debug.h"

namespace Debug {
	void Display(Point& pos, Font debugFont) {
		ClearPrint();
		if (isDebugMode) {
			auto temp = debugFont(U"FrameBufferSize: ", Window::GetState().frameBufferSize,
				U"\nVirtualSize: ", Window::GetState().virtualSize,
				U"\nSceneSize: ", Scene::Size(),
				U"\nCursorPosition: ", Cursor::Pos(),
				U"\nUserState DrawingColorID: ", User::State::GetDrawingColorID(),
				U"\nUserState SelectedColorID: ", User::State::GetSelectedColorID(),
				U"\nColorSelect NowCursorPos: ", OgameWindow::ColorSelect::GetNowCursorPos(),
				U"\nMouseR Pressed: ", MouseR.pressed(),
				U"\nNowSelectedObjID: ", User::State::GetNowSelectObjectID()
			);
			int rectHeight = (int)(temp.region().size.y + 6);
			Rect{ pos.x, pos.y, 250, rectHeight + 10 }.draw(Color(0, 0, 0, 128));
			temp.draw(pos.x + 5, pos.y + 5);

			if (KeyO.pressed()) {
				pos.y -= 5;
			}
			if (KeyL.pressed()) {
				pos.y += 5;
			}
			if (KeyK.pressed()) {
				pos.x -= 5;
			}
			if (KeySemicolon_JIS.pressed()) {
				pos.x += 5;
			}
		}
	}
}
