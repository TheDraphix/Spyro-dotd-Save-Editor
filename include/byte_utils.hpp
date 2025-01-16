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

class ByteStream: std::fstream {
	public:
		using std::fstream::fstream;
		using std::fstream::seekg;
		using std::fstream::open;
		using std::fstream::close;
		using std::fstream::fail;
		
		enum Mode {READ, WRITE};
		Mode mode;
		
		template <typename T>
		friend ByteStream& operator<=>(ByteStream& lhs, T& rhs)
		{
			if (lhs.mode==READ)
				lhs.read(reinterpret_cast<char *>(&rhs), sizeof(T));
			else if (lhs.mode==WRITE)
				lhs.write(reinterpret_cast<char *>(&rhs), sizeof(T));
			
			return lhs;
		}
};


#endif
