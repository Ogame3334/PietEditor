#pragma once

#include <Siv3D.hpp>

class Theme {
private:
	int m_ID;
	String m_EnglishName;
	String m_JapaneseName;

	Color m_BackGroundColor;

	Color m_ColorPaletteOutlineColor;
	Color m_ColorDishOutlineColor;
	Typeface m_ColorDishFont;
	Color m_ColorDishFontColor;

	Color m_CanvasBackGroundColor;
	Color m_CanvasBackOutlineColor;

	Color m_MenuBarBackGroundColor;
	Color m_MenuButtonBackColor;
	Color m_MenuButtonBackActiveColor;
	Color m_MenuButtonBackDownColor;
	Typeface m_MenuButtonFont;
	Color m_MenuButtonFontColor;

	Typeface m_StatusBarFont;
	Color m_StatusBarFontColor;
	Color m_StatusBarBackColor;
	Color m_StatusBarBackDebugColor;

	Color m_ScrollBarButtonBackColor;
	Color m_ScrollBarButtonTriangleColor;
	Color m_ScrollBarButtonTriangleActiveColor;
	Color m_ScrollBarBackColor;
	Color m_ScrollBarColor;
	Color m_ScrollBarActiveColor;
	Color m_ScrollBarOutlineColor;

public:
	/// @brief テーマの標準コンストラクタ
	Theme(){}

	/// @brief テーマのコンストラクタ
	/// @param id テーマID
	Theme(int id);

	/// @brief テーマのコンストラクタ
	/// @param id テーマID
	/// @param english_name テーマの英名
	/// @param japanese_name テーマの和名
	/// @param backgroundColor 背景色
	/// @param colorPaletteOutlineColor カラーパレットの外枠の色
	/// @param colorDishOutlineColor カラーディッシュの外枠の色
	/// @param colorDishFont カラーディッシュのフォント
	/// @param colorDishFontColor カラーディッシュのフォントカラー
	/// @param canvasBackGroundColor キャンバスの背景色
	/// @param canvasBackOutlineColor キャンバスの外枠の色
	/// @param menuBarBackgroundColor メニューバーの背景色
	/// @param menuButtonBackColor メニューボタンの背景色
	/// @param menuButtonBackActiveColor メニューボタンがアクティブの色
	/// @param menuButtonBackDownColor メニューボタンを押下時の色
	/// @param menuButtonFont メニューボタンのフォント
	/// @param menuButtonFontColor メニューボタンのフォントカラー
	/// @param statusBarFont ステータスバーのフォント
	/// @param statusBarFontColorステータスバーのフォントカラー
	/// @param statusBarBackColor ステータスバーの背景色
	/// @param statusBarBackDebugColor ステータスバーのデバッグ時の背景色
	/*Theme(int id, const String& english_name, const String& japanese_name,
		const Color& backgroundColor, const Color& colorPaletteOutlineColor,
		const Color& colorDishOutlineColor, const Typeface& colorDishFont, const Color& colorDishFontColor,
		const Color& canvasBackGroundColor, const Color& canvasBackOutlineColor, const Color& menuBarBackgroundColor,
		const Color& menuButtonBackColor, const Color& menuButtonBackActiveColor,
		const Color& menuButtonBackDownColor, const Typeface& menuButtonFont, const Color& menuButtonFontColor,
		const Typeface& statusBarFont, const Color& statusBarFontColor,
		const Color& statusBarBackColor, const Color& statusBarBackDebugColor);*/

	/// @brief テーマIDを設定
	/// @param id テーマID
	void SetID(int id) { m_ID = id; }

	/// @brief テーマの英名を設定
	/// @param english_name テーマの英名
	void SetEnglishName(const String& name) { m_EnglishName = name; }

	/// @brief テーマの和名を設定
	/// @param japanese_name テーマの和名
	void SetJapaneseName(const String& name) { m_JapaneseName = name; }

	/// @brief 背景色を設定
	/// @param backgroundColor 背景色
	void SetBackGroundColor(const Color& color) { m_BackGroundColor = color; }

