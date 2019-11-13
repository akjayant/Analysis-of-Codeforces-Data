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
vector<pll> ans;
string a,b;
int n;
bool gd = true;
void doo(int pos){
    for(int i = pos + 1;i < n; ++i){
        if(a[i] == a[pos]){
            swap(b[pos],a[i]);
            ans.pb({i,pos});
            return;
        }
    }
    for(int i = pos + 1;i < n; ++i){
        if(b[i] == a[pos]){
            swap(b[i],a[n - 1]);
            ans.pb({n - 1,i});
            swap(b[pos],a[n - 1]);
            ans.pb({n - 1,pos});
            return;
        }
    }
    gd = false;
}
void solve(){
    cin >> n;
    gd = true;
    ans.clear();
    cin >> a >> b;
    for(int i = 0;i < a.size() - 1; ++i){
        if(a[i] == b[i])continue;
        doo(i);
        if(!gd){
            cout << "No\n";
            return;
        }
    }
    if(a == b){
        if(ans.empty())ans.pb({0,0});
        cout << "Yes\n";
        cout << ans.size() << "\n";
        for(auto &it : ans)cout << it.fst + 1 << " " << it.snd + 1 << "\n";
    }else{
        cout << "No\n";
    }
}
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int k;
    cin >> k;
    for(int i = 0;i < k; ++i){
        solve();
    }
    return 0;
}

