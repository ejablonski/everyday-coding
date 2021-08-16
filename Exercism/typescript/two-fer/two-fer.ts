export function twoFer(s: string = ''): string {
  if(s == '') {
    return 'One for you, one for me.';
  } else {
    return 'One for ' + s + ', one for me.';
  }
}
