using System;
using System.Collections.Generic;

public class NucleotideCount
{
	static public Dictionary<char, int> Count(string nucleotide)
	{
		int a = 0;
		int c = 0;
		int g = 0;
		int t = 0;

		foreach(char ch in nucleotide)
		{
			switch(ch)
			{
				case 'A':
					a++;
					break;
				case 'C':
					c++;
					break;
				case 'G':
					g++;
					break;
				case 'T':
					t++;
					break;
				default:
					throw new ArgumentException();
			}
		}

		return new Dictionary<char, int>
		{
			['A'] = a,
			['C'] = c,
			['G'] = g,
			['T'] = t
		};
	}
}
