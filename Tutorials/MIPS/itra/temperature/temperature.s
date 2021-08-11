##
## Program to convert temp in C to temp in F
##

		.data
prompt:	.asciiz	"Enter temperature in celsius: "
answ:	.asciiz	"The temperature in Fahreinheit: "
endl:	.asciiz	"\n"
		.text

main:
		li		$v0, 4
		la		$a0, prompt
		syscall

		li		$v0, 5			# read integer from terminal
		syscall

		mul		$t0, $v0, 9		# store in t0 multiplication of user entered value and 9
		div		$t0, $t0, 5
		add		$t0, $t0, 32

		li		$v0, 4
		la		$a0, answ
		syscall

		li		$v0, 1			# print an integer
		move	$a0, $t0
		syscall

		li		$v0, 4
		la		$a0, endl
		syscall

end:
		li		$v0, 10
		syscall
