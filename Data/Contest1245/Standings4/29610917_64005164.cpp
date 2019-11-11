#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define Fi first
#define Se second
#define ll long long
#define inf 0x3f3f3f3f
#define lowbit(x) (x&-x)
#define ull unsigned long long
#define mmin(a,b,c) min(a,min(b,c))
#define mmax(a,b,c) max(a,max(b,c))
#define debug(a) cout<<#a<<"="<<a<<endl;
#define debug2(a,b) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<endl;
#define debug3(a,b,c) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<endl;
#define show_time cout<<"The run time is:"<<(double)clock()/CLOCKS_PER_SEC<<"s"<<endl;
using namespace std;
const int N=3e5+10;
char s[N],ans[N];

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n,a,b,c;scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);
        int x[3]={0};
        for(int i=1;i<=n;i++)
        {
            ans[i]=0;
            if(s[i]=='R') x[0]++;
            if(s[i]=='P') x[1]++;
            if(s[i]=='S') x[2]++;
        }
        ans[n+1]=0;
        int w=min(a,x[2])+min(b,x[0])+min(c,x[1]);
        if(w>=(n+1)/2)
        {
            printf("YES\n");
            for(int i=1;i<=n;i++)
            {
                if(s[i]=='R')
                {
                    if(b) ans[i]='P',b--;
                }
                else if(s[i]=='P')
                {
                    if(c) ans[i]='S',c--;
                }
                else
                {
                    if(a) ans[i]='R',a--;
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(ans[i]==0)
                {
                    if(a) ans[i]='R',a--;
                    else if(b) ans[i]='P',b--;
                    else if(c) ans[i]='S',c--;
                }
            }
            printf("%s\n",ans+1);
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
/*
R->S
P->R
S->P
*/
