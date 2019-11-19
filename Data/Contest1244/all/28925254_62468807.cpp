#include<bits/stdc++.h>
using namespace std;
typedef long long i64;

char a[1003];

int main()
{
	int T,n,i,l,r;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",a+1);
		l=r=0;
		for(i=1;i<=n;i++)
			if(a[i]=='1'){
				if(!l)l=i;
				r=i;
			}
		printf("%d\n",max(n,max(2*r,l?2*(n-l+1):0)));
	}
	return 0;
}