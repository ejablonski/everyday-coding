##
## calculate A*X^2+B*X+C
##
## answer is 180
##
		.data
X:		.word	7
A:		.word	3
B:		.word	4
C:		.word	5
ans:	.asciiz	"answer = "
endl:	.asciiz	"\n"
		.text
main:
		lw		$t0, X
		lw		$t1, A
		lw		$t2, B
		lw		$t3, C

		mul		$t4, $t0, $t0	# t4 = X^2
		mul		$t4, $t4, $t1	# t4 = A*X^2
		mul		$t5, $t2, $t0	# t5 = B*X
		add		$t4, $t4, $t5	# t4 = A*X^2+B*X
		add		$t4, $t4, $t3	# t4 = A*X^2+B*X+C

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
