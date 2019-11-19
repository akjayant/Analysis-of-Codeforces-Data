#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <= n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define F first
#define S second
#define I insert
#define mp make_pair
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define debug1(a) cout<<" "<<#a<<" : "<<a<<"\n"
#define debug2(a,b) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<"\n"
#define debug3(a,b,c) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<"\n"
#define debug4(a,b,c,d) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<"\n"
#define INF (int)10000000000000000
#define PI (double)3.14159265358979
// #define M 421412341324321
#define MOD 1000000007

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		int o1 = 0, e1=0, o2=0,e2=0;
		rep(i,n)
		{
			cin>>a[i];
			if (a[i]&1) o1++;
			else e1++;
		}
		int m;
		cin>>m;
		int b[m];
		rep(i,m)
		{
			cin>>b[i];
			if (b[i]&1) o2++;
			else e2++;
		}
		int ans = e1*e2+o1*o2;
		cout<<ans<<"\n";
	}	


	return 0;
}