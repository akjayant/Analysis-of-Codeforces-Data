#include<bits/stdc++.h>
#include<vector>
#include<string.h>
using namespace std;
#define MAX 100001
#define MAX_POINTS 201
#define DEFAULT 1;
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
int main ()
{
    int n,i,l;
    scanf("%d",&n);
    for(l=0;l<n;l++)
    {
        int a,b,c,d,k;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        int pens=(a/c)+(a%c>0);
        int pencils=(b/d)+(b%d>0);
        if(pens+pencils<=k)
        {
            printf("%d %d\n",pens,pencils);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
