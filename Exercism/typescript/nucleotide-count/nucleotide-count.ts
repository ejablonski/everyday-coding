export function nucleotideCounts(_s: string) {
  let dna = {
      'A': 0,
      'C': 0,
      'G': 0,
      'T': 0
    }

  _s.split("").forEach(e => {
    switch(e) {
      case 'A':
        dna['A']++
        break
      case 'C':
        dna['C']++
       break
      case 'G':
        dna['G']++
       break
      case 'T':
        dna['T']++
        break
      default:
        throw new Error('Invalid nucleotide in strand')
    }
  })

  return dna
}
