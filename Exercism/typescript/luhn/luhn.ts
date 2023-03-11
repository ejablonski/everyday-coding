export function valid(str: string): boolean {
  str = str.replace(/\s+/g, '').replace('-', '')

  if(str.length <= 1) return false

  let sum: number = 0
  let j = 1

  for(let i = str.length - 1; i >= 0; i--) {
    let n: number = Number(str[i])

    if(j % 2 === 0) {
      n *= 2

      if(n > 9) {
        n -= 9
      }
    }

    sum += n
    j++
  }

  return (sum % 10 == 0)
}
