#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x,y) memset(x,y,sizeof(x))
const int M=2e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
int main(){
	int a,b,c;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		int ans=0;
		int p=min(c/2,b);
		ans+=p*3;
		b-=p;
		p=min(b/2,a);
		ans+=p*3;
		printf("%d\n",ans);
	}
	return 0;
}
