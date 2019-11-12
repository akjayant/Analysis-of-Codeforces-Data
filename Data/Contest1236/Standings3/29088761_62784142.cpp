#include<bits/stdc++.h>
using namespace std;
typedef long long i64;

int main()
{
	int T,a,b,c,i,ans;
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d%d",&a,&b,&c);
		for(i=0;i<=a;i++)
			if(2*i<=b)ans=max(ans,3*i+min(b-2*i,c/2)*3);
		printf("%d\n",ans);
	}
	return 0;
}