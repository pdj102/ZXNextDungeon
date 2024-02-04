SECTION PAGE_26 
org 0xc000

PUBLIC _frontier_head
PUBLIC _frontier_tail

PUBLIC _frontier_count
PUBLIC _reached

PUBLIC _frontier

PUBLIC _start_coord
PUBLIC _goal_coord
PUBLIC _current_coord
PUBLIC _tmp_coord

PUBLIC _tail_priority

PUBLIC _max_x
PUBLIC _min_x
PUBLIC _max_y
PUBLIC _min_y

PUBLIC _neighbor

PUBLIC _priority_queue
PUBLIC _queue_head
PUBLIC _queue_tail
PUBLIC _queue_count

; bounded priority queue - 21 queues * 10 elements * 2 bytes
._priority_queue
ds 21 * 10 * 2

._queue_head
ds 21 
._queue_tail
ds 21 
._queue_count
ds 21 

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

._tmp_coord
ds 2

._start_coord
ds 2

._goal_coord
ds 2
._current_coord
ds 2

._neighbor
ds 1

._tail_priority
ds 1

._max_x
ds 1
._min_x
ds 1
._max_y
ds 1
._min_y
ds 1