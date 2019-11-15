#include<bits/stdc++.h>

using namespace std;

int main(){
	int t, a, b;
	cin >> t;
	for(int z=0;z<t;z++){
		cin >> a >> b;
		if(__gcd(a,b)==1){
			cout << "Finite\n";
		} else {
			cout << "Infinite\n";
		}
	}
return 0;
}