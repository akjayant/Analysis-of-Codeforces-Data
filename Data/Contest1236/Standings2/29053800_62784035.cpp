#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main(){
//	IOS;
	int t;
	cin >> t;
	int a,b,c;
	while(t--){
		cin >> a >> b >> c;
		int now=min(b,c/2);
		now+=min(a,(b-now)/2);
		cout << now*3 << '\n';
	}
	return 0;
}
