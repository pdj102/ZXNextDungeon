
;SECTION rodata_user

SECTION BANK_5 
org 0x6A00

PUBLIC _tile_pattern

; tile patterns
; exported from https://zx.remysharp.com/sprites/#export
; how 
; select sprites
; select 8x8
; bytes per line 4
; NB a tile defintion is 4 bytes * 8 bytes (each byte = 2 pixels)
; NB each sprite is 4 tile definitions
._tile_pattern

sprite_count EQU 41
sprite0:
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite1:
	db 0x54, 0x44, 0x31, 0x55
	db 0x43, 0x33, 0x31, 0x54
	db 0x33, 0x33, 0x31, 0x43
	db 0x11, 0x11, 0x11, 0x11
	db 0x43, 0x15, 0x55, 0x44
	db 0x33, 0x15, 0x44, 0x33
	db 0x33, 0x14, 0x33, 0x33
	db 0x11, 0x11, 0x11, 0x11
	db 0x14, 0x44, 0x31, 0x55
	db 0x13, 0x33, 0x31, 0x54
	db 0x13, 0x33, 0x31, 0x43
	db 0x11, 0x11, 0x11, 0x11
	db 0x13, 0x15, 0x55, 0x44
	db 0x13, 0x15, 0x44, 0x33
	db 0x13, 0x14, 0x33, 0x33
	db 0x11, 0x11, 0x11, 0x11
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite2:
	db 0x44, 0x54, 0x44, 0x44
	db 0x44, 0x44, 0x44, 0x54
	db 0x55, 0x55, 0x44, 0x44
	db 0x44, 0x44, 0x44, 0x44
	db 0x44, 0x44, 0x44, 0x54
	db 0x54, 0x44, 0x44, 0x44
	db 0x44, 0x44, 0x55, 0x55
	db 0x44, 0x44, 0x44, 0x54
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite3:
	db 0x11, 0x11, 0x11, 0x11
	db 0x13, 0x33, 0x33, 0x33
	db 0x13, 0x44, 0x44, 0x44
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x33, 0x33, 0x33, 0x33
	db 0x44, 0x44, 0x44, 0x44
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x44, 0x44, 0x44
	db 0x13, 0x33, 0x33, 0x33
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x44, 0x44, 0x44, 0x44
	db 0x33, 0x33, 0x33, 0x33
	db 0x11, 0x11, 0x11, 0x11

sprite4:
	db 0x11, 0x11, 0x11, 0x11
	db 0x33, 0x33, 0x33, 0x31
	db 0x44, 0x44, 0x44, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x44, 0x44, 0x44, 0x31
	db 0x33, 0x33, 0x33, 0x31
	db 0x11, 0x11, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11

sprite5:
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x44
	db 0x11, 0x11, 0x14, 0x43
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x44, 0x44, 0x44, 0x44
	db 0x33, 0x33, 0x33, 0x33
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x31
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite6:
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x44, 0x11, 0x11, 0x11
	db 0x34, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x11, 0x11, 0x14, 0x31
	db 0x11, 0x11, 0x14, 0x43
	db 0x11, 0x11, 0x11, 0x44
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x13, 0x41, 0x11, 0x11
	db 0x34, 0x41, 0x11, 0x11
	db 0x44, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11
	db 0x11, 0x11, 0x11, 0x11

sprite7:
	db 0xff, 0xf0, 0x0, 0xf
	db 0xff, 0x0, 0x55, 0x54
	db 0xff, 0x5, 0x5, 0x4
	db 0xf3, 0x5, 0x56, 0x63
	db 0x33, 0x32, 0x66, 0xf7
	db 0x36, 0x2, 0x20, 0x23
	db 0x0, 0x21, 0x1, 0xff
	db 0xf1, 0x30, 0x13, 0x1f
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite8:
	db 0xff, 0x3, 0x30, 0x3f
	db 0xf0, 0x30, 0x1, 0x3f
	db 0xf3, 0x5, 0x5, 0x3f
	db 0x3, 0x0, 0x0, 0x3f
	db 0xf0, 0x10, 0x1, 0x3f
	db 0xf0, 0x1, 0x10, 0xf
	db 0xf0, 0x10, 0xf, 0x3f
	db 0x1, 0x0, 0x0, 0x3f
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite9:
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xf5, 0x55, 0x5f
	db 0xff, 0xff, 0x55, 0xff
	db 0xff, 0xf5, 0x77, 0x5f
	db 0xff, 0x57, 0x66, 0x65
	db 0xff, 0x56, 0x66, 0x65
	db 0xff, 0xf5, 0x55, 0x5f
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xf6, 0x76, 0xff
	db 0xff, 0x75, 0x65, 0x7f
	db 0xff, 0xf4, 0x54, 0xff
	db 0xff, 0x4f, 0xff, 0x4f
	db 0xff, 0x3f, 0xff, 0x3f
	db 0xff, 0x3f, 0xff, 0x3f
	db 0xff, 0xf2, 0x22, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff

sprite10:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite11:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite12:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite13:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite14:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite15:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite16:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite17:
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x6, 0x0, 0x0
	db 0x0, 0x6, 0x0, 0x0
	db 0x0, 0x6, 0x0, 0x0
	db 0x0, 0x6, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x6, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x60, 0x6, 0x0
	db 0x0, 0x60, 0x6, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x60, 0x6, 0x0
	db 0x6, 0x66, 0x66, 0x60
	db 0x0, 0x60, 0x6, 0x0
	db 0x0, 0x60, 0x6, 0x0
	db 0x6, 0x66, 0x66, 0x60
	db 0x0, 0x60, 0x6, 0x0
	db 0x0, 0x0, 0x0, 0x0

