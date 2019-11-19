/*input
3
3
1 3 2
2
0 3
1
1
1
1
1
2
1
1

*/
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 100002

using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	ll T=1,n,m;string str;
	cin>>T;
	// cin.ignore(); put after cin, just b4 a getline(cin, s) to avoid getline() directly getting \n
	while(T--)
	{
		ll p=0,q=0,tmp=0,sum=0,count=0; //tmp variable
		ll e1=0,o1=0,e2=0,o2=0;
		int flag=0;
		cin>>n;
		ll a[n];
		for(ll i=0;i < n;i++)
		{
			cin>>a[i];
			if (a[i]%2==0)
			{
				e1++;
			}
			else
				o1++;
		}
		cin >> m;
		ll b[m];
		for (ll i = 0; i < m; ++i)
		{
			cin >> b[i];
			if (b[i]%2==0)
			{
				e2++;
			}
			else
				o2++;
		}
		// watch(e1);
		// watch(e2);
		// watch(o1);
		// watch(o2);
		cout << e1*e2 + o1*o2 << endl;
		
	}
	return 0;
}