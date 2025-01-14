#ifndef BYTE_UTILS_H
#define BYTE_UTILS_H

#include <iostream>
#include <fstream>

#include "uuid.hpp"

template <typename T>
T ByteSwap(T x)
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

template <typename T>
void ByteSwap(T *x, int size)
{
	for (int i=0; i<size; i++)
		x[i] = ByteSwap<T>(x[i]);
}

class ByteStream {
	public:
		std::fstream stream;
		
		template <typename T>
		friend ByteStream& operator>>(ByteStream& lhs, T& rhs)
		{
			lhs.stream.read(reinterpret_cast<char *>(&rhs), sizeof(T));
			return lhs;
		}
		
		template <typename T>
		friend ByteStream& operator<<(ByteStream& lhs, T& rhs)
		{
			lhs.stream.write(reinterpret_cast<char *>(&rhs), sizeof(T));
			return lhs;
		}
};


#endif
