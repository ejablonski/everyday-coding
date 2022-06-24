export function decodedValue(_vals: string[]) {
	let ret = ""

	for(let i = 0; i < 2; i++) {
		ret += getVal(_vals[i])
	}

	return Number(ret)
}

function getVal(_val: string) {
	switch(_val) {
		case "black":
			return "0"
			break
		case "brown":
			return "1"
			break
		case "red":
			return "2"
			break
		case "orange":
			return "3"
			break
		case "yellow":
			return "4"
			break
		case "green":
			return "5"
			break
		case "blue":
			return "6"
			break
		case "violet":
			return "7"
			break
		case "grey":
			return "8"
			break
		case "white":
			return "9"
			break
		default:
			return "-1"
			break
	}
}
