#Zahava Brown - 346287956
#Worked with Naomi Gutstein - 345062400
#Nachum Danzig - Lab 3 Question 1

.data
array: .word 3, -2, 7, 5, -9, 0  #check when sorted and random
spaceMan: .asciiz " "

.text
la $a0, array
li $a1, 6
la $s7, array #extra pointer so after increment still have original address in a0                                                                     
addi $s2, $a1, -1 #n-1, the limit don't want j to reach, and when i gets here need to reset
 
la $s6, array #address holder for array for printing

loopStart:
beq $s0, $a1, printArray #s0 is j, did we reach limit of loop i.e. n-1
bne $s1, $s2, swapTest #if i(s1) is not equal to n-1, check if need to swap
addi $s2, $s2, -1 #decreasing size, biggest element in last place
la $s7, array #resetting address
addi $s0, $s0, 1 #incrementing j (reached end of "inner loop")
addi $s1, $0, -1 #reseting i to -1
j loopStart #as if continuing to next iteration

swapTest:
lw $t0, 0($s7) #loading first element of array into t0
lw $t1, 4($s7) #loading next element so can compare t1 to t0
slt $t9, $t1, $t0  #if t1(array[i+1]) < t0(array[i]), stores 1 in t9
beq $t9, $0, dontSwap #this means t1>t0 so no need to swap
sw $t1, 0($s7) #putting t0 and t1 in the opposite addresses in the array
sw $t0, 4($s7)  

addi $s7, $s7, 4 #after swap moving pointer over 1 to compare next 2 elements
addi $s1, $s1, 1 #incrementing i 
j loopStart

dontSwap:
addi $s1, $s1, 1 #incrementing i, need to put after swap too
addi $s7, $s7, 4 #didn't need to swap so moving pointer over 1 to compare next 2 elements
j loopStart


printArray:
beq $a1, $t8, exit #checking if reached end of array
lw $a0, 0($s6) #taking next number to be printed
li $v0, 1 #function to print integer
syscall
#printing space
la $a0, spaceMan
li $v0, 4
syscall

addi $t8, $t8, 1 #advancing counter
addi $s6, $s6, 4 #advancing to next elements
j printArray

exit: