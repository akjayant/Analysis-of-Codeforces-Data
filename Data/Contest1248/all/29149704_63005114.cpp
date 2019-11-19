#include <bits/stdc++.h>
using namespace std;

#define el '\n'

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

template<typename so>

void read(so &x)
{
    x=0;
    char c;ll dem= 0;
    for (c=getchar();c<'0'||c>'9';c=getchar())
    {
        dem++;if (dem==100) return;
    }
    for (;c>='0'&&c<='9';c=getchar())
    {
        x = x*10+c-'0';
    }
}

const ll MaxN = 1e6+10;

const ll mod = 1e9+7;

int n,m;

ll a[1000][1000];

ll add[MaxN];


void input()
{
    cin>>n>>m;
    ll val = 0;
    add[0] = 2;
    add[1] = 2;
    add[2] = 2;
    for (int i=3;i<=100000;i++)
    {
        add[i] = (add[i-1]+add[i-2])%mod;
    }
    for (int i=0;i<n;i++)
    {
        val = (val + add[i])%mod;
    }
    for (int i=1;i<m;i++)
    {
        val = (val+add[i])%mod;
    }
    cout<<val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("1.inp","r",stdin);
    //freopen("1.out","w",stdout);
    input();
}
