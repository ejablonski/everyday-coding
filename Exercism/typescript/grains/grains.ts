export const square = (_n: number): bigint => {
  if(_n < 1 || _n > 64) {
    throw new Error("no :<")
  }

  let current_square: bigint = 1n

  for(let i: number = 1; i < _n; ++i) {
    let prev_square: bigint = current_square
    current_square = prev_square * 2n
  }

  return current_square;
}

export const total = (): bigint => {
  let result: bigint = 0n

  for(let i: number = 1; i <= 64; ++i) {
    let tmp_a: bigint = result
    let tmp_b: bigint = square(i)
    result = tmp_a + tmp_b
  }

  return result
}
