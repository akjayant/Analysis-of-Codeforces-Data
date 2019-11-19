#include <bits/stdc++.h>
using namespace std;

// macros
#define overload_rep(_1, _2 ,_3 ,name, ...) name
#define re_p(i, n) for(int i = 0; i < (n); ++i)
#define r_ep(i, x, y) for(int i = (x); i <= (y); ++i)
#define rep(...) overload_rep(__VA_ARGS__, r_ep, re_p)(__VA_ARGS__)
#define all(a) a.begin(), a.end()
#ifndef STOP_DEBUG
#define debug(...)\
    do { cerr << boolalpha << "[" << #__VA_ARGS__ << "]:";\
    debug_cerr(__VA_ARGS__); cerr << noboolalpha; } while (0)
#else
#define debug(...)
#endif

// functions
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
void debug_cerr(){ cerr << '\n'; }
template<class Head, class... Tail>
void debug_cerr(Head head, Tail... tail){
    cerr << ' ' << head;
    debug_cerr(tail...);
}

// cin/cout setup
struct IoSetup{
    IoSetup(){
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} iosetup;

// Codeforces Round #594 (Div. 2)

template<class MeetSemiLattice> 
struct SparseTable{ // Sparse Table
private:
    vector<vector<MeetSemiLattice>> dat;
    vector<int> height;
public:
    SparseTable() {}
    SparseTable (const vector<MeetSemiLattice> &vec) { init(vec); }
    void init(const vector<MeetSemiLattice> &vec) { // initialization
        int n = (int)vec.size(), h = 0;
        while((1 << h) <= n) ++h;
        dat.assign(h, vector<MeetSemiLattice>(1 << h));
        height.assign(n + 1, 0);
        for(int i = 2; i <= n; i++) height[i] = height[i >> 1] + 1;
        for(int i = 0; i < n; ++i) dat[0][i] = vec[i];
        for(int i = 1; i < h; ++i) {
            for(int j = 0; j < n; ++j) {
                dat[i][j] = min<MeetSemiLattice>(dat[i - 1][j], dat[i - 1][min<int>(j + (1 << (i - 1)), n - 1)]);
            }
        }
    }
    inline MeetSemiLattice get(const int a, const int b) { // get [l, r)
        int t = height[b - a];
        return min<MeetSemiLattice>(dat[t][a], dat[t][b - (1 << t)]); 
    }
};

int main(){
    
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<int> counter(N + 1, 0);
    rep(i, N){
        char c = s[i];
        if(c == '(')counter[i + 1]++;
        else counter[i + 1]--;
        counter[i + 1] += counter[i];
    }

    if(counter[N] != 0){
        cout << "0\n1 1\n";
        return 0;
    }

    vector<int> vec(N);
    rep(i, N)vec[i] = counter[i + 1];

    int mi = N;
    rep(i, N)chmin(mi, vec[i]);
    int most = 0;
    rep(i, N)if(vec[i] == mi)most++;
    pair<int, int> ans(0, 0);

    rep(j, N)rep(i, j){
        if(s[i] == '(' && s[j] == ')'){
            int tmi = N;
            rep(k, i)chmin(tmi, vec[k]);
            rep(k, i, j - 1)chmin(tmi, vec[k] - 2);
            rep(k, j, N - 1)chmin(tmi, vec[k]);
            int tmp = 0;
            rep(k, i)if(vec[k] == tmi)tmp++;
            rep(k, i, j - 1)if(vec[k] - 2 == tmi)tmp++;
            rep(k, j, N - 1)if(vec[k] == tmi)tmp++;
            if(chmax(most, tmp))ans = make_pair(i, j);
        }
        if(s[i] == ')' && s[j] == '('){
            int tmi = N;
            rep(k, i)chmin(tmi, vec[k]);
            rep(k, i, j - 1)chmin(tmi, vec[k] + 2);
            rep(k, j, N - 1)chmin(tmi, vec[k]);
            int tmp = 0;
            rep(k, i)if(vec[k] == tmi)tmp++;
            rep(k, i, j - 1)if(vec[k] + 2 == tmi)tmp++;
            rep(k, j, N - 1)if(vec[k] == tmi)tmp++;
            if(chmax(most, tmp))ans = make_pair(i, j);
        }
    }

    cout << most << '\n' << ans.first + 1 << ' ' << ans.second + 1 << '\n';
    return 0;

}