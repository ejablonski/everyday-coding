export function isPangram(s: string): boolean {
  return [...'abcdefghijklmnopqrstuvwxyz'].every(c => s.toLowerCase().includes(c))
}
