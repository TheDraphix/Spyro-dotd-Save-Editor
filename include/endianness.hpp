#ifndef ENDIANNESS_H
#define ENDIANNESS_H
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
#endif
