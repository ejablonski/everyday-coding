export class Matrix {
  constructor(public s: string) {}

  get rows(): number[][] {
    return this.s
      .split('\n')
      .map(row => row
        .split(' ')
        .map(char => Number(char))
      )
  }

  get columns(): number[][] {
    let ret: number[][] = []
    let row = this.rows

    for(let i = 0; i < row[0].length; i++) {
      ret[i] = row.map(x => x[i])
    }

    return ret
  }
}
