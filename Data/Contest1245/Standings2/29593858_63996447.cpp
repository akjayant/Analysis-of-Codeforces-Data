#include <bits/stdc++.h>
using namespace std;
#define sc(x)            scanf("%d",&x)
#define scc(x)           scanf("%c",&x)
#define scl(x)           scanf("%lld",&x)
#define sz(v)	     	(v.size())
#define mem(v, d)		memset(v, d, sizeof(v))
#define oo				2000000100
#define OO				2000000000000000100
#define PI 3.14159265
#define s second
#define f first
#define Ceil(x,y) ((x+y-1)/y)
#define EPS 1e-8
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const double pi=3.14159265358979323846264338327950288419716939937510582097494459;
typedef unsigned int uint;
typedef long long ll;
int dX[] = {0,1,0,-1};
int dY[] = {1,0,-1,0};
string alpha = "abcdefghijklmnopqrstuvwxyz";
const int N = 100100;
const int MOD = 1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
#else
    //freopen("reduce.in","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    int x,y,t;
    sc(t);
    while(t--){
        sc(x); sc(y);
        if(__gcd(x,y)==1) puts("Finite");
        else puts("Infinite");
    }
    return 0;
}
