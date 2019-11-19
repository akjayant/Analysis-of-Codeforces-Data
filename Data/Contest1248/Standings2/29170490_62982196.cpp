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
int n; vector<int>a;
int main(){
	fio;
	cin>>n; a.resize(n);
	for(int i=0; i<n; i++) cin>>a[i];
	sort(all(a));
	ll x=0ll, y=0ll;
	for(int i=n-1; i>=0; i--){
		if(i>=n/2) x+=a[i];
		else y+=a[i];
	}
	ll ans=x*x+y*y; cout<<ans<<endl;
	ed;
}