#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int a, b;
		cin >> a >> b;
		if(__gcd(a, b) == 1) cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}
	return 0;
}
