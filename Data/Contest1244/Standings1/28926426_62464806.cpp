#include<bits/stdc++.h>
using namespace std;
int T,a,b,c,d,k;

int main()
{
  scanf("%d",&T);
  while(T--)
    {
	  scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
	  if((c+a-1)/c+(d+b-1)/d<=k) 
	    printf("%d %d\n",(c+a-1)/c,(d+b-1)/d);
	    else printf("-1\n");
	}
} 