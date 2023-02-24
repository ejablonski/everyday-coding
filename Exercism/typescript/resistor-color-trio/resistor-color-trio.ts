const values = ['black', 'brown', 'red', 'orange', 'yellow', 'green', 'blue', 'violet', 'grey', 'white']
const prefixes = ['', 'kilo', 'mega', 'giga']

export function decodedResistorValue(vals: string[]): string {
  return reduceToMetric(Number(vals.map((e, i) => {
    return (i < 2 ? values.indexOf(e) : null)
  }).join('')) * (10 ** values.indexOf(vals[2])))
}

function reduceToMetric(n: number): string {
  let p = 0

  while(n > 1000) {
    n /= 1000
    p++
  }

  return `${n.toString()} ${prefixes[p]}ohms`
}
