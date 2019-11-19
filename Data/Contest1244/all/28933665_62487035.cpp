#include <bits/stdc++.h>
using namespace std;

// macros
#define overload_rep(_1, _2 ,_3 ,name, ...) name
#define re_p(i, n) for(int i = 0; i < (n); ++i)
#define r_ep(i, x, y) for(int i = (x); i <= (y); ++i)
#define rep(...) overload_rep(__VA_ARGS__, r_ep, re_p,)(__VA_ARGS__)
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

// Codeforces Round #592 (Div. 2)

typedef long long ll;
int N;
ll c[3][100000];
int ans[6][100000];
vector<int> to[100000];
int pos = 0;

void draw(int v, int p1, int p2){
    ans[pos][v] = 3 - ans[pos][p1] - ans[pos][p2];
    for(int u : to[v])if(u != p1)draw(u, v, p1);
}

int main(){
    
    cin >> N;
    rep(i, 3)rep(j, N)cin >> c[i][j];
    rep(i, N - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    rep(i, N){
        if(to[i].size() >= 3){
            cout << "-1\n";
            return 0;
        }
    }

    int v = to[0].front();

    ans[0][0] = 0; ans[0][v] = 1;
    ans[1][0] = 0; ans[1][v] = 2;
    ans[2][0] = 1; ans[2][v] = 0;
    ans[3][0] = 1; ans[3][v] = 2;
    ans[4][0] = 2; ans[4][v] = 0;
    ans[5][0] = 2; ans[5][v] = 1;

    ll comp = 1e18, tmp = -1;
    rep(i, 6){
        pos = i;
        ll sum = 0;
        for(int u : to[0]){
            if(u != v)draw(u, 0, v);
        }
        for(int u : to[v]){
            if(u != 0)draw(u, v, 0);
        }
        rep(j, N)sum += c[ans[i][j]][j];
        if(chmin(comp, sum))tmp = i;
    }

    cout << comp << "\n";
    rep(i, N){
        cout << ans[tmp][i] + 1 << (i == N - 1 ? "\n" : " ");
    }

}