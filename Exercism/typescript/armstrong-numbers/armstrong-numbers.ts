export function isArmstrongNumber(_n: number): boolean {
  let ret: number = 0
  let s: string[] = String(_n).split("")

  for(let i: number = 0; i < s.length; i++) {
    ret += Math.pow(parseInt(s[s.length - i - 1], 10), s.length)
  }

  return _n == ret
}
