export function convert(_n: number): string {
  let rain: string = ""

  if(_n % 3 == 0)
  {
    rain += "Pling"
  }

  if(_n % 5 == 0)
  {
    rain += "Plang"
  }

  if(_n % 7 == 0)
  {
    rain += "Plong"
  }

  if(_n % 3 != 0 && _n % 5 != 0 && _n % 7 != 0)
  {
    rain += _n
  }

  return rain
}
