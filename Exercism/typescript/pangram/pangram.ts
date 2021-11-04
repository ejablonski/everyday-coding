export function isPangram(_s: string): boolean {
  return [..."abcdefghijklmnopqrstuvwxyz"].every(c => _s.toLowerCase().includes(c))
}
