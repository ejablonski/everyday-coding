export function clean(_pn: string): string {
	let pn = _pn.match(/\d+/g)?.filter(i => i.length > 2).join('') ?? ''
	if(pn.length === 11 && pn[0] !== '1') throw new Error('11 digits must start with 1')
	if(pn.length === 11) pn = pn.substring(1, pn.length)
	if(/[`!@#$%^&*_\=\[\]{};':"\\|,<>\/?~]/.test(_pn)) throw new Error('Punctuations not permitted')
	if(/[a-z]/i.test(_pn)) throw new Error('Letters not permitted')
	if(pn.length > 11) throw new Error('More than 11 digits')
	if(pn.length < 10) throw new Error('Incorrect number of digits')
	if(pn[0] === '0') throw new Error('Area code cannot start with zero')
	if(pn[0] === '1') throw new Error('Area code cannot start with one')
	if(pn[3] === '0') throw new Error('Exchange code cannot start with zero')
	if(pn[3] === '1') throw new Error('Exchange code cannot start with one')
	return pn
}
