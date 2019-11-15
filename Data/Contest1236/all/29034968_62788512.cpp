#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf=1e18+69;
const ll mod=1e9+7;
const ld pi=acos(-1);
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(v) v.begin(), v.end()
#define ed return 0
#define hi eihufahuodhiepwkajkf
ll n, m;
ll mdx(ll b, ll e){
	ll res=1ll; b%=mod;
	while(e>0){
		if(e&1) res=(res*b)%mod;
		e>>=1; b=(b*b)%mod;
	}
	return res;
}
int main(){
	fio;
	cin>>n>>m;
	ll bs=mdx(2, m);
	bs=(bs-1)%mod;
	cout<<mdx(bs, n)<<endl;
	ed;
}