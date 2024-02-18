SECTION PAGE_80
org 0xe000

PUBLIC _reached

; Path finding map - 50 * 50 array of 3 bytes
; Must match size of dungeon map
._reached
ds 50*50*3

