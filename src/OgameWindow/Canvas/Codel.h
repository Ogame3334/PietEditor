#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/ClickableObject.h"

namespace OgameWindow{
	class Codel : public ClickableObject{
	private:
		Point m_Coordinate;
		int m_ColorID;
		Rect m_Tile;
		inline static Rect Canvas{ 0, 0, 0, 0 };
		inline static int CodelSize = 30;

		void LButtonPressed() override;
		void RButtonDown() override;
	public:
		Codel(Point coordinate) :
			m_Coordinate(coordinate),
			m_ColorID(18)
		{}

		static void SetCodelSize(int size) { CodelSize = (size >= 3) ? size : 3; }
		static int GetCodelSize() { return CodelSize; }
		static void SetCanvas(Rect canvas) {
			Canvas = canvas;
		}
		void Draw() override;
		void InputUpdate() override;
		void Update(Point pos) override;
	};
}
