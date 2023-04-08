#pragma once

class Runner
{
private:
	Point now_coord;
public:
	Runner() :
		now_coord(Point(0, 0)){}

	void init() {
		now_coord = Point(0, 0);
	}
};
