#include "Canvas.h"
#include "../../Judge/Judge.h"
#include "../../User/User.h"

namespace OgameWindow {
	void Canvas::Move(const Point& pos) {
		m_LocalPos += pos;
	}
	void Canvas::Reload() {
		m_Codels = {};
		for (int y = 0; y < m_CanvasSize.y; y++) {
			for (int x = 0; x < m_CanvasSize.x; x++) {
				//Console << Point(x, y);
				m_Codels.push_back(Codel(Point(x, y)));
			}
		}

	}
	void Canvas::UserInput() {
		if (Judge::isCursorInRect(GetClickableRange())) {
			if (KeyControl.pressed()) {
				//Console << Mouse::Wheel();
				//double temp = Mouse::Wheel() - 4;
				//int zoomDelta = ((int)(temp) >= 2) ? temp : 2;
				//Console << zoomDelta;
				Codel::SetCodelSize(Codel::GetCodelSize() - (int)Mouse::Wheel());
			}
			else if (KeyLShift.pressed()) {
				Move(Point(-(int)Mouse::Wheel() * 10, 0));
			}
			else {
				Move(Point(0, -(int)Mouse::Wheel() * 10));
			}
			if (MouseM.down()) {
				User::State::SetIsCanvasHold(true);
			}
		}
		if (MouseM.up()) {
			User::State::SetIsCanvasHold(false);
		}
		if (User::State::GetIsCanvasHold()) {
			Cursor::RequestStyle(CursorStyle::Hand);
			Move(Cursor::Delta());
		}
	}


	void Canvas::Draw() {
		Graphics2D::SetScissorRect(m_Background.GetOutline());
		RasterizerState rs = RasterizerState::Default2D;
		// シザー矩形を有効化
		rs.scissorEnable = true;
		const ScopedRenderStates2D rasterizer{ rs };
		m_Background.Draw();
		for (int y = 0; y < m_CanvasSize.y; y++) {
			for (int x = 0; x < m_CanvasSize.x; x++) {
				m_Codels[x + y * m_CanvasSize.x].Draw();
			}
		}
	}

	Canvas::Canvas(const Point& pos) {
		SetPosition(pos);
		m_Background = CanvasBackground(pos);
		SetClickableRange(m_Background.GetOutline());
		m_CanvasSize = Point(10, 10);
		m_LocalPos = Point(m_CanvasSize.x * Codel::GetCodelSize() / 2, m_CanvasSize.y * Codel::GetCodelSize() / 2 + 10);
		Reload();
	}

	void Canvas::InputUpdate() {
		if (Judge::isCursorInRect(GetClickableRange())) {
			for (int y = 0; y < m_CanvasSize.y; y++) {
				for (int x = 0; x < m_CanvasSize.x; x++) {
					m_Codels[x + y * m_CanvasSize.x].InputUpdate();
				}
			}
		}
		UserInput();
		ClickableObject::InputUpdate();
	}

	void Canvas::Update(const Point& pos) {
		Codel::SetCanvas(m_Background.GetOutline());
		SetClickableRange(m_Background.GetOutline());
		int codelSize = Codel::GetCodelSize();
		Point canvasSize{ codelSize * m_CanvasSize.x, codelSize * m_CanvasSize.y };
		for (int y = 0; y < m_CanvasSize.y; y++) {
			for (int x = 0; x < m_CanvasSize.x; x++) {
				m_Codels[x + y * m_CanvasSize.x].Update(Point(pos.x + m_LocalPos.x + canvasSize.x / 2 + codelSize * (x - m_CanvasSize.x / 2) - x - canvasSize.x / 2,
					pos.y + m_LocalPos.y + canvasSize.y / 2 + codelSize * (y - m_CanvasSize.y / 2) - y - canvasSize.y / 2));
			}
		}
		m_Background.Update(pos);
		DisplayObject::SetSize(Point(m_CanvasSize.x * Codel::GetCodelSize(), m_CanvasSize.y * Codel::GetCodelSize()));
		DisplayObject::Update(pos);
	}
}
