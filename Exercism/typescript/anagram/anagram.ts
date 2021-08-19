export class Anagram {
  private word: string
  private match: string[]

  constructor(_s: string) {
    this.word = _s
    this.match = []
  }

  matches(..._w: string[]): string[] {
    _w.forEach(e => {
      if(
        (this.word.toLowerCase() != e.toLowerCase()) && 
        (this.word.toLowerCase().split('').sort().toString() == e.toLowerCase().split('').sort().toString())
      ) {
        this.match.push(e)
      }
    });

    return this.match
  }
}
