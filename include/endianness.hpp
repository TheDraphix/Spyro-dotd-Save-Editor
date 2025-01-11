#ifndef ENDIANNESS_H
#define ENDIANNESS_H

#include "uuid.hpp"
#include <cstdint>

template <typename T>
T byteswap(T x)
{
	union
	{
		T x;
		unsigned char u8[sizeof(T)];
	} source, dest;

	source.x = x;
	
	for (int i=0; i<sizeof(T); i++)
		dest.u8[i] = source.u8[sizeof(T) - i - 1];
	
	return dest.x;
}

uuid::UUID byteswap(uuid::UUID x)
{
	x.value[0] = byteswap<uint32_t>(x.value[0]);
	x.value[1] = byteswap<uint32_t>(x.value[1]);
	x.value[2] = byteswap<uint32_t>(x.value[2]);
	x.value[3] = byteswap<uint32_t>(x.value[3]);

	return x;
}
#endif
