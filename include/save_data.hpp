#ifndef SAVE_DATA_STRUCTURE_H
#define SAVE_DATA_STRUCTURE_H

#include <cstdint>
#include <cstdbool>
#include <string>

#include "byte_utils.hpp"
// unknown save entries are named "unknown_{ps3 memory address}" unless stated otherwise

namespace save_data 
{
	enum Version {WII, PS2, XBOX, PS3};
	
	typedef struct {
		uint8_t unknown_0x0000[16]; //wii/ps2 memory address
		bool file_status;
	} Header;
	
	typedef struct {
		uint32_t file_setting;
		uint16_t game_structure_class_full_id;
		uint8_t unknown_0x0006;
		uint8_t unknown_0x0007;
		uint32_t first_slot_start_address;
	} Metadata;
	
	typedef struct {
		uint16_t player_class_full_id;
		uint8_t player_instance_id;
		uint8_t unknown_0x000F;
		uint32_t current_slot_start_offset;
		uint8_t unknown_0x0014[4];
		bool slot_status;
		float total_game_time; 
		uint32_t game_state_object_status;
		uint32_t game_state_uuid[4];
		uint32_t next_slot_start_offset;
		uint32_t spawn_point_object_status;
		uint32_t spawn_point_uuid[4];	
		bool dummy;	// Not a real save entry

		bool module_event_flag[438];
		bool module_completion_flag[438]; 
		bool game_level_flag[12];

		uint32_t spyro_current_health;
		uint32_t cynder_current_health;
		uint32_t spyro_current_mana;
		uint32_t cynder_current_mana;
		int32_t spyro_current_fury_points;
		int32_t cynder_current_fury_points;
		int32_t spyro_unspent_exp;
		int32_t cynder_unspent_exp;
		int32_t spyro_elem_exp[5];
		int32_t cynder_elem_exp[5];

		bool bonus_objective_flag[165];

		int32_t spyro_kills;
		int32_t cynder_kills;
		int32_t spyro_max_combo;
		int32_t cynder_max_combo;
		uint32_t spyro_mana_spent[5];
		uint32_t cynder_mana_spent[5];
		float spyro_gameplay_time;
		float cynder_gameplay_time;
		float total_gameplay_time;
		float total_2_player_gameplay_time;
		
		uint8_t objective[52];
		uint8_t counter[6];
		uint8_t cynder_equiped_armor[3];
		uint8_t spyro_equiped_armor[3];
		bool cynder_display_armor;
		bool spyro_display_armor;

		uint8_t unknown_0x0538;

		bool chapter_unlock[12];
		bool gallery_unlock[5];

		uint8_t unknown_0x054a;
	} Slot;
	
	typedef struct {
		bool auto_read;
		uint32_t file_setting;
		uint16_t game_structure_class_full_id;
		uint16_t game_structure_class_instance_id;
		uint8_t unknown_0x007;
		uint32_t start_of_next_slot_data;
		uint32_t current_language_fake;
		uint32_t current_language;
		bool subtitles;
		bool tutorials;
		uint8_t unknown_0x016;
		uint8_t unknown_0x017;
		uint32_t audio_mode;
		uint8_t unknown_0x01c[3]; // should be an offset of 4? but this works.
		float sound_fx_volume;
		float voices_volume;
		float music_volume;
		bool player_1_vibrations;
		bool player_2_vibrations;
		bool player_1_invert_verticle_axis;
		bool player_2_invert_verticle_axis;
		bool player_1_invert_horizontal_axis;
		bool player_2_invert_horizontal_axis;
		uint8_t unknown_0x032[10];
		bool widescreen;
		bool player_1_sixaxis;
		bool player_2_sixaxis;
		uint8_t unknown_0x03f;
		uint32_t gamma;
		uint8_t unknown_0x044[2];
		uint8_t unknown_0x046;
		uint8_t unknown_0x047;
		uint8_t unknown_0x048[4];
	} Options;

	typedef struct {
		Header header;
		Metadata metadata;
		Slot slot[5];
		Options options;
	} Content;
	
	class GameSave {
		public:
			//Content content;
			Header header;
			Metadata metadata;
			Slot slot[5];
			Options options;

			void Read(const std::string file_name);
			void Write(const std::string file_name);			
			Version GetVersion() { return version; };

		private:
			Version version;
			ByteStream file;

			void ProcessMetadata();
			void ProcessSlot(Slot& s);
			void ProcessOptions();
			
			void SwapPS2Endianness();
	};
			
}

#endif
