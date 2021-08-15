##
## ask user for decimal number
## convert to hex, print the result
##
## t0 - count for 8 digits i word
## t1 - each hex digit in turn
## t2 - number read in
## t3 - address of area used to set up answer string
##

		.data
result:	.space	8
		.asciiz	"\n"
prompt:	.asciiz "Enter decimal number: "
ans:	.asciiz "Hexadecimal is "
		.text

main:
		li		$v0, 4
		la		$a0, prompt
		syscall

		li		$v0, 5
		syscall
		move	$t2, $v0		# t2 holds the hex number

		li		$v0, 4
		la		$a0, ans
		syscall

		li		$t0, 8			# eight hex digit in word
		la		$t3, result		# answet string set up here

loop:
		rol		$t2, $t2, 4		# start with leftmost digit
		and		$t1, $t2, 0xf	# mask one digit
		ble		$t1, 9, print	# check if 0 to 9
		add		$t1, $t1, 7		# 7 chars between '9' and 'A'

print:
		add		$t1, $t1, 48
		sb		$t1, ($t3)
		add		$t3, $t3, 1
		add		$t0, $t0, -1
		bnez	$t0, loop

		li		$v0, 4
		la		$a0, result
		syscall

		li		$v0, 10
		syscall
