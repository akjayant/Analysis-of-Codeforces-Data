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
		int n;
		cin >> n;

		string s;
		cin >> s;

		int maxm = 0;

		for(int i=0; i<s.length(); i++)
			if(s[i] == '1')
				maxm = max(maxm, max(i+1, n-i));

		cout << max(n, 2*maxm) << endl;
	}
}