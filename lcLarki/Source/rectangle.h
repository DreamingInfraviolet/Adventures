#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "matrixd.h"

/**
 * A rectangle class, with the x,y coordinates describing the bottom left point.
 * */
namespace util
{
	template <class T>
	class Rectangle
	{
		T mX, mY, mH, mW;

	public:
		Rectangle()
		{
			mX = 0;
			mY = 0;
			mH = 0;
			mW = 0;
		}

		//constructs a rectangle around a circle with given centre and radius.
		Rectangle(const math::vec2& centre, float radius)
		{
			mX = centre.x - radius;
			mY = centre.y - radius;
			mH = radius * 2;
			mW = radius * 2;
		}

		T x() const { return mX; }
		T y() const { return mY; }
		T h() const { return mH; }
		T w() const { return mW; }

		T leftEdge() const { return mX; }
		T rightEdge() const { return mX + mW; }
		T bottomEdge() const { return mY; }
		T topEdge() const { return mY + mH; }

		void x(T x_) { mX = x_; }
		void y(T y_) { mY = y_; }
		void h(T h_) { mH = h_; }
		void w(T w_) { mW = w_; }
	};

	typedef Rectangle<int> Rectanglei;
	typedef Rectangle<float> Rectanglef;
}
#endif // RECTANGLE_H
