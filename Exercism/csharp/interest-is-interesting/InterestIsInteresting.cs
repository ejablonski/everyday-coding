using System;

static class SavingsAccount
{
    public static float InterestRate(decimal _balance)
    {
        if(_balance < 0)
        {
            return 3.213f;
        }
        else if(_balance >= 0 && _balance < 1000)
        {
            return 0.5f;
        }
        else if(_balance >= 1000 && _balance < 5000)
        {
            return 1.621f;
        }
        else
        {
            return 2.475f;
        }
    }

    public static decimal Interest(decimal _balance)
    {
        return _balance * (decimal)InterestRate(_balance) / 100;
    }

    public static decimal AnnualBalanceUpdate(decimal _balance)
    {
        return _balance + Interest(_balance);
    }

    public static int YearsBeforeDesiredBalance(decimal _balance, decimal _targetBalance)
    {
        int y = 0;

        while(_balance < _targetBalance)
        {
            y++;
            _balance = AnnualBalanceUpdate(_balance);
        }

        return y;
    }
}
