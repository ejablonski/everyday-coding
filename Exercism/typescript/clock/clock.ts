export class Clock {
	h: number
	m: number

	constructor(_hour: number, _minute?: number) {
		this.h = _hour
		this.m = _minute === undefined ? 0 : _minute
	}

	public toString(): string {
		let h = 0
		let m = this.m + this.h * 60

		if(m < 0) {
			h = 24

			while(m < 0) {
				h--
				m += 60

				if(h == 0)
					h = 24
			}
		} else {
			while(m >= 60) {
				h++
				m -= 60

				if(h == 24)
					h = 0
			}
		}

		if(h == 24)
			h = 0

		let hours = h.toString()
		let minutes = m.toString()

		if(h < 10)
			hours = "0" + hours

		if(m < 10)
			minutes = "0" + minutes

		return hours + ":" + minutes
	}

	public plus(_minutes: number): Clock {
		this.m += _minutes
		return this
	}

	public minus(_minutes: number): Clock {
		this.m -= _minutes
		return this
	}

	public equals(_other: Clock): boolean {
		return (this.toString() === _other.toString())
	}
}
