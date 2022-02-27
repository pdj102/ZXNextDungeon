SECTION PAGE_19 
org 0xC000


PUBLIC _frontier
PUBLIC _reached

PUBLIC _frontier_pos

PUBLIC _x_offset

PUBLIC _y_offset

PUBLIC _neighbor


; Frontier 100 elements * 2 bytes 
._frontier
ds 100*2

; Reached 10 * 10 array of 1 byte
._reached
ds 10*10*1

._frontier_pos
ds 1

._x_offset
ds 1

._y_offset
ds 1

._neighbor
ds 1
