export function score(_word?: string): number {
	let s: Map<string, number> = new Map([['A', 1], ['B', 3], ['C', 3], ['D', 2],
										['E', 1], ['F', 4], ['G', 2], ['H', 4],
										['I', 1], ['J', 8], ['K', 5], ['L', 1],
										['M', 3], ['N', 1], ['O', 1], ['P', 3],
										['R', 1], ['Q', 10], ['S', 1], ['T', 1],
										['U', 1], ['W', 4], ['V', 4], ['X', 8],
										['Y', 4], ['Z', 10]])

	let pts: number = 0
	let tmp: string = _word ?? ""
	let arr: string[] = [...(tmp.toUpperCase())] ?? []

	arr.forEach(c => 
		pts += s.get(c) ?? 0
	)

	return pts;
}
