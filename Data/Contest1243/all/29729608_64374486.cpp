/*----Author:HenryHuang----*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;++i){
			ans=max(ans,min(a[i],n-i+1));
		}
		cout<<ans<<'\n';
	} 
	return 0;
}

