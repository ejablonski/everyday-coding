struct Solution
{
    /**
     * Modular arithmetic
     */
    static int smallestRepunitDivByK(int _k)
    {
        if (_k % 2 == 0) {
            return -1;
        }

        if (_k % 5 == 0) {
            return -1;
        }

        int rem = 1 % _k;

        for (int i = 0; i <= _k; i++) {
            if (rem == 0) {
                return i + 1;
            }
            rem = ((rem * 10) + 1) % _k;
        }

        return -1;
    }
};
