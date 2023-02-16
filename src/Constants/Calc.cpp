#include "Calc.h"
#include "../User/User.h"

namespace Constants {
	namespace Calc {
		int ColorIDSub(int id) {
			int nowID = User::State::GetSelectedColorID();
			int colorIDSub;
			if (id < 18) {
				int nowID_x = nowID % 6;
				int nowID_y = (int)(nowID / 6);
				int id_x = id % 6;
				int id_y = (int)(id / 6);
				int colorIDSub_x = (id_x - nowID_x >= 0) ? id_x - nowID_x : id_x - nowID_x + 6;
				int colorIDSub_y = (id_y - nowID_y >= 0) ? id_y - nowID_y : id_y - nowID_y + 3;
				colorIDSub = colorIDSub_x + colorIDSub_y * 6;
			}
			else {
				colorIDSub = id - nowID;
			}
			colorIDSub = (colorIDSub >= 0) ? colorIDSub : colorIDSub + 18;

			return colorIDSub;
		}
	}
}
