#pragma once
#include <Siv3D.hpp>
#include "../../Constants/Constants.h"
#include "../../ParentClass/ClickableObject.h"
#include "../../ParentClass/ClickableObject.h"
#include "../../User/User.h"

namespace OgameWindow {
	class ColorDish : public ClickableObject{
	private:
		int id;
		Color color;
		String order;
		inline static int Size = 70;

		Rect outline;
		Font font{ FontMethod::MSDF, 16, this->themePtr->ColorDishFont};

	public:
		ColorDish(int _id) :
			id(_id), color(Constants::Colors[_id]),
			order(Constants::Orders[_id])
		{};

		ColorDish() {}

		/// @brief カラーディッシュの表示サイズを取得
		/// @return カラーディッシュの表示サイズ
		static int GetSize() { return Size; }

		/// @brief カラーディッシュIDを取得
		/// @return カラーディッシュID
		int getID() const { return this->id; };

		/// @brief カラーディッシュの色を取得
		/// @return カラーディッシュの色
		Color getColor() const { return this->color; };

		/// @brief カラーディッシュの命令を取得
		/// @return カラーディッシュの命令
		String getOrder() const { return this->order; };

		/// @brief 左クリックを押した瞬間
		void LButtonDown() override;

		/// @brief 右クリックを押した瞬間
		void RButtonDown() override;

		/// @brief カラーディッシュ上に命令を表示
		/// @param pos 座標
		/// @param font フォント
		void writeOrder(const Point& _pos, const Font& _font);

		/// @brief オブジェクトを画面に表示する関数
		/// @brief whileでUpdate, InputUpdateの後に呼び出される
		void draw() override;

		/// @brief オブジェクトの状態を更新するメソッド
		/// @param pos オブジェクトの座標
		void update(const Point& pos) override;
	};
}
