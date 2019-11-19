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
ll t, n, m;
ll cntpo, cntpe, cntqo, cntqe;
int main(){
	fio;
	cin>>t; while(t--){
		cntpo=cntpe=cntqo=cntqe=0;
		cin>>n; for(ll i=0; i<n; i++) {ll tmp; cin>>tmp; if(tmp&1) cntpo++; else cntpe++;}
		cin>>m; for(ll i=0; i<m; i++) {ll tmp; cin>>tmp; if(tmp&1) cntqo++; else cntqe++;}
		cout<<cntpe*cntqe+cntpo*cntqo<<endl;
	}
	ed;
}