	/// @brief カラーパレットの外枠の色を設定
	/// @param colorPaletteOutlineColor カラーパレットの外枠の色
	void SetColorPaletteOutlineColor(const Color& color) { m_ColorPaletteOutlineColor = color; }

	/// @brief カラーディッシュの外枠の色を設定
	/// @param colorDishOutlineColor カラーディッシュの外枠の色
	void SetColorDishOutlineColor(const Color& color) { m_ColorDishOutlineColor = color; }

	/// @brief カラーディッシュのフォントを設定
	/// @param colorDishFont カラーディッシュのフォント
	void SetColorDishFont(const Typeface& font) { m_ColorDishFont = font; }

	/// @brief カラーディッシュのフォントカラーを設定
	/// @param colorDishFontColor カラーディッシュのフォントカラー
	void SetColorDishFontColor(const Color& color) { m_ColorDishFontColor = color; }

	/// @brief キャンバスの背景色を設定
	/// @param canvasBackGroundColor キャンバスの背景色
	void SetCanvasBackGroundColor(const Color& color) { m_CanvasBackGroundColor = color; }

	/// @brief キャンバスの外枠の色を設定
	/// @param canvasBackOutlineColor キャンバスの外枠の色
	void SetCanvasBackOutlineColor(const Color& color) { m_CanvasBackOutlineColor = color; }

	/// @brief メニューバーの背景色を設定
	/// @param menuBarBackgroundColor メニューバーの背景色
	void SetMenuBarBackGroundColor(const Color& color) { m_MenuBarBackGroundColor = color; }

	/// @brief メニューボタンの背景色を設定
	/// @param menuButtonBackColor メニューボタンの背景色
	void SetMenuButtonBackColor(const Color& color) { m_MenuButtonBackColor = color; }

	/// @brief メニューボタンがアクティブの色を設定
	/// @param menuButtonBackActiveColor メニューボタンがアクティブの色
	void SetMenuButtonBackActiveColor(const Color& color) { m_MenuButtonBackActiveColor = color; }

	/// @brief メニューボタンを押下時の色を設定
	/// @param menuButtonBackDownColor メニューボタンを押下時の色
	void SetMenuButtonBackDownColor(const Color& color) { m_MenuButtonBackDownColor = color; }

	/// @brief メニューボタンのフォントを設定
	/// @param menuButtonFont メニューボタンのフォント
	void SetMenuButtonFont(const Typeface& font) { m_MenuButtonFont = font; }

	/// @brief メニューボタンのフォントカラーを設定
	/// @param menuButtonFontColor メニューボタンのフォントカラー
	void SetMenuButtonFontColor(const Color& color) { m_MenuButtonFontColor = color; }

	/// @brief ステータスバーのフォントを設定
	/// @param font ステータスバーのフォント
	void SetStatusBarFont(const Typeface& font) { m_StatusBarFont = font; }

	/// @brief ステータスバーのフォントカラーを設定
	/// @param color ステータスバーのフォントカラー
	void SetStatusBarFontColor(const Color& color) { m_StatusBarFontColor = color; }

	/// @brief ステータスバーの背景色を設定
	/// @param color ステータスバーの背景色
	void SetStatusBarBackColor(const Color& color) { m_StatusBarBackColor = color; }

	/// @brief ステータスバーのデバッグ時の背景色を設定
	/// @param color ステータスバーのデバッグ時の背景色
	void SetStatusBarBackDebugColor(const Color& color) { m_StatusBarBackDebugColor = color; }

	void SetScrollBarButtonBackColor(const Color& color) { m_ScrollBarButtonBackColor = color; }
	void SetScrollBarButtonTriangleColor(const Color& color) { m_ScrollBarButtonTriangleColor = color; }
	void SetScrollBarButtonTriangleActiveColor(const Color& color) { m_ScrollBarButtonTriangleActiveColor = color; }
	void SetScrollBarBackColor(const Color& color) { m_ScrollBarBackColor = color; }
	void SetScrollBarColor(const Color& color) { m_ScrollBarColor = color; }
	void SetScrollBarActiveColor(const Color& color) { m_ScrollBarActiveColor = color; }
	void SetScrollBarOutlineColor(const Color& color) { m_ScrollBarOutlineColor = color; }



