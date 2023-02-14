export function accumulate<T>(list: T[], accumulator: (args: T) => T | T[]): T[] {
  let ret: any[] = []

  list.forEach(e => {
    ret.push(accumulator(e))
  })

  return ret
}
