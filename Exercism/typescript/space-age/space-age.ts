export function age(planet: string, seconds: number): number {
  const PLANETS: { [key: string]: number } = {
    'earth': 31557600,
    'mercury': 7600544,
    'venus': 19414149,
    'mars': 59354033,
    'jupiter': 374355659,
    'saturn': 929292363,
    'uranus': 2651370019,
    'neptune': 5200418560
  }

  return Math.round((seconds / PLANETS[planet] + Number.EPSILON) * 100) / 100
}
