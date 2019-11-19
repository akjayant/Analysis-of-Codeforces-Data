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
		int n,res;
		cin>>n;
		res=n;
		string s;
		cin>>s;
		for(int i=0;i<n;++i){
			if(s[i]=='1'){
				res=max(res,2*max(n-i,i+1));
			}
		}
		cout<<res<<'\n';
	}
}