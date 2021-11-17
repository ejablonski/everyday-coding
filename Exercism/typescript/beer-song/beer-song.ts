export function verse(_n: number): string {
  let v: string

  if(_n == 0) {
    v = "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n"
  } else if(_n == 1) {
    v = "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n"
  } else {
    v = _n + " bottles of beer on the wall, " + _n

    if(_n > 1) {
      v += " bottles"
    } else {
      v += " bottle"
    }

    v += " of beer.\nTake one down and pass it around, " + (_n - 1)

    if(_n - 1 > 1) {
      v += " bottles"
    } else {
      v += " bottle"
    }

    v += " of beer on the wall.\n"
  }

  return v
}

export function sing(
  _s?: number,
  _e?: number
): string {
  let s: string = ""

  if(_s == undefined) {
    _s = 99
  }

  if(_e == undefined) {
    _e = 0
  }

  // Assumes that _s > _e
  for(let i: number = _s; i >= _e; i--) {
    s += verse(i)

    if(i != _e) {
      s += "\n"
    }
  }

  return s;
}
