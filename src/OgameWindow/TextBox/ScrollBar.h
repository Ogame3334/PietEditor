#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/ClickableObject.h"
#include "UpDownButton.h"

namespace OgameWindow {
	class ScrollBar : public ClickableObject {
	private:
		const uint32 Width = 16;

		Rect m_Region;
		UpDownButton m_UpButton{ Width, true };
		UpDownButton m_DownButton{ Width, false };
		Rect m_Bar;
		int m_BarLocalPosY = 0;

		bool m_IsHolding;
		bool m_Enable = true;

		int m_DisplayHeight;
		int m_RegionHeight;

		/// @brief 0～1の値をとる
		double m_Value = 0;

		void LButtonDown() override;

		void AddBarLocalPosY(int y);

	public:
		ScrollBar() = default;
		ScrollBar(uint32 width, int height, int displayHeight, int regionHeight);

		void SetDisplayHeight(int height) { m_DisplayHeight = height; }
		void SetRegionHeight(int height) { m_RegionHeight = height; }

		void SetValue(int value);
		void SetEnable(bool enable) { m_Enable = enable; }

		bool GetEnable() const { return m_Enable; }

		void Draw() override;
		void InputUpdate() override;
		double UpdateDouble(const Point& pos, int height);
	};
}
