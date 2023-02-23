const ALPHABET: string = 'abcdefghijklmnopqrstuvwxyz0123456789'
const CIPHER: string = 'zyxwvutsrqponmlkjihgfedcba0123456789'
const PUNCT_AND_NUMS_REGEX = /[\u2000-\u206F\u2E00-\u2E7F\\'!"#$%&()*+,\-./:;<=>?@[\]^_`{|}~]/g;

/**
 * Atbash ciphers a string. Adds space character every 5 characters for extra security.
 * @param s String to be encoded.
 * @returns Encoded string.
 */
export function encode(s: string): string {
  return atbash(s, ALPHABET, CIPHER).replace(/(.{5})/g, '$1 ').trim()
}

/**
 * Decodes Atbash encoded string.
 * @param s String to be decoded.
 * @returns Decoded string.
 */
export function decode(s: string): string {
  return atbash(s, CIPHER, ALPHABET)
}
/**
 * Map string characters from one alphabet to another.
 * @param s String to be mapped.
 * @param from Alphabet that string s is written in.
 * @param to Alphabet to map to.
 * @returns Mapped string.
 */
function atbash(s: string, from: string, to: string): string {
  return s
    .replace(PUNCT_AND_NUMS_REGEX, '')
    .toLowerCase()
    .split('')
    .map((el) => {
      return to[from.indexOf(el)]
    })
    .join('')
}
