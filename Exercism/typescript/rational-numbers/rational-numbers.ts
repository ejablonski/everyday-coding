/**
 * Rational numbers class.
 */
export class Rational {
  public n: number // numerator
  public d: number // denominator

  constructor(n: number, d: number) {
    this.n = n
    this.d = d
  }

  /**
   * Sums up two rational numbers.
   * 
   * r₁ + r₂ = n₁/d₁ + n₂/d₂ = (n₁ * d₂ + n₂ * d₁) / (d₁ * d₂)
   * @param r Rational number object.
   * @returns Sum of this and passed in r param Rational numbers objects.
   */
  add(r: Rational): Rational {
    const n: number = this.n * r.d + r.n * this.d
    const d: number = this.d * r.d

    return new Rational(n, d).reduce()
  }

  /**
   * Substracts two rational numbers.
   * 
   * r₁ - r₂ = n₁/d₁ - n₂/d₂ = (n₁ * d₂ - n₂ * d₁) / (d₁ * d₂)
   * @param r Rational number object.
   * @returns Substraction of this and passed in r param Rational numbers objects.
   */
  sub(r: Rational): Rational {
    const n: number = this.n * r.d - r.n * this.d
    const d: number = this.d * r.d

    console.log(`${this.n}/${this.d} - ${r.n}/${r.d} = ${n}/${d}`)

    if(n === 0) {
      return new Rational(0, 1)
    } else {
      return new Rational(n, d).reduce()
    }
  }

  /**
   * Miltiply two rational numbers.
   * 
   * r₁ * r₂ = (n₁ * n₂) / (d₁ * d₂)
   * @param r Rational number object.
   * @returns Multiplication of this and passed in r param Rational numbers object.
   */
  mul(r: Rational): Rational {
    const n: number = this.n * r.n
    const d: number = this.d * r.d

    return new Rational(n, d).reduce()
  }

  /**
   * Divide two rational numbers.
   * 
   * r₁ / r₂ = (n₁ * d₂) / (n₂ * d₁)
   * @param r Rational number object.
   * @returns Division of this and passed in r param Rational numbers object.
   */
  div(r: Rational): Rational {
    const n: number = this.n * r.d
    const d: number = r.n * this.d

    return new Rational(n, d).reduce()
  }

  /**
   * Absolute value.
   * 
   * @returns Absolute value of this Rational number object.
   */
  abs(): Rational {
    return new Rational(Math.abs(this.n), Math.abs(this.d))
  }

  /**
   * Exponentiation of a rational number where power is an integer.
   * 
   * For a positive power:
   * r^p = (n^p)/(d^p)
   * For a negative power:
   * r^p = (d^p)/(n^p), where |p|
   * @param p Power
   * @returns Rational number object risen to given power.
   */
  exprational(p: number): Rational {
    if(p > 0) {
      return new Rational(Math.pow(this.n, p), Math.pow(this.d, p)).reduce()
    } else {
      const pa: number = Math.abs(p)
      return new Rational(Math.pow(this.d, pa), Math.pow(this.n, pa)).reduce()
    }
  }

  /**
   * Exponentiation of a real number to a rational number
   * 
   * @param e Power
   */
  expreal(e: number): number {
    return Number(Math.pow(e, (this.n / this.d)).toPrecision(15))
  }

  reduce(): Rational {
    const gdc: number = this.gdc(this.n, this.d)
    const mod: number = ((this.n < 0 && this.d > 0) || (this.n > 0 && this.d < 0)) ? -1 : 1

    return new Rational(mod * (Math.abs(this.n) / gdc), Math.abs(this.d) / gdc)
  }

  private gdc(x: number, y: number): number {
    x = Math.abs(x);
    y = Math.abs(y);

    while(y) {
      let t = y;
      y = x % y;
      x = t;
    }

    return x;
  }
}
