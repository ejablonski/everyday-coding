export function commands(n: number): string[] {
  let ret: string[] = []
  let rev = false
  let binary = parseInt(n.toString(2), 10)


  while(binary >= 1) {
    if(binary - 10000 >= 0) {
      rev = true
      binary -= 10000
    } else if(binary - 1000 >= 0) {
      ret.push("jump")
      binary -= 1000
    } else if(binary - 100 >= 0) {
      ret.push("close your eyes")
      binary -= 100
    } else if(binary - 10 >= 0) {
      ret.push("double blink")
      binary -= 10
    } else if(binary - 1 >= 0) {
      ret.push("wink")
      binary -= 1
    }
  }

  return !rev ? ret.reverse() : ret
}
