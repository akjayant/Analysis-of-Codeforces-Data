#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
using pii=pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(c) begin(c),end(c)
#define rall(c) rbegin(c),rend(c)
#define fore(x,c) for(auto &&x:c)
#define rep(i,a,n) for(int i=a,i##len=(int)(n);i<i##len;++i)
#define rrep(i, a, n) for(int i=(int)(n-1);i>=a;--i)
#define sz(c) ((int)c.size())
#define contains(c,x) (c.find(x)!=end(c))
#define inseg(l,x,r) ((l)<=(x)&&(x)<(r))
#define dump(...)
#define pb push_back
#define _ 0
const signed INF_=1001001001; const long long INF=1001001001001001001LL;
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    for (auto i = begin(v); i != end(v); i++) os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    for (auto i = begin(v); i != end(v); i++) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T, class U> bool chmax(T &a,const U &b){return a<b?a=b,1:0;}
template<class T, class U> bool chmin(T &a,const U &b){return a>b?a=b,1:0;}
template <class T> void psum(T& c) {partial_sum(begin(c), end(c), begin(c));}
template<class T> using heap=priority_queue<T,vector<T>,greater<T>>;
struct before_main_function {
    before_main_function() {
        cin.tie(nullptr); ios::sync_with_stdio(0);
        cout << setprecision(15) << fixed;
        // #define endl "\n"
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------

signed main() {
    int N;
    cin >> N;
    vi X(N), Y(N), C(N), K(N);
    rep(i, 0, N) {
        cin >> X[i] >> Y[i];
    }
    cin >> C >> K;
    auto dist = [&](int i, int j) {
        return abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
    };
    vvi cost(N, vi(N, 0));
    rep(i, 0, N) {
        rep(j, 0, N) {
            cost[i][j] = (K[i] + K[j]) * dist(i, j);
        }
    }

    vector<pii> ord;
    rep(i, 0, N) {
        ord.emplace_back(C[i], i);
    }
    sort(all(ord));

    vector<bool> used(N, false);
    vector<pii> edge;
    vector<int> from(N, -1);
    vi powerstation;
    int ans = 0;
    rep(i, 0, N) {
        int c, v;
        tie(c, v) = ord[0];

        if (from[v] != -1 && cost[v][from[v]] == c) {
            edge.emplace_back(v, from[v]);
        } else {
            powerstation.emplace_back(v);
        }
        ans += c;
        used[v] = true;

        vector<pii> next_ord;
        rep(w, 0, N) {
            if (used[w]) continue;
            if (chmin(C[w], cost[v][w])) {
                from[w] = v;
            }
            next_ord.emplace_back(C[w], w);
        }
        sort(all(next_ord));
        ord.swap(next_ord);
    }

    cout << ans << endl;
    cout << sz(powerstation) << endl;
    for (int &v : powerstation) v++;
    cout << powerstation << endl;
    cout << sz(edge) << endl;
    for (pii e : edge) {
        cout << e.first + 1 << " " << e.second + 1 << endl;
    }
    return (0^_^0);
}

