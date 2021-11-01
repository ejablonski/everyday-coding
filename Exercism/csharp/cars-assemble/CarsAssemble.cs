using System;

static class AssemblyLine
{
    const int PRODUCTION = 221;

    public static double SuccessRate(int _speed)
    {
        if(_speed == 0)
        {
            return 0;
        }
        else if(_speed >= 1 && _speed <= 4)
        {
            return 1.0;
        }
        else if(_speed >= 5 && _speed <= 8)
        {
            return 0.9;
        }
        else if(_speed == 9)
        {
            return 0.8;
        }
        else
        {
            return 0.77;
        }
    }
    
    public static double ProductionRatePerHour(int _speed)
    {
        if(_speed == 0)
        {
            return 0;
        }
        else
        {
            return (_speed * PRODUCTION) * SuccessRate(_speed);
        }
    }

    public static int WorkingItemsPerMinute(int _speed)
    {
        if(_speed == 0)
        {
            return 0;
        }
        else
        {
            return (int)(ProductionRatePerHour(_speed) / 60);
        }
    }
}
