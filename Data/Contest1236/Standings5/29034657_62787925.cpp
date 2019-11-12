#include <bits/stdc++.h>
#define rap(i,s,n) for(int i=s;i<=n;i++)
using namespace std;
int main(){
	int t; scanf("%d",&t); while(t--){
		int a,b,c,ans=0; scanf("%d%d%d",&a,&b,&c);
		
		rap(x,0,100){
			if(x*2>c||x>b) break;
			int y=min(a,(b-x)/2); ans=max(ans,3*(x+y));
		}
		printf("%d\n",ans);
	}
	return 0;
}