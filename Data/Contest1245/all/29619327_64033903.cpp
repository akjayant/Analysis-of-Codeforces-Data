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
#define rALL(x) rbegin(x), rend(x)
    template<class T, class Compare> using p_queue = priority_queue<T, vector<T>, Compare>;
    template<class T> using min_queue = p_queue<T, greater<T>>;
    template<class T> using max_queue = p_queue<T, less<T>>;

    template<class T> bool min_update(T& X, const T& A){ if(X > A) {X = A; return true;} return false; }
    template<class T> bool max_update(T& X, const T& A){ if(X < A) {X = A; return true;} return false; }
    using V_Set = unordered_set<int>;
    using E_Set = unordered_map<int, V_Set>;

    ll operator"" _64(unsigned long long x){ return ll(x); }
    ull operator"" _64u(unsigned long long x){ return ull(x); }

    template<class T>
    vector<T> make_vector(int n, T t){
        return vector<T>(n, t);
    }
    template<class ...Ts>
    auto make_vector(int n, Ts ... ts){
        return vector<decltype(make_vector(ts...))>(n, make_vector(ts...));
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
    vector<ll> x, y;
    vector<ll> c, k;
    vector<int> cpoint;
    vector<int> pi, pj;
    void run(){
        is >> N;
        if(!is) return;
        x.resize(N), y.resize(N);
        for (int i = 0; i < N; ++i) { is >> x[i] >> y[i]; } // end i
        c.resize(N); for (auto &&ci : c ) { is >> ci; } // end ci
        k.resize(N); for (auto &&ki : k) { is >> ki; } // end ki
        ll cost = prim();

        os << cost << '\n';
        os << cpoint.size() << endl;
        for (auto &&cp : cpoint) {
            os << cp << ' ';
        } // end cp
        os << endl;
        os << pi.size() << endl;
        for (int i = 0; i < pi.size(); ++i) {
            os << pi[i] << ' ' << pj[i] << '\n';
        } // end i




    }


    ll d(int i, int j){
        return abs(x[i] - x[j]) + abs(y[i] - y[j]);
    }



    ll prim(){
        vector<ll> distances(N, INF);
        vector<ll> rt(N, -1);
        for (int i = 0; i < N; ++i) {
            distances[i] = c[i];
            rt[i] = i;
        } // end i
        vector<bool> in(N, false);
        ll cost  = 0;
        for (int i = 0; i < N; ++i) {
            int minj = 0;
            for (int j = 1; j < N; ++j) {
                if(distances[j] < distances[minj]){
                    minj = j;
                }
            } // end j
            if(rt[minj] == minj){
                cpoint.push_back(minj+1);
            }
            else{
                pi.push_back(minj+1);
                pj.push_back(rt[minj]+1);
            }
            cost += distances[minj];
            in[minj] = true;

            for (int j = 0; j < N; ++j) {
                if(in[j]) distances[j] = INF;
                else{
                    if(min_update(distances[j], d(minj, j) * (k[j] + k[minj]))){
                        rt[j] = minj;
                    }
                }
            } // end k
        } // end i
        return cost;
    }
};

int main(int argc, char *argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(16) << scientific;
#ifdef DEBUG
    string test_cases = "test_D.txt";
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
