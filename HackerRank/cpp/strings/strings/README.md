# Strings

C++ provides a nice alternative data type to manipulate strings, and the data type is conveniently called string. Some of its widely used features are the following:

Declaration:

```
string a = "abc";
```

Size:

```
int len = a.size();
```

Concatenate two strings:

```
string a = "abc";
string b = "def";
string c = a + b; // c = "abcdef".
```

Accessing  element:

```
string s = "abc";
char   c0 = s[0];   // c0 = 'a'
char   c1 = s[1];   // c1 = 'b'
char   c2 = s[2];   // c2 = 'c'

s[0] = 'z';         // s = "zbc"
```

P.S.: We will use cin/cout to read/write a string.

## HackerRank

This problem comes from [https://www.hackerrank.com/challenges/c-tutorial-strings/problem](https://www.hackerrank.com/challenges/c-tutorial-strings/problem)

Author [abhiranjan](https://www.hackerrank.com/abhiranjan)