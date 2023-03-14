#include "word_count.h"

namespace word_count {
  map<string, int> words(string text) {
    map<string, int> solution;

    transform(text.begin(), text.end(), text.begin(), ::tolower);

    // regex? nah
    for(unsigned int i = 0; i < text.length(); i++) {
      if(ispunct(text[i]) && !(text[i] == '\'' && isalpha(text[i-1]) && isalpha(text[i+1]))) {
        text.replace(text.begin() + i, text.begin() + i + 1, 1, ' ');
      }
    }

    stringstream ss(text);
    string tmp;

    while(ss >> tmp) {
      // stream to param tmp and search if it already occured
      auto search = solution.find(tmp);
      if(search != solution.end()) {
        solution[tmp] += 1;
      } else {
        solution[tmp] = 1;
      }
    }

    return solution;
  }
}  // namespace word_count
