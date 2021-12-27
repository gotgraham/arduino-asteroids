#include "ship_explosion_objects.h"

const uint8_t ship_explosion_vert_count[] = {
  9, 9, 9, 7, 3
};

const uint16_t ship_explosion_objects[] PROGMEM = {

// 1
0x0005, 0x0003,
0x0005, 0x0003,
0x8007, 0x0005,
0x0009, 0x0005,
0x800A, 0x0004,
0x000A, 0x0001,
0x8009, 0x0000,
0x0007, 0x0000,
0x8006, 0x0000,

// 2
0x0005, 0x0004,
0x8005, 0x0004,
0x8007, 0x0006,
0x000A, 0x0006,
0x800B, 0x0005,
0x000B, 0x0001,
0x800A, 0x0000,
0x0006, 0x0000,
0x8005, 0x0000,

// 3
0x0004, 0x0006,
0x8004, 0x0006,
0x8006, 0x0008,
0x000B, 0x0007,
0x800C, 0x0006,
0x000C, 0x0001,
0x800B, 0x0000,
0x0006, 0x0000,
0x8005, 0x0000,

// 4
0x0004, 0x0008,
0x8004, 0x0008,
0x8006, 0x000A,
0x000B, 0x0009,
0x800C, 0x0008,
0x000D, 0x0001,
0x800C, 0x0000,
0x0005, 0x0000,
0x8004, 0x0000,

// 5
0x0003, 0x000A,
0x8003, 0x000A,
0x0005, 0x000C,
0x000D, 0x000A,
0x800E, 0x0009,
0x0005, 0x0000,
0x8004, 0x0000,
0x0000, 0x0000,
0x0000, 0x0000,


// 6
0x0003, 0x000B,
0x8003, 0x000B,
0xB005, 0x000D,
0x0000, 0x0000,
0x0000, 0x0000,
0x0000, 0x0000,
0x0000, 0x0000,
0x0000, 0x0000,
0x0000, 0x0000,
};