export const COLORS = ['black', 'brown', 'red', 'orange', 'yellow', 'green', 'blue', 'violet', 'grey', 'white']

export function colorCode(c: string): number {
  return COLORS.indexOf(c)
}
