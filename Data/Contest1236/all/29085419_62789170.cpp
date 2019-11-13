#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<vector>
#define mod (1000000007)
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll qpow(ll a,ll b){
	ll t=1;
	while(b){
		if(b&1)	t=t*a%mod;
		a=a*a%mod;
		b>>=1; 
	}
	return t;
} 
ll n,m;
int main()
{
	cin>>n>>m;printf("%lld\n",qpow(qpow(2,m)-1,n));



	return 0;
}