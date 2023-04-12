#include "Runner.h"

void Runner::Step() {

}

void Runner::Run() {
	for (int i = 0; i < MAX_EXE_NUM; i++) {
		this->Step();
	}
}
