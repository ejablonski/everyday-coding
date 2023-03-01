namespace leap {
  bool is_leap_year(int i) {
    return (i % 4 == 0 && i % 100 != 0) ? true : (i % 400 == 0);
  }
}
