#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second

using namespace std;

const double pi = acos(-1);
const int N = 1e6 + 6, mod = 998244353, M = 1e7 + 7;
const ll MAX = 5e18;

int T, n, a[N], ans;

int main()
{
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        for(int i = 1; i <= n; i++){
            if(a[i] >= i)
                ans = i;
        }
        cout << ans << '\n';
    }

    return 0;
}
