#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c,ans=0;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=0;i<=a;i++){
			if(b-2*i<0)break;
			int j=min(b-2*i,c/2);
			if(3*i+3*j>ans)ans=3*i+3*j;
		}
		printf("%d\n",ans);
	}
} 