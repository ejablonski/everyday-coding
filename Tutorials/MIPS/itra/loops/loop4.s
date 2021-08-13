##
## swap each pair in string 
## there always will be an even number
## of characters
##
## answer is "badcfe
##

		.data
array:	.asciiz	"abcdef"
endl:	.asciiz "\n"
		.text
main:
		la		$t0, array

next_pair:
		lb		$t1, ($t0)		# load first char of a pair
		lb		$t2, 1($t0)		# load second char of a pair

		sb		$t2, ($t0)		# swap 'em
		sb		$t1, 1($t0)		# swap 'em

		beqz	$t1, str_end	# if zero then string ended
		add		$t0, 2			# move loop by two chars
		j		next_pair

str_end:
		li		$v0, 4
		la		$a0, array
		syscall

		la		$a0, endl
		syscall

end:
		li		$v0, 10
		syscall
