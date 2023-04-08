#include "ButtonsFunc.h"
#include "../User/User.h"

namespace ButtonsFunc {
	void Run() {
		User::State::SetMode(Mode::DEBUG);
	}
	void Step(){
		User::State::SetMode(Mode::DEBUG);
	}
	void Jump(){
		User::State::SetMode(Mode::DEBUG);
	}
	void Stop() {
		User::State::SetMode(Mode::EDIT);
	}
}
