#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define endl "\n"
#define int long long

const long INF = 1e8;
const double PI = acos(-1);
int mod = 1e9 + 7;


int32_t main()
{
	IOS
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	int a = n;
	int cnt = 0;
	int p = -1;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			while(n % i == 0)
				n /= i;
			p = i;
			cnt++;
		}
	}
	if(n > 1)
	{
		cnt++;
	}
	if(n == a) // Prime
		cout << a;
	else
	if(cnt == 1) // One prime factor only
	{
		cout << p;
	}
	else
		cout << 1;
	return 0;
}