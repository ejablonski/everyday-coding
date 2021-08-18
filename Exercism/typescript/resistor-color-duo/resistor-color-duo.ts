export class ResistorColor {
  private colors: string[]
  private values: Map<string, number> = new Map([
    ['black', 0],
    ['brown', 1],
    ['red', 2],
    ['orange', 3],
    ['yellow', 4],
    ['green', 5],
    ['blue', 6],
    ['violet', 7],
    ['grey', 8],
    ['white', 9]
  ])

  constructor(colors: string[]) {
    this.colors = colors

    if(this.colors.length < 2) {
      throw new Error('At least two colors need to be present')
    }
  }

  value(): number {
    let i: number = 0
    let j: number = 1
    let v: number = 0

    for(i; i <= 1; i++) {
      v += (this.values.get(this.colors[i])! * Math.pow(10, j))
      j--
    }

    return v
  }
}
