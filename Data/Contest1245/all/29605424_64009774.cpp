#include <bits/stdc++.h>
using namespace std;

int cl[100004];
int t;
int a,b;
int ok;

void DFS(int u)
{
    cl[u]=1;

    if(cl[abs(u-a)]==0)
        DFS(abs(u-a));

    if(cl[abs(u-b)]==0)
        DFS(abs(u-b));

    if(u+a<=a+b&&cl[u+a]==0)
        DFS(u+a);

    if(u+b<=a+b&&cl[u+b]==0)
        DFS(u+b);
}

int main ()
{
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);

    scanf("%d ",&t);

    for(int i=1; i<=t; ++i)
    {
        scanf("%d %d ",&a,&b);

        memset(cl,0,sizeof cl);

        DFS(0);

        ok=1;

        for(int j=1; j<min(a,b); ++j)
            if(cl[j]==0)
                ok=0;

        if(ok==1)
            printf("Finite\n");
        else
            printf("Infinite\n");
    }
}
