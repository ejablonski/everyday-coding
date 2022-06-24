export function age(_planet: string, _seconds: number): number {
  const EARTH: number    = 31557600;
  const MERCURY: number  = 7600544;
  const VENUS: number    = 19414149;
  const MARS: number     = 59354033;
  const JUPITER: number  = 374355659;
  const SATURN: number   = 929292363;
  const URANUS: number   = 2651370019;
  const NEPTUNE: number  = 5200418560;

  switch(_planet) {
    case 'earth':
      return Math.round((_seconds / EARTH + Number.EPSILON) * 100) / 100;
    case 'mercury':
      return Math.round((_seconds / MERCURY + Number.EPSILON) * 100) / 100;
    case 'venus':
      return Math.round((_seconds / VENUS + Number.EPSILON) * 100) / 100;
    case 'mars':
      return Math.round((_seconds / MARS + Number.EPSILON) * 100) / 100;
    case 'jupiter':
      return Math.round((_seconds / JUPITER + Number.EPSILON) * 100) / 100;
    case 'saturn':
      return Math.round((_seconds / SATURN + Number.EPSILON) * 100) / 100;
    case 'uranus':
      return Math.round((_seconds / URANUS + Number.EPSILON) * 100) / 100;
    case 'neptune':
      return Math.round((_seconds / NEPTUNE + Number.EPSILON) * 100) / 100;
    default:
      return 0;
  }
}
