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
int dp[N];
int solve(int i)
{
    if(i == 0) return 1;
    if(i<0) return 0;
    int& ret = dp[i];
    if(~ret) return ret;
    ret = (solve(i-2)+solve(i-1))%MOD;
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
#else
    //freopen("reduce.in","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    mem(dp,-1);
    string str;
    cin>>str;
    if(count(str.begin(),str.end(),'m')) return puts("0");
    if(count(str.begin(),str.end(),'w')) return puts("0");
    ll out = 1,cnt = 0;
    for(char c:str){
        if(c == 'u') cnt++;
        else out*=solve(cnt),out%=MOD,cnt = 0;
    }
    out*=solve(cnt),out%=MOD,cnt = 0;
    for(char c:str){
        if(c == 'n') cnt++;
        else out*=solve(cnt),out%=MOD,cnt = 0;
    }
    out*=solve(cnt),out%=MOD,cnt = 0;

    cout << out << endl;
    return 0;
}
