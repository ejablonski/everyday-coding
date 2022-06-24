export function isLeap(_y: number) : boolean {
  if(_y % 4 == 0 && _y % 100 != 0) {
    return true;
  } else {
    if(_y % 400 == 0) {
      return true;
    } else {
      return false;
    }
  }
}

