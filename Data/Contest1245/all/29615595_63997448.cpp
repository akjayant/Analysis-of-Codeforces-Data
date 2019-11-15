#include <iostream>
using namespace std;

int mygcd(int a, int b){
	if(!b)
		return a;
	return mygcd(b,a%b);
}

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		int g = mygcd(a,b);
		if(g==1){
			cout << "Finite\n";
		}else
			cout << "Infinite\n";
	}
	return 0;
}