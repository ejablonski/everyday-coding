export function transform(_in: {[key: string]: string[]}): {[key: string]: number} {
    const res: {[key: string]: number} = {}

    for (const key in _in) {
        for (const char of _in[key]) {
            res[char.toLowerCase()] = parseInt(key, 10)
        }
    }

    return res
}