	/// @brief テーマIDを取得
	/// @return テーマID
	int GetID() const { return m_ID; }

	/// @brief テーマの英名を取得
	/// @return テーマの英名 
	String GetEnglishName() const { return m_EnglishName; }

	/// @brief テーマの和名を取得
	/// @return テーマの和名
	String GetJapaneseName() const { return m_JapaneseName; }

	/// @brief 背景色を取得
	/// @return 背景色
	Color GetBackGroundColor() const { return m_BackGroundColor; }

	/// @brief カラーパレットの外枠の色を取得
	/// @return カラーパレットの外枠の色
	Color GetColorPaletteOutlineColor() const { return m_ColorPaletteOutlineColor; }

	/// @brief カラーディッシュの外枠の色を取得
	/// @return カラーディッシュの外枠の色
	Color GetColorDishOutlineColor() const { return m_ColorDishOutlineColor; }

	/// @brief カラーディッシュのフォントを取得
	/// @return カラーディッシュのフォント
	Typeface GetColorDishFont() const { return m_ColorDishFont; }

	/// @brief カラーディッシュのフォントカラーを取得
	/// @return カラーディッシュのフォントカラー
	Color GetColorDishFontColor() const { return m_ColorDishFontColor; }

	/// @brief キャンバスの背景色を取得
	/// @return キャンバスの背景色
	Color GetCanvasBackGroundColor() const { return m_CanvasBackGroundColor; }

	/// @brief キャンバスの外枠の色を取得
	/// @return キャンバスの外枠の色
	Color GetCanvasBackOutlineColor() const { return m_CanvasBackOutlineColor; }

	/// @brief メニューバーの背景色を取得
	/// @return メニューバーの背景色
	Color GetMenuBarBackGroundColor() const { return m_MenuBarBackGroundColor; }

	/// @brief メニューボタンの背景色を取得
	/// @return メニューボタンの背景色
	Color GetMenuButtonBackColor() const { return m_MenuButtonBackColor; }

	/// @brief メニューボタンがアクティブの色を取得
	/// @return メニューボタンがアクティブの色
	Color GetMenuButtonBackActiveColor() const { return m_MenuButtonBackActiveColor; }

	/// @brief メニューボタンを押下時の色を取得
	/// @return メニューボタンを押下時の色
	Color GetMenuButtonBackDownColor() const { return m_MenuButtonBackDownColor; }

	/// @brief メニューボタンのフォントを取得
	/// @return メニューボタンのフォント
	Typeface GetMenuButtonFont() const { return m_MenuButtonFont; }

	/// @brief メニューボタンのフォントカラーを取得
	/// @return メニューボタンのフォントカラー
	Color GetMenuButtonFontColor() const { return m_MenuButtonFontColor; }

	/// @brief ステータスバーのフォントを取得
	/// @return ステータスバーのフォント
	Typeface GetStatusBarFont() { return m_StatusBarFont; }

	/// @brief ステータスバーのフォントカラーを取得
	/// @return ステータスバーのフォントカラー
	Color GetStatusBarFontColor() { return m_StatusBarFontColor; }

	/// @brief ステータスバーの背景色を取得
	/// @return ステータスバーの背景色
	Color GetStatusBarBackColor() { return m_StatusBarBackColor; }

	/// @brief ステータスバーのデバッグ時の背景色を取得
	/// @return ステータスバーのデバッグ時の背景色
	Color GetStatusBarBackDebugColor() { return m_StatusBarBackDebugColor; }

	Color GetScrollBarButtonBackColor() const { return m_ScrollBarButtonBackColor; }
	Color GetScrollBarButtonTriangleColor() const { return m_ScrollBarButtonTriangleColor; }
	Color GetScrollBarButtonTriangleActiveColor() const { return m_ScrollBarButtonTriangleActiveColor; }
	Color GetScrollBarBackColor() const { return m_ScrollBarBackColor; }
	Color GetScrollBarColor() const { return m_ScrollBarColor; }
	Color GetScrollBarActiveColor() const { return m_ScrollBarActiveColor; }
	Color GetScrollBarOutlineColor() const { return m_ScrollBarOutlineColor; }
};
