SECTION PAGE_21 
org 0xc000


PUBLIC _text_token_data

; text_token data  
._text_token_data

;       1234567890123456789012345
ds 25, "ZERO TOKEN"

; game messages 1 - 19
ds 25,  "WELCOME TO DUNGEON"        ; 1
ds 25, ""                           ; 2
ds 25, ""                           ; 3
ds 25, ""                           ; 4
ds 25, ""                           ; 5
ds 25, ""                           ; 6
ds 25, ""                           ; 7
ds 25, ""                           ; 8
ds 25, ""                           ; 9
ds 25, ""                           ; 10
ds 25, ""                           ; 11
ds 25, ""                           ; 12
ds 25, ""                           ; 13
ds 25, ""                           ; 14
ds 25, ""                           ; 15
ds 25, ""                           ; 16
ds 25, ""                           ; 17
ds 25, ""                           ; 18
ds 25, ""                           ; 19

; Dungeon cells 20 - 29

ds 25, "WALL"                       ; 20
ds 25, "FLOOR"                      ; 21
ds 25, ""                           ; 22
ds 25, ""                           ; 23
ds 25, ""                           ; 24
ds 25, ""                           ; 25
ds 25, ""                           ; 26
ds 25, ""                           ; 27
ds 25, ""                           ; 28
ds 25, ""                           ; 29

; potions 30 - 39
ds 25, "UNKOWN POTION"              ; 30
ds 25, "POTION OF HEALING"          ; 31
ds 25, "POTION OF SPEED"            ; 32
ds 25, ""                           ; 33
ds 25, ""                           ; 34
ds 25, ""                           ; 35
ds 25, ""                           ; 36
ds 25, ""                           ; 37
ds 25, ""                           ; 38
ds 25, ""                           ; 39

; melee weapons 40 - 49
ds 25, "CLUB"                       ; 40
ds 25, "DAGGER"                     ; 41
ds 25, "AXE"                        ; 42
ds 25, "SHORT SWORD"                ; 43
ds 25, "LONG SWORD"                 ; 44
ds 25, "GREAT SWORD"                ; 45
ds 25, ""                           ; 46
ds 25, ""                           ; 47
ds 25, ""                           ; 48
ds 25, ""                           ; 49

; ranged weapons 50 - 59
ds 25, "SLING"                      ; 50
ds 25, "DART"                       ; 51
ds 25, "SHORTBOW"                   ; 52
ds 25, "LONG BOW"                   ; 53
ds 25, "CROSS BOW"                  ; 54
ds 25, "GREAT SWORD"                ; 55
ds 25, ""                           ; 56
ds 25, ""                           ; 57
ds 25, ""                           ; 58
ds 25, ""                           ; 59

; armour 60 - 69
ds 25, "PADDED ARMOUR"              ; 60
ds 25, "LEATHER ARMOUR"             ; 61
ds 25, "SUDDED LEATHER ARMOUR"      ; 62
ds 25, "CHAIN SHIRT ARMOUR"         ; 63
ds 25, "SCALE MAIL ARMOUR"          ; 64
ds 25, "HALF PLATE ARMOUR"          ; 65
ds 25, "RING MAIL ARMOUR"           ; 66
ds 25, "CHAIM MAIL ARMOUR"          ; 67
ds 25, "SPLINT ARMOUR"              ; 68
ds 25, "PLATE ARMOUR"               ; 69

; rings 70 - 79
ds 25, "UNKNOWN RING"               ; 70
ds 25, "RING OF HEALTH"             ; 71
ds 25, "RING OF SPEED"              ; 72
ds 25, ""                           ; 73
ds 25, ""                           ; 74
ds 25, ""                           ; 75
ds 25, ""                           ; 76
ds 25, ""                           ; 77
ds 25, ""                           ; 78
ds 25, ""                           ; 79

; scrolls 80 - 89
ds 25, "UNKNOWN SCROLL"             ; 80
ds 25, "SCROLL OF FIREBALL"         ; 81
ds 25, ""                           ; 82
ds 25, ""                           ; 83
ds 25, ""                           ; 84
ds 25, ""                           ; 85
ds 25, ""                           ; 86
ds 25, ""                           ; 87
ds 25, ""                           ; 88
ds 25, ""                           ; 89

; dungeon objects 90 - 99
ds 25, "DOOR"                       ; 90
ds 25, "CHEST"                      ; 91
ds 25, "TRAP"                       ; 92
ds 25, ""                           ; 93
ds 25, ""                           ; 94
ds 25, ""                           ; 95
ds 25, ""                           ; 96
ds 25, ""                           ; 97
ds 25, ""                           ; 98
ds 25, ""                           ; 99

; food 100 - 109
ds 25, "BREAD"                      ; 100
ds 25, ""                           ; 101
ds 25, ""                           ; 102
ds 25, ""                           ; 103
ds 25, ""                           ; 104
ds 25, ""                           ; 105
ds 25, ""                           ; 106
ds 25, ""                           ; 107
ds 25, ""                           ; 108
ds 25, ""                           ; 109

; humanoid creature 110 - 119
ds 25, "HUMAN"                      ; 110
ds 25, ""                           ; 111
ds 25, ""                           ; 112
ds 25, ""                           ; 113
ds 25, ""                           ; 114
ds 25, ""                           ; 115
ds 25, ""                           ; 116
ds 25, ""                           ; 117
ds 25, ""                           ; 118
ds 25, ""                           ; 119

; beast creature 120 - 129
ds 25, "SNAKE"                      ; 120
ds 25, ""                           ; 121
ds 25, ""                           ; 122
ds 25, ""                           ; 123
ds 25, ""                           ; 124
ds 25, ""                           ; 125
ds 25, ""                           ; 126
ds 25, ""                           ; 127
ds 25, ""                           ; 128
ds 25, ""                           ; 129
; ooze creature 130 - 139
ds 25, "SLIME"                      ; 130
ds 25, ""                           ; 131
ds 25, ""                           ; 132
ds 25, ""                           ; 133
ds 25, ""                           ; 134
ds 25, ""                           ; 135
ds 25, ""                           ; 136
ds 25, ""                           ; 137
ds 25, ""                           ; 138
ds 25, ""                           ; 139

; undead creature 140 - 149
ds 25, "SKELETON"                   ; 140
ds 25, ""                           ; 141
ds 25, ""                           ; 142
ds 25, ""                           ; 143
ds 25, ""                           ; 144
ds 25, ""                           ; 145
ds 25, ""                           ; 146
ds 25, ""                           ; 147
ds 25, ""                           ; 148
ds 25, ""                           ; 149
