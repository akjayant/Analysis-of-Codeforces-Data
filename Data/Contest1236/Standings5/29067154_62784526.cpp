#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3+5;

int main() {
	int t;
	cin>>t;
	while(t--) {
		int a, b, c;
		cin>>a>>b>>c;
		int ans = min(b, c/2);
		b -= ans;
		ans += min(a, b/2);
		cout<<ans*3<<endl;
	}


	return 0;
}