##
## prints out the length of a character string "str"
##
## t0 - holds each byte from string in turn
## t1 - contains count of characters
## t2 - points to the string
##

		.data
str:	.asciiz	"Hello world"
ans:	.asciiz	"Length is "
endl:	.asciiz	"\n"
		.text
main:
		la		$t2, str		# t2 points to the string
		li		$t1, 0			# t1 holds the count

next_char:
		lb		$t0, ($t2)		# get a byte from string
		beqz	$t0, str_end	# zero means end of string
		add		$t1, $t1, 1		# increment count
		add		$t2, 1			# move pointer by one char
		j		next_char		# loop

str_end:
		li		$v0, 4
		la		$a0, ans
		syscall

		li		$v0, 1
		move	$a0, $t1
		syscall

		li		$v0, 4
		la		$a0, endl
		syscall

end:
		li		$v0, 10
		syscall
