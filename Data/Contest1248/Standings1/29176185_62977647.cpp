#include <bits/stdc++.h>

#define fi first
#define se second
#define m_p make_pair
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

typedef long long ll;

const int MAXN = 1123456;
const int MAXINT = 2147483098;
const ll MAXLL = 9223372036854775258LL;

int main()
{
    fast_io;

    int t;

    cin >> t;
    while(t--) {
        int n;
        ll odd1 = 0, even1 = 0, odd2 = 0, even2 = 0;

        cin >> n;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (a % 2) odd1++;
            else even1++;
        }
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (a % 2) odd2++;
            else even2++;
        }
        cout << even1 * even2 + odd1 * odd2 << endl;
    }

    return 0;
}
