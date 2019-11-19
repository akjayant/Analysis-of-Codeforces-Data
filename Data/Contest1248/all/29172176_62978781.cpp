#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const int N = 1e5+7;
typedef long long ll;
const ll mod = 1e9+7;
using namespace std;
//int a[N],b[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n;
		int ji,ou;
		ji=ou=0;
		for(int i=0;i<n;i++){
			int x; cin>>x;
			if(x&1) ji++;
			else ou++;
		}
		cin>>m;
		ll ans=0;
		for(int i=0;i<m;i++){
			int x; cin>>x;
			if(x&1) ans+=ji;
			else ans+=ou;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 