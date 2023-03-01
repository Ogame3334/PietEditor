#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/ClickableObject.h"

namespace OgameWindow{
	class Codel : public ClickableObject{
	private:
		Point m_Coordinate;
		int m_ColorID;
		Rect m_Tile;
		inline static Rect Canvas{ 0, 0, 0, 0 };
		inline static int CodelSize = 30;

		/// @brief 左クリックを押している間
		void LButtonPressed() override;
		/// @brief 右クリックを押した瞬間
		void RButtonDown() override;
	public:
		/// @brief コンストラクタ
		/// @param coordinate コーデるのキャンバス内での座標
		Codel(const Point& coordinate) :
			m_Coordinate(coordinate),
			m_ColorID(18)
		{}

		/// @brief コーデルサイズを設定
		/// @param size コーデルの表示サイズ
		static void SetCodelSize(int size) { CodelSize = (size >= 3) ? size : 3; }

		/// @brief コーデルサイズを取得
		/// @return コーデるの表示サイズ
		static int GetCodelSize() { return CodelSize; }

		/// @brief キャンバスを設定
		/// @param canvas キャンバス
		static void SetCanvas(Rect canvas) {
			Canvas = canvas;
		}

		/// @brief オブジェクトを画面に表示する関数
		/// @brief whileでUpdate, InputUpdateの後に呼び出される
		void Draw() override;

		/// @brief オブジェクトの状態を更新するメソッド
		/// @param pos オブジェクトの座標
		void Update(const Point& pos) override;
	};
}
