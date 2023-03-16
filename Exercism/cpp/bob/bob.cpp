#include "bob.h"

string bob::hey(string s) {
  // get rid of white spaces
  s.erase(remove(s.begin(), s.end(), ' '), s.end());

  // get rid of white printing characters
  s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
    return !isspace(ch);
  }));

  // check if all chars are uppercase (shouting)
  bool shouting = true;
  for(unsigned int i = 0; i < s.length(); i++) {
    if(!isupper(s[i]) && !ispunct(s[i]) && !isdigit(s[i])) {
      shouting = false;
      break;
    }
  }

  // check if string contains numbers (and punctual chars) only
  bool numOnly = true;
  for(unsigned int i = 0; i < s.length(); i++) {
    if(!isdigit(s[i]) && !ispunct(s[i])) {
      numOnly = false;
      break;
    }
  }

  if(shouting && !numOnly && s.back() == '?')
    return "Calm down, I know what I'm doing!";
  else if(shouting && s.length() > 0 && !numOnly)
    return "Whoa, chill out!";
  else if(s.back() == '?')
    return "Sure.";
  else if(s.length() == 0)
    return "Fine. Be that way!";
  
  return "Whatever.";
}
