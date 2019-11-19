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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i = 0, j = n - 1;
        while (i < n && s[i] == '0')
            i++;
        while (j > -1 && s[j] == '0')
            j--;
        int ans = 0;
        if (i == n)
            ans = n;
        else
            ans = max(2 * n - 2 * i, 2 * n - 2 * (n - j - 1));
        cout << ans << endl;
    }
}

// clang++ -std=c++11 -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion -Wfloat-equal -fsanitize=address,undefined -D_GLIBCXX_DEBUG -DDEBUG -ggdb con1.cpp -o a
