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
    int t;
    cin >> t;
    REP(f, t)
    {
        int n, m;
        cin >> n;
        VI p(n);
        REP(i, n)
            cin >> p[i];
        cin >> m;
        VI q(m);
        REP(i, m)
            cin >> q[i];
        L p1 = 0, n1 = 0, p2 = 0, n2 = 0;
        REP(i, n)
        {
            if (p[i] % 2 == 0)
                p1++;
            else
                n1++;
        }
        REP(i, m)
        {
            if (q[i] % 2 == 0)
                p2++;
            else
                n2++;
        }
        cout << p1 * p2 + n1 * n2 << endl;
    }
}

// clang++ -std=c++11 -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion -Wfloat-equal -fsanitize=address,undefined -D_GLIBCXX_DEBUG -DDEBUG -ggdb con1.cpp -o a
