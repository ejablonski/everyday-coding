##
## ask user for decimal number
## convert to ASCII string, print the result
##
## t0 - number read in
## t1 - points to memory for string
## t2 - each byte for the string in turn
##

		.data
result:	.space	12
prompt:	.asciiz "Enter decimal number: "
ans:	.asciiz "ASCII string is "
endl:	.asciiz "\n"
		.text

main:
		li		$v0, 4
		la		$a0, prompt
		syscall

		li		$v0, 5			# syscall 5 reads an integer
		syscall
		move	$t0, $v0		# t0 holds the number

		la		$t1, result		# answer string set up here
		add		$t1, 11

		li		$t2, 0
		sb		$t2, ($t1)		# save in string
		sub		$t1, 1			# adjust destination pointer
		# li		$t2, '\n'
		sb		$t2, ($t1)		# save in string

loop:
		rem		$t2, $t0, 10	# get the remainder
		add		$t2, 48			# convert to ASCII code
		sub		$t1, 1			# adjust destination pointer
		sb		$t2, ($t1)		# save in string
		div		$t0, $t0, 10	# get quotient
		bnez	$t0, loop		# cont if quotient > 0

		li		$v0, 4
		la		$a0, ans
		syscall

		li		$v0, 4
		move	$a0, $t1
		syscall

		li		$v0, 4
		la		$a0, endl
		syscall

		li		$v0, 10
		syscall
