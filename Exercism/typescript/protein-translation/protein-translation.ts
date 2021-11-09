export function translate(_s: string): string[] {
  const dict = new Map([
    ["Methionine", ["AUG"]],
    ["Phenylalanine", ["UUU", "UUC"]],
    ["Leucine", ["UUA", "UUG"]],
    ["Serine", ["UCU", "UCC", "UCA", "UCG"]],
    ["Tyrosine", ["UAU", "UAC"]],
    ["Cysteine", ["UGU", "UGC"]],
    ["Tryptophan", ["UGG"]],
    ["STOP", ["UAA", "UAG", "UGA"]]
  ])

  let trans: string[] = []
  let seq: string[] = []

  for(let i: number = 0; i < _s.length - 2; i += 3) {
    seq.push(_s.substr(i, 3))
  }

  for(let i: number = 0; i < seq.length; i++) {
    dict.forEach((value, key) => {
      for(const elem of value) {
        if(seq[i] == elem) {
          if(key != "STOP") {
            trans.push(key)
          } else {
            i = seq.length;
            break
          }
        }
      }
    })
  }

  return trans;
}
