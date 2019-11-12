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
    int TC;
    cin >> TC;
    while (TC--)
    {
        int a, sum = 0;
        cin >> a;
        string s, s1, t, t1;
        cin >> s >> s1;
        rep(i, 0, a)
        {
            if (s[i] != s1[i])
            {
                t.pb(s[i]), t1.pb(s1[i]);
                sum++;
            }
        }
        if (sum != 2 && sum != 0)
        {
            cout << "No" << endl;
            continue;
        }
        swap(t[0], t1[0]);
        sort(all(t)), sort(all(t1));
        if (t == t1)
        {
            cout << "Yes" << endl;
            continue;
        }
        else
        {
            cout << "No" << endl;
            continue;
        }
    }
}
