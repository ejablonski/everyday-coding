using System;
using System.Collections.Generic;

public static class SumOfMultiples
{
	public static int To(int[] multiples, int max)
	{
		List<int> to_sum = new List<int>();

		for(int i = 0; i < max; i++)
		{
			for(int j = 0; j < multiples.Length; j++)
			{
				if(i % multiples[j] == 0)
				{
					if(!to_sum.Contains(i))
					{
						to_sum.Add(i);
					}
				}
			}
		}

		int sum = 0;
		foreach(int n in to_sum)
		{
			sum += n;
		}

		return sum;
	}
}
