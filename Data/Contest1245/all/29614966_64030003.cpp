#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define M 1000000007
using namespace std;
ll power(ll a, ll b)
{
    if(b == 0)
        return 1;
    ll x = power(a, b/2);
    x = x*x;
    if(b%2)
        x = x*a;
    return x;
}
ll dp[40][2][2];
ll cal(ll i, ll j, ll k, vector <ll> &a, vector <ll> &b)
{
    if(i < 0)
        return 1;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    if(j == 0 and k == 0)
        return dp[i][j][k] = power(3,i+1);
    if(j == 0 and k == 1)
    {
        if(b[i] == 0)
            return dp[i][j][k] = 2*cal(i-1, j, k, a, b);
        return dp[i][j][k] = 2*cal(i-1,0,0,a,b) + cal(i-1,j,k,a,b);
    }
    if(j == 1 and k == 0)
    {
        if(a[i] == 1)
            return dp[i][j][k] = cal(i-1,j,k,a,b);
        return dp[i][j][k] = 2*cal(i-1,j,k,a,b) + cal(i-1,0,0,a,b);
    }
    if(a[i] == 0 and b[i] == 0)
        return dp[i][j][k] = cal(i-1,1,1,a,b) + cal(i-1,0,1,a,b);
    if(a[i] == 0 and b[i] == 1)
        return dp[i][j][k] = cal(i-1,1,1,a,b)+cal(i-1,0,0,a,b)+cal(i-1,1,0,a,b);
    if(a[i] == 1 and b[i] == 0)
        return dp[i][j][k] = cal(i-1,1,1,a,b);
    return dp[i][j][k] = cal(i-1,1,0,a,b);
}
ll cal2(ll i, ll j, ll k, vector <ll> &v)
{
    if(i < 0)
        return 1;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    if(j == 0 and k == 0)
        return dp[i][j][k] = power(3,i+1);
    if(j == 0 and k == 1)
    {
        if(v[i] == 0)
            return dp[i][j][k] = 2*cal2(i-1, j, k, v) + cal2(i-1,0,0,v); 
        return dp[i][j][k] = cal2(i-1,j,k,v);
    }
    if(j == 1 and k == 0)
    {
        if(v[i] == 0)
            return dp[i][j][k] = 2*cal2(i-1, j, k, v) + cal2(i-1,0,0,v);
        return dp[i][j][k] = cal2(i-1,j,k,v);
    }
    if(v[i] == 1)
        return 0;
    return dp[i][j][k] = cal2(i-1,1,1,v) + cal2(i-1,1,0,v)+cal2(i-1,0,1,v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,l,r,n,ans,i,tmp;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        vector <ll> a,b;
        tmp = l;
        if(l == 0 and r == 0)
        {
            cout<<1<<endl;
            continue;
        }
        while(l)
        {
            a.pb(l%2);
            l = l/2;
        }
        while(r)
        {
            b.pb(r%2);
            r = r/2;
        }
        if(a.size() == b.size())
        {
            cout<<0<<endl;
            continue;
        }
        n = b.size();
        while(a.size() < n)
            a.pb(0);
        for(i=0;i<40;i++)
            dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -1;
        ans = cal(n-2, 1, 1, a, b);
        ans = 2*ans;
        for(i=0;i<40;i++)
            dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -1;
        ans += cal2(n-2, 1, 1,a);
        cout<<ans<<endl;
    }
    return 0;
}
