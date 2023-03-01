#pragma once
#include <Siv3D.hpp>
#include "../../Constants/Constants.h"
#include "../../ParentClass/ClickableObject.h"
#include "../../ParentClass/ClickableObject.h"
#include "../../User/User.h"

namespace OgameWindow {
	class ColorDish : public ClickableObject{
	private:
		int m_id;
		Color m_Color;
		String m_Order;
		inline static int Size = 70;

		Rect m_outline;
		Font m_Font{ FontMethod::MSDF, 16, User::Setting::GetTheme().GetColorDishFont()};

	public:
		ColorDish(int id) :
			m_id(id), m_Color(Constants::Colors[id]),
			m_Order(Constants::Orders[id])
		{};

		ColorDish() {}

		/// @brief カラーディッシュの表示サイズを取得
		/// @return カラーディッシュの表示サイズ
		static int GetSize() { return Size; }

		/// @brief カラーディッシュIDを取得
		/// @return カラーディッシュID
		int GetID() const { return m_id; };

		/// @brief カラーディッシュの色を取得
		/// @return カラーディッシュの色
		Color GetColor() const { return m_Color; };

		/// @brief カラーディッシュの命令を取得
		/// @return カラーディッシュの命令
		String GetOrder() const { return m_Order; };

		/// @brief 左クリックを押した瞬間
		void LButtonDown() override;

		/// @brief 右クリックを押した瞬間
		void RButtonDown() override;

		/// @brief カラーディッシュ上に命令を表示
		/// @param pos 座標
		/// @param font フォント
		void WriteOrder(const Point& pos, const Font& font);

		/// @brief オブジェクトを画面に表示する関数
		/// @brief whileでUpdate, InputUpdateの後に呼び出される
		void Draw() override;

		/// @brief オブジェクトの状態を更新するメソッド
		/// @param pos オブジェクトの座標
		void Update(const Point& pos) override;
	};
}
