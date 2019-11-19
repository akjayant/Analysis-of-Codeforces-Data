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
ll dp[50][2][2][2][2];
string L,R; int n;
ll solve(int ind=0,bool a=0,bool b=0,bool c=0,bool d=0)
{
    if(ind == n) return 1;
    ll& ret = dp[ind][a][b][c][d];
    if(~ret) return ret;
    ret = 0;
    for(int i = 0;i<2;++i)
        for(int j = 0;j<2;++j){
            if(i==j && i==1) continue;
            if(i<L[ind]-'0' && !a) continue;
            if(i>R[ind]-'0' && !b) continue;
            if(j<L[ind]-'0' && !c) continue;
            if(j>R[ind]-'0' && !d) continue;
            ret += solve(ind+1,a||i>L[ind]-'0',b||i<R[ind]-'0',c||j>L[ind]-'0',d||j<R[ind]-'0');
        }
    return ret;
}
string toBinary(int num)
{
	string tmp = "";
	if(!num) tmp = "0";
	while(num) tmp+=( (num&1)+'0'),num>>=1;
	reverse(tmp.begin(),tmp.end());
	return tmp;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
#else
    //freopen("reduce.in","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    int t; sc(t);
    while(t--){
        int l,r;
        sc(l); sc(r);
        L = toBinary(l);
        R = toBinary(r);
        while(sz(L) < sz(R)) L = "0" + L;
        mem(dp,-1); n = sz(R);
        printf("%lld\n",solve());
    }

    return 0;
}
