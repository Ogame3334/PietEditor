#include "Theme.h"

/*Theme::Theme(int id, const String& english_name, const String& japanese_name,
		const Color& backgroundColor, const Color& colorPaletteOutlineColor,
		const Color& colorDishOutlineColor, const Typeface& colorDishFont, const Color& colorDishFontColor,
		const Color& canvasBackGroundColor, const Color& canvasBackOutlineColor, const Color& menuBarBackgroundColor,
		const Color& menuButtonBackColor, const Color& menuButtonBackActiveColor,
		const Color& menuButtonBackDownColor, const Typeface& menuButtonFont, const Color& menuButtonFontColor,
		const Typeface& statusBarFont, const Color& statusBarFontColor,
		const Color& statusBarBackColor, const Color& statusBarBackDebugColor) :
	m_ID(id), m_EnglishName(english_name), m_JapaneseName(japanese_name),
	m_BackGroundColor(backgroundColor), m_ColorPaletteOutlineColor(colorPaletteOutlineColor),
	m_ColorDishOutlineColor(colorDishOutlineColor), m_ColorDishFont(colorDishFont), m_ColorDishFontColor(colorDishFontColor),
	m_CanvasBackGroundColor(canvasBackGroundColor), m_CanvasBackOutlineColor(canvasBackOutlineColor), m_MenuBarBackGroundColor(menuBarBackgroundColor),
	m_MenuButtonBackColor(menuButtonBackColor), m_MenuButtonBackActiveColor(menuButtonBackActiveColor),
	m_MenuButtonBackDownColor(menuButtonBackDownColor), m_MenuButtonFont(menuButtonFont), m_MenuButtonFontColor(menuButtonFontColor),
	m_StatusBarFont(statusBarFont), m_StatusBarFontColor(statusBarFontColor),
	m_StatusBarBackColor(statusBarBackColor), m_StatusBarBackDebugColor(statusBarBackDebugColor)
{}*/

Theme::Theme(int id) {
	switch (id)
	{
	case 1:
		SetID(1);
		SetEnglishName(U"Dark");
		SetJapaneseName(U"ダーク");
		SetBackGroundColor(Color(0, 0, 50));
		SetColorPaletteOutlineColor(Color(102, 153, 255));
		SetColorDishOutlineColor(Color(0, 52, 156));
		SetColorDishFont(Typeface::Black);
		SetColorDishFontColor(Palette::Black);
		SetCanvasBackGroundColor(Palette::Gray);
		SetCanvasBackOutlineColor(Palette::Black);
		SetMenuBarBackGroundColor(Palette::Black);
		SetMenuButtonBackColor(Palette::Black);
		SetMenuButtonBackActiveColor(Color(0, 0, 105));
		SetMenuButtonBackDownColor(Color(0, 102, 204));
		SetMenuButtonFont(Typeface::CJK_Regular_JP);
		SetMenuButtonFontColor(Palette::White);
		SetStatusBarFont(Typeface::CJK_Regular_JP);
		SetStatusBarFontColor(Palette::Black);
		SetStatusBarBackColor(Palette::Skyblue);
		SetStatusBarBackDebugColor(Palette::Orange);
		SetScrollBarButtonBackColor(Palette::White);
		SetScrollBarButtonTriangleColor(Palette::Lightgray);
		SetScrollBarButtonTriangleActiveColor(Palette::Gray);
		SetScrollBarBackColor(Palette::White);
		SetScrollBarColor(Palette::Lightgray);
		SetScrollBarActiveColor(Palette::Gray);
		SetScrollBarOutlineColor(Palette::Black);
		break;
	case 2:
		SetID(2);
		SetEnglishName(U"Ogame");
		SetJapaneseName(U"おがめ");
		SetBackGroundColor(Color(238, 255, 213));
		SetColorPaletteOutlineColor(Color(0, 255, 0));
		SetColorDishOutlineColor(Color(0, 52, 156));
		SetColorDishFont(Typeface::Black);
		SetColorDishFontColor(Palette::Black);
		SetCanvasBackGroundColor(Color(100, 153, 100));
		SetCanvasBackOutlineColor(Palette::Black);
		SetMenuBarBackGroundColor(Color(204, 255, 255));
		SetMenuButtonBackColor(Color(204, 255, 255));
		SetMenuButtonBackActiveColor(Color(0, 0, 105));
		SetMenuButtonBackDownColor(Color(0, 102, 204));
		SetMenuButtonFont(Typeface::CJK_Regular_JP);
		SetMenuButtonFontColor(Palette::Green);
		SetStatusBarFont(Typeface::CJK_Regular_JP);
		SetStatusBarFontColor(Palette::Black);
		SetStatusBarBackColor(Palette::Skyblue);
		SetStatusBarBackDebugColor(Palette::Orange);
		break;
	default:
		SetID(0);
		SetEnglishName(U"Default");
		SetJapaneseName(U"デフォルト");
		SetBackGroundColor(Color(235, 235, 235));
		SetColorPaletteOutlineColor(Palette::Black);
		SetColorDishOutlineColor(Palette::Black);
		SetColorDishFont(Typeface::Black);
		SetColorDishFontColor(Palette::Black);
		SetCanvasBackGroundColor(Palette::Gray);
		SetCanvasBackOutlineColor(Palette::Black);
		SetMenuBarBackGroundColor(Palette::White);
		SetMenuButtonBackColor(Palette::White);
		SetMenuButtonBackActiveColor(Color(230, 244, 255));
		SetMenuButtonBackDownColor(Color(215, 238, 255));
		SetMenuButtonFont(Typeface::CJK_Regular_JP);
		SetMenuButtonFontColor(Palette::Black);
		SetStatusBarFont(Typeface::CJK_Regular_JP);
		SetStatusBarFontColor(Palette::Black);
		SetStatusBarBackColor(Palette::Skyblue);
		SetStatusBarBackDebugColor(Palette::Orange);
		SetScrollBarButtonBackColor(Palette::White);
		SetScrollBarButtonTriangleColor(Palette::Lightgray);
		SetScrollBarButtonTriangleActiveColor(Palette::Gray);
		SetScrollBarBackColor(Palette::White);
		SetScrollBarColor(Palette::Lightgray);
		SetScrollBarActiveColor(Palette::Gray);
		SetScrollBarOutlineColor(Palette::Black);
		break;
	}
}
