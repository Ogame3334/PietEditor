#pragma once

#include <Siv3D.hpp>
#include "Codel.h"
#include "CanvasBackground.h"
#include "../../ParentClass/DisplayObject.h"

namespace OgameWindow {
	class Canvas : public DisplayObject{
	private:
		Point canvasWidthHeight;
		Point localPos;
		Array<Codel> codels;
		CanvasBackground background;

		/// @brief キャンバスに引数の座標を加算
		/// @param pos 加算座標
		void move(const Point& _pos);

		/// @brief キャンバスを再生成
		void init();

		/// @brief ユーザー入力
		void userInput();
		
	public:
		Canvas() = default;

		/// @brief Canvasのコンストラクタ
		/// @param pos 座標
		Canvas(const Point& _pos);

		/// @brief キャンバス背景のRectを取得
		/// @return キャンバス背景のRect
		Rect getBackground() const { return this->background.getOutline(); };

		/// @brief キャンバスの幅と高さを取得
		/// @return キャンバスの幅と高さ
		Point getCanvasSize() const { return this->canvasWidthHeight; }

		/// @brief キャンバスのローカル座標を取得
		/// @return ローカル座標
		Point getLocalPosition() const { return this->localPos; }

		/// @brief コーデルsを取得
		/// @return コーデル配列
		Array<Codel> getCodels() const { return this->codels; }

		void reload(const Point&, const Size&) override;

		/// @brief オブジェクトを画面に表示する関数
		/// @brief whileでUpdate, InputUpdateの後に呼び出される
		void draw() override;
		/// @brief ユーザーの入力を受け付ける
		/// @brief whileでUpdateの後に呼ばれる
		void inputUpdate() override;
		/// @brief オブジェクトの状態を更新するメソッド
		/// @param pos オブジェクトの座標
		//void update() override;
	};
}
