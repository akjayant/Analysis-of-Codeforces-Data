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

constexpr int N = 100;
ld tmp[N];
int to[N];

int num(int i, int j) {
    if (i % 2 == 0) {
        return N - 10 * i - j - 1;
    }
    return N - 10 * (i + 1) + j;
}

signed main() {
#ifdef ON
//    freopen("../in.txt", "r", stdin);
//    freopen("../out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
//            cerr << num(i, j) << ' ';
            int t = input();
            if (t) {
//                cerr << i << ' ' << j << endl;
//                cerr << i << ' ' << j << endl;
                to[num(i, j)] = num(i - t, j);
            }
        }
    }

    tmp[98] = 6;
    tmp[97] = 6;
    tmp[96] = 6;
    tmp[95] = 6;
    tmp[94] = 6;

    for (int i = 93; i >= 0; --i) {
        for (int r = 1; r <= 6; ++r) {
            if (to[i + r]) {
//                debug(to[i + r]);
                tmp[i] += (1.l / 6) * min(tmp[i + r] + 1, tmp[to[i + r]] + 1);
            } else {
                tmp[i] += (1.l / 6) * (tmp[i + r] + 1);
            }
        }
    }
    cout << fixed << setprecision(10) << tmp[0] << endl;
}
