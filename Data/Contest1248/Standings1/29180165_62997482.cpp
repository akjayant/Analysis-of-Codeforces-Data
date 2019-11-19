#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

const ll mod = 1000000007;

ll f(ll n){
	if(n==1)return 2;
	if(n==2)return 4;
	if(n==3)return 6;
	//ll m[2][2]={{6,4},{4,2}};
	n-=3;
	ll m[2][2]={{1,1},{1,0}};
	ll res[2]={6,4};
	while(n){
		if(n&1){
			ll tmp[2]={((res[0]*m[0][0])%mod+(res[1]*m[0][1])%mod)%mod,((res[0]*m[1][0])%mod+(res[1]*m[1][1])%mod)%mod};
			res[0]=tmp[0];
			res[1]=tmp[1];
		}
		ll tmp[2][2]={{0,0},{0,0}};
		for(int y=0; y<2; ++y){
			for(int x=0; x<2; ++x){
				for(int i=0; i<2; ++i){
					tmp[y][x]=((tmp[y][x]+(m[y][i]*m[i][x])%mod)%mod);
				}
			}
		}
		for(int y=0; y<2; ++y){
			for(int x=0; x<2; ++x){
				m[y][x]=tmp[y][x];
			}
		}
		n>>=1;
	}
	return res[0];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll a,b;
	cin>>a>>b;
	cout<<((f(a)+f(b))%mod+mod-2)%mod<<endl;
	return 0;
}
