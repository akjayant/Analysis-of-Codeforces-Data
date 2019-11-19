#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define mst(a,i) memset(a,i,sizeof a)
#define ll long long
#define eps 1e-10 
const int mod = 1e9+7;
const int N = 1e5+6;

int a[N],b[N],cnt1[N],cnt2[N];

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t,n,m;
	cin>>t;
	while(t--){
		mst(cnt1,0);
		mst(cnt2,0);
		cin>>n;
		rep(i,1,n)
			cin>>a[i],cnt1[a[i]%2]++;
		cin>>m;
		rep(i,1,m)
			cin>>b[i],cnt2[b[i]%2]++;
		ll ans=1ll*cnt1[0]*cnt2[0]+1ll*cnt1[1]*cnt2[1];
		cout<<ans<<endl;
	}
	return 0;
}
/*

*/