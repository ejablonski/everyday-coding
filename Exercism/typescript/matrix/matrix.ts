export class Matrix {
	s: string

	constructor(_s: string) {
		this.s = _s
	}

	get rows(): number[][] {
		let ret: number[][] = []
		let row: string[] = this.s.split('\n')

		for(let i = 0; i < row.length; i++) {
			ret.push(row[i].split(' ').map(x => +x))
		}

		return ret
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
