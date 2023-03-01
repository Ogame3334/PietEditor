#pragma once

#include <Siv3D.hpp>
#include "Codel.h"
#include "CanvasBackground.h"

namespace OgameWindow {
	class Canvas : public ClickableObject{
	private:
		Point m_CanvasSize;
		Point m_LocalPos;
		Array<Codel> m_Codels;
		CanvasBackground m_Background;

		/// @brief キャンバスに引数の座標を加算
		/// @param pos 加算座標
		void Move(const Point& pos);

		/// @brief キャンバスを再生成
		void Reload();

		/// @brief ユーザー入力
		void UserInput();
		
	public:
		/// @brief Canvasのコンストラクタ
		/// @param pos 座標
		Canvas(const Point& pos);

		/// @brief キャンバス背景のRectを取得
		/// @return キャンバス背景のRect
		Rect GetBackground() const { return m_Background.GetOutline(); };

		/// @brief キャンバスの幅と高さを取得
		/// @return キャンバスの幅と高さ
		Point GetCanvasSize() const { return m_CanvasSize; }

		/// @brief キャンバスのローカル座標を取得
		/// @return ローカル座標
		Point GetLocalPosition() const { return m_LocalPos; }

		/// @brief オブジェクトを画面に表示する関数
		/// @brief whileでUpdate, InputUpdateの後に呼び出される
		void Draw() override;
		/// @brief ユーザーの入力を受け付ける
		/// @brief whileでUpdateの後に呼ばれる
		void InputUpdate() override;
		/// @brief オブジェクトの状態を更新するメソッド
		/// @param pos オブジェクトの座標
		void Update(const Point& pos) override;
	};
}
