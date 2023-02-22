// Latin alphabet Atbash cipher
const CIPHER: [string, string][] = [
  ['a', 'z'], ['b', 'y'], ['c', 'x'], ['d', 'w'], ['e', 'v'], ['f', 'u'],
  ['g', 't'], ['h', 's'], ['i', 'r'], ['j', 'q'], ['k', 'p'], ['l', 'o'],
  ['m', 'n'], ['n', 'm'], ['o', 'l'], ['p', 'k'], ['q', 'j'], ['r', 'i'],
  ['s', 'h'], ['t', 'g'], ['u', 'f'], ['v', 'e'], ['w', 'd'], ['x', 'c'],
  ['y', 'b'], ['z', 'a']
]

/**
 * Atbash ciphers a string. Adds space character every 5 characters for extra security.
 * @param s String to be encoded.
 * @returns Encoded string.
 */
export function encode(s: string): string {
  const PUNCT_REGEX = /[\u2000-\u206F\u2E00-\u2E7F\\'!"#$%&()*+,\-./:;<=>?@[\]^_`{|}~]/g;

  var ret: string[] = []

  s.replace(PUNCT_REGEX, '')
    .replace(/ /g, '')
    .toLowerCase()
    .split('')
    .forEach(el => {
      let found = false

      for(let pair of CIPHER) {
        if(pair[0] === el) {
          ret.push(pair[1])
          found = true
          break
        }
      }

      if(!found) ret.push(el)
    })

  for (var i = 0, a = []; i < ret.length; i++) {
    a.push(ret[i]);
    if ((i + 1) % 5 === 0) {
      a.push(' ');
      i++;
      if(ret[i]) a.push(ret[i]);
    }
  }

  ret = a

  return ret.join('').trim()
}

/**
 * Decodes Atbash encoded string.
 * @param s String to be decoded.
 * @returns Decoded string.
 */
export function decode(s: string): string {
  var ret: string[] = []

  s.replace(/ /g, '')
    .split('')
    .forEach(el => {
      let found = false

      for(let pair of CIPHER) {
        if(pair[1] === el) {
          ret.push(pair[0])
          found = true
          break
        }
      }

      if(!found) ret.push(el)
    })

  return ret.join('')
}
