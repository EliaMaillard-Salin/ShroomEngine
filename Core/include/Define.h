#ifndef CORE_DEFINE_H
#define CORE_DEFINE_H

#include <memory>

namespace shroom
{
	template <typename T>
	using uptr = std::unique_ptr<T>;

	template <typename T>
	using sptr = std::shared_ptr<T>;

	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;
	typedef unsigned long long uint64;

	typedef char int8;
	typedef short int16;
	typedef int int32;
	typedef long long int64;
};

#endif // !CORE_DEFINE_H
