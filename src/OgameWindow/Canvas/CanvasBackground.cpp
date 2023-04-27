#include "CanvasBackground.h"
#include "../../User/User.h"

namespace OgameWindow {
	void CanvasBackground::draw() {
		Point pos = getPosition();
		setSize(Point(Scene::Size().x - pos.x - 20, Scene::Size().y - pos.y - 300));
		Point _size = getSize();
		this->outline = Rect(pos.x, pos.y, _size.x, _size.y);
		this->outline.drawFrame(1, 0, this->themePtr->CanvasBackOutlineColor);
		Rect background = this->outline;
		background.draw(this->themePtr->CanvasBackGroundColor);
	}
}
