#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007LL
#define ROD 100000000ll
#define INF 123456789123456ll
#define MIN(a,b) (a>b?b:a)
using namespace std;
#define mp make_pair
#define  piii pair<pair<ll,ll>,pair<ll,ll>>
#define pii pair<ll,ll>
#define fi first
#define se second
ll t,a,b,c,d,k;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&k);
		ll min_=a/c+(a%c!=0)+b/d+(b%d!=0);
		if(min_<=k)
			cout<<a/c+(a%c!=0)<<" "<<b/d+(b%d!=0)<<"\n";
		else
			cout<<"-1\n";
	}
}