#pragma once

#include <Siv3D.hpp>

class DisplayObject {
private:
	inline static int m_LatestID = 0;
	int m_ObjectID;
	Point m_Pos;
	Point m_Size;
protected:
	int GetObjectID() { return m_ObjectID; };
	DisplayObject() :
		m_ObjectID(m_LatestID),
		m_Pos(Point{0, 0}),
		m_Size(Point(0, 0))
	{
		m_LatestID++;
	}
public:
	void SetPosition(Point pos) { m_Pos = pos; };
	Point GetPosition() const { return m_Pos; };
	void SetSize(Point size) { m_Size = size; };
	Point GetSize() const { return m_Size; };

	virtual void Draw() {};
	virtual void Update(Point pos) {
		m_Pos = pos;
	};
};
