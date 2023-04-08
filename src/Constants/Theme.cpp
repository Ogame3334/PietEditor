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

void Theme::ChangeTheme(int id) {
	switch (id)
	{
	case 1:
		ID = 1;
		EnglishName = U"Dark";
		JapaneseName = U"ダーク";
		BackGroundColor = Color(0, 0, 50);
		ColorPaletteOutlineColor = Color(102, 153, 255);
		ColorDishOutlineColor = Color(0, 52, 156);
		ColorDishFont = Typeface::Black;
		ColorDishFontColor = Palette::Black;
		CanvasBackGroundColor = Palette::Gray;
		CanvasBackOutlineColor = Palette::Black;
		MenuBarBackGroundColor = Palette::Black;
		MenuButtonBackColor = Palette::Black;
		MenuButtonBackActiveColor = Color(0, 0, 105);
		MenuButtonBackDownColor = Color(0, 102, 204);
		MenuButtonFont = Typeface::CJK_Regular_JP;
		MenuButtonFontColor = Palette::White;
		StatusBarFont = Typeface::CJK_Regular_JP;
		StatusBarFontColor = Palette::Black;
		StatusBarBackColor = Palette::Skyblue;
		StatusBarBackDebugColor = Palette::Orange;
		ScrollBarButtonBackColor = Palette::White;
		ScrollBarButtonTriangleColor = Palette::Lightgray;
		ScrollBarButtonTriangleActiveColor = Palette::Gray;
		ScrollBarBackColor = Palette::White;
		ScrollBarColor = Palette::Lightgray;
		ScrollBarActiveColor = Palette::Gray;
		ScrollBarOutlineColor = Palette::Black;
		TextBoxTitleFontColor = Palette::Black;
		TextBoxFont = Typeface::CJK_Regular_JP;
		TextBoxFontColor = Palette::Black;
		TextBoxBackColor = Palette::White;
		TextBoxOutlineColor = Palette::Black;
		break;
	case 2:
		ID = 2;
		EnglishName = U"Ogame";
		JapaneseName = U"おがめ";
		BackGroundColor = Color(238, 255, 213);
		ColorPaletteOutlineColor = Color(0, 255, 0);
		ColorDishOutlineColor = Color(0, 52, 156);
		ColorDishFont = Typeface::Black;
		ColorDishFontColor = Palette::Black;
		CanvasBackGroundColor = Color(100, 153, 100);
		CanvasBackOutlineColor = Palette::Black;
		MenuBarBackGroundColor = Color(204, 255, 255);
		MenuButtonBackColor = Color(204, 255, 255);
		MenuButtonBackActiveColor = Color(0, 0, 105);
		MenuButtonBackDownColor = Color(0, 102, 204);
		MenuButtonFont = Typeface::CJK_Regular_JP;
		MenuButtonFontColor = Palette::Green;
		StatusBarFont = Typeface::CJK_Regular_JP;
		StatusBarFontColor = Palette::Black;
		StatusBarBackColor = Palette::Skyblue;
		StatusBarBackDebugColor = Palette::Orange;
		break;
	default:
		ID = 0;
		EnglishName = U"Default";
		JapaneseName = U"デフォルト";
		BackGroundColor = Color(235, 235, 235);
		ColorPaletteOutlineColor = Palette::Black;
		ColorDishOutlineColor = Palette::Black;
		ColorDishFont = Typeface::Black;
		ColorDishFontColor = Palette::Black;
		CanvasBackGroundColor = Palette::Gray;
		CanvasBackOutlineColor = Palette::Black;
		MenuBarBackGroundColor = Palette::White;
		MenuButtonBackColor = Palette::White;
		MenuButtonBackActiveColor = Color(230, 244, 255);
		MenuButtonBackDownColor = Color(215, 238, 255);
		MenuButtonFont = Typeface::CJK_Regular_JP;
		MenuButtonFontColor = Palette::Black;
		StatusBarFont = Typeface::CJK_Regular_JP;
		StatusBarFontColor = Palette::Black;
		StatusBarBackColor = Palette::Skyblue;
		StatusBarBackDebugColor = Palette::Orange;
		ScrollBarButtonBackColor = Palette::White;
		ScrollBarButtonTriangleColor = Palette::Lightgray;
		ScrollBarButtonTriangleActiveColor = Palette::Gray;
		ScrollBarBackColor = Palette::White;
		ScrollBarColor = Palette::Lightgray;
		ScrollBarActiveColor = Palette::Gray;
		ScrollBarOutlineColor = Palette::Black;
		TextBoxTitleFontColor = Palette::Black;
		TextBoxFont = Typeface::CJK_Regular_JP;
		TextBoxFontColor = Palette::Black;
		TextBoxBackColor = Palette::White;
		TextBoxOutlineColor = Palette::Black;
		TextBoxActiveOutlineColor = Palette::Skyblue;
		TextBoxCursorColor = Palette::Black;
		break;
	}
}
