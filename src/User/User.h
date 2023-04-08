#pragma once

#include "../Constants/Constants.h"

enum class Mode {
	EDIT,
	DEBUG
};

namespace User {
	class State {
	private:
		inline static int m_DrawingColorID = 0;
		inline static int m_SelectedColorID = 0;
		inline static bool m_IsCanvasHold = false;
		inline static int m_NowSelectObjectID = 0;
		inline static Mode m_Mode = Mode::EDIT;
	public:
		/// @brief ユーザーが描画する色のIDを設定
		/// @param id 色のID
		static void SetDrawingColorID(int id) { m_DrawingColorID = id; }

		/// @brief ユーザーが描画する色のIDを取得
		/// @return 色のID
		static int GetDrawingColorID() { return m_DrawingColorID; }

		/// @brief カラーディッシュの命令の基準とする色のIDを設定
		/// @param id 色のID
		static void SetSelectedColorID(int id) { m_SelectedColorID = id; }

		/// @brief カラーディッシュの命令の基準とする色のIDを設定
		/// @return 色のID
		static int GetSelectedColorID() { return m_SelectedColorID; }

		/// @brief ユーザーが描画する色のIDを設定
		/// @brief カラーディッシュの命令の基準とする色のIDを設定
		/// @param id 色のID
		static void SetNowColorID(int id) {
			m_DrawingColorID = id;
			m_SelectedColorID = id;
		}

		/// @brief ユーザーがキャンバスを掴んでいるかどうかを設定する
		/// @param tf ユーザーがキャンバスを掴んでいるかどうか
		static void SetIsCanvasHold(bool tf) { m_IsCanvasHold = tf; }

		/// @brief ユーザーがキャンバスを掴んでいるかどうかを取得する
		/// @return ユーザーがキャンバスを掴んでいるかどうか
		static bool GetIsCanvasHold() { return m_IsCanvasHold; }

		/// @brief 現在カーソルを合わせているDisplayObjectのIDを設定する
		/// @param obj 現在カーソルを合わせているオブジェクトID
		static void SetNowSelectObjectID(int obj) { m_NowSelectObjectID = obj; }

		/// @brief 現在カーソルを合わせているDisplayObjectのIDを設定する
		/// @return 現在カーソルを合わせているオブジェクトID
		static int GetNowSelectObjectID() { return m_NowSelectObjectID; }

		static void SetMode(Mode mode) { m_Mode = mode; }
		static Mode GetMode() { return m_Mode; }
	};

	class Setting {
	private:
		inline static bool m_IsJapanese = true;
		inline static int m_InputMode = 2;
		// 0: Mouse & KeyBoard
		// 1: WASD & DirectionKey & Enter
		// 2: KeyBoradColorPick
		inline static int m_ThemeID = 0;
		inline static Theme m_Theme{ 0 };
	public:
		/// @brief 日本語かどうかを設定する
		/// @param isJapanese 日本語かどうか
		static void SetIsJapanese(bool isJapanese) { m_IsJapanese = isJapanese; }

		/// @brief 日本語かどうかを取得する
		/// @return 日本語かどうか
		static bool GetIsJapanese() { return m_IsJapanese; }

		/// @brief 入力モードを設定する
		/// @param mode 入力モード
		static void SetInputMode(int mode) { m_InputMode = mode; }

		/// @brief 入力モードを取得する
		/// @return 入力モード
		static int GetInputMode() { return m_InputMode; }

		/// @brief テーマIDを設定する
		/// @param theme_id テーマID
		static void SetThemeID(int theme_id) {
			m_ThemeID = theme_id;
			m_Theme = Theme(theme_id);
		}

		/// @brief テーマを変更する
		/// @param id テーマID
		static void ChangeTheme(int id) {
			m_ThemeID = id;
			m_Theme.ChangeTheme(id);
		}

		/// @brief テーマIDを取得する
		/// @return テーマID
		static int GetThemeID() { return m_ThemeID; }

		/// @brief テーマを取得する
		/// @return テーマ
		static Theme GetTheme() { return m_Theme; }

		/// @brief テーマのポインタを取得する
		/// @return テーマのポインタ
		static Theme* GetThemePtr() { return &m_Theme; }
	};
}
