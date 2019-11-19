#include <bits/stdc++.h>
#define REP(i,s,e) for(int i=(s); i<(e);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n)
#define repe(i,n) for(auto &&i:n)
#define all(v) (v).begin(),(v).end()
#define decimal fixed<<setprecision(20)
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
using namespace std;
using LL = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;
const LL LLINF = 1e16;

int main(){
    fastcin();

    int t;
    cin >> t;
    rep(i, t){
        LL op=0, oq=0, ep=0, eq=0;
        int n;
        cin >> n;
        vector<LL> p(n);
        rep(j, n){
            cin >> p[j];
            if(p[j]%2==1) op++;
            else ep++;
        }
        int m;
        cin >> m;
        vector<LL> q(m);
        rep(j, m){
            cin >> q[j];
            if(q[j]%2==1) oq++;
            else eq++;
        }
        cout << op*oq+ep*eq << endl;
    }
}