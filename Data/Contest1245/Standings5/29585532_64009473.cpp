//be name khoda
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 3e5+10;
const ll mod = 1e9+9;

ll n, m;
char ans[120];
ll mark[maxn];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll q; cin>> q;
    while(q--)
    {
        cin>> n;
        ll r, p, s; cin>> r >> p >> s;
        string ss; cin>> ss;
        for(ll i = 0; i < n; i++) mark[i] = 0;

        ll as = 0;
        for(ll i = 0; i < n; i++)
        {
            if(ss[i] == 'R' && p >= 1)
            {
                as++;
                p--;
                ans[i] = 'P';
                mark[i] = 1;
            }
            if(ss[i] == 'P' && s >= 1)
            {
                as++;
                s--;
                ans[i] = 'S';
                mark[i] = 1;
            }
            if(ss[i] == 'S' && r >= 1)
            {
                as++;
                r--;
                ans[i] = 'R';
                mark[i] = 1;
            }
        }
        if(as < ((n+1)/2)){
            cout<<"NO\n";
            continue;
        }

        for(ll i = 0; i < n; i++)
            if(mark[i] == 0)
            {
                if(r >= 1)
                {
                    r--;
                    ans[i] = 'R';
                    continue;
                }
                if(p >= 1)
                {
                    p--;
                    ans[i] = 'P';
                    continue;
                }
                if(s >= 1)
                {
                    s--;
                    ans[i] = 'S';
                    continue;
                }
            }
        cout<<"YES\n";
        for(ll i = 0; i < n; i++)
            cout<< ans[i];
        cout<<"\n";
    }
}
