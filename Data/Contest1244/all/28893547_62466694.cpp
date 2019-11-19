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

int t, n, ans;
string a, b;

int main()
{
    cin >> t;
    while(t--){
        cin >> n >> a;
        ans = a.size();
        b = a;
        reverse(a.begin(), a.end());
        while(!a.empty() && a.back() == '0')
            a.pop_back();
        while(!b.empty() && b.back() == '0')
            b.pop_back();

        ans = max(ans, 2 * (int)a.size());
        ans = max(ans, 2 * (int)b.size());
        cout << ans << '\n';
    }

    return 0;
}
