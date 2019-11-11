// 17:30

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


signed main() {
#ifdef ON
//    freopen("../in.txt", "r", stdin);
//    freopen("../out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = input();
    while (t--) {
        int x = input();
        int y = input();
        cout << (gcd(x, y) == 1 ? "Finite" : "Infinite") << endl;
    }
}
