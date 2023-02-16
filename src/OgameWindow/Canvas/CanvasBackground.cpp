#include "CanvasBackground.h"

namespace OgameWindow {
	void CanvasBackground::Draw() {
		Point pos = GetPosition();
		SetSize(Point(Scene::Size().x - pos.x - 10, Scene::Size().y - pos.y - 300));
		Point size = GetSize();
		m_outline = Rect(pos.x, pos.y, size.x, size.y);
		m_outline.drawFrame(1, 0, Palette::Black);
		Rect background = m_outline;
		background.draw(Palette::Gray);
	}

	void CanvasBackground::Update(Point pos) {
		DisplayObject::Update(pos);
	}
}
