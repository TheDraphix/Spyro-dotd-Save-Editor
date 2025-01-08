#ifndef SAVE_DATA_STRUCTURE_H
#define SAVE_DATA_STRUCTURE_H

#include <stdint.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>


// unknown save entries are named "unknown_{xbox360 memory address}" unless stated otherwise

namespace save_data 
{
	enum Version {WII, PS2, XBOX, PS3};
	
	typedef struct {
		uint8_t *unknown_0x0000[0x10]; // wii/ps2 memory address
		bool *file_status;
	} Header;
	
	typedef struct {
		uint32_t *file_setting;
		uint16_t *game_structure_class_full_id;
		uint8_t *unknown_0x0006;
		uint8_t *unknown_0x0007;
		uint32_t *first_slot_start_address;
	} Metadata;
	
	typedef struct {
		uint16_t *player_class_full_id;
		uint8_t *player_instance_id;
		uint8_t *unknown_0x000F;
		uint32_t *current_slot_start_offset;
		uint8_t *unknown_0x0014[4];
		bool *slot_status;
		float *total_game_time; 
		uint32_t *game_state_object_status;
		uint32_t *game_state_uuid[4];
		uint32_t *next_slot_start_offset;
		uint32_t *spawn_point_object_status;
		uint32_t *spawn_point_uuid[4];
		
		bool *module_event_flag[438];
		bool *module_completion_flag[438];
		bool *game_level_flag[12];

		uint32_t *spyro_current_health;
		uint32_t *cynder_current_health;
		uint32_t *spyro_current_mana;
		uint32_t *cynder_current_mana;
		int32_t *spyro_current_fury_points;
		int32_t *cynder_current_fury_points;
		int32_t *spyro_unspent_exp;
		int32_t *cynder_unspent_exp;
		int32_t *fire_exp;
		int32_t *ice_exp;
		int32_t *earth_exp;
		int32_t *electricity_exp;
		int32_t *purple_fury_exp;
		int32_t *poison_exp;
		int32_t *shadow_exp;
		int32_t *fear_exp;
		int32_t *wind_exp;
		int32_t *dark_fury_exp;

		bool *bonus_objective_flag[165];

		int32_t *spyro_kills;
		int32_t *cynder_kills;
		int32_t *spyro_max_combo;
		int32_t *cynder_max_combo;
		uint32_t *fire_mana_spent;
		uint32_t *ice_mana_spent;
		uint32_t *earth_mana_spent;
		uint32_t *electricty_mana_spent;
		uint32_t *purple_fury_mana_spent;
		uint32_t *poison_mana_spent;
		uint32_t *shadow_mana_spent;
		uint32_t *fear_mana_spent;
		uint32_t *wind_mana_spent;
		uint32_t *dark_fury_mana_spent;
		float *spyro_gameplay_time;
		float *cynder_gameplay_time;
		float *total_gameplay_time;
		float *total_2_player_gameplayer_time;
		
		uint8_t *objective[52];
		uint8_t *counter[6];

		uint8_t *cynder_equiped_armor[3];
		uint8_t *spyro_equiped_armor[3];
		bool *cynder_display_armor;
		bool *spyro_display_armor;

		uint8_t *unknown_0x0574;

		bool *chapter_unlock[12]; // note an unused entry is included (probably an unused chapter)
		bool *gallery_unlock[5];

		uint8_t *unknown_0x0586;
	} Slot;
	
	typedef struct { // ps3 addresses are used for unknown addresses
		bool *auto_read;
		uint32_t *file_setting;
		uint16_t *game_structure_class_full_id;
		uint16_t *game_structure_class_instance_id;
		uint8_t *unknown_0x007;
		uint32_t *start_of_next_slot_data;
		uint32_t *current_language_fake;
		uint32_t *current_language;
		bool *subtitles;
		bool *tutorials;
		uint8_t *unknown_0x016;
		uint8_t *unknown_0x017;
		uint32_t *audio_mode;
		uint8_t *unknown_0x01c[4];
		float *sound_effects_volume;
		float *voices_volume;
		float *music_volume;
		bool *player_1_vibrations;
		bool *player_2_vibrations;
		bool *player_1_invert_verticle_axis;
		bool *player_2_invert_verticle_axis;
		bool *player_1_invert_horizontal_axis;
		bool *player_2_invert_horizontal_axis;
		uint8_t *unknown_0x032[10];
		bool *widescreen;
		bool *player_1_sixaxis;
		uint8_t *unknown_0x03f;
		uint8_t *unknown_0x044[2];
		uint8_t *unknown_0x046;
		uint8_t *unknown_0x047;
		uint8_t *unknown_0x048[4];
	} Options;

	typedef struct {
		Header header;
		Metadata metadata;
		Slot slot[5];
		Options options;
	} Save;
	
	class GameSave {
		public:
			Version version;
			Save save;
			
			GameSave(const char *file_name);
			int GetSize() { return this->size; };
		
		private:
			int size;
			char *data;
			
			void MapSaveData();	// map the save file to data adressess
			void DetermineVersion();
	};
}

#endif
