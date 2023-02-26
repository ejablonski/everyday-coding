export function isLeap(y: number) : boolean {
  return (y % 4 === 0 && y % 100 !== 0) ? true : (y % 400 === 0)
}
