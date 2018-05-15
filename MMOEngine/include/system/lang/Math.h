/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef MATH_
#define MATH_

#include <math.h>

#include "system/platform.h"

namespace sys {
  namespace lang {

	class Math {
	public:
		static double PI;
		static double DEG2RAD;
		static double RAD2DEG;
		static double E;

		static double sqrt(double number);

		//static float rsqrt(float number);

		//static float fabs(float f);

		template<typename T>
		static T clamp(const T& min, const T& value, const T& max) {
			return (value < min) ? min : ((value > max) ? max : value);
		}

		template<class T>
		static T linearInterpolate(const T& start, const T& end, float t) {
			return ((end - start) * t) + start;
		}

		template<typename T>
		static inline T sqr(const T& val) {
			return val * val;
		}

		template<typename T>
		static inline T min(const T& val1, const T& val2) {
			return val1 < val2 ? val1 : val2;
		}

		template<typename T>
		static inline T max(const T& val1, const T& val2) {
			return val1 > val2 ? val1 : val2;
		}

		static float getPrecision(float num, int digits) {
			float power = pow((float)10, digits);
			return float(floor(num * power + .05f) / power);
		}

		static inline double acos(double arg) {
			return ::acos(arg);
		}

		static inline double sin(double arg) {
			return ::sin(arg);
		}

		static inline double cos(double arg) {
			return ::cos(arg);
		}

		static inline double deg2rad(double degrees) {
			return degrees * DEG2RAD;
		}

		static inline double rad2deg(double radians) {
			return radians * RAD2DEG;
		}

		static inline double ln(float value) {
			return (log10(value) / log10(E));
		}
	};

  } // namespace lang
} // namespace sys

using namespace sys::lang;

#endif /*MATH_*/
