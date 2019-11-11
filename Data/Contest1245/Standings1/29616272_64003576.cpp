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
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int R, P, S;
        cin >> R >> P >> S;
        string str;
        cin >> str;

        int win = 0;
        string ans = "";
        for (char hand : str) {
            if (hand == 'R') {
                if (P > 0) {
                    win++;
                    P--;
                    ans += 'P';
                } else {
                    ans += '#';
                }
            } else if (hand == 'P') {
                if (S > 0) {
                    win++;
                    S--;
                    ans += 'S';
                } else {
                    ans += '#';
                }
            } else {
                if (R > 0) {
                    win++;
                    R--;
                    ans += 'R';
                } else {
                    ans += '#';
                }
            }
        }
        if (win * 2 >= N) {
            cout << "YES" << endl;
            rep(i, 0, N) {
                if (ans[i] == '#') {
                    if (R > 0) {
                        ans[i] = 'R';
                        R--;
                    } else if (S > 0) {
                        ans[i] = 'S';
                        S--;
                    } else {
                        ans[i] = 'P';
                        P--;
                    }
                }
            }
            cout << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return (0^_^0);
}

