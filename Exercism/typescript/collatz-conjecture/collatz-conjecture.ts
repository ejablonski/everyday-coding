export function steps(_n: number): number {
	if(_n <= 0)	{
		throw new Error("Only positive numbers are allowed")
	}

	let step: number = 0

	while(_n != 1) {
		if(_n % 2 == 0) {
			_n /= 2
			step++
		} else {
			_n = _n * 3 + 1
			step++
		}
	}

	return step
}
