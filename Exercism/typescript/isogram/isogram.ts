export function isIsogram(_s: string): boolean {
	return !/(\w).*\1/i.test(_s)
}
