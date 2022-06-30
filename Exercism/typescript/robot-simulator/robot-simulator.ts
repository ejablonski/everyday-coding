export class InvalidInputError extends Error {
	constructor(message: string) {
		super()
		this.message = message || 'Invalid Input'
	}
}

type Direction = 'north' | 'east' | 'south' | 'west'
type Coordinates = [number, number]

export class Robot {
	coords: Coordinates = [0, 0]
	direction: Direction = 'north'

	get bearing(): Direction {
		return this.direction
	}

	get coordinates(): Coordinates {
		return this.coords
	}

	place(_o: { x: number; y: number; direction: string }) {
		this.coords = [_o.x, _o.y]
		switch(_o.direction) {
		case 'north':
			this.direction = 'north'
			break
		case 'east':
			this.direction = 'east'
			break
		case 'south':
			this.direction = 'south'
			break
		case 'west':
			this.direction = 'west'
			break
		default:
			throw new InvalidInputError('')
		}
	}

	evaluate(_ins: string) {
		_ins.split('').forEach(it => {
			switch(it) {
			case 'L':
				this.turn_left()
				break
			case 'R':
				this.turn_right()
				break
			case 'A':
				this.advance()
				break
			default:
				break
			}
		})
	}

	private turn_right() {
		switch(this.direction) {
		case 'north':
			this.direction = 'east'
			break
		case 'east':
			this.direction = 'south'
			break
		case 'south':
			this.direction = 'west'
			break
		case 'west':
			this.direction = 'north'
			break
		default:
			break
		}
	}

	private turn_left() {
		switch(this.direction) {
		case 'north':
			this.direction = 'west'
			break
		case 'east':
			this.direction = 'north'
			break
		case 'south':
			this.direction = 'east'
			break
		case 'west':
			this.direction = 'south'
			break
		default:
			break
		}
	}

	private advance() {
		switch(this.bearing) {
		case 'north':
			this.coords[1]++;
			break
		case 'east':
			this.coords[0]++;
			break
		case 'south':
			this.coords[1]--;
			break
		case 'west':
			this.coords[0]--;
			break
		default:
			break
		}
	}
}
