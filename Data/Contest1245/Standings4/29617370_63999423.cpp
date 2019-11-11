#include<bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> pii;

int32_t main(){
	int tests; cin >> tests;
	//dati due interi determina se sono coprimi
	for(int t=0; t<tests; ++t){
		int ans=1;
		int a, b; cin >> a >> b;
		for(int i=2; i<=min(a, b); ++i){
			if(a%i == 0 && b%i == 0) ans=0;
		}
		if(a == 1 || b == 1) ans=1;
		if(ans) cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}
}
