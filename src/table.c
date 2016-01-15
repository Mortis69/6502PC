/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPL
 *
 * Copyright 2010-2015 by Michael Kohn, Joe Davisson
 *
 * 65xx by Joe Davisson
 *
 */

#include "table.h"

int table_mode[] =
{
  /* 0x00 */ OP_NONE,
  /* 0x01 */ OP_X_INDIRECT8,
  /* 0x02 */ OP_NONE,
  /* 0x03 */ OP_NONE,
  /* 0x04 */ OP_NONE,
  /* 0x05 */ OP_ADDRESS8,
  /* 0x06 */ OP_ADDRESS8,
  /* 0x07 */ OP_NONE,
  /* 0x08 */ OP_NONE,
  /* 0x09 */ OP_IMMEDIATE,
  /* 0x0A */ OP_NONE,
  /* 0x0B */ OP_NONE,
  /* 0x0C */ OP_NONE,
  /* 0x0D */ OP_ADDRESS16,
  /* 0x0E */ OP_ADDRESS16,
  /* 0x0F */ OP_NONE,

  /* 0x10 */ OP_RELATIVE,
  /* 0x11 */ OP_INDIRECT8_Y,
  /* 0x12 */ OP_NONE,
  /* 0x13 */ OP_NONE,
  /* 0x14 */ OP_NONE,
  /* 0x15 */ OP_INDEXED8_X,
  /* 0x16 */ OP_INDEXED8_X,
  /* 0x17 */ OP_NONE,
  /* 0x18 */ OP_NONE,
  /* 0x19 */ OP_INDEXED16_Y,
  /* 0x1A */ OP_NONE,
  /* 0x1B */ OP_NONE,
  /* 0x1C */ OP_NONE,
  /* 0x1D */ OP_INDEXED16_X,
  /* 0x1E */ OP_INDEXED16_X,
  /* 0x1F */ OP_NONE,

  /* 0x20 */ OP_ADDRESS16,
  /* 0x21 */ OP_X_INDIRECT8,
  /* 0x22 */ OP_NONE,
  /* 0x23 */ OP_NONE,
  /* 0x24 */ OP_ADDRESS8,
  /* 0x25 */ OP_ADDRESS8,
  /* 0x26 */ OP_ADDRESS8,
  /* 0x27 */ OP_NONE,
  /* 0x28 */ OP_NONE,
  /* 0x29 */ OP_IMMEDIATE,
  /* 0x2A */ OP_NONE,
  /* 0x2B */ OP_NONE,
  /* 0x2C */ OP_ADDRESS16,
  /* 0x2D */ OP_ADDRESS16,
  /* 0x2E */ OP_ADDRESS16,
  /* 0x2F */ OP_NONE,

  /* 0x30 */ OP_RELATIVE,
  /* 0x31 */ OP_INDIRECT8_Y,
  /* 0x32 */ OP_NONE,
  /* 0x33 */ OP_NONE,
  /* 0x34 */ OP_NONE,
  /* 0x35 */ OP_INDEXED8_X,
  /* 0x36 */ OP_INDEXED8_X,
  /* 0x37 */ OP_NONE,
  /* 0x38 */ OP_NONE,
  /* 0x39 */ OP_INDEXED16_Y,
  /* 0x3A */ OP_NONE,
  /* 0x3B */ OP_NONE,
  /* 0x3C */ OP_NONE,
  /* 0x3D */ OP_INDEXED16_X,
  /* 0x3E */ OP_INDEXED16_X,
  /* 0x3F */ OP_NONE,

  /* 0x40 */ OP_NONE,
  /* 0x41 */ OP_X_INDIRECT8,
  /* 0x42 */ OP_NONE,
  /* 0x43 */ OP_NONE,
  /* 0x44 */ OP_NONE,
  /* 0x45 */ OP_ADDRESS8,
  /* 0x46 */ OP_ADDRESS8,
  /* 0x47 */ OP_NONE,
  /* 0x48 */ OP_NONE,
  /* 0x49 */ OP_IMMEDIATE,
  /* 0x4A */ OP_NONE,
  /* 0x4B */ OP_NONE,
  /* 0x4C */ OP_ADDRESS16,
  /* 0x4D */ OP_ADDRESS16,
  /* 0x4E */ OP_ADDRESS16,
  /* 0x4F */ OP_NONE,

  /* 0x50 */ OP_RELATIVE,
  /* 0x51 */ OP_INDIRECT8_Y,
  /* 0x52 */ OP_NONE,
  /* 0x53 */ OP_NONE,
  /* 0x54 */ OP_NONE,
  /* 0x55 */ OP_INDEXED8_X,
  /* 0x56 */ OP_INDEXED8_X,
  /* 0x57 */ OP_NONE,
  /* 0x58 */ OP_NONE,
  /* 0x59 */ OP_INDEXED16_Y,
  /* 0x5A */ OP_NONE,
  /* 0x5B */ OP_NONE,
  /* 0x5C */ OP_NONE,
  /* 0x5D */ OP_INDEXED16_X,
  /* 0x5E */ OP_INDEXED16_X,
  /* 0x5F */ OP_NONE,

  /* 0x60 */ OP_NONE,
  /* 0x61 */ OP_X_INDIRECT8,
  /* 0x62 */ OP_NONE,
  /* 0x63 */ OP_NONE,
  /* 0x64 */ OP_NONE,
  /* 0x65 */ OP_ADDRESS8,
  /* 0x66 */ OP_ADDRESS8,
  /* 0x67 */ OP_NONE,
  /* 0x68 */ OP_NONE,
  /* 0x69 */ OP_IMMEDIATE,
  /* 0x6A */ OP_NONE,
  /* 0x6B */ OP_NONE,
  /* 0x6C */ OP_INDIRECT16,
  /* 0x6D */ OP_ADDRESS16,
  /* 0x6E */ OP_ADDRESS16,
  /* 0x6F */ OP_NONE,

  /* 0x70 */ OP_RELATIVE,
  /* 0x71 */ OP_INDIRECT8_Y,
  /* 0x72 */ OP_NONE,
  /* 0x73 */ OP_NONE,
  /* 0x74 */ OP_NONE,
  /* 0x75 */ OP_INDEXED8_X,
  /* 0x76 */ OP_INDEXED8_X,
  /* 0x77 */ OP_NONE,
  /* 0x78 */ OP_NONE,
  /* 0x79 */ OP_INDEXED16_Y,
  /* 0x7A */ OP_NONE,
  /* 0x7B */ OP_NONE,
  /* 0x7C */ OP_NONE,
  /* 0x7D */ OP_INDEXED16_X,
  /* 0x7E */ OP_INDEXED16_X,
  /* 0x7F */ OP_NONE,

  /* 0x80 */ OP_NONE,
  /* 0x81 */ OP_X_INDIRECT8,
  /* 0x82 */ OP_NONE,
  /* 0x83 */ OP_NONE,
  /* 0x84 */ OP_ADDRESS8,
  /* 0x85 */ OP_ADDRESS8,
  /* 0x86 */ OP_ADDRESS8,
  /* 0x87 */ OP_NONE,
  /* 0x88 */ OP_NONE,
  /* 0x89 */ OP_NONE,
  /* 0x8A */ OP_NONE,
  /* 0x8B */ OP_NONE,
  /* 0x8C */ OP_ADDRESS16,
  /* 0x8D */ OP_ADDRESS16,
  /* 0x8E */ OP_ADDRESS16,
  /* 0x8F */ OP_NONE,

  /* 0x90 */ OP_RELATIVE,
  /* 0x91 */ OP_INDIRECT8_Y,
  /* 0x92 */ OP_NONE,
  /* 0x93 */ OP_NONE,
  /* 0x94 */ OP_INDEXED8_X,
  /* 0x95 */ OP_INDEXED8_X,
  /* 0x96 */ OP_INDEXED8_Y,
  /* 0x97 */ OP_NONE,
  /* 0x98 */ OP_NONE,
  /* 0x99 */ OP_INDEXED16_Y,
  /* 0x9A */ OP_NONE,
  /* 0x9B */ OP_NONE,
  /* 0x9C */ OP_NONE,
  /* 0x9D */ OP_INDEXED16_X,
  /* 0x9E */ OP_NONE,
  /* 0x9F */ OP_NONE,

  /* 0xA0 */ OP_IMMEDIATE,
  /* 0xA1 */ OP_X_INDIRECT8,
  /* 0xA2 */ OP_IMMEDIATE,
  /* 0xA3 */ OP_NONE,
  /* 0xA4 */ OP_ADDRESS8,
  /* 0xA5 */ OP_ADDRESS8,
  /* 0xA6 */ OP_ADDRESS8,
  /* 0xA7 */ OP_NONE,
  /* 0xA8 */ OP_NONE,
  /* 0xA9 */ OP_IMMEDIATE,
  /* 0xAA */ OP_NONE,
  /* 0xAB */ OP_NONE,
  /* 0xAC */ OP_ADDRESS16,
  /* 0xAD */ OP_ADDRESS16,
  /* 0xAE */ OP_ADDRESS16,
  /* 0xAF */ OP_NONE,

  /* 0xB0 */ OP_RELATIVE,
  /* 0xB1 */ OP_INDIRECT8_Y,
  /* 0xB2 */ OP_NONE,
  /* 0xB3 */ OP_NONE,
  /* 0xB4 */ OP_INDEXED8_X,
  /* 0xB5 */ OP_INDEXED8_X,
  /* 0xB6 */ OP_INDEXED8_Y,
  /* 0xB7 */ OP_NONE,
  /* 0xB8 */ OP_NONE,
  /* 0xB9 */ OP_INDEXED16_Y,
  /* 0xBA */ OP_NONE,
  /* 0xBB */ OP_NONE,
  /* 0xBC */ OP_INDEXED16_X,
  /* 0xBD */ OP_INDEXED16_X,
  /* 0xBE */ OP_INDEXED16_Y,
  /* 0xBF */ OP_NONE,

  /* 0xC0 */ OP_IMMEDIATE,
  /* 0xC1 */ OP_X_INDIRECT8,
  /* 0xC2 */ OP_NONE,
  /* 0xC3 */ OP_NONE,
  /* 0xC4 */ OP_ADDRESS8,
  /* 0xC5 */ OP_ADDRESS8,
  /* 0xC6 */ OP_ADDRESS8,
  /* 0xC7 */ OP_NONE,
  /* 0xC8 */ OP_NONE,
  /* 0xC9 */ OP_IMMEDIATE,
  /* 0xCA */ OP_NONE,
  /* 0xCB */ OP_NONE,
  /* 0xCC */ OP_ADDRESS16,
  /* 0xCD */ OP_ADDRESS16,
  /* 0xCE */ OP_ADDRESS16,
  /* 0xCF */ OP_NONE,

  /* 0xD0 */ OP_RELATIVE,
  /* 0xD1 */ OP_INDIRECT8_Y,
  /* 0xD2 */ OP_NONE,
  /* 0xD3 */ OP_NONE,
  /* 0xD4 */ OP_NONE,
  /* 0xD5 */ OP_INDEXED8_X,
  /* 0xD6 */ OP_INDEXED8_X,
  /* 0xD7 */ OP_NONE,
  /* 0xD8 */ OP_NONE,
  /* 0xD9 */ OP_INDEXED16_Y,
  /* 0xDA */ OP_NONE,
  /* 0xDB */ OP_NONE,
  /* 0xDC */ OP_NONE,
  /* 0xDD */ OP_INDEXED16_X,
  /* 0xDE */ OP_INDEXED16_X,
  /* 0xDF */ OP_NONE,

  /* 0xE0 */ OP_IMMEDIATE,
  /* 0xE1 */ OP_X_INDIRECT8,
  /* 0xE2 */ OP_NONE,
  /* 0xE3 */ OP_NONE,
  /* 0xE4 */ OP_ADDRESS8,
  /* 0xE5 */ OP_ADDRESS8,
  /* 0xE6 */ OP_ADDRESS8,
  /* 0xE7 */ OP_NONE,
  /* 0xE8 */ OP_NONE,
  /* 0xE9 */ OP_IMMEDIATE,
  /* 0xEA */ OP_NONE,
  /* 0xEB */ OP_NONE,
  /* 0xEC */ OP_ADDRESS16,
  /* 0xED */ OP_ADDRESS16,
  /* 0xEE */ OP_ADDRESS16,
  /* 0xEF */ OP_NONE,

  /* 0xF0 */ OP_RELATIVE,
  /* 0xF1 */ OP_INDIRECT8_Y,
  /* 0xF2 */ OP_NONE,
  /* 0xF3 */ OP_NONE,
  /* 0xF4 */ OP_NONE,
  /* 0xF5 */ OP_INDEXED8_X,
  /* 0xF6 */ OP_INDEXED8_X,
  /* 0xF7 */ OP_NONE,
  /* 0xF8 */ OP_NONE,
  /* 0xF9 */ OP_INDEXED16_Y,
  /* 0xFA */ OP_NONE,
  /* 0xFB */ OP_NONE,
  /* 0xFC */ OP_NONE,
  /* 0xFD */ OP_INDEXED16_X,
  /* 0xFE */ OP_INDEXED16_X,
  /* 0xFF */ OP_NONE
};

