#include <bits/stdc++.h>

using namespace std;

int t,a,b,c,d,k;

void check(){
	for(int x = 0; x <= k; ++x){
		int y = k - x;
		if(x * c >= a && y * d >= b){
			cout << x << " " << y << endl;
			return ;
		}
	}
	cout << -1 << endl;
}
int main(){
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cin >> a >> b >> c >> d >> k;
		check();
	}
}