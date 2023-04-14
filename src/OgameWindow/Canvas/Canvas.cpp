#include "Canvas.h"
#include "../../Judge/Judge.h"
#include "../../User/User.h"

namespace OgameWindow {
	void Canvas::move(const Point& _pos) {
		this->localPos += _pos;
	}
	void Canvas::reload() {
		this->codels = {};
		for (int y = 0; y < this->canvasWidthHeight.y; y++) {
			for (int x = 0; x < this->canvasWidthHeight.x; x++) {
				//Console << Point(x, y);
				this->codels.push_back(Codel(Point(x, y)));
			}
		}
	}
	void Canvas::userInput() {
		if (Judge::IsCursorInRect(getClickableRange())) {
			if (KeyControl.pressed()) {
				//Console << Mouse::Wheel();
				//double temp = Mouse::Wheel() - 4;
				//int zoomDelta = ((int)(temp) >= 2) ? temp : 2;
				//Console << zoomDelta;
				Codel::SetCodelSize(Codel::GetCodelSize() - (int)Mouse::Wheel());
			}
			else if (KeyLShift.pressed()) {
				this->move(Point(-(int)Mouse::Wheel() * 10, 0));
			}
			else {
				this->move(Point(0, -(int)Mouse::Wheel() * 10));
			}
			if (MouseM.down()) {
				User::State::SetIsCanvasHold(true);
			}
		}
		if (MouseM.up()) {
			User::State::SetIsCanvasHold(false);
		}
		if (User::State::GetIsCanvasHold()) {
			Cursor::RequestStyle(CursorStyle::Cross);
			this->move(Cursor::Delta());
		}
	}


	void Canvas::draw() {
		Graphics2D::SetScissorRect(this->background.getOutline());
		RasterizerState rs = RasterizerState::Default2D;
		// シザー矩形を有効化
		rs.scissorEnable = true;
		const ScopedRenderStates2D rasterizer{ rs };
		this->background.draw();
		for (int y = 0; y < this->canvasWidthHeight.y; y++) {
			for (int x = 0; x < this->canvasWidthHeight.x; x++) {
				this->codels[x + y * this->canvasWidthHeight.x].draw();
			}
		}
	}

	Canvas::Canvas(const Point& _pos) {
		this->setPosition(_pos);
		this->background = CanvasBackground(_pos);
		this->setClickableRange(this->background.getOutline());
		this->canvasWidthHeight = Point(10, 10);
		this->localPos = Point(this->canvasWidthHeight.x * Codel::GetCodelSize() / 2, this->canvasWidthHeight.y * Codel::GetCodelSize() / 2 + 10);
		this->reload();
	}

	void Canvas::inputUpdate() {
		if (Judge::IsCursorInRect(getClickableRange())) {
			for (int y = 0; y < this->canvasWidthHeight.y; y++) {
				for (int x = 0; x < this->canvasWidthHeight.x; x++) {
					this->codels[x + y * this->canvasWidthHeight.x].inputUpdate();
				}
			}
		}
		this->userInput();
		ClickableObject::inputUpdate();
	}

	void Canvas::update(const Point& _pos) {
		Codel::setCanvas(this->background.getOutline());
		this->setClickableRange(this->background.getOutline());
		const int codelSize = Codel::GetCodelSize();
		Point _canvasSize{ codelSize * this->canvasWidthHeight.x, codelSize * this->canvasWidthHeight.y };
		for (int y = 0; y < this->canvasWidthHeight.y; y++) {
			for (int x = 0; x < this->canvasWidthHeight.x; x++) {
				//this->codels[x + y * this->canvasWidthHeight.x].update(Point(_pos.x + this->localPos.x + _canvasSize.x / 2 + codelSize * (x - _canvasSize.x / 2) - x - _canvasSize.x / 2,
				//	_pos.y + this->localPos.y + _canvasSize.y / 2 + codelSize * (y - _canvasSize.y / 2) - y - _canvasSize.y / 2));
				this->codels[x + y * this->canvasWidthHeight.x].update(Point(
					_pos.x + codelSize * x + this->localPos.x - x - _canvasSize.x / 2,
					_pos.y + codelSize * y + this->localPos.y - y - _canvasSize.y / 2
				));
			}
		}
		this->background.update(_pos);
		DisplayObject::setSize(Point(_canvasSize.x * Codel::GetCodelSize(), _canvasSize.y * Codel::GetCodelSize()));
		DisplayObject::update(_pos);
	}
}
