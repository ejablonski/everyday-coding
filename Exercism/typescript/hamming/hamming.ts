export function compute(a: string, b: string): number {
  if(a.length != b.length) {
    throw new Error('DNA strands must be of equal length.')
  }

  let n: number = 0;
  for(let i: number = 0; i < a.length; i++)
  {
    if(a[i] != b[i]) {
      n++
    }
  }

  return n
}
