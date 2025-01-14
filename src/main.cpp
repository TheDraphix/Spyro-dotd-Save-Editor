#include <iostream>
#include <cstdint>
#include <cstring>

#include "uuid.hpp"
#include "byte_utils.hpp"

int main()
{ // New uuid demo
	uint32_t a[4] = {0xb537349c, 0x22ff7d46, 0x83d8c133, 0x34416b2d};
	std::memcpy(a, uuid::spawn::twilight_falls[0], 4);
	ByteSwap<uint32_t>(a,4);
	std::cout << std::hex << a[0] << std::endl;
}
