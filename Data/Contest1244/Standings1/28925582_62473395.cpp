#include<bits/stdc++.h>
using namespace std;
char dr[1005];
void solve(){
	int n,mi=1e6,mx=0,ans;
	scanf("%d%s",&n,dr+1);ans=n;
	for(int i=1;i<=n;++i)if(dr[i]=='1'){
		ans++;mx=max(mx,i);
		mi=min(mi,i);
	}
	printf("%d\n",max(ans,max(mx*2,(n-mi+1)*2)));
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
}