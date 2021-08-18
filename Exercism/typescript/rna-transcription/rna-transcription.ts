class Transcriptor {
  toRna(_rna: string): string {
    let transcription = ''

    for(let i = 0; i < _rna.length; i++) {
      if(_rna[i] == 'G') {
          transcription += 'C'
      } else if(_rna[i] == 'C') {
          transcription += 'G'
      } else if(_rna[i] == 'T') {
          transcription += 'A'
      } else if(_rna[i] == 'A') {
          transcription += 'U'
      } else {
        throw new Error("Invalid input DNA.")
      }
    }

    return transcription
  }
}

export default Transcriptor
