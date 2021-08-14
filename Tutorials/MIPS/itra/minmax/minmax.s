##
## t0 - points to array elements in turn
## t1 - contains count of elements
## t2 - contains min
## t3 - contains max
## t4 - each word from array in turn
##

		.data
array:	.word	3, 4, 2, 6, 12, 7, 18, 26, 2, 14, 19, 7, 8, 12, 13
count:	.word	15
endl:	.asciiz	"\n"
ans1:	.asciiz	"min = "
ans2:	.asciiz	"max = "
		.text

main:
		la 		$t0, array
		lw		$t1, count
		lw		$t2, ($t0)
		lw		$t3, ($t0)
		add		$t0, $t0, 4			# pointer to start at a[0]
		add		$t1, $t1, -1		# adm go round count-1 times

loop:
		lw		$t4, ($t0)			# load next word from array
		bge		$t4, $t2, notMin	# skip if a[i] >- min
		move	$t2, $t4			# copy a[i] to min

notMin:
		ble		$t4, $t3, notMax	# skip if a[i] <= max
		move	$t3, $t4			# copy a[i] to max

notMax:
		add		$t1, $t1, -1		# decrement counter
		add		$t0, $t0, 4			# increment pointer by word
		bnez	$t1, loop			# and continue if counter>0

print_results:
		li		$v0, 4
		la		$a0, ans1
		syscall

		li		$v0, 1
		move	$a0, $t2
		syscall

		li		$v0, 4
		la		$a0, endl
		syscall

		li		$v0, 4
		la		$a0, ans2
		syscall

		li		$v0, 1
		move	$a0, $t3
		syscall

		li		$v0, 4
		la		$a0, endl
		syscall

end:
		li		$v0, 10
		syscall
