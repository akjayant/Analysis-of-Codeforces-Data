#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <map>
#define ll long long
#define mm 1000000007
using namespace std;

vector<ll> ttt;
int main()
{
	ll n;
	cin >> n;
	ll tem = n;
	int cnt = 0;
	for (ll i = 2;i*i <= tem;i=i+1LL)
	{
		if (n%i == 0)
		{
			while (n%i == 0)
				n /= i;
			cnt++;
			ttt.push_back(i);
		}
	}
	if (n == tem)
	{
		cout << tem;
		return 0;
	}
	if (n != 1)
	{
		cout << 1;
		return 0;
	}
	if (cnt == 1)
	{
		cout << ttt[0];
	}
	else
		printf("1");
}