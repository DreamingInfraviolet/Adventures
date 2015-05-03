#include <math.h>
#include "matrixd.h"
using namespace std;

namespace math
{
float dot (const vec2& v1, const vec2& v2)
{
	return v1.x*v2.x+v1.y*v2.y;
}

vec2::vec2 ()
{
	reset();
}

vec2::vec2 (const float x_, const float y_)
{
	x=x_;
	y=y_;
}

vec2::vec2 (const float n)
{
	x = n;
	y = n;
}

inline float vec2::angle () const
{
	return atan2(y,x);
}

inline float vec2::lengthSquared() const
{
	return x*x+y*y;
}

inline float vec2::length () const
{
	return sqrtf(x*x+y*y);
}

float vec2::distance(const vec2& v) const
{
	return sqrtf((x - v.x)*(x - v.x) + (y - v.y)*(y - v.y));
}

float vec2::distanceSquared(const vec2& v) const
{
	return (x - v.x)*(x - v.x) + (y - v.y)*(y - v.y);
}

vec2 vec2::operator * (const float n) const
{
	vec2 out;
	out.x=x*n;
	out.y=y*n;
	return out;
}
vec2 vec2::operator / (const float n) const
{
	vec2 out;
	out.x=x/n;
	out.y=y/n;
	return out;
}
vec2 vec2::operator + (const float n) const
{
	vec2 out;
	out.x=x+n;
	out.y=y+n;
	return out;
}
vec2 vec2::operator - (const float n) const
{
	vec2 out;
	out.x-=n;
	out.y-=n;
	return out;
}
void  vec2::operator *= (const float n)
{
	x*=n;
	y*=n;
}
void vec2::operator /= (const float n)
{
	x/=n;
	y/=n;
}
void vec2::operator += (const float n)
{
	x+=n;
	y+=n;
}
void vec2::operator -= (const float n)
{
	x-=n;
	y-=n;
}
bool vec2::operator == (const vec2& vec)
{
	return x == vec.x && y == vec.y;
}
inline float vec2::dot (const vec2& v) const
{
	return math::dot (*this, v);
}

vec2& vec2::normalize ()
{
	float lenDivisor = 1.f/length();
	x*=lenDivisor;
	y*=lenDivisor;
	return *this;
}

vec2 vec2::operator + (const vec2& vec) const
{
	return vec2(x + vec.x, y + vec.y);
}

vec2 vec2::operator - (const vec2& vec) const
{
	return vec2(x - vec.x, y - vec.y);
}

vec2 vec2::operator * (const vec2& vec) const
{
	return vec2(x*vec.x, y*vec.y);
}

vec2 vec2::operator / (const vec2& vec) const
{
	return vec2(x/vec.x, y/vec.y);
}

void vec2::operator += (const vec2& vec)
{
	x += vec.x;
	y += vec.y;
}

void vec2::operator -= (const vec2& vec)
{
	x -= vec.x;
	y -= vec.y;
}

void vec2::operator *= (const vec2& vec)
{
	x *= vec.x;
	y *= vec.y;
}

void vec2::operator /= (const vec2& vec)
{
	x /= vec.x;
	y /= vec.y;
}

vec2 vec2::xy() { return vec2(x, y); } vec2 vec2::yx() { return vec2(y, x); }

void vec2::reset()
{
	x = 0;
	y = 0;
}
}