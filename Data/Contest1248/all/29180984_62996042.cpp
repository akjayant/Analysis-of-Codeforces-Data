#include<bits/stdc++.h>
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
long long int a,b,c,d;

void fast_fib(long long int n,long long int ans[])
{
    if(n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;
        return;
    }
    fast_fib((n/2),ans);
    a = ans[0];             /* F(n) */
    b = ans[1];             /* F(n+1) */
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;      /* F(2n) */
    d = (a*a + b*b) % MOD;  /* F(2n + 1) */
    if(n%2 == 0)
    {
        ans[0] = c;
        ans[1] = d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c+d;
    }
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n,m;
    cin>>n>>m; 
        long long int ans[2]={0};
        long long int bans[2]={0};
        fast_fib(n+1,ans); fast_fib(m+1,bans);
        long long sum=ans[0]+bans[0]-1;
        sum%=MOD;
        sum*=2;
        sum%=MOD;
        cout<<sum;    
    
    return 0;
}

