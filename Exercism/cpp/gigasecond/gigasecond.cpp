#include "gigasecond.h"

namespace gigasecond {
  ptime advance(ptime d) {
    return d + seconds(1000000000);
  }
}  // namespace gigasecond
