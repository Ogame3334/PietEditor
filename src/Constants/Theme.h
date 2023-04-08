#pragma once

#include <Siv3D.hpp>

class Theme {
public:
	int ID;
	String EnglishName;
	String JapaneseName;

	Color BackGroundColor;

	Color ColorPaletteOutlineColor;
	Color ColorDishOutlineColor;
	Typeface ColorDishFont;
	Color ColorDishFontColor;

	Color CanvasBackGroundColor;
	Color CanvasBackOutlineColor;

	Color MenuBarBackGroundColor;
	Color MenuButtonBackColor;
	Color MenuButtonBackActiveColor;
	Color MenuButtonBackDownColor;
	Typeface MenuButtonFont;
	Color MenuButtonFontColor;

	Typeface StatusBarFont;
	Color StatusBarFontColor;
	Color StatusBarBackColor;
	Color StatusBarBackDebugColor;

	Color ScrollBarButtonBackColor;
	Color ScrollBarButtonTriangleColor;
	Color ScrollBarButtonTriangleActiveColor;
	Color ScrollBarBackColor;
	Color ScrollBarColor;
	Color ScrollBarActiveColor;
	Color ScrollBarOutlineColor;

	Color TextBoxTitleFontColor;
	Typeface TextBoxFont;
	Color TextBoxFontColor;
	Color TextBoxBackColor;
	Color TextBoxOutlineColor;
	Color TextBoxActiveOutlineColor;
	Color TextBoxCursorColor;

	/// @brief テーマの標準コンストラクタ
	Theme() { ChangeTheme(0); }

	/// @brief テーマのコンストラクタ
	/// @param id テーマID
	Theme(int id) { ChangeTheme(id); }

	void ChangeTheme(int id);
};
