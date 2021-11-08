export function hey(_s: string): string {
  let trimmed = _s.trim()
  let empty = trimmed.length === 0
  let question = trimmed.endsWith('?')
  let shouting = /[A-Z]/.test(trimmed) && !/[a-z]/.test(trimmed)

  if(empty) {
    return "Fine. Be that way!"
  } else if(shouting && question) {
    return "Calm down, I know what I'm doing!"
  } else if(question) {
    return "Sure."
  } else if(shouting) {
    return "Whoa, chill out!"
  }

  return "Whatever.";
}
