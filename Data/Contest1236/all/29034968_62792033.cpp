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
ll mdx(ll b, ll e){
	ll res=1ll; b%=mod;
	while(e>0){
		if(e&1) res=(res*b)%mod;
		e>>=1; b=(b*b)%mod;
	}
	return res;
}
int n, ans[369][369];
int main(){
	fio;
	cin>>n; int cnt=1;
	for(int i=0; i<n; i++){
		if(i&1){
			for(int j=n-1; j>=0; j--){
				ans[j][i]=cnt; cnt++;
			}
		}else{
			for(int j=0; j<n; j++){
				ans[j][i]=cnt; cnt++;
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<ans[i][j]; if(j==n-1) cout<<endl; else cout<<" ";
		}
	}
	ed;
}