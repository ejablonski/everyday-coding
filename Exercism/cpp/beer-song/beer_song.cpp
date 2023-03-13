#include "beer_song.h"

namespace beer_song {
  string verse(int _n) {
    string v;

    if(_n == 0) {
      v = "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n";
    } else if(_n == 1) {
      v = "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n";
    } else {
      v = to_string(_n) + " bottles of beer on the wall, " + to_string(_n) + " bottles of beer.\nTake one down and pass it around, " + to_string(_n - 1);
      
      if(_n - 1 == 1) {
        v += " bottle of beer on the wall.\n";
      } else {
        v += " bottles of beer on the wall.\n";
      }
    }

    return v;
  }

  string sing(int _s, int _e) {
    string s;

    // Assumes that _s > _e
    for(int i = _s; i >= _e; i--) {
      s += verse(i);

      if(i != _e) {
        s += "\n";
      }
    }

    return s;
  }
}  // namespace beer_song
