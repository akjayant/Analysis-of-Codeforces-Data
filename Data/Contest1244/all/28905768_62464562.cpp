#include <bits/stdc++.h>
#define int long long
using namespace std;
int q;
signed main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>q;
	while(q--){
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		bool bb=1;
		for(int i=0;i<=k;++i){
			int j=k-i;
			if(i*c>=a&&j*d>=b){
				bb=0;
				cout<<i<<' '<<j<<'\n';
				break;
			}
		}
		if(bb)cout<<"-1\n";
	}
}