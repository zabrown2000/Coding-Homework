#Zahava Brown - 346287956
#Worked with Naomi Gutstein - 345062400
#Nachum Danzig - Lap 2 Question 1

.data
list: .byte 13, -67, 67, 25, 0, 80, -100, 6

.text

la $a0, list #loading address of list into a0
li $a1, 8 #putting length of array in a1
lb $v0, 0($a0) #loading first element into $v0, did lb because list is byte size not word size
li $t9, 0
loopStart:
slt $s0, $t9, $a1 #checking if t9 is less than the length in a1 before advancing to next element
beq $s0,$0, exit
addi $a0, $a0, 1 #advancing array by 1 byte
lb $t1, 0($a0) #can use 0 because moved forward so this 0 is really next element
slt $s0, $v0, $t1 #if what's in v0 is < what's in t1 will store 1 in s0
beq $0, $s0, increment #if 0 is in s0, meaning v0 > t1, increment and then go to top of loop
add $v0, $t1, $0 #setting v0 to contain the new max element from t1

increment:
addi $t9, $t9, 1 #incrementing counter to check if reached end of array
j loopStart 

exit:
add $a0, $v0, $0 #moving largest integer into a0 so it can be printed
li $v0, 1 #1 is code to print an integer
syscall

