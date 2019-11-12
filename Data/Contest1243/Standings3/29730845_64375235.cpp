#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
const int mx=2e5+10;
int s[mx];
int t,n;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
		sort(s+1,s+1+n);
		int ans=0;
		for(int i=n,j=1;i>=1;i--,j++)
		{
			int m=min(s[i],j);
			ans=max(ans,m);
		}
		printf("%d\n",ans);
	}
	return 0;
}