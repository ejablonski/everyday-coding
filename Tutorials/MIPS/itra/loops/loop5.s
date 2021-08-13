##
## replace every second char with 'X'
## that is the first, third, fifth etc.
##
## answer XbXdXf
##

		.data
array:	.asciiz	"abcdef"
endl:	.asciiz "\n"
		.text

main:
		la		$t2, array
		li		$t1, 'X'

next_pair:
		lb		$t0, ($t2)
		beqz	$t0, str_end
		sb		$t1, ($t2)
		add		$t2, 2
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
