using System;

public static class TwoFer
{
	public static string Speak(String _s = "")
	{
		if(_s.Length == 0)
		{
			return "One for you, one for me.";
		}
		else
		{
			return "One for " + _s + ", one for me.";
		}
	}
}
