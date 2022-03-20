SECTION PAGE_16 
org 0x0000


PUBLIC _dungeon_map

; Dungeon map 40 by 40 tiles * 3 bytes per tile (4,800 bytes)
._dungeon_map
ds 40*40*3