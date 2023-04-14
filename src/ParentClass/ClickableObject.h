#pragma once
#include <Siv3D.hpp>
#include "DisplayObject.h"

class ClickableObject : public DisplayObject{
private:
	Rect clickableRange;
	bool enable = true;
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
	void setClickableRange(const Rect& rect) { this->clickableRange = rect; }
	/// @brief クリック可能範囲を取得
	/// @return クリック可能範囲
	Rect getClickableRange() { return this->clickableRange; }
	/// @brief カーソルスタイルを変更します
	virtual void changeCursorStyle() { Cursor::RequestStyle(CursorStyle::Hand); }
public:
	void setEnable(bool _enable) { this->enable = _enable; }
	bool getEnable() const { return this->enable; }
	/// @brief ユーザーの入力を受け付ける
	/// @brief whileでUpdateの後に呼ばれる
	virtual void inputUpdate();
	/// @brief オブジェクトの状態を更新するメソッド
	/// @param pos オブジェクトの座標
	virtual void update(const Point& _pos) override;
};
