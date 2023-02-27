export class GradeSchool {
  _roster: { [key: number]: string[] } = {}

  roster(): { [key: number]: string[] } {
    return structuredClone(this._roster)
  }

  add(name: string, grade: number): void {
    Object.entries(this._roster).forEach(
      ([k, v]) => {
        if(v.includes(name)) {
          v.splice(v.indexOf(name), 1)
        }
      }
    )

    if(this._roster[grade] === undefined) {
      this._roster[grade] = new Array(name)
    } else {
      this._roster[grade].push(name)
      this._roster[grade].sort((a, b) => a.localeCompare(b))
    }
  }

  grade(grade: number): string[] {
    return this._roster[grade] === undefined
      ? new Array() 
      : [...this._roster[grade]]
  }
}
