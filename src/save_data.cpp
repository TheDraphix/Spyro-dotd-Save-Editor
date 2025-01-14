#include <string>
#include <fstream>

#include "save_data.hpp"
#include "byte_utils.hpp"

using namespace save_data;

GameSave::GameSave(const std::string file_name)
{
	version = PS2; // temp

	ByteStream file;
	file.stream.open(file_name, std::ios::in);
	
	int slots;
	
	if (version==PS2 || version==WII)
	{
		file >> content.header.unknown_0x0000 >> content.header.file_status;
		slots = 5;
	}
	
	file >> 
		content.metadata.file_setting >> 
		content.metadata.game_structure_class_full_id >> 
		content.metadata.unknown_0x0006 >> 
		content.metadata.unknown_0x0007 >> 
		content.metadata.first_slot_start_address;
	
	for (int i=0; i<slots; i++)
	{
		file >> 
			content.slot[i].player_class_full_id >> 
			content.slot[i].player_instance_id >> 
			content.slot[i].unknown_0x000F >>
			content.slot[i].current_slot_start_offset >>
			content.slot[i].unknown_0x0014 >>
			content.slot[i].slot_status >>
			content.slot[i].total_game_time >>
			content.slot[i].game_state_object_status >>
			content.slot[i].game_state_uuid >>
			content.slot[i].next_slot_start_offset >>
			content.slot[i].spawn_point_object_status;
		if (content.slot[i].spawn_point_object_status == 0xffffffff)
		{
			content.slot[i].dummy = true;
		}
		else
		{
			file >> content.slot[i].spawn_point_uuid;
			content.slot[i].dummy = false;
		}
		file >> 
			content.slot[i].module_event_flag >>
			content.slot[i].module_completion_flag >> 
			content.slot[i].game_level_flag;
		file >>
			content.slot[i].spyro_current_health >>
			content.slot[i].cynder_current_health >>
			content.slot[i].spyro_current_mana >>
			content.slot[i].cynder_current_mana >>
			content.slot[i].spyro_current_fury_points >>
			content.slot[i].cynder_current_fury_points >>
			content.slot[i].spyro_unspent_exp >>
			content.slot[i].cynder_unspent_exp >>
			content.slot[i].spyro_elem_exp >>
			content.slot[i].cynder_elem_exp;
		file >> content.slot[i].bonus_objective_flag;
		file >>
			content.slot[i].spyro_kills >>
			content.slot[i].cynder_kills >>
			content.slot[i].spyro_max_combo >>
			content.slot[i].cynder_max_combo >>
			content.slot[i].spyro_mana_spent >>
			content.slot[i].cynder_mana_spent >>
			content.slot[i].spyro_gameplay_time >>
			content.slot[i].cynder_gameplay_time >>
			content.slot[i].total_gameplay_time >>
			content.slot[i].total_2_player_gameplay_time;
		file >>
			content.slot[i].objective >>
			content.slot[i].counter >>
			content.slot[i].cynder_equiped_armor >>
			content.slot[i].spyro_equiped_armor >>
			content.slot[i].cynder_display_armor >>
			content.slot[i].spyro_display_armor;
		file >> content.slot[i].unknown_0x0538;
		file >>
			content.slot[i].chapter_unlock >>
			content.slot[i].gallery_unlock;
		file >> content.slot[i].unknown_0x054a;
	}	
}

void GameSave::Write(const std::string file_name)
{
	ByteStream file;
	file.stream.open(file_name, std::ios::out);

	int slots = 0;

	if (version==PS2 || version==WII)
	{
		file << content.header.unknown_0x0000 << content.header.file_status;
		slots = 5;
	}
	
	file <<
		content.metadata.file_setting <<
		content.metadata.game_structure_class_full_id << 
		content.metadata.unknown_0x0006 << 
		content.metadata.unknown_0x0007 << 
		content.metadata.first_slot_start_address;
	
	for (int i=0; i<slots; i++)
	{
		file <<
			content.slot[i].player_class_full_id << 
			content.slot[i].player_instance_id << 
			content.slot[i].unknown_0x000F <<
			content.slot[i].current_slot_start_offset <<
			content.slot[i].unknown_0x0014 <<
			content.slot[i].slot_status <<
			content.slot[i].total_game_time <<
			content.slot[i].game_state_object_status <<
			content.slot[i].game_state_uuid <<
			content.slot[i].next_slot_start_offset <<
			content.slot[i].spawn_point_object_status;
		if (content.slot[i].spawn_point_object_status != 0xffffffff)
			file << content.slot[i].spawn_point_uuid;
		file << 
			content.slot[i].module_event_flag <<
			content.slot[i].module_completion_flag << 
			content.slot[i].game_level_flag;
		file <<
			content.slot[i].spyro_current_health <<
			content.slot[i].cynder_current_health <<
			content.slot[i].spyro_current_mana <<
			content.slot[i].cynder_current_mana <<
			content.slot[i].spyro_current_fury_points <<
			content.slot[i].cynder_current_fury_points <<
			content.slot[i].spyro_unspent_exp <<
			content.slot[i].cynder_unspent_exp <<
			content.slot[i].spyro_elem_exp <<
			content.slot[i].cynder_elem_exp;
		file << content.slot[i].bonus_objective_flag;
		file <<
			content.slot[i].spyro_kills <<
			content.slot[i].cynder_kills <<
			content.slot[i].spyro_max_combo <<
			content.slot[i].cynder_max_combo <<
			content.slot[i].spyro_mana_spent <<
			content.slot[i].cynder_mana_spent <<
			content.slot[i].spyro_gameplay_time <<
			content.slot[i].cynder_gameplay_time <<
			content.slot[i].total_gameplay_time <<
			content.slot[i].total_2_player_gameplay_time;
		file <<
			content.slot[i].objective <<
			content.slot[i].counter <<
			content.slot[i].cynder_equiped_armor <<
			content.slot[i].spyro_equiped_armor <<
			content.slot[i].cynder_display_armor <<
			content.slot[i].spyro_display_armor;
		file << content.slot[i].unknown_0x0538;
		file <<
			content.slot[i].chapter_unlock <<
			content.slot[i].gallery_unlock;
		file << content.slot[i].unknown_0x054a;
	}
}
