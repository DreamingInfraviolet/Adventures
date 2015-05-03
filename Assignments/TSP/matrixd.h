#pragma once
namespace math
{
	class vec2;

	float dot (const vec2& v1, const vec2& v2);

	class vec2
	{
	public:
	float x, y;
	vec2 ();
	vec2 (const float x_, const float y_);
	vec2 (const float direction);
	inline float angle () const;
	inline float lengthSquared() const;
	inline float length () const;
	float distance(const vec2& v) const;
	float distanceSquared(const vec2& v) const;
	vec2 operator * (const float n) const;
	vec2 operator / (const float n) const;
	vec2 operator + (const float n) const;
	vec2 operator - (const float n) const;
	vec2 operator + (const vec2& vec) const;
	vec2 operator - (const vec2& vec) const;
	vec2 operator * (const vec2& vec) const;
	vec2 operator / (const vec2& vec) const;
	void operator *= (const float n);
	void operator /= (const float n);
	void operator += (const float n);
	void operator -= (const float n);
	void operator += (const vec2& vec);
	void operator -= (const vec2& vec);
	void operator *= (const vec2& vec);
	void operator /= (const vec2& vec);
	bool operator == (const vec2& vec);
	inline float dot (const vec2& v) const;
	inline float cross (const vec2& v) const;
	vec2& normalize ();
	void reset();
	vec2 xy(); vec2 yx();
	};


	#define R 6371
	#define TO_RAD (3.1415926536 / 180)

	//th1,ph1,th2,ph2
	static float haversine(vec2 v1, vec2 v2)
	{
		double dx, dy, dz;
		v1.y -= v2.y;
		v1.y *= TO_RAD, v1.x *= TO_RAD, v2.x *= TO_RAD;
	 
		dz = sin(v1.x) - sin(v2.x);
		dx = cos(v1.y) * cos(v1.x) - cos(v2.x);
		dy = sin(v1.y) * cos(v1.x);
		return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
	}

}

