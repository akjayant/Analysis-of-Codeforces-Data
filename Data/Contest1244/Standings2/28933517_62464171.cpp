#include <bits/stdc++.h>

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
#define pb 	push_back
#define ff 	first
#define ss 	second
#define nl 	"\n"
#define rep(i, a, b) for(int i=a; i<b; i++)
typedef	long long ll;
typedef	long double	ld;
typedef unsigned long long ull;

using namespace std;

int main()
{
	fastio();
	int t;
	cin >> t;

	while(t--)
	{
		int x, y, a, b, k, c, d;
		cin >> a >> b >> c >> d >> k;

		x = a/c + (a%c != 0);
		y = b/d + (b%d != 0);

		if(x+y <= k)
			cout << x << " " << y << endl;
		else
			cout << "-1\n";
	}
}