#Zahava Brown - 346287956
#Worked with Naomi Gutstein - 345062400
#Nachum Danzig - Lap 2 Question 2

.data                                        
enterNum: .asciiz "ENTER VALUE"
enterOp: .asciiz "ENTER OP-CODE"
resultMes: .asciiz "The result is "
overMes: .asciiz "Overflow detected\n"
.text
#need to create char variables to compare to later on
li $s0, '+'
li $s1, '-'
li $s2, '*'
li $s3, '@'

la $a0, enterNum #moving address of what what to print to a0
li $v0, 4 #command to print string
syscall

li $v0, 5 #reading in integer from user to v0
syscall
add $t1, $v0, $0 #moving value so doesn't get overridden 

li $a0, '\n' #printing char for new line
li $v0, 11
syscall   

loopStart: 
la $a0, enterOp #moving address of what what to print to a0
li $v0, 4 #command to print string
syscall

li $v0, 12 #reading in char to v0
syscall
add $t5, $v0, $0 #so the symbol doesn't get overwritten

li $a0, '\n' #printing char for new line
li $v0, 11
syscall

beq $t5, $s3, exit #@ is terminating symbol, so go to bottem of code

la $a0, enterNum #moving address of what what to print to a0, need another number to perform operation
li $v0, 4 #command to print string
syscall

li $v0, 5 #reading in integer from user to v0
syscall
add $t2, $v0, $0 #result below will be t2 +,-,or * t1

li $a0, '\n' #printing char for new line
li $v0, 11
syscall

#checking which operation to complete
beq $t5, $s0, plus #user entered +
beq $t5, $s1, minus #user entered -
beq $t5, $s2, multiply #user entered *

plus:
add $t1, $t1, $t2 #add t2 from t1 and store in t1
j loopStart

minus:
sub $t1, $t1, $t2 #subtract t2 from t1 and store in t1
j loopStart

multiply:
mult $t1, $t2
mfhi $t3 #moving result from hi to $t3
mflo $t7 #moving result from lo into $t7

slt $t9, $t7, $0 #if lo was negative put 1 in t9
beq $t9, $0, loPos #if t9 had a 0 then lo was 0 or positive, so jump to loPos
li $t8, -1 #put -1 in t8 so can compare it
bne $t3, $t8, negOverFlow #lo was negative, so continue and check if hi != -1, then there is an overflow error
add $t1, $t7, $0 #no overflow error, so move lo to t1 to be used for next operation
j loopStart

negOverFlow:
la $a0, overMes #putting address of overflow message into a0 to be printed
li $v0, 4 #code to print string
syscall
j loopStart

loPos:  
bne $t3, $0, posOverFlow
add $t1, $t7, $0 #no overflow error, so move lo to t1 to be used for next operation
j loopStart #directions said for this type of overflow to just print the message

posOverFlow: #need to jump to exit after print msg
la $a0, overMes #putting address of overflow message into a0 to be printed
li $v0, 4 #code to print string
syscall
j exit #directions said for this type of overflow to terminate the program
 
exit:
la $a0, resultMes #moving address of string to be printed
li $v0, 4 #code to print string
syscall
add $a0, $t1, $0 #moving integer want to print to a0
li $v0, 1 #code to print integer
syscall





