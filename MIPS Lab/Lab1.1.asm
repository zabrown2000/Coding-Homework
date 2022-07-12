#Zahava Brown - 346287956
#Worked with Naomi Gutstein - 345062400
#Nachum Danzig - Lap 1 Question 1

.data
myArray1: .word 4, 20000, 36, -89, 17, 0, 9
myArray2: .space 100

.text #check slides from today for exapmles on how t increment and deal with arrays and syscall
#array of word-length numbers
#use seconf array for space
#hardcoded array no input

la $a0, myArray1 #pointer to array with numbers
la $a1, myArray2 #pointer to array copying to

loopStart: #label to signal loop
lw $t0, 0($a0) #loading first value in array to register t0
sw $t0, 0($a1) #storing what's in t0 to first place in new array

beq $t0, $zero, end #check if t0 is 0, if so copy and then leave loop without counting

addi $v0, $v0, 1 #count amount of numbers, not 0
addi $a0, $a0, 4 #moving address in a0 up 4 bytes so next time at 0($a0) at next element
addi $a1, $a1, 4

j loopStart

end: #label to end the loop
