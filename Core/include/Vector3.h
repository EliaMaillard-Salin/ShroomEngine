#ifndef CORE_MATH_VECTOR3_H
#define CORE_MATH_VECTOR3_H

namespace shroom
{
	template<typename T>
	struct Vector3
	{
		Vector3() = default;
		Vector3(T x, T y, T z);
		Vector3(Vector3<T> const&);
		Vector3<T>& operator=(Vector3<T> const&);

		~Vector3() = default;

		T& X();
		T& Y();
		T& Z();

		void operator+=(Vector3<T> const& val);
		Vector3<T> operator+(Vector3<T> const& val);

		void operator-=(Vector3<T> const& val);
		Vector3<T> operator-(Vector3<T> const& val);

		void operator*=(Vector3<T> const& val);
		Vector3<T> operator*(Vector3<T> const& val);
		void operator*=(T const& val);
		Vector3<T> operator*(T const& val);

		void operator/=(Vector3<T> const& val);
		Vector3<T> operator/(Vector3<T> const& val);
		void operator/=(T const& val);
		Vector3<T> operator/(T const& val);


		float GetMagnitude();
		void Normalize();
		Vector3<T> GetNormalize();
		float DotProduct();


		static Vector3<T> Zero();
		static Vector3<T> One();
	private:
		T m_x;
		T m_y;
		T m_z;
	};


};

#include "Vector3.inl"

#endif // !CORE_MATH_VECTOR3_H
