export class GradeSchool {
	_roster: { [key: number]: string[] } = {}

	roster(): { [key: number]: string[] } {
		const ret: { [key: number]: string[] } = structuredClone(this._roster)
		return ret
	}

	add(_name: string, _grade: number): void {
		Object.entries(this._roster).forEach(
			([k, v]) => {
				if(v.includes(_name)) {
					v.splice(v.indexOf(_name), 1)
				}
			}
		)

		if(this._roster[_grade] === undefined) {
			this._roster[_grade] = new Array(_name)
		} else {
			this._roster[_grade].push(_name)
			this._roster[_grade].sort((a, b) => a.localeCompare(b))
		}
	}

	grade(_grade: number): string[] {
		let ret: string[]

		this._roster[_grade] === undefined
			? ret = new Array() 
			: ret = [...this._roster[_grade]]

		return ret
	}
}
