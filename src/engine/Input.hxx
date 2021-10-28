#pragma once

#ifdef _WIN32
enum class KeyCode : int {
	LeftMouse = 0x01, RightMouse, MiddleMouse, Mouse4, Mouse5,
	Tab = 0x09, Enter = 0x0D,
	a = 0x41, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,
	Num0 = 0x60, Num1, Num2, Num3m, Num4, Num5, Num6, Num7, Num8, Num9,
	LeftShift = 0xA0, RightShift, LeftControl, RightControl, LeftAlt
};
#endif
