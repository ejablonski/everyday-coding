const ALPHA_LOW = 'abcdefghijklmnopqrstuvwxyz'
const ALPHA_UPP = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

/**
 * Apply ROT algorithm on a given string with a rotation value n.
 * This function relies on f(x) = (x + n) mod 26, where x is a char
 * to be encoded, and n is a distance.
 * 
 * @param s String to be rotated
 * @param n Amount to be rotated
 * @returns Encoded string
 */
export function rotate(s: string, n: number): string {
  return s.split('').map(c => {
    if(ALPHA_LOW.indexOf(c) !== -1)
      return ALPHA_LOW[(ALPHA_LOW.indexOf(c) + n) % 26]
    if(ALPHA_UPP.indexOf(c) !== -1)
      return ALPHA_UPP[(ALPHA_UPP.indexOf(c) + n) % 26]

    return c
  }).join('')
}
