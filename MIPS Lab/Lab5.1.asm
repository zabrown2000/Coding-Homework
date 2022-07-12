#Zahava Brown - 346287956
#Worked with Naomi Gutstein - 345062400
#Nachum Danzig - Lab 5 Question 1

.data
message: .asciiz "Enter length of code followed by number in code\n"
notFound: .asciiz "\n Code was not found"
found: .asciiz "\n Code was found"
list: .byte 1,2,3,4,5,1,1,1,1,2,2,2,3,4,5,6,7,8,9,0,25,74,-9,-8,-8,-6,-7,-6,-5,-4,-3,-2
code: .space 500

.text
#printing message
la $a0, message
li $v0, 4
syscall
#reading in from user size for code
li $v0, 5
syscall
add $a3, $v0, $0

la $a0, list
li $a1, 32
la $a2, code
la $s6, code #address holder for printing the code

inputCode:
beq $s0, $a3, printCode
li $v0, 5
syscall
sb $v0 0($a2) #storing user input into space set aside above
addi $a2, $a2, 1 #incrementing so can input to next space in code
addi $s0, $s0, 1 #counter to see if reached end of user input
j inputCode


printCode:
lb $a0, 0($s6) #printing each number in the code
li $v0, 1
syscall
li $a0, ' ' #printing space in between each number
li $v0, 11
syscall
addi $t0, $t0, 1 #setting counter to see if full code was printed
addi $s6, $s6, 1 #incrementing next element in the code
bne $a3, $t0, printCode #if entire code is not printed, will go back to top to print

checkCode:
la $t0, list #pointer to outer loop
sub $s1, $a1, $a3 #boundary for outer loop

outerLoop:
la $a2, code #reseting it because changed it when read in numbers
beq $t2, $s1, printNotFound #finished checking for code in list

add $t1, $0, $t0 #inner loop pointer will equal outer loop pointer

li $t3, -1 #counter for inner loop
innerLoop:
beq $t3, $a3, increment #checking if reached limit of code length
lb $t4, 0($a2) #getting first element of code to compare
lb $t5, 0($t1) #getting first element of list to compare
bne $t4, $t5, increment #code not found at this point in list, can leave
li $t9, 1 #flag
addi $t8, $t8, 1 #counting how many times set flag to 1
beq $t8, $a3, printFound #checking if each number in code was found in list, like a break

addi $a2, $a2, 1 #incrementing to next element in code
addi $t1, $t1, 1 #increment current pointer in list
addi, $t3, $t3, 1 #iterator for inner loop
j innerLoop

increment:
li $t9, 0 #resetting flag
li $t8, 0 #resetting flag counter
addi $t0, $t0, 1 #moving pointer forward in list
addi $t2, $t2, 1 #iterator for outer loop
j outerLoop


printNotFound:
la $a0, notFound #printing message if code was not found
li $v0, 4
syscall
j exit

printFound:
la $a0, found #printing message if code was found
li $v0, 4
syscall
j exit

exit: