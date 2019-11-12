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
        int a, b, c, res = 0;
        cin >> a >> b >> c;

        while(b > 0 && c > 1) b--, c -= 2, res += 3;
        while(a > 0 && b > 1) a--, b -= 2, res += 3;


        cout << res << endl;
    }


    return 0;
}
