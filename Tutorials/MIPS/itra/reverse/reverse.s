##
## reverse the character string "str"
## t1 - poits to the string
## t0 - holds each byte from string in turn
##
		.data
str:	.asciiz	"hello world"
endl:	.asciiz	"\n"
		.text

main:
		la		$t1, str

next_char:
		lb		$t0, ($t1)		# get a byte to the string
		beqz	$t0, str_end	# zero means end of string
		sub		$sp, $sp, 4		# adjust stack pointer
		sw		$t0, ($sp)		# PUSH the t0 register
		add		$t1, 1			# move pointer one character
		j		next_char		# go round the loop again

str_end:
		la		$t1, str

store:
		lb		$t0, ($t1)		# get byte from string
		beqz	$t0, done		# zero means end of string
		lw		$t0, ($sp)		# POP a value from the stack
		add		$sp, $sp, 4		# and adjust the pointer
		sb		$t0, ($t1)		# store in string
		add		$t1, 1			# move pointer one character
		j		store

done:
		li		$v0, 4
		la		$a0, str
		syscall

		li		$v0, 4
		la		$a0, endl
		syscall

		li		$v0, 10
		syscall
