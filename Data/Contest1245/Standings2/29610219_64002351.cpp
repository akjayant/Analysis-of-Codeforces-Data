#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5;
const ll MOD = 1e9+7;

int N;
string S;
ll fact[MAXN+10], invfact[MAXN+10], ans=1;

ll mypow(ll x, ll y)
{
    if(y==0) return 1;
    if(y%2) return mypow(x, y-1)*x%MOD;
    ll t=mypow(x, y/2);
    return t*t%MOD;
}

ll C(ll n, ll m) { return fact[n]*invfact[m]%MOD*invfact[n-m]%MOD; }
ll H(ll n, ll m) { return C(n+m-1, m); }

ll f(int x)
{
    int i, j;
    ll ret=0;
    for(i=1; i<=x && x-2*i+2>=0; i++)
    {
        ret+=H(i, x-2*i+2);
        ret%=MOD;
    }
    return ret;
}

int main()
{
    int i, j;

    fact[0]=1;
    for(i=1; i<=MAXN; i++) fact[i]=fact[i-1]*i%MOD;
    invfact[MAXN]=mypow(fact[MAXN], MOD-2);
    for(i=MAXN-1; i>=0; i--) invfact[i]=invfact[i+1]*(i+1)%MOD;

    cin>>S;
    N=S.size();

    vector<int> T;
    char bef='!';
    int cnt=0;
    for(i=0; i<N; i++)
    {
        if(S[i]=='m' || S[i]=='w') return !printf("0");
        if(S[i]=='u' || S[i]=='n')
        {
            if(S[i]!=bef)
            {
                if(bef!='!') T.push_back(cnt);
                cnt=1;
                bef=S[i];
            }
            else
            {
                cnt++;
            }
        }
        else
        {
            if(bef!='!') T.push_back(cnt);
            cnt=0;
            bef='!';
        }
    }
    if(bef!='!') T.push_back(cnt);
    for(auto it : T) ans=ans*f(it)%MOD;
    printf("%lld", ans);
}
