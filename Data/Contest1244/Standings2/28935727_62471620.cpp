#include<bits/stdc++.h>
using namespace std;

int main(){
	int tests; cin >> tests;
	for(int t=0; t<tests; ++t){
		int n; cin >> n;
		string s; cin >> s;
		int first=2000, last=-10; //indici del primo e dell'ultimo 1
		for(int i=0; i<n; ++i){
			if(s[i] == '1'){
				first=min(i, first);
				last=max(i, last);
			}
		}
		int ans=max(2*(n-first), 2*(1+last));
		ans=max(ans, n);
		cout << ans << endl;
	}
}
