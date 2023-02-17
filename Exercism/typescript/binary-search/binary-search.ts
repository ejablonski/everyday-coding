/**
 * Binary search.
 * @param h Array to search in. Need to be sorted!
 * @param n Value to be found.
 * @returns Index of a found value.
 * @throws Error if value is not found.
 */
export function find(h: number[], n: number): number {
  let l: number = 0
  let r: number = h.length - 1

  while(l <= r) {
    const M = Math.floor((l + r) / 2)
    if(h[M] < n) {
      l = M + 1
    } else if(h[M] > n) {
      r = M - 1
    } else {
      return M
    }
  }

  throw new Error('Value not in array')
}
