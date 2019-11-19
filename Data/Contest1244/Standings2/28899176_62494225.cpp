#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using vi = vector<int>;
#define f(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define c(n) cout << n << " ";
#define ci(n) cin >> n;
#define cn cout << "\n";
#define ic(n) int n; cin >> n;
#define lc(n) int n; cin >> n;
#define all(a) a.begin(), a.end()
#define pri(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
#define sc(a, n) int a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define scl(a, n) ll a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define pb push_back
#define eb emplace_back
#define int long long
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    sc(a, n)
    sort(a, a + n);
    vector<int> b, ams;
    int am = 0;
    b.pb(a[0]);
    for(int i = 0; i < n; i++)
    {
        if(i == 0 || a[i] == a[i - 1]) am++;
        else ams.pb(am), am = 1, b.pb(a[i]);
    }
    ams.pb(am);
    n = b.size();
    int l = 0, r = n - 1, d = b[r] - b[l], cl = ams[l], cr = ams[r];
    while(r > l && k > 0)
    {
        if(cl <= cr)
        {
            if((b[l + 1] - b[l]) * cl <= k)
            {
                d -= (b[l + 1] - b[l]);
                k -= (b[l + 1] - b[l]) * cl;
                l++;
                cl += ams[l];
            }
            else
            {
                d -= k / cl;
                break;
            }
        }
        else
        {
            if((b[r] - b[r - 1]) * cr <= k)
            {
                d -= (b[r] - b[r - 1]);
                k -= (b[r] - b[r - 1]) * cr;
                r--;
                cr += ams[r];
            }
            else
            {
                d -= k / cr;
                break;
            }
        }
    }
    cout << d;
}
