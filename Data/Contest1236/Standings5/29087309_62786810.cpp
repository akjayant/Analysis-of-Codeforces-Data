#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <bitset>
#include <tuple>
#include <cmath>
#include <complex>
#include <algorithm>
#include <utility>
#include <regex>
#include <cstdint>
#include <numeric>
#include <functional>
#include <cassert>

using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll INF = 1'000'000'000'000'000'000;
namespace utils{
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
    template<class T, class Compare> using p_queue = priority_queue<T, vector<T>, Compare>;
    template<class T> using min_queue = p_queue<T, greater<T>>;
    template<class T> using max_queue = p_queue<T, less<T>>;

    template<class T> bool up_min(T& X, const T& A){ if(X > A) {X = A; return true;} return false; }
    template<class T> bool up_max(T& X, const T& A){ if(X < A) {X = A; return true;} return false; }

    ll operator"" _64(unsigned long long x){ return ll(x); }
    ull operator"" _64u(unsigned long long x){ return ull(x); }

    template<class T>
    vector<T> make_mdvector(int n, T t){
        return vector<T>(n, t);
    }
    template<class ...Ts>
    auto make_mdvector(int n, Ts ... ts){
        return vector<decltype(make_mdvector(ts...))>(n, make_mdvector(ts...));
    }

    inline ll bit(int x){
        return 1ll << x;
    }

    template<class T>
    istream& operator>>(istream& is, vector<T>& v){
        for (auto &&x : v) { is >> x; } return is;
    }

    template<class T>
    ostream& operator<<(ostream& os, const vector<T>& v){
        for (auto &&x : v) { os << x << ' '; } cout << endl; return os ;
    }
}
using namespace utils;

class solver{
    istream& is;
    ostream& os;

public:
    solver(istream& I, ostream& O) :is(I), os(O) {}
    ll N;
    void run();
};

int main(int argc, char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(16) << scientific;
#ifdef XELMH
    string test_cases = "test_A.txt";
    cerr << test_cases << " -->" << endl;
    auto fs = fstream(test_cases, fstream::in);
    int loop = 0;
    while(fs) {
        loop++;
        cout << '#' << loop << "#------\n";
        solver(fs, cout).run();
    }
    if(loop <= 1) {
        cout << "===" << endl;
        while(cin) solver(cin, cout).run();
    }
#else
    solver(cin, cout).run();
#endif
    return 0;
}


void solver::run(){
    int t;
    is >> t;
    if(!is) return;
    while(t--){
        int a, b, c;
        is >> a >> b >> c;
        int ans = 0;
        for (int ai = 0; ai <= a; ++ai) {
            int remb = b - 2*ai;
            for (int bi = 0; bi <= remb; ++bi) {
                int remc = c - 2*bi;
                if(remc < 0) break;
                ans = max(ans, ai*3 + bi * 3);

            } // end bi

        } // end ai
        os << ans << endl;

    }
}
