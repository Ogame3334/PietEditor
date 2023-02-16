#pragma once
#include <Siv3D.hpp>
#include "DisplayObject.h"

class ClickableObject : public DisplayObject{
private:
	Rect m_ClickableRange;
protected:
	virtual void LButtonDown() {};
	virtual void LButtonPressed() {};
	virtual void LButtonUp() {};
	virtual void RButtonDown() {};
	virtual void RButtonPressed() {};
	virtual void RButtonUp() {};
	virtual void MButtonDown() {};
	virtual void MButtonUp() {};
	virtual void MButtonPressed() {};
	void SetClickableRange(Rect rect) { m_ClickableRange = rect; };
	Rect GetClickableRange() { return m_ClickableRange; };
public:
	virtual void InputUpdate();
	virtual void Update(Point pos) override;
};
