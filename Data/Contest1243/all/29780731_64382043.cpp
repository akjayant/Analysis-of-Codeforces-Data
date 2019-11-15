#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("fast-math")
 
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
#include <map>
 
#define ll long long
#define S second
#define F first
 
using namespace std;
 
ll a, b, c, d, e, f, cycle, st, ot, k;
vector <vector <ll> > arr, arr1;
vector <ll> ar;
 
 
 
ll nod(ll a, ll b)
{
	if (b == 0)
		return a;
	return nod(b, a % b);
}


 
 
int main()
{
	cin >> a;
	for (ll j = 0; j < a; ++j)
	{
		ll f;
		cin >> f;
		string s, s1;
		cin >> s;
		cin >> s1;
		if ((ll)s.length() != (ll)s1.length())
		{
			cout << "No" << endl;
			continue;
		}
		d = 0;
		for (ll i = 0; i < s.length(); ++i)
		{
			if (s[i] != s1[i])
			{
				++d;
				if (d == 1)
					b = i;
				if (d == 2)
					c = i;
			}
		}
		if (d == 0)
		{
			cout << "Yes" << endl;
			continue;
		}
		if (d == 2 && s[b] == s[c] && s1[c] == s1[b])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}