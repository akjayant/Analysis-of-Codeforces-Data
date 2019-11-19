#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define mst(a,i) memset(a,i,sizeof a)
#define ll long long
#define eps 1e-10 
const int mod = 1e9+7;
const int N = 1e5+6;

ll a[N];

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t,n,m;
	ll sum=0,sum1=0;
	cin>>n;
	rep(i,1,n)
		cin>>a[i],sum+=a[i];
	sort(a+1,a+1+n);
	ll ans=0;
	rep(i,1,n/2)
		sum-=a[i],sum1+=a[i];
	cout<<sum*sum+sum1*sum1<<endl;
	return 0;
}
/*

*/