#Zahava Brown - 346287956
#Worked with Naomi Gutstein - 345062400
#Nachum Danzig - Lab 3 Question 2

#works for each case!!!!

.data
list: .byte 2,-4,8,-17  #change case for each run, -3,-1,1,3  1,1,1,1  2,-4,8,-16   
arithMes: .asciiz "d = "
geoMes: .asciiz "q = "
notMes: .asciiz "Not a progression"

.text
la $a0, list 
li $a1, 4

Arithmetic:
lb $t1, 0($a0) #need to compare 2 elements at a time
lb $t2, 1($a0)
sub $t0, $t2, $t1 #placing difference of 2nd and 1st elements into t0
li $s1, 2 #already checked 2 out of 4 elements

arithLoop:
beq $a1, $s1, endArith #checking if our counter reached end of list
addi $a0, $a0, 1 #incrementing further in list 
lb $t1, 0($a0) #need to compare 2 elements at a time
lb $t2, 1($a0)
sub $t3, $t2, $t1 #placing difference of 2nd and 1st elements into t3

#now need to compare t0 and t3
bne $t0, $t3, notArith 
addi $s1, $s1, 1 #increment so can check at beginning of next iteration
j arithLoop


notArith:
addi $s7, $s7, 1 #using a counter to check at end if wasn't progession at all
j Geometric

endArith:
#printing d = 
la $a0, arithMes
li $v0, 4
syscall
#printing d value
add $a0, $0, $t0
li $v0, 1
syscall
#printing new line
li $a0, '\n'
li $v0, 11
syscall

j Geometric


Geometric:
la $a0, list 
li $a1, 4
lb $t1, 0($a0) #need to compare 2 elements at a time
lb $t2, 1($a0)

div $t2, $t1
mflo $t3 #actual result
mfhi $t4 #remainder of int division
bne $t4, $0, notGeo #if wasn't clean division, know right away not geometric progression
li $s1, 2 #already checked 2 out of 4 elements

geoLoop:
beq $a1, $s1, endGeo #checking if our counter reached end of list
addi $a0, $a0, 1 #incrementing to check next 2 elements
lb $t1, 0($a0) #need to compare 2 elements at a time
lb $t2, 1($a0)

div $t2, $t1
mflo $t5 #quotient - need to match t3
mfhi $t6 #remainder - needs to match t4 (0)
bne $t6, $t4, notGeo #remainder not 0
bne $t5, $t3, notGeo #progression not the same
addi $s1, $s1, 1 #increment so can check at beginning of next iteration
j geoLoop

notGeo:
addi $s7, $s7, 1 #using a counter to check at end if wasn't progession at all
j notProgressive

endGeo:
#printing q = 
la $a0, geoMes
li $v0, 4
syscall
#printing q value
add $a0, $0, $t3
li $v0, 1
syscall
#printing new line
li $a0, '\n'
li $v0, 11
syscall

notProgressive:
li $t9, 2 #made counter to keep track if both not arith and not geo
bne $s7, $t9, exit
#printing not progressive
la $a0, notMes
li $v0, 4
syscall

exit: