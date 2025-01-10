#include "save_data.hpp"

save_data::GameSave::GameSave(const char *file_name)
{
	this->name = const_cast<char *>(file_name);
	std::fstream fs(this->name);	
		if (fs.fail())
	std::cout << "error opening file :(" << std::endl;
  	
	fs.seekg(0, std::ios::end);
	size = fs.tellg(); 
	fs.seekg(0, std::ios::beg);
  
	this->data = new char[this->size];
	fs.read(this->data, this->size);
	if (fs.fail())
		std::cout << "error reading file :(" << std::endl;
  	
	this->DetermineVersion();
	this->MapSaveDataAddresses();
}

void save_data::GameSave::MapSaveDataAddresses()
// originally content data was to be loaded into a struct raw from the content file, however, due to padding this is not possible.
// instead a struct is used as an interface to access content entries from a buffer using pointers.
// this might not be the most elegant solution so it may be changed in the future.
{
	int offset = 0x0;
	int slots = 1;
	
	if (this->GetVersion() == save_data::PS2 || this->GetVersion() == save_data::WII)
	{
		this->content.header.unknown_0x0000 =	reinterpret_cast<uint8_t*>(&this->data[0x0000]);
		this->content.header.file_status =		reinterpret_cast<bool*>(&this->data[0x0010]);
		
		offset += 0x11;
		slots = 5;
	}
	
	this->content.metadata.file_setting =					reinterpret_cast<uint32_t*>(&this->data[0x0000 + offset]);
	this->content.metadata.game_structure_class_full_id =	reinterpret_cast<uint16_t*>(&this->data[0x0004 + offset]);
	this->content.metadata.unknown_0x0006 =				reinterpret_cast<uint8_t*>(&this->data[0x0006 + offset]);
	this->content.metadata.unknown_0x0007 =				reinterpret_cast<uint8_t*>(&this->data[0x0007 + offset]);
	this->content.metadata.first_slot_start_address =		reinterpret_cast<uint32_t*>(&this->data[0x0008 + offset]);

	for (int i=0; i<slots; i++)
	{
		this->content.slot[i].player_class_full_id =		reinterpret_cast<uint16_t*>(&this->data[0x000c + offset]);
		this->content.slot[i].player_instance_id =			reinterpret_cast<uint8_t*>(&this->data[0x000e + offset]);
		this->content.slot[i].unknown_0x000F =				reinterpret_cast<uint8_t*>(&this->data[0x000F + offset]);
		this->content.slot[i].current_slot_start_offset =	reinterpret_cast<uint32_t*>(&this->data[0x0010 + offset]);
		this->content.slot[i].unknown_0x0014 =				reinterpret_cast<uint8_t*>(&this->data[0x0014 + offset]);
		this->content.slot[i].slot_status =				reinterpret_cast<bool*>(&this->data[0x0018 + offset]);
		this->content.slot[i].total_game_time =			reinterpret_cast<float*>(&this->data[0x0019 + offset]);
		this->content.slot[i].game_state_object_status =	reinterpret_cast<uint32_t*>(&this->data[0x001d + offset]);
		this->content.slot[i].game_state_uuid =			reinterpret_cast<uint32_t*>(&this->data[0x0021 + offset]);
		this->content.slot[i].next_slot_start_offset =		reinterpret_cast<uint32_t*>(&this->data[0x0031 + offset]);
		this->content.slot[i].spawn_point_object_status =	reinterpret_cast<uint32_t*>(&this->data[0x0035 + offset]);
		this->content.slot[i].spawn_point_uuid =			reinterpret_cast<uint32_t*>(&this->data[0x0039 + offset]);

		offset += 0x53f; // wii/ps2 hack (change later)
	}
}
void save_data::GameSave::DetermineVersion()
{
	this->version = save_data::PS2; // temporary hack
}

void save_data::GameSave::Write()
{
	std::ofstream outfile(this->name);
	outfile.write(this->data, this->size);
	if (outfile.fail())
		std::cout << "failed to write to file" << std::endl;
}
