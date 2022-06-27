export function calculatePrimeFactors(_n: number) {
	let pri: number[] = primes(900000)
	let ret: number[] = []

	let divisor_index: number = 0

	while(_n > 1) {
		if(_n % pri[divisor_index] == 0) {
			ret.push(pri[divisor_index])
			_n /= pri[divisor_index]
		} else {
			divisor_index++
		}
	}

	return ret
}

function primes(_n: number): number[] {
	// 0 and 1 are not primes so 'false' them right away
	let primes_b: boolean[] = [false, false]

	for(var i = 2; i <= _n; i++) {
		primes_b.push(true)
	}

	// Eratosthenes sieve
	for(var i = 2; i <= Math.trunc(Math.sqrt(_n)); i++) {
		if(primes_b[i] === true) {
			let is_prime: boolean = true

			for(var j = 2; j <= i; j++) {
				if(i % j == 0 && i != j) {
					is_prime = false
					break
				}
			}

			if(is_prime) {
				primes_b[i] = true
				primes_b[i * i] = false

				for(var k = 1; (i * i) + (i * k) <= _n; k++) {
					primes_b[(i * i) + (i * k)] = false
				}
			} else {
				primes_b[i] = false
			}
		}
	}

	let primes_l: number[] = []

	for(var i = 0; i < primes_b.length; i++) {
		if(primes_b[i] == true)
			primes_l.push(i)
	}

	return primes_l
}
