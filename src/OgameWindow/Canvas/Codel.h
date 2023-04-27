#pragma once

#include <Siv3D.hpp>
#include "../../ParentClass/DisplayObject.h"

namespace OgameWindow{
	class Codel : public DisplayObject{
	private:
		Point coordinate;
		int colorID;
		Rect tile;
		inline static Rect Canvas{ 0, 0, 0, 0 };
		inline static int CodelSize = 30;

		/// @brief 左クリックを押している間
		void LButtonPressed() override;
		/// @brief 右クリックを押した瞬間
		void RButtonDown() override;
	public:
		Codel() = default;
		/// @brief コンストラクタ
		/// @param coordinate コーデルのキャンバス内での座標
		Codel(const Point& coordinate) :
			coordinate(coordinate),
			colorID(18),
			tile(Rect())
		{}

		/// @brief コーデルサイズを設定
		/// @param size コーデルの表示サイズ
		static void SetCodelSize(int _size) { CodelSize = (_size >= 3) ? _size : 3; }

		/// @brief コーデルサイズを取得
		/// @return コーデるの表示サイズ
		static int GetCodelSize() { return CodelSize; }

		/// @brief キャンバスを設定
		/// @param canvas キャンバス
		static void SetCanvas(Rect _canvas) {
			Canvas = _canvas;
		}

		void reload(const Point&, const Size&) override;

		/// @brief オブジェクトを画面に表示する関数
		/// @brief whileでUpdate, InputUpdateの後に呼び出される
		void draw() override;

		/// @brief オブジェクトの状態を更新するメソッド
		/// @param pos オブジェクトの座標
		//void update() override;
	};
}
