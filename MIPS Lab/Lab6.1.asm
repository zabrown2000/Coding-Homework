#Zahava Brown - 346287956
#Worked with Naomi Gutstein - 345062400
#Nachum Danzig - Lab 6 Question 1

.data
A: .space 1000
B: .space 1000
C: .space 1000 #could store 3rd matrix or just print in as calculate
message: .asciiz "Please enter dimensions for the matrices\n"
matA: .asciiz "Please enter values for matrix A\n"
matB: .asciiz "Please enter values for matrix B\n"
X: .asciiz " X\n"
result: .asciiz "Result:\n"

.text
readDimensions:
la $a0, message
li $v0, 4
syscall
#mxn for A
li $v0, 5
syscall
add $s1, $0, $v0 #row in A
li $v0, 5
syscall
add $s0, $0, $v0 #col in A
#mxn for B
li $v0, 5
syscall
add $s3, $0, $v0 #row in B
li $v0, 5
syscall
add $s2, $0, $v0 #col in B
bne $s0, $s3, readDimensions #invalid entries for matrices dimensions

#loop for set A
la $t0, A
#size = m*n
mult $s0, $s1
mflo $k0
sll $k0, $k0, 2 #to make it word length = 4
add $t1, $t0, $k0 #pointer to end of array, loop till pointers =eachother, no need for counter

la $a0, matA
li $v0, 4
syscall
Start: #input will be row, row, row, etc but will be stored as one long row
beq $t1, $t0, endLoop #checking if pointer equal
#get input
li $v0, 5
syscall
sw $v0, 0($t0)
addi $t0, $t0, 4
j Start
endLoop:


#loop for set B
la $t0, B
#size = m*n
mult $s2, $s3
mflo $k0
sll $k0, $k0, 2 #to make it word length = 4
add $t1, $t0, $k0 #pointer to end of array, loop till pointers =eachother, no need for counter

la $a0, matB
li $v0, 4
syscall
Start2: #input will be row, row, row, etc but will be stored as one long row
beq $t1, $t0, endLoop2 #checking if pointer equal
#get input
li $v0, 5
syscall
sw $v0, 0($t0)
addi $t0, $t0, 4
j Start2
endLoop2:


#now multiply
la $t0, A
la $t1, B
la $t8, C
li $t2, 0 #counter for amount of elements in a row in A (amount of columns)
li $t5, 0 #counter for amount of rows in A
li $t9, 0 #counter for amount of columns in B
li $t6, 0 #counter for product matrix
li $t7, 0 #sum for product matrix


multRow:

#1st row of A times 1st column of B
beq $t2, $s0, endRow #checking if reached end of row (will increment t2)
sll $t3, $t2, 2 #need to increment by 4 not 1
add $t4, $t3, $t0 #need to connect jump to address. t4 is temp pointer to array
lw $k0, 0($t4) #get row numbers

mult $t2, $s2 #getting location of next number in B
mflo $t4
sll $t4, $t4, 2
add $t4, $t4, $t1
lw $k1, 0($t4)
mult $k0, $k1
mflo $t4
add $t7, $t7, $t4 #sum of row
addi $t2, $t2, 1
j multRow

endRow:
addi $t9, $t9, 1
sll $t3, $t6, 2 #t6 counter to know where to store t7 result in 3rd array
add $t3, $t3, $t8 #getting pointer to correct spot in C 
sw $t7, 0($t3)
addi $t6, $t6, 1

li $t2, 0 #resetting counter for numbers in each row
li $t7, 0 #resetting holder for row sum
addi $t1, $t1, 4 #moving t1 to point to next col in B
bne $t9, $s2, multRow #checking if finished going through B with current row from A

addi $t5, $t5, 1
sll $t9, $s0, 2 #getting t0 to point to next row in A
add $t0, $t0, $t9
la $t1, B #reseting t1 
li $t9, 0 
beq $t5, $s1, printMatrices #got through all rows in A, time to print result
j multRow

printFunction:
	#a0 will hold address of matrix a1 holds rows and a2 hold columns
	addi $sp, $sp, -16
	sw $t0, 0($sp)
	sw $t1, 4($sp)
	sw $t2, 8($sp)
	sw $a0, 12($sp)

	li $t1, 0 #pointer for amount of rows
	li $t2, 0 #pointer for amount of columns
	add $t0, $0, $a0

	printNum:
	lw $a0, 0($t0) #getting current number to be printed
	li $v0, 1
	syscall
	li $a0, ' '
	li $v0, 11
	syscall
	addi $t0, $t0, 4 #advancing pointer in matrix
	addi $t2, $t2, 1 #advancing counter for each col in a row

	bne $t2, $a2, printNum #if didn't reach end of row print next num
	addi $t1, $t1, 1 #end of row so increment counter for rows
	li $t2, 0 #resetting counter for columns in a row
	li $a0, '\n'
	li $v0, 11
	syscall
	bne $t1, $a1, printNum #if went through all rows in matrix will end here

	lw $t0, 0($sp)
	lw $t1, 4($sp)
	lw $t2, 8($sp)
	lw $a0, 12($sp)
	addi $sp, $sp, 16
	jr $ra

printMatrices:
#print A
la $a0, A
add $a1, $s1, $0
add $a2, $s0, $0
jal printFunction

#print x 
la $a0, X
li $v0, 4
syscall

#print B
la $a0, B
add $a1, $s3, $0
add $a2, $s2, $0
jal printFunction

#print result is 
la $a0, result
li $v0, 4
syscall

#print C
la $a0, C
add $a1, $s1, $0
add $a2, $s2, $0
jal printFunction


exit:
