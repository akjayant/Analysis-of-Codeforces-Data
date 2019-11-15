#include<bits/stdc++.h>
using namespace std;
#define MAX 300001
#define MAX_POINTS 201
#define DEFAULT 1;
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define MOD 1000000007
long long int bigmod(long long int a,long long int b)
{
    if(b==0) return 1;
    long long int res=bigmod(a,b/2);
    res=(res*res)%MOD;
    if(b%2) res=(res*a)%MOD;
    return res;
}
int main()
{
    long long int n,m;
    scanf("%I64d %I64d",&n,&m);
    long long int r=(bigmod(2,m)-1+MOD)%MOD;
    r=bigmod(r,n);
    printf("%I64d",r);
    return 0;
}
