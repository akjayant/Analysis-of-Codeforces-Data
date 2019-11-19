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
    ic(t)
    f(t)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int a1 = (a + c - 1) / c, a2 = (b + d - 1) / d;
        if(a1 + a2 <= k)
        {
            cout << a1 << " " << a2 << "\n";
        }
        else cout << -1 << "\n";
    }
}
