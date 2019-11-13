#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1e6+69;
const ll infll=1e18+69;
const ll mod=1e9+7;
const ld pi=acos(-1.0L);
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define	ed return 0
#define hi hfvjidwkofiuhgaew
#define all(v) v.begin(), v.end()
int gcd(int a, int b){
	if(a<b) swap(a, b);
	if(b==0) return a;
	return gcd(b, a%b);
}
int main(){
	fio;
	int t; cin>>t;
	while(t--){
		int a, b; cin>>a>>b;
		if(gcd(a, b)!=1) cout<<"Infinite\n";
		else cout<<"Finite\n";
	}
	ed;
}