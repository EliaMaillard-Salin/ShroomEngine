
#include "Logger.h"

template <typename T>
inline Vector2<T>::Vector2(T _x, T _y)
{
	m_x = _x;
	m_y = _y;
}

template <typename T>
inline Vector2<T>::Vector2(Vector2<T> const& other)
{
	m_x = other.m_x;
	m_y = other.m_y;
}

template <typename T>
inline Vector2<T>& Vector2<T>::operator=(Vector2<T> const& val)
{
	m_x = val.m_x;
	m_y = val.m_y;
	return *this;
}

template <typename T>
inline T& Vector2<T>::X() { return m_x; }
template <typename T>
inline T& Vector2<T>::Y() { return m_y; }

template <typename T>
inline void Vector2<T>::operator+=(Vector2<T> const& val)
{
	m_x = m_x + val.m_x;
	m_y = m_y + val.m_y;
}
template <typename T>
inline Vector2<T> Vector2<T>::operator+(Vector2<T> const& val)
{
	Vector2<T> out = this;
	out += val;
	return out;
}

template <typename T>
inline void Vector2<T>::operator-=(Vector2<T> const& val)
{
	m_x = m_x - val.m_x;
	m_y = m_y - val.m_y;
}
template <typename T>
inline Vector2<T> Vector2<T>::operator-(Vector2<T> const& val)
{
	Vector2<T> out = this;
	out -= val;
	return out;
}

template <typename T>
inline void Vector2<T>::operator*=(Vector2<T> const& val)
{
	m_x = m_x * val.m_x;
	m_y = m_y * val.m_y;
}
template <typename T>
inline Vector2<T> Vector2<T>::operator*(Vector2<T> const& val)
{
	Vector2<T> out = this;
	out *= val;
	return out;
}
template <typename T>
inline void Vector2<T>::operator*=(T const& val)
{
	m_x = m_x * val;
	m_y = m_y * val;
}
template <typename T>
inline Vector2<T> Vector2<T>::operator*(T const& val)
{
	Vector2<T> out = this;
	out *= val;
	return out;
}

template <typename T>
inline void Vector2<T>::operator/=(Vector2<T> const& val)
{
	if (val.m_x == 0 || val.m_y == 0)
	{
		Logger::Info("Try To Divide By 0");
		return;
	}
	m_x = m_x / val.m_x;
	m_y = m_y / val.m_y;
}
template <typename T>
inline Vector2<T> Vector2<T>::operator/(Vector2<T> const& val)
{
	Vector2<T> out = this;
	out /= val;
	return out;
}
template <typename T>
inline void Vector2<T>::operator/=(T const& val)
{
	if (val == 0)
	{
		Logger::Info("Try To Divide By 0");
		return;
	}
	m_x = m_x / val;
	m_y = m_y / val;
}
template <typename T>
inline Vector2<T> Vector2<T>::operator/(T const& val)
{
	Vector2<T> out = this;
	out /= val;
	return out;
}

template <typename T>
inline float Vector2<T>::GetMagnitude();

template <typename T>
inline void Vector2<T>::Normalize();

template <typename T>
inline Vector2<T> Vector2<T>::GetNormalize();

template <typename T>
inline float Vector2<T>::DotProduct();

template <>
inline static Vector2<float> Vector2<float>::Zero()
{
	return Vector2(0.0f, 0.0f);
}
template <>
inline static Vector2<int> Vector2<int>::Zero()
{
	return Vector2(0, 0);
}

template <>
inline static Vector2<float> Vector2<float>::One()
{
	return Vector2(1.0f, 1.0f);
}
template <>
inline static Vector2<int> Vector2<int>::One()
{
	return Vector2(1, 1);
}
