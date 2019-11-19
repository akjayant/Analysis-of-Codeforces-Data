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
    int t,k;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        int n;
        scanf("%d ",&n);
        char sit[n];
        int i,j;
        int findex=-1,lindex=n;
        for(i=0;i<n;i++)
        {
            scanf("%c",&sit[i]);
            if(findex==-1&&sit[i]=='1')
            {
                findex=i;
            }
        }
        for(i=n-1;i>=0;i--)
        {
            if(lindex==n&&sit[i]=='1')
            {
                lindex=i;
            }
        }
        int result=n;
        if(findex!=-1)
        {
            int rooms=2*(n-findex);
            if(rooms>result)
            {
                result=rooms;
            }
        }
        if(lindex!=n)
        {
            int rooms=2*(n-(n-1-lindex));
            if(rooms>result)
            {
                result=rooms;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
