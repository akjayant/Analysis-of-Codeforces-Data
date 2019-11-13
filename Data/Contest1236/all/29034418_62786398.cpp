#include<bits/stdc++.h>
using namespace std;
const int maxn = 2005;
#define ll long long
typedef pair<int, int> pii;
int n;
int main()
{
	while (cin >> n)
	{
		while (n--)
		{
			int ans = 0;
			int a, b, c;
			cin >> a >> b >> c;
			int t = c / 2;
			if (t > b)ans += 3 * b, b = 0;
			else ans += 3 * t,b-=t;
			ans += 3*min(a, b/2);
			cout << ans << endl;
		}
	
	}
}