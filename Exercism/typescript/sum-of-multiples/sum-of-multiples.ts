export function sum(_multiples: number[], _n: number): number {
  let toSum: number[] = []

  for(let i: number = 1; i < _n; i++) {
    _multiples.forEach((e) => {
      if(i % e == 0) {
        if(!toSum.includes(i)) {
          toSum.push(i)
        }
      }
    })
  }

  let sum: number = 0

  toSum.forEach((e) => { sum += e })

  return sum
}
