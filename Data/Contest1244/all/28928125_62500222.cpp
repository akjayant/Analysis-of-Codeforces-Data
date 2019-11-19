#include<bits/stdc++.h>
#define ll long long
#define S second
#define F first

using namespace std;

const int N = 1e5+5;

ll arr[N];
deque <pair<ll, ll> > Q;

int main()
{
    ll ans = 0;
    ll n, k;
    scanf("%lld%lld", &n, &k);
    for(int i = 0 ; i < n ; i++) scanf("%lld", arr + i);
    sort(arr, arr+n);
    for(int i = 0 ; i < n ; i++)
    {
        if(Q.size() and Q.back().F == arr[i])
        {
            Q[Q.size()-1].S++;
        }
        else
        {
            Q.push_back({arr[i], 1});
        }
    }
    // for(auto i:Q) cout<<i.F<<" "<<i.S<<endl;
    ans = Q.back().F - Q[0].F;
    while(k > 0 and Q.size() > 1)
    {
        if(Q[0].S < Q.back().S)
        {
            if(k >= (Q[1].F - Q[0].F) * Q[0].S)
            {
                k -= (Q[1].F - Q[0].F) * Q[0].S;
                Q[1].S += Q[0].S;
                Q.pop_front();
            }
            else
            {
                Q[0].F += (k / Q[0].S);
                return printf("%lld", Q.back().F - Q[0].F), 0;
            }
        }
        else
        {
            if(k >= (Q.back().F - Q[Q.size()-2].F) * Q.back().S)
            {
                k -= (Q.back().F - Q[Q.size()-2].F) * Q.back().S;
                Q[Q.size()-2].S += Q.back().S;
                Q.pop_back();
            }
            else
            {
                Q[Q.size()-1].F -= k / Q.back().S;
                return printf("%lld", Q.back().F - Q[0].F), 0;
            }
        }
        ans = Q.back().F - Q[0].F;
        // cout<<k<<" "<<Q.front().F<<" "<<Q.back().F<<endl;
    }
    printf("%lld", ans);
}
