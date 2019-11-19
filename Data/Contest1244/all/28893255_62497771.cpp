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
long long int gcd(long long int a,long long int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main ()
{
    long long int n,p,w,d;
    scanf("%I64d %I64d %I64d %I64d",&n,&p,&w,&d);
    long long int g=gcd(w,d);
    if(p%g)
    {
        printf("-1");
        return 0;
    }
    p=p/g;
    w=w/g;
    d=d/g;
    long long int x,y=-1;
    long long int div_by_w=p/w;
    for(x=div_by_w;x>=div_by_w-w&&x>=0;x--)
    {
        if((p-x*w)%d==0)
        {
            y=(p-x*w)/d;
            break;
        }
    }
    if(x>=0&&y>=0&&x+y<=n)
    {
        printf("%I64d %I64d %I64d",x,y,n-x-y);
    }
    else
    {
        printf("-1");
    }
    return 0;
}