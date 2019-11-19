#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

ll dp[50][16];
// l<a, a<r, l<b, b<r


int main(void){
	int t,k,i,p,q,a,b,x,y;
	ll l,r,ans;
	scanf("%d",&t);
	for(k=0; k<t; ++k){
		fill(dp[0],dp[50],0ll);
		dp[32][0] = 1ll;
		scanf("%lld%lld",&l,&r);
		for(i=31; i>=0; --i){
			p = !!(l&(1ll<<i));
			q = !!(r&(1ll<<i));
			for(a=0; a<2; ++a){
				for(b=0; b<2; ++b){
					if(a&&b){
						continue;
					}
					for(x=0; x<16; ++x){
						for(y=0; y<16; ++y){
							if((x&y)!=x){
								continue;
							}
							if((!(x&1))){
								if(p>a){
									continue;
								}
								if((!!(y&1))^(p<a)){
									continue;
								}
								
							}
							if((!(x&2))){
								if(q<a){
									continue;
								}
								if((!!(y&2))^(q>a)){
									continue;
								}
							}
							if((!(x&4))){
								if(p>b){
									continue;
								}
								if((!!(y&4))^(p<b)){
									continue;
								}
							}
							if((!(x&8))){
								if(q<b){
									continue;
								}
								if((!!(y&8))^(q>b)){
									continue;
								}
							}
							dp[i][y] += dp[i+1][x];
						}
					}
				}
			}
		}
		ans = 0ll;
		for(i=0; i<16; ++i){
			ans += dp[0][i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
