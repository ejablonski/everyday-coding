export default class Squares {
  squareOfSum: number = 0
  sumOfSquares: number = 0
  difference: number = 0

  constructor(_n: number) {
    for(let i = 1; i <= _n; i++) {
      this.squareOfSum += i
      this.sumOfSquares += i * i;
    }

    this.squareOfSum *= this.squareOfSum
    this.difference = this.squareOfSum - this.sumOfSquares
  }
}
