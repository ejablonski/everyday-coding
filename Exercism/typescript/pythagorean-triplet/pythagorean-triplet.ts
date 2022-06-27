type Options = {
	minFactor?: number
	maxFactor?: number
	sum: number
}

export function triplets({ minFactor, maxFactor, sum }: Options): Triplet[] {
    let min: number = minFactor || 1
    let max: number = maxFactor || sum
    let ret = []

    for(let a = min; a <= max; a++) {
        for(let b = a; b <= max; b++) {
            let c = sum - a - b;
            if(a * a + b * b === c * c && c <= max) {
                ret.push(new Triplet(a, b, c))
            }
        }
    }
    return ret
}

class Triplet {
    private a: number
	private b: number
	private c: number

    constructor(a: number, b: number, c: number) {
        this.a = a
        this.b = b
        this.c = c
    }

    toArray(): [number, number, number] {
        return [this.a, this.b, this.c]
    }
}
