struct Solution
{
    static bool isUgly(int _n)
    {
        if (_n < 1) {
            return false;
        }

        bool f = true;

        while (f) {
            if (_n % 2 == 0) {
                _n /= 2;
            } else if (_n % 3 == 0) {
                _n /= 3;
            } else if (_n % 5 == 0) {
                _n /= 5;
            } else {
                f = false;
            }
        }

        return _n == 1;
    }
};
