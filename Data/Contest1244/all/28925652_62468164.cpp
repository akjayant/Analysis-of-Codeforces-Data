#include<bits/stdc++.h>
using namespace std;
int i,i0,n,m,T,ans;
char s[10005];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %s",&n,s+1);
        int d=0;
        for(i=1;i<=n;i++)
        {
            if(s[i]=='1')
            {
                d=max(d,i);
                d=max(d,n-i+1);
            }
        }
        printf("%d\n",max(n,d*2));
    }
    return 0;
}