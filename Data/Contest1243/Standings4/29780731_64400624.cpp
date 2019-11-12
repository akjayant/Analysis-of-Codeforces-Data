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
 
ll a, b, c, d, e, f, cycle, st, k;
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
	for (ll r = 0; r < a; ++r)
	{
		ll f;
		cin >> f;
		string s, s1;
		cin >> s;
		cin >> s1;
		vector <ll> pp(26, 0);
		vector <pair <ll, ll> > ot;
		for (ll i = 0; i < f; ++i)
		{
			++pp[s[i] - 'a'];
			++pp[s1[i] - 'a'];
		}
		ll fl = 0;
		for (ll i = 0; i < 26; ++i)
		{
			if (pp[i] % 2 == 1)
				fl = 1;
		}
		if (fl == 1)
		{
			cout << "No" << endl;
			continue;
		}
		for (ll i = 0; i < f; ++i)
		{
			ll fl1 = 0;
			ll k = -1;
			for (ll j = i; j < f; ++j)
			{
				if (s[i] == s1[j])
				{
					k = j;
					fl1 = 1;
					break;
				}
			}
			if (fl1 == 1)
			{
				swap(s[i], s1[i]);
				swap(s[i], s1[k]);
				ot.push_back(make_pair(i + 1, i + 1));
				ot.push_back(make_pair(i + 1, k + 1));
				continue;
			}
			for (ll j = i + 1; j < f; ++j)
			{
				if (s[i] == s[j])
				{
					k = j;
					fl1 = 1;
					break;
				}
			}	
			swap(s[k], s1[i]);
			ot.push_back(make_pair(k + 1, i + 1));
		}
		cout << "Yes" << endl;
		cout << ot.size() << endl;
		for (ll i = 0; i < ot.size(); ++i)
		{
			cout << ot[i].F << " " << ot[i].S << endl;
		}
	}
}
