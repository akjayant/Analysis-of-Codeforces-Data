#include<bits/stdc++.h>
using namespace std;const int N=1e3+7;
int cnt[N],n,i,j,T_T,sum,mx;
int main(){
	for(scanf("%d",&T_T);T_T--;mx=0,memset(cnt,0,sizeof(cnt))){
		for(scanf("%d",&n),i=1;i<=n;++i)scanf("%d",&j),cnt[j]++;
		for(i=1;i<=n;++i){
			sum=0;
			for(j=i;j<=n;++j)sum+=cnt[j];
			if(sum>=i)mx=max(mx,i);
		}printf("%d\n",mx);
	}
} 