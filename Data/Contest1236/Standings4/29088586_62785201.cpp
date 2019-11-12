#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int a[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int a, b, c;
		cin>>a>>b>>c;
		int ans = 0;
		ans += min(c/2, b)*3;
		b -= min(c/2, b);
		ans += min(b/2, a)*3;
		cout<<ans<<endl;
	}
	return 0;
}