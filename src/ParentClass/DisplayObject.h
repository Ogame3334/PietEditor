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
	/// @brief オブジェクトのIDを取得します
	/// @return オブジェクトID
	int getObjectID() { return objectID; };
	/// @brief DisplayObjectの標準コンストラクタ
	DisplayObject() :
		objectID(LatestID),
		position(Point{ 0, 0 }),
		size(Point(0, 0)),
		themePtr(User::Setting::GetThemePtr())
	{
		LatestID++;
	}
public:
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

	/// @brief オブジェクトを画面に表示する関数
	/// @detail whileでUpdate, InputUpdateの後に呼び出される
	virtual void draw() {}
	/// @brief オブジェクトの状態を更新するメソッド
	/// @param pos オブジェクトの座標
	virtual void update(const Point& _pos) {
		this->position = _pos;
	}
};
