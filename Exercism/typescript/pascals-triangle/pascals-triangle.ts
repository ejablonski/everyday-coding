export class Triangle {
  triangle: Array<number[]> = []

  constructor(_n: number) {
    for(let i: number = 0; i < _n; ++i) {
      let row: number[] = []

      for(let j: number = 0; j < i + 1; j++) {
        if(i == 0 || j == 0 || j == i) {
          row.push(1)
        } else {
          // pascals formula - https://mathworld.wolfram.com/PascalsFormula.html
          row.push(this.factorial(i) / (this.factorial(j) * this.factorial(i - j)))
        }
      }

      this.triangle.push(row)
    }
  }

  get rows() {
    return this.triangle
  }

  get lastRow() {
    return this.triangle[this.triangle.length - 1]
  }

  factorial(_n: number): number
  {
    if(_n == 0) {
      return 1
    }

    return _n * this.factorial(_n - 1)
  }
}
