SECTION PAGE_19 
org 0xC000


PUBLIC _frontier_head
PUBLIC _frontier_tail

PUBLIC _frontier_count
PUBLIC _reached

PUBLIC _frontier

PUBLIC _x_offset

PUBLIC _y_offset

PUBLIC _neighbor


; Frontier 100 elements * 2 bytes 
._frontier
ds 100*2

; Reached 40 * 40 array of 2 byte
._reached
ds 40*40*2

._frontier_head 
ds 1

._frontier_tail
ds 1

._frontier_count
ds 1

._x_offset
ds 1

._y_offset
ds 1

._neighbor
ds 1
