#ifndef CORE_MATH_VECTOR2_H
#define CORE_MATH_VECTOR2_H

template<typename T>
struct Vector2
{
	Vector2() = default;
	Vector2(T _x, T _y);
	Vector2(Vector2<T> const&);
	Vector2<T>& operator=(Vector2<T> const&);

	~Vector2() = default;
	
	T& X();
	T& Y();

	void operator+=(Vector2<T> const& val);
	Vector2<T> operator+(Vector2<T> const& val);

	void operator-=(Vector2<T> const& val);
	Vector2<T> operator-(Vector2<T> const& val);

	void operator*=(Vector2<T> const& val);
	Vector2<T> operator*(Vector2<T> const& val);
	void operator*=(T const& val);
	Vector2<T> operator*(T const& val);

	void operator/=(Vector2<T> const& val);
	Vector2<T> operator/(Vector2<T> const& val);
	void operator/=(T const& val);
	Vector2<T> operator/(T const& val);


	float GetMagnitude();
	void Normalize();
	Vector2<T> GetNormalize();
	float DotProduct();


	static Vector2<T> Zero();
	static Vector2<T> One();
private:
	T m_x;
	T m_y;
};

#include "Vector2.inl"

#endif // !CORE_MATH_VECTOR2_H
