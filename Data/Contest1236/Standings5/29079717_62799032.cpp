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
const ll MOD = 1e9 + 7;

set <ll> cur;

int main()
{
    fast_io;

    ll n, m, mx = -1;

    cin >> n;
    m = n * n;

    for (int i = 1; i <= m; ++i) cur.insert(i);

    if (n % 2 == 0) {
        for (int i = 1; i <= n; ++i) {
            int who = 0;
            for (int j = 1; j <= n; ++j) {
                if (!who) {
                    cout << *(cur.begin()) << " ";
                    cur.erase(cur.begin());
                }else {
                    cout << *(--cur.end()) << " ";
                    cur.erase(--cur.end());
                }

                who = 1 - who;
            }
            cout << endl;
        }
    }else {
      for (int i = 1; i <= n; ++i) {
            int who = 0;
            for (int j = 1; j < n; ++j) {
                if (!who) {
                    cout << *(cur.begin()) << " ";
                    cur.erase(cur.begin());
                }else {
                    cout << *(--cur.end()) << " ";
                    cur.erase(--cur.end());
                }

                who = 1 - who;
            }

            int num = (cur.size()) / 2 + 1;
            int kek = 0;

            for (auto x : cur) {
                kek++;
                if (kek == num) {
                    cout << x << endl;
                    cur.erase(x);
                    break;
                }
            }

        }
    }

    return 0;
}
