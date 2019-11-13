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
    ic(n)
    int h = n / 2;
    for(int g = 0; g < n; g++)
    {
        for(int i = g; i < g + h * n; i += n)
        {
            cout << i + 1 << " ";
        }
        for(int i = n * n - 1 - g; i >= n * n - 1 - g - n * (n - h - 1); i -= n)
        {
            cout << i + 1 << " ";
        }
        cn
    }
}
