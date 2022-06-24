export function decodedResistorValue(_vals: string[]) {
	let ret = ""

	for(let i = 0; i < _vals.length - 1; i++) {
		ret += getVal(_vals[i])
	}

	for(let j = 0; j < Number(getVal(_vals[_vals.length - 1])); j++) {
		ret += "0"
	}

	if(Number(ret) > 1000) {
		ret = (Number(ret) / 1000).toString()
		ret += " kiloohms"
	} else {
		ret += " ohms"
	}

	return ret
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
