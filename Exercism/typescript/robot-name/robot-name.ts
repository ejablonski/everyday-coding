export class Robot {
	_name: string = ""
	_names: string[] = []

	constructor() {
		this._name = this.createName()
		this._names.push(this.name)
	}

	public get name(): string {
		return this._name
	}

	public resetName(): void {
		let f: boolean = true
		while(f) {
			let s: string = this.createName()
			if(!this._names.includes(s)) {
				this._name = s
				this._names.push(this.name)
				f = false
			}
		}
	}

	public static releaseNames(): void {
	}

	private createName(): string {
		let AA: string = Math.random().toString(36).replace(/[^a-z]+/g, '').substr(0, 2).toUpperCase()
		let BBB: string = (Math.floor(Math.random() * 999)).toString()

		if(BBB.length < 3) {
			let fill: string = ""
			for(let i = 0; i < 3 - BBB.length; i++) {
				fill += "0"
			}
			fill += BBB
			BBB = fill
		}

		return AA + BBB
	}
}
