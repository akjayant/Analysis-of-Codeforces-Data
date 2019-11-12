#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		int ans = 0;
		cin >> a >> b >> c;
		int num2 = min(b,c/2);
		ans += num2*3;
		b -= num2;
		int num1 = min(a,b/2);
		ans += num1*3;
		cout << ans << endl;
	}
	return 0;
} 