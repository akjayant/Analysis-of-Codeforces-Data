#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll infll=1e18+69;
const ll mod=1e9+7;
const ld pi=acos(-1.0L);
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define	ed return 0
#define hi hfvjidwkofiuhgaew
#define all(v) v.begin(), v.end()
ll n, m, f[100069]; 
int main(){
	fio;
	f[1]=2; f[2]=4;
	for(int i=3; i<100069; i++) f[i]=(f[i-1]+f[i-2])%mod;
	cin>>n>>m;
	ll ans=(f[n]+f[m])%mod;
	ans=(ans-2)%mod;
	if(ans<0) ans+=mod;
	cout<<ans<<endl;
	ed;
}