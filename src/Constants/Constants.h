#pragma once

#include<Siv3D.hpp>

namespace Constants {
	inline static const Array<Color> Colors = {
		Color{255, 192, 192}, // red
		Color{255, 255, 192}, // yellow
		Color{192, 255, 192}, // green
		Color{192, 255, 255}, // cyan
		Color{192, 192, 255}, // blue
		Color{255, 192, 255}, // magenta

		Color{ 255, 0, 0 },
		Color{255, 255, 0},
		Color{0, 255, 0},
		Color{0, 255, 255},
		Color{0, 0, 255},
		Color{255, 0, 255},

		Color{ 192, 0, 0 },
		Color{192, 192, 0},
		Color{0, 192, 0},
		Color{0, 192, 192},
		Color{0, 0, 192},
		Color{192, 0, 192},

		Color{255, 255, 255}, // white
		Color{0, 0, 0}, // black

		Color{255, 192, 192}
	};

	inline static const Array<String> Orders = {
		U"*",
		U"add",
		U"div",
		U"great",
		U"dup",
		U"in(c)",
		U"push",
		U"sub",
		U"mod",
		U"point",
		U"roll",
		U"out(n)",
		U"pop",
		U"mul",
		U"not",
		U"switch",
		U"in(n)",
		U"out(c)",
		U"white",
		U"black",
		U""
	};
}
