#pragma once

#include <Siv3D.hpp>
#include "Codel.h"
#include "CanvasBackground.h"

namespace OgameWindow {
	class Canvas : public ClickableObject{
	private:
		Point m_CanvasSize;
		Point m_LocalPos;
		Array<Codel> m_Codels;
		CanvasBackground m_Background;

		void Move(Point pos);
		void Reload(void);
		void UserInput();
		
	public:
		Canvas(Point pos);
		Rect GetBackground() { return m_Background.GetOutline(); };
		void Draw() override;
		void InputUpdate() override;
		void Update(Point pos) override;
	};
}
