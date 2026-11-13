
#include "Logger.h"

namespace shroom
{

	template <typename T>
	inline Vector3<T>::Vector3(T x, T y, T z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}

	template <typename T>
	inline Vector3<T>::Vector3(Vector3<T> const& other)
	{
		m_x = other.m_x;
		m_y = other.m_y;
		m_z = other.m_z;
	}

	template <typename T>
	inline Vector3<T>& Vector3<T>::operator=(Vector3<T> const& val)
	{
		m_x = val.m_x;
		m_y = val.m_y;
		m_z = val.m_z;
		return *this;
	}

	template <typename T>
	inline T& Vector3<T>::X() { return m_x; }
	template <typename T>
	inline T& Vector3<T>::Y() { return m_y; }
	template <typename T>
	inline T& Vector3<T>::Z() { return m_z; }

	template <typename T>
	inline void Vector3<T>::operator+=(Vector3<T> const& val)
	{
		m_x = m_x + val.m_x;
		m_y = m_y + val.m_y;
		m_z = m_z + val.m_z;
	}
	template <typename T>
	inline Vector3<T> Vector3<T>::operator+(Vector3<T> const& val)
	{
		Vector3<T> out = *this;
		out += val;
		return out;
	}

	template <typename T>
	inline void Vector3<T>::operator-=(Vector3<T> const& val)
	{
		m_x = m_x - val.m_x;
		m_y = m_y - val.m_y;
		m_z = m_z - val.m_z;
	}
	template <typename T>
	inline Vector3<T> Vector3<T>::operator-(Vector3<T> const& val)
	{
		Vector3<T> out = *this;
		out -= val;
		return out;
	}

	template <typename T>
	inline void Vector3<T>::operator*=(Vector3<T> const& val)
	{
		m_x = m_x * val.m_x;
		m_y = m_y * val.m_y;
		m_z = m_z * val.m_z;
	}
	template <typename T>
	inline Vector3<T> Vector3<T>::operator*(Vector3<T> const& val)
	{
		Vector3<T> out = *this;
		out *= val;
		return out;
	}
	template <typename T>
	inline void Vector3<T>::operator*=(T const& val)
	{
		m_x = m_x * val;
		m_y = m_y * val;
		m_z = m_z * val;
	}
	template <typename T>
	inline Vector3<T> Vector3<T>::operator*(T const& val)
	{
		Vector3<T> out = *this;
		out *= val;
		return out;
	}

	template <typename T>
	inline void Vector3<T>::operator/=(Vector3<T> const& val)
	{
		if (val.m_x == 0 || val.m_y == 0 || val.m_z == 0)
		{
			Logger::Info("Try To Divide By 0");
			return;
		}
		m_x = m_x / val.m_x;
		m_y = m_y / val.m_y;
		m_z = m_z / val.m_z;
	}
	template <typename T>
	inline Vector3<T> Vector3<T>::operator/(Vector3<T> const& val)
	{
		Vector3<T> out = *this;
		out /= val;
		return out;
	}
	template <typename T>
	inline void Vector3<T>::operator/=(T const& val)
	{
		if (val == 0)
		{
			Logger::Info("Try To Divide By 0");
			return;
		}
		m_x = m_x / val;
		m_y = m_y / val;
		m_z = m_z / val;
	}
	template <typename T>
	inline Vector3<T> Vector3<T>::operator/(T const& val)
	{
		Vector3<T> out = *this;
		out /= val;
		return out;
	}

	template <typename T>
	inline float Vector3<T>::GetMagnitude();

	template <typename T>
	inline void Vector3<T>::Normalize();

	template <typename T>
	inline Vector3<T> Vector3<T>::GetNormalize();

	template <typename T>
	inline float Vector3<T>::DotProduct();

	template <>
	inline static Vector3<float> Vector3<float>::Zero()
	{
		return Vector3(0.0f, 0.0f,0.0f);
	}
	template <>
	inline static Vector3<int> Vector3<int>::Zero()
	{
		return Vector3(0, 0,0);
	}

	template <>
	inline static Vector3<float> Vector3<float>::One()
	{
		return Vector3(1.0f, 1.0f,1.0f);
	}
	template <>
	inline static Vector3<int> Vector3<int>::One()
	{
		return Vector3(1, 1,1);
	}
}