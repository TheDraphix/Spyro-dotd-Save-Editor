#include <iostream>
#include <cstdint>
#include <cstring>

#include "uuid.hpp"
#include "byte_utils.hpp"
#include "save_data.hpp"

int main()
{
	char input[32];
	
	std::cout << "INFILE: ";
	std::cin >> input;
	save_data::GameSave save(input);
	
	memcpy(save.slot[0].spawn_point_uuid, uuid::spawn::valley_of_avalar[0], 4*sizeof(uint32_t));
	
	std::cout << "OUTFILE: ";
	std::cin >> input;
	save.Write(input);
	
	return 0;
}
