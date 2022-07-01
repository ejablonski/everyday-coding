export function isValid(_isbn: string): boolean {
	 _isbn = _isbn.replace(/[-]/g, '')

	if(_isbn.length !== 10) return false

	let sum: number = 0
	let mod: number = 10

	for(var i = 0; i < _isbn.length; i++) {
		let n: number

		if(i === 9 && _isbn[i] === 'X') {
			n = 10
		} else {
			n = Number(_isbn[i])
		}

		if(n < 0 || n > 10 && i !== 10) return false

		sum += n * mod
		mod--
	}

	return (sum % 11 === 0)
}
