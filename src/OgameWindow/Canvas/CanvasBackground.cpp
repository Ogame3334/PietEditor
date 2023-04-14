#include "CanvasBackground.h"
#include "../../User/User.h"

namespace OgameWindow {
	void CanvasBackground::draw() {
		Point pos = getPosition();
		setSize(Point(Scene::Size().x - pos.x - 20, Scene::Size().y - pos.y - 300));
		Point size = getSize();
		this->outline = Rect(pos.x, pos.y, size.x, size.y);
		this->outline.drawFrame(1, 0, this->themePtr->CanvasBackOutlineColor);
		Rect background = this->outline;
		background.draw(this->themePtr->CanvasBackGroundColor);
	}
}
