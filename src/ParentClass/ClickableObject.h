#pragma once
#include <Siv3D.hpp>
#include "DisplayObject.h"

class ClickableObject : public DisplayObject{
private:
	Rect m_ClickableRange;
	bool m_Enable = true;
protected:
	/// @brief 左クリックを押した瞬間
	virtual void LButtonDown() {}
	/// @brief 左クリックを押している間
	virtual void LButtonPressed() {}
	/// @brief 左クリックを離した瞬間
	virtual void LButtonUp() {}
	/// @brief 右クリックを押した瞬間
	virtual void RButtonDown() {}
	/// @brief 右クリックを押している間
	virtual void RButtonPressed() {}
	/// @brief 左クリックを離した瞬間
	virtual void RButtonUp() {}
	/// @brief 中クリックを押した瞬間
	virtual void MButtonDown() {}
	/// @brief 中クリックを押している間
	virtual void MButtonPressed() {}
	/// @brief 中クリックを離した瞬間
	virtual void MButtonUp() {}
	/// @brief クリック可能範囲を設定
	/// @param rect クリック可能範囲
	void SetClickableRange(const Rect& rect) { m_ClickableRange = rect; }
	/// @brief クリック可能範囲を取得
	/// @return クリック可能範囲
	Rect GetClickableRange() { return m_ClickableRange; }
	/// @brief カーソルスタイルを変更します
	virtual void ChangeCursorStyle() { Cursor::RequestStyle(CursorStyle::Hand); }
public:
	void SetEnable(bool enable) { m_Enable = enable; }
	bool GetEnable() const { return m_Enable; }
	/// @brief ユーザーの入力を受け付ける
	/// @brief whileでUpdateの後に呼ばれる
	virtual void InputUpdate();
	/// @brief オブジェクトの状態を更新するメソッド
	/// @param pos オブジェクトの座標
	virtual void Update(const Point& pos) override;
};
