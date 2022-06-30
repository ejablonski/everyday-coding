export function valid(_s: string): boolean {
	_s = _s.replace(/\s+/g, '').replace('-', '')

	if(_s.length <= 1)
		return false

	let sum: number = 0

	for(let i = _s.length - 1; i >= 0; i--) {
		let n: number = parseInt(_s[i])
		if(i % 2) {  
			n *= 2
			if(n > 9) {
			  n -= 9
			}
		}
		sum += n
	}

	return (sum % 10 == 0)
}
