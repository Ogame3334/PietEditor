#pragma once

#include <Siv3D.hpp>
#include "../User/User.h"

class DisplayObject {
private:
	inline static int LatestID = 0;
	int objectID;
protected:
	Point position;
	Point size;
	const Theme* themePtr;
	Rect clickableRange;
	bool enable = true;

	/// @brief オブジェクトのIDを取得します
	/// @return オブジェクトID
	int getObjectID() { return objectID; };

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
	/// @brief DisplayObjectの標準コンストラクタ
	DisplayObject() :
		objectID(LatestID),
		position(Point{ 0, 0 }),
		size(Point(0, 0)),
		themePtr(User::Setting::GetThemePtr()),
		clickableRange(Rect())
	{
		LatestID++;
	}
	/// @brief オブジェクトの座標を設定
	/// @param pos オブジェクトの座標
	void setPosition(const Point& _pos) { this->position = _pos; }

	/// @brief オブジェクトの座標を取得
	/// @return オブジェクトの座標
	Point getPosition() const { return this->position; }

	/// @brief オブジェクトの幅と高さを設定
	/// @param size オブジェクトの幅と高さ
	void setSize(const Point& _size) { this->size = _size; }

	/// @brief オブジェクトの幅と高さを取得
	/// @return オブジェクトの幅と高さ
	Point getSize() const { return this->size; }

	void setEnable(bool _enable) { this->enable = _enable; }
	bool getEnable() const { return this->enable; }

	/// @brief TextBoxMultiLinesにて用いたいメソッド
	/// @return テキストボックスが選択されているか
	bool getIsSelected() const { return true; }

	/// @brief オブジェクトの座標を更新
	/// @param _pos オブジェクトの座標
	virtual void reload(const Point& _pos, const Size& _size) {
		this->position = _pos;
		this->size = _size;
	}

	/// @brief オブジェクトを画面に表示する関数
	/// @detail whileでUpdate, InputUpdateの後に呼び出される
	virtual void draw() {}
	/// @brief ユーザーの入力を受け付ける
	/// @brief whileでUpdateの後に呼ばれる
	virtual void inputUpdate();
	/// @brief 毎フレーム更新
	virtual void update() {
		if (this->clickableRange.mouseOver() and this->enable) {
			User::State::SetNowSelectObjectID(this->getObjectID());
		}
	}
};
