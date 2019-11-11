#include<bits/stdc++.h>
#define ll long long
#define here cout<<"here\n"
#define pb push_back
#define mp make_pair
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf printf
#define pfi(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
using namespace std;

const ll mod = 1e9+7;

const int MAX = 100005;

ll modexp(ll x, ll n)
{
    if(n==0)
        return 1LL;
    if(n%2==0)
    {
        ll y = modexp(x,n/2)%mod;
        return (y*y)%mod;
    }
    return (x*modexp(x,n-1)%mod)%mod;
}

ll powr(ll x, ll n)
{
    ll ans = 1;
    for(int i=1;i<=n;i++)
        ans=ans*x;
    return ans;
}

ll f[MAX];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    f[0] = 1;
    for(int i=1;i<MAX;i++)
    {
        f[i] = (f[i-1]*i)%mod;
    }
    string s;
    cin>>s;
    ll ans = 1;
    bool flag = 0;
    int n = s.size();
    for(int i=0;i<n;)
    {
        int cnt = 0;
        char ch = s[i];
        if(ch=='m'||ch=='w')
            return 0*pf("0\n");
        if(ch!='u'&&ch!='n')
        {
            i++;
            continue;
        }
        while(i<n&&s[i]==ch)
        {
            i++;
            cnt++;
        }
        if(cnt==1)
        {
            // flag = 1;
            continue;
        }
        ll temp = 0;
        for(int w=1;(cnt-w*2)>=0;w++)
        {
            ll rem = cnt - w*2;
            ll num = f[rem + w];
            ll den = (f[rem]*f[w])%mod;
            ll aux = (num*modexp(den,mod-2))%mod;
            temp = (temp+aux)%mod;
        }
        ans = (ans*(temp+1)%mod)%mod;
    }
    pfl(ans);
    return 0;
}