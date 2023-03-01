#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/ClickableObject.h"
#include "../../User/User.h"

namespace OgameWindow {
	class MenuButton : public ClickableObject{
	private:
		String m_IdName;
		String m_DisplayName;
		int m_Width;

		std::function<void()> m_Function;

		Font m_Font{ 12 , User::Setting::GetTheme().GetMenuButtonFont()};

		//bool isDown = false;
		//bool isUp = false;

		/// @brief ボタンが押された時の挙動
		void Clicked();
	public:
		/// @brief コンストラクタ
		/// @param id_name ID名
		/// @param display_name 表示名
		MenuButton(const String& id_name, const String& display_name);
		/// @brief コンストラクタ
		/// @param id_name ID名
		/// @param display_name 表示名
		/// @param width 横幅
		MenuButton(const String& id_name, const String& display_name, int width);

		/// @brief ボタンの機能を設定
		/// @param function ボタンの機能
		void SetFunction(std::function<void()> function) { m_Function = function; }

		/// @brief ボタンの機能を取得
		/// @return ボタンの機能
		std::function<void()> GetFunction() { return m_Function; }

		/// @brief ボタンの機能を削除
		void RemoveFunction() { m_Function = []() { return; }; }

		/// @brief ID名を取得
		/// @return ID名
		String GetIDName() const { return m_IdName; }

		/// @brief 表示名を取得
		/// @return 表示名
		String GetDisplayName() const { return m_DisplayName; }

		/// @brief 左クリックを押した瞬間
		void LButtonDown() override;

		/// @brief オブジェクトを画面に表示する関数
		/// @brief whileでUpdate, InputUpdateの後に呼び出される
		void Draw() override;

		/// @brief オブジェクトの状態を更新するメソッド
		/// @param pos オブジェクトの座標
		void Update(const Point& pos) override;
	};
}
