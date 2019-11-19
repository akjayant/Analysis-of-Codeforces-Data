#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long LL;
const int MAXN = 1e5+5;

int n ,m;

int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		int x;	
		LL ji1 = 0,ou1=0,ji2=0,ou2=0;
		for(int i = 0;i<n;i++){
			scanf("%d",&x);
			if(x&1) ji1++;
			else ou1++;
		}		
		scanf("%d",&m);
		for(int i = 0;i<m;i++){
			scanf("%d",&x);
			if(x&1) ji2++;
			else ou2++;
		}	
		LL ans = ji1*ji2+ou1*ou2;
		printf("%lld\n",ans);
	} 
	return 0;
}