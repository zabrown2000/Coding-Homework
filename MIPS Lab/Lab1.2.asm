#Zahava Brown - 346287956
#Worked with Naomi Gutstein - 345062400
#Nachum Danzig - Lap 1 Question 2

.data 
inputMes: .asciiz "Enter a number less than 100 and greater than -100  "
outputMes: .asciiz "\nSum is: "

.text
la $a0 inputMes #loading address of inputMes array into a0 register for function call
li $v0, 4 #putting command 4 in v0 to print a string
syscall

loopStart: #label to signal loop
li $v0, 5 #putting command 5 in v0 to read in an integer
syscall

slti $t0, $v0, 100 #checking if user input is less than 100
beq $t0, $zero, loopStart #if user inputted number >99 then ignore input and go to top of loop

li $t1, -99 #putting -99 in register so can compare $v0 to it
slt $t2, $v0, $t1 #if user entered value <-99

bne $t2, $zero, loopStart #if user inputted number <-99 then ignore input and go to top of loop

beq $v0, $zero, endLoop #user entered a zero, so now we can leave the loop to print the sum

add $t3 $t3 $v0 #accumilating sum from each user input

j loopStart 

endLoop: 
la $a0, outputMes #loading address of outputMes array into a0 register for function call
li $v0, 4 #putting command 4 in v0 to print a string
syscall

la $a0, 0($t3) #loading address of interger into a0
li $v0, 1 #putting command 2 in v0 to print integer
syscall
