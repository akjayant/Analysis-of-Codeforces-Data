#pragma GCC optimize(3)//手动Ox优化
#include<bits/stdc++.h>
#define N 210
#define INF 0x3f3f3f3f
#define eps 1e-5
#define pi 3.141592653589793
#define LL long long
#define pb push_back
#define cl clear
#define si size
#define lb lowwer_bound
#define mem(x) memset(x,0,sizeof x)
#define sc(x) scanf("%d",&x)
#define scc(x,y) scanf("%d%d",&x,&y)
#define sccc(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define db double
using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    sc(T);
    while(T--){
        int a,b;
        scc(a,b);
        if (__gcd(a,b)==1) puts("Finite");else puts("Infinite");
    }
    return 0;
}