sprite18:
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x66, 0x66, 0x60
	db 0x0, 0x60, 0x60, 0x0
	db 0x0, 0x66, 0x66, 0x60
	db 0x0, 0x0, 0x60, 0x60
	db 0x0, 0x66, 0x66, 0x60
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x6, 0x60, 0x0, 0x60
	db 0x6, 0x60, 0x6, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x6, 0x0, 0x0
	db 0x0, 0x60, 0x6, 0x60
	db 0x6, 0x0, 0x6, 0x60
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x6, 0x0, 0x0
	db 0x0, 0x60, 0x60, 0x0
	db 0x0, 0x6, 0x0, 0x0
	db 0x0, 0x60, 0x60, 0x60
	db 0x6, 0x0, 0x6, 0x0
	db 0x0, 0x66, 0x60, 0x60
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x6, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0

sprite19:
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x6, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x0, 0x6, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x6, 0x0, 0x0, 0x0
	db 0x0, 0x60, 0x0, 0x0
	db 0x0, 0x60, 0x0, 0x0
	db 0x0, 0x60, 0x0, 0x0
	db 0x0, 0x60, 0x0, 0x0
	db 0x6, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x6, 0x6, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x66, 0x66, 0x60
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x6, 0x6, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x66, 0x66, 0x60
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x0, 0x0, 0x0

sprite20:
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x6, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x66, 0x66, 0x60
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x66, 0x0
	db 0x0, 0x0, 0x66, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x60
	db 0x0, 0x0, 0x6, 0x0
	db 0x0, 0x0, 0x60, 0x0
	db 0x0, 0x6, 0x0, 0x0
	db 0x0, 0x60, 0x0, 0x0
	db 0x0, 0x0, 0x0, 0x0

sprite21:
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xe6, 0x6e
	db 0xe6, 0xee, 0x6e, 0x6e
	db 0xe6, 0xe6, 0xee, 0x6e
	db 0xe6, 0x6e, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xe6, 0x6e, 0xee
	db 0xee, 0x6e, 0x6e, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0x66, 0x66, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0xee, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee

sprite22:
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xe6, 0x6e, 0xee
	db 0xee, 0x6e, 0x6e, 0xee
	db 0xe6, 0xee, 0x6e, 0xee
	db 0xe6, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0x6e
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0x6e
	db 0xee, 0xee, 0xee, 0x6e
	db 0xee, 0xee, 0xe6, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee

sprite23:
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0x6e
	db 0xee, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0x6e, 0xee, 0xee

sprite24:
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xe6, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xee, 0xe6, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xee, 0xe6, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0xee, 0xe6, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xee, 0xee, 0xee

sprite25:
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0x6e, 0x6e
	db 0xe6, 0xe6, 0xee, 0x6e
	db 0xe6, 0xe6, 0x66, 0x6e
	db 0xe6, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0x66, 0x66, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee

sprite26:
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x6e, 0xee
	db 0xe6, 0xee, 0xe6, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xe6, 0xee
	db 0xe6, 0x66, 0x6e, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0x6e
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0x6e
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0x66, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee

sprite27:
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0x66, 0x66, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0x6e
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0x66, 0x66, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0x6e
	db 0xee, 0xee, 0xee, 0x6e
	db 0xee, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xe6, 0xee
	db 0xe6, 0xee, 0x6e, 0xee
	db 0xe6, 0x66, 0xee, 0xee
	db 0xe6, 0xee, 0x6e, 0xee
	db 0xe6, 0xee, 0xe6, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0xee, 0xee, 0xee

sprite28:
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0x6e, 0xe6, 0x6e
	db 0xe6, 0xe6, 0x6e, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0x6e, 0xee, 0x6e
	db 0xe6, 0xe6, 0xee, 0x6e
	db 0xe6, 0xee, 0x6e, 0x6e
	db 0xe6, 0xee, 0xe6, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee

sprite29:
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xe6, 0xee, 0x6e
	db 0xe6, 0xee, 0x6e, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xe6, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xe6, 0xee, 0xee, 0xee
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee

sprite30:
	db 0xee, 0xee, 0xee, 0xee
	db 0x66, 0x66, 0x66, 0x6e
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x66, 0x66, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x6e, 0xe6, 0xee
	db 0xee, 0xe6, 0x6e, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xe6, 0xe6, 0x6e, 0x6e
	db 0xee, 0x6e, 0xe6, 0xee
	db 0xee, 0xee, 0xee, 0xee

sprite31:
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0x6e, 0xe6, 0xee
	db 0xee, 0xe6, 0x6e, 0xee
	db 0xee, 0xe6, 0x6e, 0xee
	db 0xee, 0x6e, 0xe6, 0xee
	db 0xe6, 0xee, 0xee, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0x6e, 0xee, 0xee, 0x6e
	db 0xe6, 0xee, 0xe6, 0xee
	db 0xee, 0x6e, 0x6e, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xee, 0xee, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0x6e
	db 0xee, 0xee, 0xe6, 0xee
	db 0xee, 0xee, 0x6e, 0xee
	db 0xee, 0xe6, 0xee, 0xee
	db 0xee, 0x6e, 0xee, 0xee
	db 0xe6, 0x66, 0x66, 0x6e
	db 0xee, 0xee, 0xee, 0xee
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite32:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite33:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite34:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite35:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite36:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite37:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite38:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite39:
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0xff, 0xff, 0xff, 0xff
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33

sprite40:
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
	db 0x33, 0x33, 0x33, 0x33
