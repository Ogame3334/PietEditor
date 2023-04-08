﻿#include "CanvasBackground.h"
#include "../../User/User.h"

namespace OgameWindow {
	void CanvasBackground::Draw() {
		Point pos = GetPosition();
		SetSize(Point(Scene::Size().x - pos.x - 20, Scene::Size().y - pos.y - 300));
		Point size = GetSize();
		m_outline = Rect(pos.x, pos.y, size.x, size.y);
		m_outline.drawFrame(1, 0, m_ThemePtr->CanvasBackOutlineColor);
		Rect background = m_outline;
		background.draw(m_ThemePtr->CanvasBackGroundColor);
	}
}
