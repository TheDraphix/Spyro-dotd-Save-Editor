#include <string>
#include <fstream>
#include <iomanip>
#include <cstdint>

#include "save_data.hpp"
#include "byte_utils.hpp"

using namespace save_data;

void GameSave::ProcessMetadata()
{
	file <=>
		metadata.file_setting <=>
		metadata.game_structure_class_full_id <=> 
		metadata.unknown_0x0006 <=>
		metadata.unknown_0x0007 <=>
		metadata.first_slot_start_address;
}

void GameSave::ProcessSlot(Slot& s)
{
	file <=>
		s.player_class_full_id <=> 
		s.player_instance_id <=>
		s.unknown_0x000F <=>
		s.current_slot_start_offset <=>
		s.unknown_0x0014 <=>
		s.slot_status <=>
		s.total_game_time <=>
		s.game_state_object_status <=>
		s.game_state_uuid <=>
		s.next_slot_start_offset <=>
		s.spawn_point_object_status;
	if (s.spawn_point_object_status == 0xffffffff)
	{
		s.dummy = true;
	}
	else
	{
		file <=> s.spawn_point_uuid;
		s.dummy = false;
	}
	file <=>
		s.module_event_flag <=>
		s.module_completion_flag <=>
		s.game_level_flag;
	file <=>
		s.spyro_current_health <=>
		s.cynder_current_health <=>
		s.spyro_current_mana <=>
		s.cynder_current_mana <=>
		s.spyro_current_fury_points <=>
		s.cynder_current_fury_points <=>
		s.spyro_unspent_exp <=>
		s.cynder_unspent_exp <=>
		s.spyro_elem_exp <=>
		s.cynder_elem_exp;
	file <=> s.bonus_objective_flag;
	file <=>
		s.spyro_kills <=>
		s.cynder_kills <=>
		s.spyro_max_combo <=>
		s.cynder_max_combo <=>
		s.spyro_mana_spent <=>
		s.cynder_mana_spent <=>
		s.spyro_gameplay_time <=>
		s.cynder_gameplay_time <=>
		s.total_gameplay_time <=>
		s.total_2_player_gameplay_time;
	// xbox achivement data goes here.
	file <=>
		s.objective <=>
		s.counter <=>
		s.cynder_equiped_armor <=>
		s.spyro_equiped_armor <=>
		s.cynder_display_armor <=>
		s.spyro_display_armor;
	file <=> s.unknown_0x0538;
	file <=>
		s.chapter_unlock <=>
		s.gallery_unlock;
	file <=> s.unknown_0x054a;
}

void GameSave::ProcessOptions()
{
	if (version==WII || version==PS2 || version==PS3)
	{
		//if (version==PS3)
		//  change the stream of "file"
		// else
		file.seekg(0x4011, std::ios::beg);
		
		file <=>
			options.auto_read <=>
			options.file_setting <=>
			options.game_structure_class_full_id <=>
			options.game_structure_class_instance_id <=>
			options.unknown_0x007 <=>
			options.start_of_next_slot_data <=>
			options.current_language_fake <=>
			options.current_language <=>
			options.subtitles <=>
			options.tutorials <=>
			options.unknown_0x016 <=>
			options.unknown_0x017 <=>
			options.audio_mode <=>
			options.unknown_0x01c <=>
			options.sound_fx_volume <=>
			options.voices_volume <=>
			options.music_volume <=>
			options.player_1_vibrations <=>
			options.player_2_vibrations <=>
			options.player_1_invert_verticle_axis <=>
			options.player_2_invert_verticle_axis <=>
			options.player_1_invert_horizontal_axis <=>
			options.player_2_invert_horizontal_axis <=>
			options.unknown_0x032 <=>
			options.widescreen <=>
			options.player_1_sixaxis <=>
			options.player_2_sixaxis <=>
			options.unknown_0x03f;
			if (version==PS3)
				file <=> options.gamma;
			file <=>
			options.unknown_0x044 <=>
			options.unknown_0x046 <=>
			options.unknown_0x047 <=>
			options.unknown_0x048; // 31
	}
}

void GameSave::SwapPS2Endianness()
{
	for (int i=0; i<5; i++)
	{
		ByteSwap(slot[i].game_state_uuid, 4);
		ByteSwap(slot[i].spawn_point_uuid, 4);
	}
}


GameSave::GameSave(const std::string file_name)
{
	file.open(file_name, std::ios::in);
	if (file.fail())
		std::cout << "Failed to read file" << std::endl;
	file.mode = ByteStream::READ;
	int slots = 1;
	
	version = PS2; // temp

	if (version==PS2 || version==WII)
	{
		slots = 5;
		file <=> header.unknown_0x0000 <=> header.file_status;
	}
	ProcessMetadata();
	for (int i=0; i<slots; i++)
		ProcessSlot(slot[i]);
	ProcessOptions();	
	
	if (version==PS2)
		SwapPS2Endianness();
		
	file.close();
}

void GameSave::Write(const std::string file_name)
{
	if (version==PS2)
		SwapPS2Endianness();

	file.open(file_name, std::ios::out);
	if (file.fail())
		std::cout << "Failed to write file" << std::endl;
	file.mode = ByteStream::WRITE;
	int slots;
	
	if (version==PS2 || version==WII)
	{
		slots = 5;
		file <=> header.unknown_0x0000 <=> header.file_status;
	}
	ProcessMetadata();
	for (int i=0; i<slots; i++)
		ProcessSlot(slot[i]);
	ProcessOptions();	

	if (version==PS2)
	{
		uint8_t padding[0x3bd] = {0};
		file <=> padding;
	}
	
	file.close();
}
