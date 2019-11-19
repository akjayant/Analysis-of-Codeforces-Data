#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,k,t;
int main(){
	cin >> t;
	while (t--){
		bool flag=false;
		cin >> a >> b >> c >> d >> k;
		for (int i=1;i<=k;i++){
			if (i*c>=a&&(k-i)*d>=b){
				flag=true;
				cout << i << ' ' << (k-i) << '\n';
				break;
			}
		}
		if (!flag){
			cout << -1 << '\n';
		}
	}
}