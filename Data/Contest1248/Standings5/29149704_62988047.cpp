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

ll mu(ll a,ll b)
{
    if (b==1)
        return a;
    if (b==0) return 1;
    ll k = mu(a,b/2);
    if (b%2==0)
        return k*k%mod;
    else return k*a%mod*k%mod;
}

int n;

ll a[MaxN];

void input()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);ll g1 = 0,g2=0;
    for (int i=0;i<n/2;i++)
    {
        g1+=a[i];
    }
    for (int i=n/2;i<n;i++)
    {
        g2+=a[i];
    }
    cout<<g1*g1+g2*g2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("1.inp","r",stdin);
    //freopen("1.out","w",stdout);
    input();
}
