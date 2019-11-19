#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,n;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
		int ans1=-1,ans2=-1;
		for(int i=0;i<=n;i++){
			int j=n-i;
			if(c*i>=a&&d*j>=b){ans1=i,ans2=j;break;}
		}
		if(ans1!=-1)printf("%d %d\n",ans1,ans2);
		else puts("-1");
	}
	return 0;
}