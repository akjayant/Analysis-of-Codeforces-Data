#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,a1=0,b1=0;
		cin >> n;
		while(n--){
			int x;
			cin >> x;
			if(x%2) a1++;
			else b1++;
		}
		int m,a2=0,b2=0;
		cin >> m;
		while(m--){
			int x;
			cin >> x;
			if(x%2) a2++;
			else b2++;
		}
		long long ans=1ll*a1*a2+1ll*b1*b2;
		cout << ans << endl;
	}
	return 0;
}