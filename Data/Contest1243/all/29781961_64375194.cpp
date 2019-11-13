#include<bits/stdc++.h>
using namespace std;
int a[1100];
int main()
{
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		for(int i = 1; i <= n; ++i) cin>>a[i];
		sort(a + 1, a + 1 + n);
		int ans = 0;
		for(int i = n; i >= 1; --i){
			ans = max(ans, min(n - i + 1, a[i]));
		}
		cout<<ans<<endl;
	}
}
 