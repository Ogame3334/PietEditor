#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/ClickableObject.h"

namespace OgameWindow {
	class MenuButton : public ClickableObject{
	private:
		String m_IdName;
		String m_DisplayName;
		int m_Width;

		std::function<void()> m_Function;

		Font m_Font{ 12 , Typeface::CJK_Regular_JP };

		//bool isDown = false;
		//bool isUp = false;


		void Clicked();
	public:
		MenuButton(String id_name, String display_name);
		MenuButton(String id_name, String display_name, int width);

		void SetFunction(std::function<void()> function) { m_Function = function; };
		std::function<void()> GetFunction() { return m_Function; };
		void RemoveFunction() { m_Function = []() { return; }; };
		String GetIDName(void) const { return m_IdName; }
		String GetDisplayName(void) const { return m_DisplayName; }

		void LButtonDown() override;

		void Draw() override;
		void Update(Point pos) override;
	};
}
