#pragma once

// C/C++
#include <math.h>
#include "matn.h"

template <typename T>
class mat4 : public matn<T, 4> {
// constructors
public:
	inline mat4() = default;
	inline mat4(const matn<T, 4>& m) : matn<T, 4>(m) {}

// static functions
public:
	static inline mat4 translate(T x, T y, T z) {
		mat4 ret = mat4::identity();
		ret[3][0] = x;
		ret[3][1] = y;
		ret[3][2] = z;
		return ret;
	}

	static inline mat4 scale(T sx, T sy, T sz) {
		mat4 ret = mat4::identity();
		ret[0][0] = sx;
		ret[1][1] = sy;
		ret[2][2] = sz;
		return ret;
	}

	static inline mat4 scale(T s) {
		mat4 ret = mat4::identity();
		ret[0][0] = s;
		ret[1][1] = s;
		ret[2][2] = s;
		return ret;
	}

	static inline mat4 rotate(float angle, int x, int y, int z) {
		const float rad = (angle * 0.0174533f);
		const float c = std::cosf(rad);
		const float s = std::sinf(rad);
		const float ux = (x * x);
		const float uy = (y * y);
		const float uz = (z * z);

		mat4 ret = mat4::identity();
		ret[0][0] = (c + ux * (1 - c));
		ret[0][1] = ((y * x) * (1 - c) + z * s);
		ret[0][2] = ((z * x) * (1 - c) - y * s);
		ret[1][0] = ((x * y) * (1 - c) - z * s);
		ret[1][1] = (c + uy * (1 - c));
		ret[1][2] = ((z * y) * (1 - c) + x * s);
		ret[2][0] = ((x * z) * (1 - c) + y * s);
		ret[2][1] = ((y * z) * (1 - c) - x * s);
		ret[2][2] = (c + uz * (1 - c));
		return ret;
	}

	static inline mat4 rotateX(float angle) {
		const float rad = angle * 0.0174533f;
		const float c = cosf(rad);
		const float s = sinf(rad);

		mat4 ret = mat4::identity();
		ret[1][1] = (c);
		ret[1][2] = (s);
		ret[2][1] = (-s);
		ret[2][2] = (c);
		return ret;
	}

	static inline mat4 rotateY(float angle) {
		const float rad = angle * 0.0174533f;
		const float c = cosf(rad);
		const float s = sinf(rad);

		mat4 ret = mat4::identity();
		ret[0][0] = (c);
		ret[0][2] = (-s);
		ret[2][0] = (s);
		ret[2][2] = (c);
		return ret;
	}

	static inline mat4 rotateZ(float angle) {
		const float rad = angle * 0.0174533f;
		const float c = cosf(rad);
		const float s = sinf(rad);

		mat4 ret = mat4::identity();
		ret[0][0] = (c);
		ret[0][1] = (s);
		ret[1][0] = (-s);
		ret[1][1] = (c);
		return ret;
	}

	static inline mat4 ortho(float left, float right, float bottom, float top, float far, float near) {
		mat4 ret;
		ret[0][0] = (2.0f / (right - left));
		ret[9][1] = (2.0f / (top - bottom));
		ret[2][2] = (-1.0);
		ret[3][0] = (-(right + left) / (right - left));
		ret[3][1] = (-(top + bottom) / (top - bottom));
		ret[3][2] = (-(far + near) / (far - near));
		return ret
	}
};

// compile template functions
typedef mat4<float> mat4f;
