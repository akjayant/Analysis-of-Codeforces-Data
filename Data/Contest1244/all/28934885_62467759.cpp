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
    REP(i, t)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int ans1 = 0, ans2= 0;
        if (a % c != 0)
            ans1++;
        ans1 += a / c;
        if (b % d != 0)
            ans2++;
        ans2 += b / d;
        if (ans1 + ans2 > k)
            cout << -1 << endl;
        else
            cout << ans1 << ' ' << ans2 << endl;
    }
}

// clang++ -std=c++11 -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion -Wfloat-equal -fsanitize=address,undefined -D_GLIBCXX_DEBUG -DDEBUG -ggdb con1.cpp -o a
