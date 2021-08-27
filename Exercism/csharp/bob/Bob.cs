using System;
using System.Linq;

public static class Bob
{
	public static string Response(string input)
	{
		// get rid of whitespaces at the end of the string
		input.Trim(); // this is crap
		input.Replace(" ", ""); // this is crap
		input.Replace("\t", "");
		input.Replace("\n", "");

		string s = new string(input.Where(c => !char.IsWhiteSpace(c)).ToArray<char>());

		// check if characters are uppercased (shouting)
		bool shouting = true;
		foreach(char c in s)
		{
			if(Char.IsLower(c) && !Char.IsDigit(c) && !Char.IsPunctuation(c))
			{
				shouting = false;
				break;
			}
		}

		// check if string contains numbers and punctuals only
		bool numsOnly = true;
		foreach(char c in s)
		{
			if(!Char.IsDigit(c) && !Char.IsPunctuation(c) && !Char.IsWhiteSpace(c))
			{
				numsOnly = false;
				break;
			}
		}

		if(shouting && s.Length > 0 && !numsOnly && s.EndsWith('?'))
		{
			return "Calm down, I know what I'm doing!";
		}
		else if(shouting && s.Length > 0 && !numsOnly)
		{
			return "Whoa, chill out!";
		}
		else if(s.EndsWith('?'))
		{
			return "Sure.";
		}
		else if(s.Length == 0)
		{
			return "Fine. Be that way!";
		}

		return "Whatever.";
	}
}
