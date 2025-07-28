.data

	message: .asciiz "How many numbers do you want to print? "
	space: .asciiz " "

.text 
	
	la $a0, message
	add $v0, $zero, 4
	syscall 
	
	# Read integer from user input
	add $v0, $zero, 5
	syscall 
	
	addi $t3, $v0, 0 
	
	addi $t0, $zero, 1 
	addi $t1, $zero, 0 
	
	Loop:
	
		beq $t3, $t4, End 
	
		# N_n = N_n-2 + N_n-1
		add $t2, $t0, $t1 
		
		addi $t0, $t1, 0
		addi $t1, $t2, 0
		
		add $t4,$t4, 1
		
		la $a0, space
		add $v0, $zero, 4
		syscall
		
		addi $a0, $t2, 0
		addi $v0, $zero, 1
		syscall 
		
		j Loop
	
	End:	
		
add $v0, $zero, 10
syscall