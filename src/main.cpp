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

	save.content.slot[0].spawn_point_uuid[0] = uuid::spawn::malefors_lair[0][0];
	save.content.slot[0].spawn_point_uuid[1] = uuid::spawn::malefors_lair[0][1];
	save.content.slot[0].spawn_point_uuid[2] = uuid::spawn::malefors_lair[0][2];
	save.content.slot[0].spawn_point_uuid[3] = uuid::spawn::malefors_lair[0][3];

	save.content.slot[0].spawn_point_uuid[0] = byteswap<uint32_t>(save.content.slot[0].spawn_point_uuid[0]);
	save.content.slot[0].spawn_point_uuid[1] = byteswap<uint32_t>(save.content.slot[0].spawn_point_uuid[1]);
	save.content.slot[0].spawn_point_uuid[2] = byteswap<uint32_t>(save.content.slot[0].spawn_point_uuid[2]);
	save.content.slot[0].spawn_point_uuid[3] = byteswap<uint32_t>(save.content.slot[0].spawn_point_uuid[3]);

	save.Write();
return 0;
}

