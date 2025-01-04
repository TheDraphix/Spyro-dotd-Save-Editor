#ifndef SAVE_DATA_STRUCTURE_H
#define SAVE_DATA_STRUCTURE_H

#include <stdint.h>
#include <stdbool.h>

// TODO: Complete the save_slotdata struct. create a uuid struct in the future?
//
// unknown entries are given the name "unknown_{xbox memory address}" (This might be unreliable in the future).

typedef struct {
    uint8_t unknown_0x0000[0x10];
    bool file_status;
} save_wii_ps2_header;

typedef struct {
    uint32_t file_setting;
    uint16_t game_structure_class_full_id;
    uint8_t unknown_0x0006;
    uint8_t unknown_0x0007;
    uint32_t first_slot_start_address;
} save_metadata;

typedef struct {
    uint16_t player_class_full_id[0x2];
    uint8_t player_instance_id;
    uint8_t unknown_0x000F;
    uint8_t current_slot_start_offset[0x4];
    uint8_t unknown_0x0014[0x4];
    bool slot_status;
    float total_game_time; // the size of a float is not standardised however it is usually 4 bytes (should be fine)
    uint32_t game_state_object_status;
    uint32_t game_state_uuid[4];
    uint32_t next_slot_start_offset;
    uint32_t spawn_point_object_status;
    uint32_t spawn_point_uuid;

    // add flags. entries should be placed in the order they are in memory.    
} save_slotdata;


// W.I.P example
typedef struct {
    save_wii_ps2_header header;
    save_metadata metadata;
    save_slotdata slotdata[5];
} ps2_save;

#endif
