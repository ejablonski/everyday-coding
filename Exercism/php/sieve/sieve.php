<?php
function sieve(int $_n) : array
{
	$flagArray = [false, false]; // 0 and 1 are not primes so 'false' them right away
	for ($i = 2; $i <= $_n; $i++) {
		array_push($flagArray, true);
	}

	// Eratosthenes sieve
	for ($i = 0; $i <= intval(sqrt($_n)); $i++) {
		if ($flagArray[$i] == true) { // Check only numbers that hasn't been crossed out
			$isPrime = true;

			for ($j = 2; $j <= $i; $j++) {
				if ($i % $j == 0 && $i != $j) {
					$isPrime = false;
					break;
				}
			}

			if ($isPrime) {
				$flagArray[$i] = true;
				$flagArray[$i * $i] = false;
				for ($k = 1; ($i * $i) + ($i * $k) <= $_n; $k++) {
					$flagArray[($i * $i) + ($i * $k)] = false;
				}
			} else {
				$flagArray[$i] = false;
			}
		}
	}

	$primes = [];
	for ($i = 0; $i < count($flagArray); $i++) {
		if ($flagArray[$i] == true) {
			array_push($primes, $i);
		}
	}

	return $primes;
}
