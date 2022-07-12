#Zahava Brown - 346287956
#Worked with Naomi Gutstein - 345062400
#Nachum Danzig - Lab 4 Question 1

.data

numMes: .asciiz "Please enter a number"
opMes: .asciiz "Please enter addtion, multiplication, or power operator"

.text
#printing 1st message
la $a0, numMes 
li $v0, 4
syscall
#printing new line
li $a0, '\n'
li $v0, 11
syscall
#reading in first number
li $v0, 5
syscall
add $s0, $0, $v0
#printing new line
li $a0, '\n'
li $v0, 11
syscall
#printing 2nd message
la $a0, opMes 
li $v0, 4
syscall
#printing new line
li $a0, '\n'
li $v0, 11
syscall
#reading in op
li $v0, 12
syscall
add $s7, $0, $v0
#printing new line
li $a0, '\n'
li $v0, 11
syscall
#printing 1st message
la $a0, numMes 
li $v0, 4
syscall
#printing new line
li $a0, '\n'
li $v0, 11
syscall
#reading in second number
li $v0, 5
syscall
add $s1, $0, $v0

li $t0, '+'
li $t1, '*'
li $t2, '^'

beq $s7, $t0, addPlace
beq $s7, $t1, multPlace
beq $s7, $t2, powPlace


addPlace:
add $a0, $s0, $0   #putting values read in into parameters a0 and a1
add $a1, $s1, $0
jal addFunction #returns result from function and move on to printing result
j printResult

multPlace:
add $a0, $s0, $0   #putting values read in into parameters a0 and a1
add $a1, $s1, $0
jal multFunction #returns result from function and move on to printing result
j printResult

powPlace:
add $a0, $s0, $0   #putting values read in into parameters a0 and a1
add $a1, $s1, $0
jal powFunction #returns result from function and move on to printing result
j printResult




addFunction:
add $v0, $a0, $a1
jr $ra #going back to wherever function was called




multFunction:
addi $sp, $sp,-20    #making room in stack 
sw $ra, 0($sp)  #storing original values of registers in memory
sw $t1, 4($sp)
sw $a0, 8($sp)
sw $a1, 12($sp)
sw $t7, 16($sp)

slt $t1, $a0, $0 #checking if a0 < 0
beq $t1, $0, positive #if positive, all good, make a counter
sub $a0, $0, $a0 #changing signs of both numbers so can make a counter
sub $a1, $0, $a1

positive: #if a0 is positive, no need to change signs, so move on
add $t7, $0, $a0 #storing a0 to be used as counter since will change a0 later on
li $a0, 0 #so when call add, it can correctly add a1 the right amount of times
li $t1, 0 #so can use it as a counter

counterMult:
beq $t7, $t1, leaveMult #if reached limit of counter go to end of function
jal addFunction
add $a0, $0, $v0 #keeping track of sum, so when call addFunction again, proper values are there
addi $t1, $t1, 1 #increment counter
j counterMult

leaveMult:
add $v0, $0, $a0 #storing results
lw $ra, 0($sp) #putting values back from stack
lw $t1, 4($sp)
lw $a0, 8($sp)
lw $a1, 12($sp)
lw $t7, 20($sp)
addi $sp, $sp,20 #moving pointer back to top of stack
jr $ra



powFunction:
addi $sp, $sp, -20
sw $ra, 0($sp)
sw $a0, 4($sp)
sw $a1, 8($sp) 
sw $t0, 12($sp)
sw $t1, 16($sp)

slt $t0, $a1, $0 #checking if user entered -exponent, invalid
bne $t0, $0, leavePow #leave function, nothing to do

add $t1, $a1, $0 #storing a1 to use as limit for counter
li $a1, 1 #so when call mult, it can correctly mult a0 the right amount of times
li $t0, 0 #this will be our counter

counterPow:
beq $t1, $t0, leavePow
jal multFunction
add $a1, $0, $v0 #keeping track of product, so when call multFunction again, proper values are there
addi $t0, $t0, 1 #increment counter
j counterPow

leavePow:
add $v0, $0, $a1 #storing results
lw $ra, 0($sp) #putting values back from stack
lw $a0, 4($sp)
lw $a1, 8($sp) 
lw $t0, 12($sp)
lw $t1, 16($sp)
addi $sp, $sp, 20 #moving pointer back to top of stack
jr $ra



printResult:
add $a0, $0, $v0 #putting integer to print in a0
li $v0, 1
syscall 
