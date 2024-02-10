SECTION PAGE_26 
org 0xc000

PUBLIC _reached

PUBLIC _start_coord
PUBLIC _goal_coord
PUBLIC _current_coord
PUBLIC _next_coord
PUBLIC _tmp_coord

PUBLIC _tail_priority
PUBLIC _priority_offset

PUBLIC _max_x
PUBLIC _min_x
PUBLIC _max_y
PUBLIC _min_y

PUBLIC _tmp_total_cost
PUBLIC _tmp_cost_so_far

PUBLIC _neighbor

PUBLIC _priority_queue
PUBLIC _queue_head
PUBLIC _queue_tail
PUBLIC _queue_count

; bounded priority queue - 21 queues * 10 elements * 2 bytes
._priority_queue
ds 21 * 20 * 2

._queue_head
ds 21 
._queue_tail
ds 21 
._queue_count
ds 21 


; Path finding map - 50 * 50 array of 3 bytes
; Must match size of dungeon map
._reached
ds 50*50*3

._tmp_coord
ds 2

._start_coord
ds 2

._goal_coord
ds 2
._current_coord
ds 2
._next_coord
ds 2

._neighbor
ds 1

._tail_priority
ds 1
._priority_offset
ds 1

._max_x
ds 1
._min_x
ds 1
._max_y
ds 1
._min_y
ds 1

._tmp_total_cost
ds 1

._tmp_cost_so_far
ds 1