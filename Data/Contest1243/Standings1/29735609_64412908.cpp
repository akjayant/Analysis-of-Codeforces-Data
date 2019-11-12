/* 
 Author:N_o_o_B 
 Created:November 06 2019 20:46:13
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define TRACE
#ifdef TRACE
#define trace(...) { cerr<<"[ "; __trace__(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.first<<","<<x.second<<")";
}
 
template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1>
void __trace__(const string name, Arg1&& arg1){
    cerr << name << " : " << arg1 << " ] " << endl;
}
 
template <typename Arg1, typename... Args>
void __trace__(const string names, Arg1&& arg1, Args&&... args){
    const string name = names.substr(0,names.find(','));
    cerr<<name<<" : "<<arg1<<" | ";
    __trace__(names.substr(1+(int)name.size()), args...);
}
#else
    #define trace(args...)
#endif
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<vl> vvl;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
#define fori(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
#define ford(i,n)  for(int i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl '\n'
#define sz(a) (int)a.size()
#define fi first
#define se second
clock_t time_p=clock();
void time_taken()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
//const ll mod=998244353;
const ll mod=1e9+7;
const ll INF=1e18;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cout.precision(12);cout << fixed;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        vii ans;
        bool ok=1;
        fori(i,n){
            if(s[i]==t[i]) continue;
            rep(j,i+1,n-1){
                bool done=1;
                if(s[i]==s[j]){
                    ans.pb({j+1,i+1});
                    swap(t[i],s[j]);
                }
                else if(t[i]==t[j]){
                    ans.pb({i+1,j+1});
                    swap(s[i],t[j]);
                }
                else if(s[i]==t[j]){
                    ans.pb({j+1,j+1});
                    ans.pb({j+1,i+1});
                    swap(s[j],t[j]);
                    swap(t[i],s[j]);
                }
                else if(t[i]==s[j]){
                    ans.pb({j+1,j+1});
                    ans.pb({i+1,j+1});
                    swap(s[j],t[j]);
                    swap(s[i],t[j]);
                }
                else {
                    done=0;
                }
                if(done) break;
            }
        }
        ok=(s==t);
        if(!ok){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            cout << sz(ans) << endl;
            for(pii p:ans){
                cout << p.fi << " " << p.se << endl;
            }
        }
    }




    time_taken();
    return 0;
}