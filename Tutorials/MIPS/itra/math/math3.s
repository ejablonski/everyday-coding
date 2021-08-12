##
## calculate (NUM-3)*(NUM+4)
##
## answer is 98
##
		.data
NUM:	.word	10
ans:	.asciiz	"answer = "
endl:	.asciiz	"\n"
		.text
main:
		lw		$t0, NUM

		sub		$t1, $t0, 3
		add		$t2, $t0, 4
		mul		$t4, $t1, $t2

		li		$v0, 4
		la		$a0, ans
		syscall

		li		$v0, 1
		move	$a0, $t4
		syscall

		li		$v0, 4
		la		$a0, endl
		syscall
end:
		li		$v0, 10
		syscall
