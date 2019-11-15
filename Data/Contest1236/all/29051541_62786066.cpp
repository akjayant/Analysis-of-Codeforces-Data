#include<bits/stdc++.h>

using namespace std;
const int MAXN = 100100;

signed main(){
	int t;
	cin >> t;
	
	while(t --){
		int a,b,c;
		cin >> a >> b >> c;
		
		int h = 0;
		if(c >= 2*b){
			cout << 3*b << endl;
			continue;
		}
		b -= c / 2 , h += 3 * (c / 2);
		if(b >= 2*a){
			cout << 3*a + h << endl;
			continue;
		}
		
		a -= b / 2 , h += 3 * (b / 2);
		
		cout << h << endl;
	}	
}
