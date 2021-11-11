export function primes(_n: number): number[] {
  // 0 and 1 are not primes so 'false' them right away
  let primes_b: boolean[] = [false, false]

  for(let i: number = 2; i <= _n; i++) {
    primes_b.push(true);
  }

  // Eratosthenes sieve
  for(let i: number = 0; i <= Math.sqrt(_n); i++) {
      // Check only numbers that hasn't been crossed out
      if(primes_b[i] == true) {
          // Check if current i is a prime
          let is_prime: boolean = true;

          for(let j: number = 2; j <= i; j++) {
              if(i % j == 0 && i != j) {
                  is_prime = false
                  break
              }
          }

          if(is_prime) {
              primes_b[i] = true
              primes_b[i * i] = false

              for(let k: number = 1; (i * i) + (i * k) <= _n; k++) {
                  primes_b[(i * i) + (i * k)] = false
              }
          } else {
              primes_b[i] = false
          }
      }
  }

  let primes_l: number[] = []

  for(let i: number = 0; i < primes_b.length; i++)
  {
      if(primes_b[i] == true)
          primes_l.push(i)
  }

  return primes_l
}
