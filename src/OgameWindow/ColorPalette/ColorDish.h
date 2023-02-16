#pragma once
#include <Siv3D.hpp>
#include "../../Constants/Constants.h"
#include "../../ParentClass/ClickableObject.h"
#include "../../ParentClass/ClickableObject.h"

namespace OgameWindow {
	class ColorDish : public ClickableObject{
	private:
		int m_id;
		Color m_Color;
		String m_Order;
		inline static int Size = 70;

		Rect m_outline;
		Font m_Font{ FontMethod::MSDF, 18, Typeface::Bold };

	public:
		ColorDish(int id) :
			m_id(id), m_Color(Constants::Colors[id]),
			m_Order(Constants::Orders[id])
		{};

		ColorDish() {}

		static int GetSize(void) { return Size; }

		int GetID(void) const { return m_id; };
		Color GetColor(void) const { return m_Color; };
		String GetOrder(void) const { return m_Order; };

		void LButtonDown() override;
		void RButtonDown() override;

		void WriteOrder(Point pos, Font font);

		void Draw() override;

		void Update(Point pos) override;
	};
}
