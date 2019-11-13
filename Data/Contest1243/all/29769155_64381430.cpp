#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define watch(x) cout << (#x) << " is: " << (x) << endl
#define vw(v)                        \
    cout << (#v) << " is: " << endl; \
    for (int B : (v))                \
    {                                \
        cout << B << " ";            \
    }                                \
    cout << endl
#define check(x) cout << "here " << (x) << "?" << endl
#define rep(i, a, b) for (long long i = (a); i < (b); i++)
#define per(i, a) for (long long i = (a - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rv(x) (x).rbegin(), (x).rend()
#define pb push_back
long long const MAX = 2147483647, REALMAX = 9223372036854775806;
int main()
{
    FAST_IO
    int a;
    cin >> a;
    rep(i, 0, a)
    {
        int b;
        cin >> b;
        vector<int> v(b);
        rep(j, 0, b)
        {
            cin >> v[j];
        }
        int maxi = 0;
        sort(all(v));
        for (int j = v.size(); j > 0; j--)
        {
            rep(k, 0, j)
            {
                if (v[v.size() - k - 1] < j)
                {
                    break;
                }
                if (k == j - 1)
                {
                   // watch(j);
                    maxi = max(maxi, j);
                }
            }
        }
        cout << maxi << endl;
    }
}
