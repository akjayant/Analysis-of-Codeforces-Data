// Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>

using namespace std;

#define double long double
#define Long long long
#define EPS 1e-12
#define PI acos(-1.0)

#define MAX 200000
#define MOD 1000000007

#define POS_INF (1LL << 55)
#define NEG_INF (-(1LL << 55))

#define RIGHT_MOST_INDEX (1 << 30)
#define LEFT_MOST_INDEX (-(1 << 30))

#define MEMSET(x,y) memset(x, y, sizeof(x))
#define PB push_back
#define MP make_pair
#define SORT(A) sort(A.begin(), A.end());
#define REVERSE(A) reverse(A.begin(), A.end());

Long ar[MAX+9];
Long dp[MAX+9][5][5];
Long vis[MAX+9][5][5];


Long bigmod(Long x, Long y, Long mod)
{
    Long ret = 1;
    x %= mod;

    while(y)
    {
        if (y&1) ret = (ret * x) % mod;
        x = (x * x) % mod, y >>= 1;
    }
    return ret;
}

Long check(Long curr, Long a, Long b, Long n)
{
    if(curr > n) return 1;
    if(vis[curr][a][b]) return dp[curr][a][b];
    vis[curr][a][b] = 1;

    Long ans = 0;
    if(a != 1 || b != 1) ans += check(curr+1, b, 1, n);
    if(a != 2 || b != 2) ans += check(curr+1, b, 2, n);
    ans %= MOD;

    return dp[curr][a][b] = ans;
}

int main()
{
    Long i,j,k,l,n,m,tot,temp,curr,val,prev,a,b,c,t,ans,flag,x,y,siz,ii,jj,xx,yy,ind,len,q,xxx,yyy,d;

    cin>>n>>m;

    MEMSET(vis, 0);
    ans = check(1, 0, 0, n);

    a = ans - 2;
    a %= MOD;
    a += MOD;
    a %= MOD;

    MEMSET(vis, 0);
    ans = check(1, 0, 0, m);
    ans += a;
    ans %= MOD;

    cout<<ans<<endl;
}
