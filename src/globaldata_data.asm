SECTION PAGE_16 
org 0x0000


PUBLIC _globaldata

; Game global data structures are placed in pages 16 and 17 and mapped into MMU slot 0 and 1 (0x0000)
; globaldata is a reference to address 0x0000
._globaldata

; dummy sizing information. Not used
ds 40*40*4