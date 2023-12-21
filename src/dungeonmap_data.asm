SECTION PAGE_16 
org 0x0000


PUBLIC _dungeonmap

; Dungeon map 40 by 40 tiles * 3 bytes per tile (4,800 bytes)
; TO DO - set the correct size. The whole page is used only for the dungeonmap data structure so no other data goes in here
._dungeonmap

ds 40*40*4