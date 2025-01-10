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

// all offsets are relative to the ps3 version of the game. // should also change the unknown naming convention to also align with the ps3 version.
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
		this->content.slot[i].slot_status =					reinterpret_cast<bool*>(&this->data[0x0018 + offset]);
		this->content.slot[i].total_game_time =				reinterpret_cast<float*>(&this->data[0x0019 + offset]);
		this->content.slot[i].game_state_object_status =	reinterpret_cast<uint32_t*>(&this->data[0x001d + offset]);
		this->content.slot[i].game_state_uuid =				reinterpret_cast<uint32_t*>(&this->data[0x0021 + offset]);
		this->content.slot[i].next_slot_start_offset =		reinterpret_cast<uint32_t*>(&this->data[0x0031 + offset]);
		this->content.slot[i].spawn_point_object_status =	reinterpret_cast<uint32_t*>(&this->data[0x0035 + offset]);
		if (*this->content.slot[i].spawn_point_object_status == 0xffffffff)
		{
			this->content.slot[i].dummy = true;
			offset -= 16;
		}
		else
		{
			this->content.slot[i].dummy = false;
			this->content.slot[i].spawn_point_uuid = reinterpret_cast<uint32_t*>(&this->data[0x0039 + offset]);
		}
		
		this->content.slot[i].module_event_flag =		reinterpret_cast<bool *>(&this->data[0x0049 + offset]);
		this->content.slot[i].module_completion_flag =	reinterpret_cast<bool *>(&this->data[0x01ff + offset]);
		this->content.slot[i].game_level_flag =			reinterpret_cast<bool *>(&this->data[0x03b5 + offset]);

		this->content.slot[i].spyro_current_health =			reinterpret_cast<uint32_t *>(&this->data[0x03c1 + offset]);
		this->content.slot[i].cynder_current_health =		reinterpret_cast<uint32_t *>(&this->data[0x03c5 + offset]);
		this->content.slot[i].spyro_current_mana =			reinterpret_cast<uint32_t *>(&this->data[0x03c9 + offset]);
		this->content.slot[i].cynder_current_mana =			reinterpret_cast<uint32_t *>(&this->data[0x03cd + offset]);
		this->content.slot[i].spyro_current_fury_points =	reinterpret_cast<int32_t *>(&this->data[0x03d1 + offset]);
		this->content.slot[i].cynder_current_fury_points =	reinterpret_cast<int32_t *>(&this->data[0x03d5 + offset]);
		this->content.slot[i].spyro_unspent_exp =			reinterpret_cast<int32_t *>(&this->data[0x03d9 + offset]);
		this->content.slot[i].cynder_unspent_exp =			reinterpret_cast<int32_t *>(&this->data[0x03dd + offset]);
		this->content.slot[i].fire_exp =						reinterpret_cast<int32_t *>(&this->data[0x03e1 + offset]);
		this->content.slot[i].ice_exp =						reinterpret_cast<int32_t *>(&this->data[0x03e5 + offset]);
		this->content.slot[i].earth_exp =					reinterpret_cast<int32_t *>(&this->data[0x03e9 + offset]);
		this->content.slot[i].electricity_exp =				reinterpret_cast<int32_t *>(&this->data[0x03ed + offset]);
		this->content.slot[i].purple_fury_exp =				reinterpret_cast<int32_t *>(&this->data[0x03f1 + offset]);
		this->content.slot[i].poison_exp =					reinterpret_cast<int32_t *>(&this->data[0x03f5 + offset]);
		this->content.slot[i].shadow_exp =					reinterpret_cast<int32_t *>(&this->data[0x03f9 + offset]);
		this->content.slot[i].fear_exp = 					reinterpret_cast<int32_t *>(&this->data[0x03fd + offset]);
		this->content.slot[i].wind_exp =						reinterpret_cast<int32_t *>(&this->data[0x0401 + offset]);
		this->content.slot[i].dark_fury_exp =				reinterpret_cast<int32_t *>(&this->data[0x0405 + offset]);

		this->content.slot[i].bonus_objective_flag = reinterpret_cast<bool *>(&this->data[0x0409]);
		
		this->content.slot[i].spyro_kills =						reinterpret_cast<int32_t *>(&this->data[0x04ae + offset]);
		this->content.slot[i].cynder_kills =						reinterpret_cast<int32_t *>(&this->data[0x04b2 + offset]);
		this->content.slot[i].spyro_max_combo =					reinterpret_cast<int32_t *>(&this->data[0x04b6 + offset]);
		this->content.slot[i].cynder_max_combo =					reinterpret_cast<int32_t *>(&this->data[0x04ba + offset]);
		this->content.slot[i].fire_mana_spent =					reinterpret_cast<uint32_t *>(&this->data[0x04be + offset]);
		this->content.slot[i].ice_mana_spent =					reinterpret_cast<uint32_t *>(&this->data[0x04c2 + offset]);
		this->content.slot[i].earth_mana_spent =					reinterpret_cast<uint32_t *>(&this->data[0x04c6 + offset]);
		this->content.slot[i].electricty_mana_spent =			reinterpret_cast<uint32_t *>(&this->data[0x04ca + offset]);
		this->content.slot[i].purple_fury_mana_spent =			reinterpret_cast<uint32_t *>(&this->data[0x04ce + offset]);
		this->content.slot[i].poison_mana_spent =				reinterpret_cast<uint32_t *>(&this->data[0x04d2 + offset]);
		this->content.slot[i].shadow_mana_spent =				reinterpret_cast<uint32_t *>(&this->data[0x04d6 + offset]);
		this->content.slot[i].fear_mana_spent =					reinterpret_cast<uint32_t *>(&this->data[0x04da + offset]);
		this->content.slot[i].wind_mana_spent =					reinterpret_cast<uint32_t *>(&this->data[0x04de + offset]);
		this->content.slot[i].dark_fury_mana_spent =				reinterpret_cast<uint32_t *>(&this->data[0x04e2 + offset]);
		this->content.slot[i].spyro_gameplay_time =				reinterpret_cast<float *>(&this->data[0x04e6 + offset]);
		this->content.slot[i].cynder_gameplay_time =				reinterpret_cast<float *>(&this->data[0x04ea + offset]);
		this->content.slot[i].total_gameplay_time =				reinterpret_cast<float *>(&this->data[0x04ee + offset]);
		this->content.slot[i].total_2_player_gameplayer_time =	reinterpret_cast<float *>(&this->data[0x04f2 + offset]);

		// xbox achievement data goes here

		this->content.slot[i].objective = reinterpret_cast<uint8_t *>(&this->data[0x04f6 + offset]);
		this->content.slot[i].counter = reinterpret_cast<uint8_t *>(&this->data[0x04f7 + offset]);
		
		this->content.slot[i].cynder_equiped_armor = reinterpret_cast<uint8_t *>(&this->data[0x0530 + offset]);
		this->content.slot[i].spyro_equiped_armor = reinterpret_cast<uint8_t *>(&this->data[0x0533 + offset]);
		this->content.slot[i].cynder_display_armor = reinterpret_cast<bool *>(&this->data[0x0536 + offset]);
		this->content.slot[i].cynder_display_armor = reinterpret_cast<bool *>(&this->data[0x0537 + offset]);

		this->content.slot[i].unknown_0x0574 = reinterpret_cast<uint8_t *>(&this->data[0x0538 + offset]);

		this->content.slot[i].chapter_unlock = reinterpret_cast<bool *>(&this->data[0x0539 + offset]);
		this->content.slot[i].gallery_unlock = reinterpret_cast<bool *>(&this->data[0x0545 + offset]);
		
		this->content.slot[i].unknown_0x0586 = reinterpret_cast<uint8_t *>(&this->data[0x054a + offset]);
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
