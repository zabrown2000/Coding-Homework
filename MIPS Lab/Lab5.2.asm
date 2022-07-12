#Zahava Brown - 346287956
#Worked with Naomi Gutstein - 345062400
#Nachum Danzig - Lab 5 Question 2

.data
message: .asciiz "Please enter a number\n"
errorMes: .asciiz "error please try again\n"

.text
beg:
#printing message
la $a0, message
li $v0, 4
syscall
#reading in int
li $v0, 5
syscall
add $t9, $v0, $0

beq $t9, $0, exit #once user enters 0, end program
#possible options for 8 left most bits
li $s0, 0x31
li $s1, 0x30
li $s2, 0x48
li $s3, 0x74
srl $t0, $t9, 24 #shifting to check left most 8 bits to compare
#now checking which case user entered
beq $t0, $s0, case1
beq $t0, $s1, case2
beq $t0, $s2, case3
beq $t0, $s3, case4
#user didn't enter correct number, will print error and have user try again
la $a0, errorMes
li $v0, 4
syscall
j beg



#0x31
case1:
#printing number before change in hex
add $a0, $0, $t9
li $v0, 34
syscall

li $k0, 195 #value of bits want to change (0,1,6,7) 1+2+64+128
or $t9, $t9, $k0 #or-ing input number so putting 1s in correct places
j printNew

#0x30
case2:
#printing number before change in hex
add $a0, $0, $t9
li $v0, 34
syscall

li $k0, 2147483453 #value of number with 0's in bits 0,1,6,7 and rest have 1
and $t9, $t9, $k0
j printNew


#0x48
case3:
#printing number before change in hex
add $a0, $0, $t9
li $v0, 34
syscall

li, $k0, 65280 #bits 8-15 were made 1, as an xor mask
xor $t9, $t9, $k0
j printNew

#0x74
#4. If they are 0x74 then the program should perform shift left by N places. The N is equal
#	to the value of the five bits 20-24.
case4:
#printing number before change in hex
add $a0, $0, $t9
li $v0, 34
syscall

#getting N for shift amount
srl $k0, $t9, 20
sllv $t9, $t9, $k0 #shifting left by N places (using shift left logical variable)

printNew:
#printing space
li $a0, ' '
li $v0, 11
syscall
#printing number in hex
add $a0, $0, $t9
li $v0, 34
syscall
#printing new line
li $a0, '\n'
li $v0, 11
syscall
j beg


exit: