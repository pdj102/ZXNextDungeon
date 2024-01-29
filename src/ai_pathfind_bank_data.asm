SECTION PAGE_26 
org 0xc000

PUBLIC _frontier_head
PUBLIC _frontier_tail

PUBLIC _frontier_count
PUBLIC _reached

PUBLIC _frontier

PUBLIC _x_offset

PUBLIC _y_offset

PUBLIC _neighbor

PUBLIC _max_x
PUBLIC _min_x
PUBLIC _max_y
PUBLIC _min_y


; Frontier 100 elements * 2 bytes 
._frontier
ds 100*2

; Reached 40 * 40 array of 2 byte
._reached
ds 50*50*2

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

._max_x
ds 1
._min_x
ds 1
._max_y
ds 1
._min_y
ds 1