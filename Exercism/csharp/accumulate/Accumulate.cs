using System;
using System.Linq;
using System.Collections.Generic;

public static class AccumulateExtensions
{
	public static IEnumerable<U> Accumulate<T, U>(this IEnumerable<T> collection, Func<T, U> func)
	{
		foreach(T it in collection)
		{
			//https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/yield
			yield return func(it);
		}
	}
}
