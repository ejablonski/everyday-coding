var names: string[] = []

export class Robot {
  public name = ''

  constructor() {
    this.resetName()
  }

  public static releaseNames(): void { names = [] }

  public resetName(): void {
    let f = true
    while(f) {
      let s: string = this.createName()
      if(!names.includes(s)) {
        this.name = s
        names.push(this.name)
        f = false
      }
    }
  }

  private createName(): string {
    const ALPHA = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    const NUMS = '0123456789'

    let aa: string[] = Array.from({ length: 2 })
    let nnn: string[] = Array.from({ length: 3 })

    aa = aa.map(() => {
      return ALPHA[Math.floor(Math.random() * ALPHA.length)]
    })

    nnn = nnn.map(() => {
      return NUMS[(Math.floor(Math.random() * NUMS.length))]
    })

    return `${aa.join('')}${nnn.join('')}`
  }
}
