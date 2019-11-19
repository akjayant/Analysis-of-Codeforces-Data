#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ff first
#define ss second
#define endl '\n'

int n, m;
ll M = 1000000007;
ll x[1000001];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	x[0] = 0;
	x[1] = 1;
	x[2] = 1;
	for(int i = 3; i < 200000; i++)
		x[i] = (x[i-1]+x[i-2])%M;
	
	ll ans = (2*x[m+1]-2 + 2*(x[n+1]) + M)%M;
	cout << ans	 << endl;

	return 0;
}