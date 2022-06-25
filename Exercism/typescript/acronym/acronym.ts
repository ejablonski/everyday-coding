export function parse(_s: string): string {
	let ret: string = ""

	for(let i = 1; i < _s.length; i++) {
		if(_s[i] === '-') {
			_s = _s.substring(0, i - 1) + ' ' + _s.substring(i + 1)
		}

		if(_s[i] === _s[i].toUpperCase() && _s[i - 1] === _s[i - 1].toLowerCase() && _s[i - 1] !== ' ' && _s[i] !== ' ' && _s[i] !== ',') {
			_s = _s.slice(0, i) + ' ' + _s.slice(i)
			i++
		}

		if(_s[i] === ':') {
			return _s.substring(0, i)
		}
	}

	_s.split(' ').forEach(word => {
		ret += word[0]
	})

	return ret.toUpperCase()
}
