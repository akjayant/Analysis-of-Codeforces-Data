#include<bits/stdc++.h>
using namespace std;

int n;
char str[1005];

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%d%s",&n,str+1);
        int l=-1,r=-1;
        for(int i=1;i<=n;i++)if(str[i]=='1'){l=i;break;}
        for(int i=n;i>=1;i--)if(str[i]=='1'){r=i;break;}
        if(l==-1 && r==-1)printf("%d\n",n);
        else printf("%d\n",2*(n-min(l-1,n-r)));
    }
    return 0;
}