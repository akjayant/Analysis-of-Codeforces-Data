/*
 * @Author: Snicky
 * @Date: 2019-11-06 23:07:49 
 * @Last Modified by: Simon
 * @Last Modified time: 2019-11-06 23:07:49
 */ 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 200005
#define INF 0x3f3f3f3f
int a[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1,greater<int>());
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,min(i,a[i]));
		}
		cout<<ans<<endl;
	}
	return 0;
}
