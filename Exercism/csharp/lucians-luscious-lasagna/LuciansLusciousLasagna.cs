class Lasagna
{
    public int ExpectedMinutesInOven()
    {
        return 40;
    }

    public int RemainingMinutesInOven(int _n)
    {
        return 40 - _n;
    }

    public int PreparationTimeInMinutes(int _n)
    {
        return _n * 2;
    }

    public int ElapsedTimeInMinutes(int _i, int _j)
    {
        return PreparationTimeInMinutes(_i) + _j;
    }
}
