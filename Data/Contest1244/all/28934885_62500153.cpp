#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define L long long
#define MP make_pair
#define REP(i, n) for(int i = 0; i < n; ++i)
#define REPR(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, a, b) for(int i = b - 1; i >= a; --i)
#define EB emplace_back
#define ST first
#define ND second
#define S size()
#define RS resize

using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using PI = pair<int, int>;
using VPI = vector<PI>;
using VVPI = vector<VPI>;
using VL = vector<L>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VC = vector<char>;
using VVC = vector<VC>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    L k;
    cin >> n >> k;
    VL b(n);
    REP(i, n)
        cin >> b[i];
    sort(b.begin(), b.end());
    vector<pair<L, L> > a(1);
    a[0] = MP(b[0], (L)1);
    FOR(i, 1, n)
    {
        if (b[i] == b[i - 1])
            a.back().ND++;
        else
            a.EB(MP(b[i], (L)1));
    }
    int r = int(a.S);
    int poc = 0, kon = r - 1;
    while (k > 0 && poc < kon)
    {
        if (a[poc].ND <= a[kon].ND)
        {
            if ((a[poc + 1].ST - a[poc].ST) * a[poc].ND <= k)
            {   
                k -= (a[poc + 1].ST - a[poc].ST) * a[poc].ND;
                a[poc + 1].ND += a[poc].ND;
                poc++;
            }
            else
            {
                a[poc].ST += k / a[poc].ND;
                k = 0;
            }
        }
        else
        {
            if ((a[kon].ST - a[kon - 1].ST) * a[kon].ND <= k)
            {   
                k -= (a[kon].ST - a[kon - 1].ST) * a[kon].ND;
                a[kon - 1].ND += a[kon].ND;
                kon--;
            }
            else
            {
                a[kon].ST -= k / a[kon].ND;
                k = 0;
            }
        }
    }
    cout << a[kon].ST - a[poc].ST;
}

// clang++ -std=c++11 -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion -Wfloat-equal -fsanitize=address,undefined -D_GLIBCXX_DEBUG -DDEBUG -ggdb con1.cpp -o a
