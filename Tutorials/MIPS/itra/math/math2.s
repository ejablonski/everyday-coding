##
## calculate 5*X^2-3
##
## answer is 242
##
		.data
X:		.word	7
ans:	.asciiz	"answer = "
endl:	.asciiz	"\n"
		.text
main:
		lw		$t0, X

		mul		$t4, $t0, $t0
		mul		$t4, $t4, 5
		sub		$t4, $t4, 3

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
