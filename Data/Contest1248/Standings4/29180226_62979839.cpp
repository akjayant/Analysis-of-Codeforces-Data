#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc, n, m, a;
	long long oddn, evenn, oddm, evenm;
	cin>>tc;
	while(tc--) {
		cin>>n;
		oddn = evenn = oddm = evenm = 0;
		for(int i = 0; i<n;i++) {
			cin>>a;
			if(a%2) {
				oddn++;
			} else {
				evenn++;
			}
		}
		cin>>m;
		for(int i = 0; i<m;i++) {
			cin>>a;
			if(a%2) {
				oddm++;
			} else {
				evenm++;
			}
		}
		cout<<oddn*oddm + evenn*evenm<<endl;
	}
	return 0;
}
