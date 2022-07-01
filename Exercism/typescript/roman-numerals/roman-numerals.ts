export const toRoman = (_n: number): string => {
	const values: {[key: string]: number} = {
		M: 1000, CM: 900, D: 500, CD: 400, C: 100, XC: 90, L: 50, XL: 40,
		X: 10, IX: 9, V: 5, IV: 4, I: 1
	}

	const orders: string[] = [
		'M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'
	]

	let roman = ''

	for(const symbol of orders) {
		while(_n >= values[symbol]) {
			roman += symbol
			_n -= values[symbol]
		}
	}

	return roman
}
