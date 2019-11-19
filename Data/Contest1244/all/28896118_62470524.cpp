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
ll t,n;
char str[1005];
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %s",&n,str);
		ll max_=0;
		rep(i,0,n)
		if(str[i]=='1')
			max_=max({max_,(ll)i+1,n-i});
		//cout<<max_<<" ";
		printf("%lld\n",max(n,2*max_));
	}
}