#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/ClickableObject.h"
#include "UpDownButton.h"

namespace OgameWindow {
	class ScrollBar : public ClickableObject {
	private:
		const uint32 Width = 16;

		Rect region;
		UpDownButton upButton{ Width, true };
		UpDownButton downButton{ Width, false };
		Rect bar;
		int barLocalPosY = 0;

		bool isHolding;
		bool enable = true;

		int displayHeight;
		int regionHeight;

		/// @brief 0～1の値をとる
		double value = 0;

		void LButtonDown() override;

		void addBarLocalPosY(int _y);
	public:
		ScrollBar() = default;
		ScrollBar(uint32 _width, int _height, int _displayHeight, int _regionHeight);

		void setDisplayHeight(int _height) { this->displayHeight = _height; }
		void setRegionHeight(int _height) { this->regionHeight = _height; }

		void setValue(int _value);
		void setEnable(bool _enable) { this->enable = _enable; }

		bool getEnable() const { return this->enable; }

		void draw() override;
		void inputUpdate() override;
		double updateDouble(const Point& _pos, int _height);
	};
}
