#include<bits/stdc++.h>
typedef long long lnt;
const lnt mod = 1e9 + 7;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d",&n);
		lnt nn[2]={0},mm[2]={0};
		for(int k=1;k<=n;k++){
			int x;
			scanf("%d",&x);
			if(x&1) nn[0]++;
			else nn[1]++;
		}
		scanf("%d",&m);
		for(int k=1;k<=m;k++){
			int x;
			scanf("%d",&x);
			if(x&1) mm[0]++;
			else mm[1]++;
		} 
		printf("%lld\n",nn[0]*mm[0]+mm[1]*nn[1]); 
	} 

}