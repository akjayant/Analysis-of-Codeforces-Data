#include<bits/stdc++.h>
using namespace std;

int T,a,b,c;

int main(){
	scanf("%d",&T);
	while(T--){
		int res=0;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=0;i<=a&&2*i<=b;++i){
			int j=min(c/2,b-2*i);
			res=max(res,3*i+3*j);
		}
		printf("%d\n",res);
	}
	return 0;
}
 