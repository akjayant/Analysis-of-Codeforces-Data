#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
int t, n, m;
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> t;
 	while(t--)
 	{
 		int odd1 = 0, odd2 = 0, even1 = 0, even2 = 0;
 		cin >> n;
 		for(int i=1;i<=n;i++)
 		{
 			int p;
 			cin >> p;
 			if(p%2) odd1++;
 			else even1++;
 		}
 		cin >> m;
 		for(int i=1;i<=m;i++)
 		{
 			int q;
 			cin >> q;
 			if(q%2) odd2++;
 			else even2++;
 		}
 		ll ans = 1ll*odd1*odd2 + 1ll*even1*even2;
 		cout << ans << '\n';
 	}
	return 0;
}
