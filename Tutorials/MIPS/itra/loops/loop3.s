##
## replace all occurances of 'a' with 'A'
##

		.data
array:	.asciiz	"abbbaabbbababab\n"
		.text
main:
		la		$t2, array
		li		$t1, 'A'

next_char:
		lb		$t0, ($t2)
		beqz	$t0, str_end
		bne		$t0, 'a', nota
		sb		$t1, ($t2)		# store upper case A

nota:
		add		$t2, 1
		j		next_char

str_end:
		li		$v0, 4
		la		$a0, array
		syscall

end:
		li		$v0, 10
		syscall
