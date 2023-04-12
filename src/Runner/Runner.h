#pragma once
#include "../OgameWindow/Canvas/Canvas.h"
#include "../OgameWindow/Canvas/Codel.h"

class Runner
{
private:
	const int MAX_EXE_NUM = 10000;
	Point now_coord;
	OgameWindow::Canvas canvas;
	Array<OgameWindow::Codel> codels;
	
public:
	Runner(OgameWindow::Canvas canvas) :
		now_coord(Point(0, 0)),
		codels({}), canvas(canvas)
	{}

	void Init() {
		now_coord = Point(0, 0);
		codels = this->canvas.GetCodels();
	}

	void Step();
	void Run();
};
