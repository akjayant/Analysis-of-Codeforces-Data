#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ff first
#define ss second
#define endl '\n'

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	ll x[n];
	for(int i = 0; i < n; i++)
		cin >> x[i];
	sort(x, x+n);
	ll s1 = 0, s2 = 0;
	for(int i = 0; i < n; i++)
	{
		if(i < n/2)
			s1 += x[i];
		else
			s2 += x[i];
	}
	cout << s1*s1 + s2*s2 << endl;

	return 0;
}