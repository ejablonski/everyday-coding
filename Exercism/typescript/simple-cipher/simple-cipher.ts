export class SimpleCipher {
  public key: string
  private alphabet = 'abcdefghijklmnopqrstuvwxyz'
  private charOffset = 'a'.charCodeAt(0)

  constructor(key?: string) {
    this.key = key || this.generateKey(100)
  }

  encode(s: string): string {
    return this.shift(s, true)
  }

  decode(s: string): string {
    return this.shift(s, false)
  }

  /**
   * Substitution cipher algorithm.
   * https://www.khanacademy.org/computing/computer-science/cryptography/ciphers/a/shift-cipher
   * @param s String to be encoded or decoded.
   * @param f Direction of the shift. True will encode and false will decode.
   * @returns Encoded or decoded string.
   */
  private shift(s: string, f: boolean = true): string {
    let ret = ''
    let deranged = this.key.length < 26 ? this.generateDerangedAlphabet(this.key) : this.key

    for(let i = 0; i < s.length; i++) {
      const K = deranged[i].charCodeAt(0) - this.charOffset
      const X = s[i].charCodeAt(0) - this.charOffset
      const Y = f ? (X + K) % 26 : (X - K) % 26
      ret += Y < 0 ? this.alphabet[Y + 26] : this.alphabet[Y]
    }

    return ret
  }

  /**
   * Generates new deranged alphabet for keys shorter than string to be shifted.
   * @param k Key.
   */
  private generateDerangedAlphabet(k: string): string {
    let newKey = ''

    for(let i = 0; i < Math.ceil(100 / k.length); i++) {
      newKey += k
    }

    return newKey
  }

  /**
   * Generates new string key.
   * @param l Length of the key.
   * @returns String with a new key.
   */
  private generateKey(l: number): string {
    return Array.from({ length: l }, () => this.alphabet[(Math.floor(Math.random() * this.alphabet.length))]).join('')
  }
}
