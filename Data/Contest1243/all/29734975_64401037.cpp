#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> plll;
typedef pair<pll,pll> ppll;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fst first
#define snd second
#define ins insert
#define pb push_back
template< typename T,typename V>ostream &operator<< (ostream &out,const pair<T,V> x){ out << "{" << x.fst << " : " << x.snd << "}"; return out;}template< typename T>ostream &operator<< (ostream &out,const set<T> x){ for(auto &it : x){ out << it << " "; } return out;}template< typename T>ostream &operator<< (ostream &out,const multiset<T> x){ for(auto &it : x){ out << it << " "; } return out;}template< typename T,typename V>ostream &operator<< (ostream &out,const map<T,V> x){ for(auto &it : x){ out << "[" << it.fst << "]" << " = " << it.snd << "\n"; } return out;}template< typename T>ostream &operator<< (ostream &out,const vector<T> x){ for(int i = 0;i < x.size() - 1; ++i){ out << x[i] << " "; } out << x.back(); return out;}template< typename T>ostream &operator<< (ostream &out,const vector<vector<T> > x){ for(int i = 0;i < x.size() - 1; ++i){ out << "[" << i << "]" << " = {" << x[i] << "}\n"; } out << "[" << x.size() - 1 << "]" << " = {" << x.back() << "}\n"; return out;}

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
set<int> s;
set<pll> ed;
void get(int v){
    s.erase(v);
    int was = -1;
    while(true){
        auto it = s.upper_bound(was);
        was = *it;
        if(it == s.end())break;
        if(ed.find(make_pair(v,*it)) == ed.end()){
            get(*it);
        }
    }
}
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n; ++i)s.ins(i);
    for(int i = 0;i < m; ++i){
        int x,y;
        cin >> x >> y;
        ed.ins({x,y});
        ed.ins({y,x});
    }
    int ans = -1;
    for(int i = 1;i <= n; ++i){
        if(s.find(i) != s.end()){
            get(i);
            ans++;
        }
    }
    cout << ans;
    return 0;
}

