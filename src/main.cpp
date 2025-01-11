#include "save_data.hpp"
#include "uuid.hpp"
#include "endianness.hpp"

int main()
{
	char file_name[32];
	std::cout << "Enter file name: ";
	std::cin >> file_name;
	
	save_data::GameSave save(file_name);
	std::cout << "File size: " << save.GetSize() << std::endl;
	std::cout << "Version: " << save.GetVersion() << std::endl;

	save.content.slot[0].spawn_point_uuid = byteswap(uuid::spawn::floating_islands[1]);
		
	save.Write();
	return 0;
}

