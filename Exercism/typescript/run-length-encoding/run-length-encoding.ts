export function encode(s: string): string {
  var e: string[] = ['']

  s.match(/(.)\1*/g)?.forEach((substr: string) => {
    e.push(`${substr.length === 1 ? '' : substr.length}${substr[0]}`)
  })

  return e.join('')
}

export function decode(s: string): string {
  var d: string[] = ['']

  for(let i = 0; i < s.length; i++) {
    if(!isNumber(s[i])) {
      d.push(s[i])
    } else {
      // find next non digit character...
      for(let j = i; j < s.length; j++) {
        if(!isNumber(s[j])) {
          d.push(s[j]?.repeat(Number(s.slice(i, j))))
          i = j
          break
        }
      }
    }
  }

  return d.join('')
}

function isNumber(c: string): boolean {
  return (c >= '0' && c <= '9' ? true : false)
}
