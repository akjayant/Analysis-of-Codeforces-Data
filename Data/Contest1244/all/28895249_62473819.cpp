#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;
ll ara[400000];
ll csum[400000];

ll moves(ll mid)
{
    ll re = 1e17;
    for(ll i = 1; i <= n; i++){

        ll cur1 = ara[i];
        ll cur2 = ara[i] + mid;

        ll pos1 = i - 1;
        ll pos2 = upper_bound(ara + 1, ara + n + 1, cur2) - ara;

        ll tmp1 = (i - 1) * ara[i] - csum[i - 1];
        ll tmp2 = (csum[n] - csum[pos2 - 1]) - cur2 * (n - pos2 + 1);
        re = min(re, tmp1 + tmp2);

    }

    for(ll i = 1; i <= n; i++){

        ll cur1 = ara[i] - mid;
        ll cur2 = ara[i];

        ll pos1 = lower_bound(ara + 1, ara + n + 1, cur1) - ara;
        pos1--;
        ll pos2 = i;

        ll tmp1 = pos1 * cur1 - csum[pos1];
        ll tmp2 = (csum[n] - csum[pos2]) - cur2 * (n - pos2);
        re = min(re, tmp1 + tmp2);

    }

    return re;
}

int main()
{
    cin >> n >> k;
    for(ll i = 1; i <= n; i++) scanf("%lld", &ara[i]);

    sort(ara + 1, ara + n + 1);

    for(ll i = 1; i <= n; i++) csum[i] = csum[i - 1] + ara[i];

    ll lo = 0, hi = ara[n] - ara[1];
    ll anss = hi;

    while(lo <= hi){

        ll mid = (lo + hi) / 2;
        if(moves(mid) <= k){
            anss = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << anss << endl;

    return 0;
}