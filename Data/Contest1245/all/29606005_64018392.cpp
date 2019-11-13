#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
ll mod = 1000LL*1000LL*1000LL + 7;



int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    string s;
    cin >> s;
    vector<ll> f(s.size());
    f[0] = f[1] = 1;
    for(int i=2;i<s.size()+1;i++)
    {
        f[i] = (f[i-1] + f[i-2])%mod;
    }
    ll out = 1;
    ll k = 0;
    ll h = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == 'm' || s[i] == 'w')
        {
            cout << 0;
            return 0;
        }
        if(s[i] == 'n')
        {
            k++;
        }
        else
        {
            if(k>1)
            {
                out *= f[k];
                out %= mod;
            }
            k = 0;
        }
        if(s[i] == 'u')
        {
            h++;
        }
        else
        {
            if(h>1)
            {
                out *= f[h];
                out %= mod;
            }
            h = 0;
        }
    }
    out *= f[h];
    out %= mod;
    out *= f[k];
    out %= mod;
    cout << out;
    return 0;
}
