using System;
using System.Linq;
using System.Collections.Generic;

public class School
{
	SortedDictionary<string, int> db = new SortedDictionary<string, int>();

	public void Add(string student, int grade)
	{
		db.Add(student, grade);
	}

	public IEnumerable<string> Roster()
	{
		Dictionary<string, int> ret = new Dictionary<string, int>();
		foreach(KeyValuePair<string,int> item in db.OrderBy(value => value.Value))
		{
			ret.Add(item.Key, item.Value);
		}
		return ret.Keys;
	}

	public IEnumerable<string> Grade(int grade)
	{
		Dictionary<string, int> ret = new Dictionary<string, int>();
		foreach(KeyValuePair<string,int> item in db.OrderBy(value => value.Value))
		{
			if(item.Value == grade)
			{
				ret.Add(item.Key, item.Value);
			}
		}
		return ret.Keys;
	}
}
