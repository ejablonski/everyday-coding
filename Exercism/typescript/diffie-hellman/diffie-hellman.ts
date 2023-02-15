export class DiffieHellman {
  private sieve: boolean[] = this.primes(9999)

  constructor(private p: number, private g: number) {
    if(this.sieve[this.p] !== true || this.sieve[this.g] !== true) {
      throw Error('Arguments not a prime numbers')
    }
  }

  public getPublicKey(privateKey: number): number {
    if(privateKey <= 1 || privateKey >= this.p) {
      throw new Error('Invalid argument')
    } else {
      return (this.g ** privateKey) % this.p
    }
  }

  public getSecret(theirPublicKey: number, myPrivateKey: number): number {
    return (theirPublicKey ** myPrivateKey) % this.p
  }

  primes(_n: number): boolean[] {
    // 0 and 1 are not primes so 'false' them right away
    let primes_b: boolean[] = [false, false]

    for(let i = 2; i <= _n; i++) {
      primes_b.push(true)
    }

    // Eratosthenes sieve
    for(let i = 2; i <= Math.trunc(Math.sqrt(_n)); i++) {
      if(primes_b[i] === true) {
        let is_prime = true

        for(var j = 2; j <= i; j++) {
          if(i % j === 0 && i !== j) {
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

    return primes_b
  }
}
