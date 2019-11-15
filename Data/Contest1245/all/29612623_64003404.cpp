// 17:31

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

#define ON

#ifdef ON
#define debug(x) cerr << #x << " = " << (x) << endl
#else
#define debug(x)
#endif


template<typename T = int>
T input() {
    T res;
    cin >> res;
    return res;
}

template<typename It>
void input_seq(It begin, It end, istream &in = cin) {
    generate(begin, end, input<typename remove_reference<decltype(*begin)>::type>);
}

template<class It>
void output(It begin, It end, ostream &out = cerr) {
    while (begin != end) {
        out << *(begin++) << ' ';
    }
    out << endl;
}

const char let[3]{'R', 'P', 'S'};

signed main() {
#ifdef ON
//    freopen("../in.txt", "r", stdin);
//    freopen("../out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<char, int> f;
    f['R'] = 0;
    f['P'] = 1;
    f['S'] = 2;

    int t = input();
    while (t--) {
        int n = input();
        int val[3];
        val[0] = input(), val[1] = input(), val[2] = input();
        auto str = input<string>();

        int cnt = 0;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            int num = f[str[i]];
            if (val[(num + 1) % 3]) {
                val[(num + 1) % 3]--;
                ans[i] = ((num + 1) % 3);
                ++cnt;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (ans[i] == -1) {
                if (val[0]) {
                    ans[i] = 0;
                    val[0]--;
                } else if (val[1]) {
                    ans[i] = 1;
                    val[1] --;
                } else {
                    ans[i] = 2;
                    val[2] --;
                }
            }
        }
        if (cnt >= (n + 1) / 2) {
            cout << "YES" << endl;
            for (int i : ans) {
                cout << let[i];
            }
            cout << endl;
        }else {
            cout << "NO" << endl;
        }
    }
}
