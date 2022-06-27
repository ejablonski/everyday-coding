export class Series {
	str: number[] = []

	constructor(_series: string) {
		let s: string[] = [..._series]

		s.forEach(c =>
			this.str.push(parseInt(c, 10))
		)
	}

	slices(_n: number): number[][] {
		if(this.str.length === 0) {
			throw new Error("series cannot be empty")
		}
		if(_n === 0) {
			throw new Error("slice length cannot be zero")
		}
		if(this.str.length < _n) {
			throw new Error("slice length cannot be greater than series length")
		}
		if(_n < 0) {
			throw new Error("slice length cannot be negative")
		}

		let r: number[][] = []

		for(var i: number = 0; i <= this.str.length - _n; i++) {
			let temp: number[] = []

			for(var j = 0; j < _n; j++) {
				temp.push(this.str[i + j])
			}

			r.push(temp);
		}

		return r;
	}
}
