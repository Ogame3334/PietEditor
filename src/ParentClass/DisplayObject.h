#pragma once

#include <Siv3D.hpp>
#include "../User/User.h"

class DisplayObject {
private:
	inline static int m_LatestID = 0;
	int m_ObjectID;
protected:
	Point m_Pos;
	Point m_Size;
	const Theme* m_ThemePtr;
	/// @brief オブジェクトのIDを取得します
	/// @return オブジェクトID
	int GetObjectID() { return m_ObjectID; };
	/// @brief DisplayObjectの標準コンストラクタ
	DisplayObject() :
		m_ObjectID(m_LatestID),
		m_Pos(Point{ 0, 0 }),
		m_Size(Point(0, 0)),
		m_ThemePtr(User::Setting::GetThemePtr())
	{
		m_LatestID++;
	}
public:
	/// @brief オブジェクトの座標を設定
	/// @param pos オブジェクトの座標
	void SetPosition(const Point& pos) { m_Pos = pos; }

	/// @brief オブジェクトの座標を取得
	/// @return オブジェクトの座標
	Point GetPosition() const { return m_Pos; }

	/// @brief オブジェクトの幅と高さを設定
	/// @param size オブジェクトの幅と高さ
	void SetSize(const Point& size) { m_Size = size; }

	/// @brief オブジェクトの幅と高さを取得
	/// @return オブジェクトの幅と高さ
	Point GetSize() const { return m_Size; }

	/// @brief オブジェクトを画面に表示する関数
	/// @detail whileでUpdate, InputUpdateの後に呼び出される
	virtual void Draw() {}
	/// @brief オブジェクトの状態を更新するメソッド
	/// @param pos オブジェクトの座標
	virtual void Update(const Point& pos) {
		m_Pos = pos;
	}
};
