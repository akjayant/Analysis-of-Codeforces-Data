#include<bits/stdc++.h>
using namespace std;
typedef long long i64;

int main()
{
	int T,a,b,c,d,k,i,f;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		f=0;
		for(i=0;i<=k&&!f;i++)
			if(c*i>=a&&d*(k-i)>=b){
				printf("%d %d\n",i,k-i);
				f=1;
			}
		if(!f)printf("-1\n");
	}
	return 0;
}