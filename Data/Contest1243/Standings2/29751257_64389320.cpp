//be name khoda
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int maxn = 100 * 1001;
const int mod = 1e9+7;

ll a[maxn];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int q; cin>> q;
    while(q--)
    {
        int n; cin>> n;
        for(int i = 1; i <= n; i++) cin>> a[i];
        sort(a+1, a+n+1);
        ll ans = 0;
        for(ll i = 1; i <= n; i++)
            ans = max(ans, min(a[i],n-i+1));
        cout<< ans <<"\n";
    }
}
