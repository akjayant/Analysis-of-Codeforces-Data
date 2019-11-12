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

    vector<vector<int>> vec;

    ll calcF(int A, int B){
        ll count = 0;
        for (auto &&a : vec[A]) {
            for (auto &&b : vec[B]) {
                if(a > b) count++;
            } // end b
        } // end a
        return count;
    }
};

int main(int argc, char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(16) << scientific;
#ifdef XELMH
    string test_cases = "test_C.txt";
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
    is >> N;
    if(!is) return;
    vec = make_mdvector(N, N, 0);
    int i, j, t;
    int di = 1;
    i = j = 0;  t = 1;
    while(t <= N*N){
        vec[i][j] = t++;
        i += di;
        if(i == N){
            di = -1;
            j++; i-=1;
        }
        if(i == -1){
            di = 1;
            j++; i +=1;
        }
    }

    for (int i = 0; i < N; ++i) {
        os << vec[i];
    } // end i

//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            if(i == j) continue;
//            os << i << ':' << j << "=" << calcF(i, j) << '\n';
//        } // end j
//    } // end i

}
