type Position = readonly [number, number]

type Positions = {
  white: Position
  black: Position
}

export class QueenAttack {
  public readonly black: Position
  public readonly white: Position

  constructor({ white = [7, 3], black = [0, 3] }: Partial<Positions> = {}) {
    this.white = white
    this.black = black

    if(
      (this.white[0] < 0 || this.white[1] < 0 || this.black[0] < 0 || this.black[1] < 0) ||
      (this.white[0] > 7 || this.white[1] > 7 || this.black[0] > 7 || this.black[1] > 7)
    ) {
      throw new Error('Queen must be placed on the board')
    } else if(this.white[0] == this.black[0] && this.white[1] == this.black[1]) {
      throw new Error('Queens cannot share the same space')
    }
  }

  toString(): string {
    let b: string = ''

    for(let i: number = 0; i < 8; i++)
    {
      for(let j: number = 0; j < 8; j++)
      {
        if(this.white[0] == i && this.white[1] == j)
        {
          j != 7 ? b += 'W ' : b += 'W'
        }
        else if(this.black[0] == i && this.black[1] == j)
        {
          j != 7 ? b += 'B ' : b += 'B'
        }
        else
        {
          j != 7 ? b += '_ ' : b += '_';
        }
      }

      if(i < 7) {
        b += '\n'
      }
    }

    return b
  }

  get canAttack() {
    if(this.white[0] == this.black[0] || this.white[1] == this.black[1])
    {
      return true
    }
    else if(Math.abs(this.white[0] - this.black[0]) == Math.abs(this.white[1] - this.black[1]))
    {
      return true
    }
    else
    {
      return false
    }
  }
}
