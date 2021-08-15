##
## count the occurrences of a specific character in str
##
## t0 - holds each byte from string
## t1 - index into array
## t2 - count of occurences
## t3 - holds the character to count
##
		.data
str:	.asciiz	"abceebceebeebbacacb"
char:	.asciiz	"e"
ans:	.asciiz	"count is "
endl:	.asciiz	"\n"
		.text

main:
		li		$t1, 0			# t1 will be the arr index
		li		$t2, 0			# t2 will be the counter
		lb		$t3, char		# t3 will hold the char

loop:
		lb		$t0, str($t1)	# fetch next char
		beqz	$t0, str_end	# if it's a null, exit loop
		bne		$t0, $t3, con	# not null; same as char?
		add		$t2, $t2, 1		# counter++

con:
		add		$t1, $t1, 1		# index++
		j		loop

str_end:
		li		$v0, 4
		la		$a0, ans
		syscall

		li		$v0, 1
		move	$a0, $t2
		syscall

		li		$v0, 4
		la		$a0, endl
		syscall

end:
		li		$v0, 10
		syscall
