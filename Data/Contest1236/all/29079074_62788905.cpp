#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a) for(int i=1;i<=a;i++)
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define Fi first
#define Se second
#define INF 987654321
#define IINF 987654321987654321
#define LINF 987654321987654321
//0x3F3F3F3F3F3F3F3Fll
#define sz(v) ((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pq priority_queue
#define BIGMOD 9223372036854775783
#define PI 3.14159265358979
#define eps 1e-7
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<bool,bool> pbb;
typedef pair<ll,ll> pll;
typedef complex<double> base;
typedef pair<bool,int> pbi;
typedef pair<ll,int> pli;
typedef pair<pll,ll> plll;
const ll MOD=1e9+7;
ll times(ll a,ll b){
	ll ans=1; ll A=a;
	while(b){
		if(b&1){
			ans=(ans*A)%MOD;
		}
		A=(A*A)%MOD;
		b/=2;
	}
	return ans;
}
int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",times((times(2,m)-1),n));
}