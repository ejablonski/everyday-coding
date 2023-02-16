export function classify(n: number): string {
  if(n <= 0) throw new Error('Classification is only possible for natural numbers.')

  let aliquot = 0

  for(let i = 1; i < n; i++) {
    if(n % i === 0) {
      aliquot += i
    }
  }

  if(aliquot === n) return 'perfect'
  if(aliquot > n) return 'abundant'

  return 'deficient' // aliqout < n
}
