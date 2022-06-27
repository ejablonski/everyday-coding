export function commands(_n: number) {
	if(_n == 0)
		return []

	let ret: string[] = []
	let rev: boolean = false
	let n: number = parseInt(_n.toString(2), 10)

	while(n >= 1) {
		if(n - 10000 >= 0) {
			rev = true
			n -= 10000
		} else if(n - 1000 >= 0) {
			ret.push("jump")
			n -= 1000
		} else if(n - 100 >= 0) {
			ret.push("close your eyes")
			n -= 100
		} else if(n - 10 >= 0) {
			ret.push("double blink")
			n -= 10
		} else if(n - 1 >= 0) {
			ret.push("wink")
			n -= 1
		}
	}

	if(!rev)
		ret.reverse()

	return ret;
}
