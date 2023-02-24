const values = ['black', 'brown', 'red', 'orange', 'yellow', 'green', 'blue', 'violet', 'grey', 'white']

export function decodedValue(v: string[]): number {
  return Number(v.map((e) => { return values.indexOf(e) }).slice(0, 2).join(''))
}
