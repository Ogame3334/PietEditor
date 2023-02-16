#pragma once

namespace User {
	class State {
	private:
		inline static int m_DrawingColorID = 0;
		inline static int m_SelectedColorID = 0;
		inline static bool m_IsCanvasHold = false;
		inline static int m_NowSelectObjectID = 0;
	public:
		static void SetDrawingColorID(int id) { m_DrawingColorID = id; }
		static int GetDrawingColorID(void) { return m_DrawingColorID; }
		static void SetSelectedColorID(int id) { m_SelectedColorID = id; }
		static int GetSelectedColorID(void) { return m_SelectedColorID; }
		static void SetNowColorID(int id) {
			m_DrawingColorID = id;
			m_SelectedColorID = id;
		}
		static void SetIsCanvasHold(bool tf) { m_IsCanvasHold = tf; }
		static bool GetIsCanvasHold(void) { return m_IsCanvasHold; }
		static void SetNowSelectObjectID(int obj) { m_NowSelectObjectID = obj; }
		static int GetNowSelectObjectID(void) { return m_NowSelectObjectID; }
	};

	class Setting {
	private:
		inline static bool m_IsJapanese = true;
		inline static int m_InputMode = 2;
		// 0: Mouse & KeyBoard
		// 1: WASD & DirectionKey & Enter
		// 2: KeyBoradColorPick
	public:
		static void SetIsJapanese(bool isJapanese) { m_IsJapanese = isJapanese; }
		static bool GetIsJapanese(void) { return m_IsJapanese; }
		static void SetInputMode(int mode) { m_InputMode = mode; }
		static int GetInputMode(void) { return m_InputMode; }
	};
}
