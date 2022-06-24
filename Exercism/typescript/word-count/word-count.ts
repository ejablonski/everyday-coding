export function count(_s: string) {
	let ret = new Map()
	let arr = _s.replace(/[\n\t\r]/gm, ' ').replace(/\s+(?: )/g, ' ').trim().toLowerCase().split(' ')

	arr.forEach(it => {
		if(ret.has(it)) {
			ret.set(it, ret.get(it) + 1)
		} else {
			ret.set(it, 1)
		}
	})

	return ret
}
