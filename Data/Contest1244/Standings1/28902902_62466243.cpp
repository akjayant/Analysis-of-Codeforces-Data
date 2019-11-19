#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d,k;
int main(){
	scanf("%d",&t);
	while(t--){
		bool fl=0;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		for(int i=0;i<=k;++i){
			int x=i*c,y=(k-i)*d;
			if(x>=a&&y>=b){
				fl=1;
				printf("%d %d\n",i,k-i);
				break;
			}
		}
		if(!fl)puts("-1");
	}
	return 0;
}
