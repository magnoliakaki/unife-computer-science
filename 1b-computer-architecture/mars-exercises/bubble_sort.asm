\.data
#arrayToSort: .word 4,3,11,2,92,0
arrayToSort: .word 12,3,11,2,92,12,12,45,21,243,23,1

.text
	
addi $s0, $zero, 44 # array dimension
		
jal BubbleSort
	
add $v0, $zero, 10
syscall
	
BubbleSort:	
	# The ra value must be saved if I'm calling another procedure
	# inside BubbleSort, because otherwise jal will clobber its value
	addi $sp, $sp, -8
	sw $ra, 0($sp)
	sw $s0, 4($sp)

	add $t0, $zero, 0
	add $t3, $zero, 0
	add $t4, $zero, 4
	

	Loop:

		beq $t0, $s0, EndLoop
			
		lw $t1, arrayToSort($t3)
		lw $t2, arrayToSort($t4)
			
		slt $t5, $t1, $t2
		beq $t5, 1, NoSwap
	
		addi $t6, $t1, 0
		addi $t7, $t2, 0 
			
		sw $t7, arrayToSort($t3)
		sw $t6, arrayToSort($t4)
			
		NoSwap:
		
		add $t3, $t3, 4
		add $t4, $t3, 4 
		addi $t0, $t0, 4
			
		j Loop
		
	EndLoop:
		
	addi $s0, $s0, -4
	beq $s0, 0, ExitBubbleSort
	
	jal BubbleSort
		
	ExitBubbleSort:
		# Restore the stack
		lw $s0, 4($sp)
		lw $ra, 0($sp)
		addi $sp, $sp, 8
		jr $ra