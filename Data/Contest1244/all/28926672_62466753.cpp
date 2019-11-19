#include "bits/stdc++.h"
using namespace std;

int t, n;
string s;

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		cin >> s;
		int ans = n;
		for(int i = 0; i < n; ++i){
			if(s[i] == '1'){
				ans = max(ans, n+1);
				ans = max(ans, 2*(i+1));
				ans = max(ans, 2*(n-i));
			}
		}
		printf("%d\n", ans);
	}
}