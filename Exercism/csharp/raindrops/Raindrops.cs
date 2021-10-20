using System;

public static class Raindrops
{
	public static string Convert(int n)
	{
		string rain = "";

		if(n % 3 == 0)
		{
			rain += "Pling";
		}
		if(n % 5 == 0)
		{
			rain += "Plang";
		}
		if(n % 7 == 0)
		{
			rain += "Plong";
		}
		if(n % 3 != 0 && n % 5 != 0 && n % 7 != 0)
		{
			rain += n.ToString();
		}

		return rain;
	}
}
