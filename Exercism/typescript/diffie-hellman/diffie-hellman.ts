export class DiffieHellman {
  constructor(private p: number, private g: number) {
    if(this.isPrime(this.p) !== true || this.isPrime(this.g) !== true) {
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

  private isPrime(n: number): boolean {
    let is_prime = true

      for(let i = 2; i < n; i++) {
        if(n % i === 0) {
          is_prime = false
          break
        }
      }

    return is_prime
  }
}
