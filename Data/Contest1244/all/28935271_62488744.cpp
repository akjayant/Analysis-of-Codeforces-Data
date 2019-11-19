//#include "pch.h"
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <map>
#include<list>

using namespace std;
#define var auto
#define ll long long
#define endl '\n'


void solve()
{
	ll n, k;
	cin >> n >> k;
	map<ll, ll>m;
	for (ll i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		m[x]++;
	}
	list<pair<ll, ll>> pairs;
	for (auto a : m)
		pairs.push_back(a);

	pairs.sort([](const pair<ll, ll>& lhs, const pair<ll, ll>& rhs)
	{
		return lhs.first < rhs.first;
	});
	while (true)
	{
		if (pairs.size() == 1)
		{
			cout << 0;
			return;
		}
		if (pairs.front().second < pairs.back().second)
		{
			var fst = pairs.front();
			pairs.pop_front();
			var snd = pairs.front();
			if (k < fst.second*(snd.first - fst.first))
			{
				cout << pairs.back().first - fst.first - k / fst.second;
				return;
			}
			else
			{
				k -= fst.second*(snd.first - fst.first);
				pairs.pop_front();
				snd.second += fst.second;
				pairs.push_front(snd);
			}
		}
		else
		{
			var fst = pairs.back();
			pairs.pop_back();
			var snd = pairs.back();
			if (k < fst.second*(fst.first - snd.first))
			{
				cout << fst.first - pairs.front().first - k / fst.second;
				return;
			}
			else
			{
				k -= fst.second*(fst.first - snd.first);
				pairs.pop_back();
				snd.second += fst.second;
				pairs.push_back(snd);
			}
		}
	}

}
int main()
{
	int t = 1;
	//cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}