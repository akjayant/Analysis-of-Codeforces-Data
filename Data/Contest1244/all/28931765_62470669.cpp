#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1000+100;

char s[maxn];
int main()
{
    int n,m,i,j,k,x,y;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        int l=n+1,r=0;
        for(i=1;i<=n;i++)
        {
            if(s[i]=='1')
            {
                l=min(l,i);
                r=max(r,i);
            }
        }
        int cnt=n;
        if(l!=n+1)
        {
            cnt=max(cnt,l*2);
            cnt=max(cnt,n*2-l*2+2);
            l=r;
            cnt=max(cnt,l*2);
            cnt=max(cnt,n*2-l*2+2);
        }
        printf("%d\n",cnt);
    }
    return 0;
}

/**
4
0 1 2 2
1 10 100 1000
*/
