##
## calculate the sum of elements in array
##

		.data
array:	.word	3, 4, 2, 6
count:	.word	4
ans:	.asciiz	"sum = "
endl:	.asciiz	"\n"
		.text

main:
		la		$t0, array
		lw		$t1, count

loop:
		lw		$t3, ($t0)
		add		$t2, $t2, $t3
		beqz	$t1, print_answer
		sub		$t1, 1
		j		loop

print_answer:
		li		$v0, 4
		la		$a0, ans
		syscall

		li		$v0, 1
		move	$a0, $t2
		syscall

		li		$v0, 4
		la		$a0, endl
		syscall

end:
		li		$v0, 10
		syscall
