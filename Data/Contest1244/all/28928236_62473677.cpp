#include<bits/stdc++.h>
using namespace std;
char s[1005];

int main()
{
    int n,l,r,t,ans;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d",&n);
        scanf("%s",s+1);
        l=n+1;
        r=0;
        for(int i=1;i<=n;i++)
        {
        	if(s[i]=='1')
        		r=i;
		}
		for(int i=n;i>=1;i--)
        {
        	if(s[i]=='1')
        		l=i;
		}
		ans=max(n,max(r*2,2*(n+1-l)));
		printf("%d\n",ans);
    }
	return 0;
}
