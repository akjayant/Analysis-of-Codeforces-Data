#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int T, a, b;
	for(cin >> T; T; T--){
		cin >> a >> b;
		cout << ((__gcd(a, b) == 1)? "Finite\n":"Infinite\n");
	}
}
