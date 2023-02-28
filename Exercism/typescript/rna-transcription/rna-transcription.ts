const DNA = ['G', 'C', 'T', 'A']
const RNA = ['C', 'G', 'A', 'U']

export function toRna(dna: string): string {
  return dna.split('').map(el => {
    let i = DNA.indexOf(el)

    if(i < 0 || i > 4) {
      throw new Error("Invalid input DNA.")
    } else {
      return RNA[i]
    }
  }).join('')
}
