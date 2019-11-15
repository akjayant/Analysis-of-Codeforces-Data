#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int t;
	cin >>t;
	while (t--) {
		int a, b, c;
		cin >>a>>b>>c;
		int sol = 0;
		for (int i=0 ; i<=100 ; i++) {
			for (int j=0 ; j<=100 ; j++) {
				if (a<i or b<i*2+j or c<j*2) continue;
				sol = max(sol, (i+j)*3);
			//	if (sol == 12) cout <<i<<j<<endl;
			}
		}
		cout <<sol<<endl;
	}
	return 0;
}