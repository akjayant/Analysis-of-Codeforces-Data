#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#define pb push_back
#define For(i,s,e) for (ll i=(s); i<(e); i++)
#define Debug_array(a,n) for (ll i=(0); i<(n); i++) cout<<a[i]<<" "
#define Foe(i,s,e) for (ll i=(s); i<=(e); i++)
#define Fod(i,s,e) for (ll i=(s)-1; i>=(e); i--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define endl "\n"
#define mp make_pair
#define big_prime 15486277
#define bigger_prime 179424697
#define biggest_prime 32416188691
//#define random_shuffle(indices.begin(), indices.end());
//std::random_device rd;
//std::mt19937 g(rd());
//std::shuffle(v.begin(), v.end(), g);
using namespace __gnu_pbds; 
using namespace std;
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
// template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <class Arg1> void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
    template <class Arg1, class... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* sep = strchr(names + 1, ',');
        cerr.write(names, sep - names) << " : " << arg1 << "  ";
        __f(sep + 1, args...);
    }
#else
#define trace(...) 0
#define _CRT_SECURE_NO_WARNINGS
#endif // ifndef ONLINE_JUDGE


typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; 

#define Mod 1000000007
#define MAX 100010

ll n,m;
pii edges[MAX];
set<ll> adj[MAX];

class Disjoint_Sets{
public:
    ll* parent;
    ll* size;
    Disjoint_Sets(ll n){
        parent = new ll[n];
        size = new ll[n];
        For(i,0,n) parent[i]=i;
        For(i,0,n) size[i]=1;
    }
    void merge(ll a,ll b){
        ll parent_a = find(a);
        ll parent_b = find(b);
        if(parent_a==parent_b) return;
        if(size[parent_a]<size[parent_b]){
            parent[parent_a] = parent_b;
            size[parent_b] += size[parent_a];
            size[parent_a] = 0;
        }else{
            parent[parent_b] = parent_a;
            size[parent_a] += size[parent_b];
            size[parent_b] = 0;
        }
    }
    ll find(ll a){
        if(parent[a]==a){
            return a;
        }
        parent[a]=find(parent[a]);
        return parent[a];
    }
}; 

set<ll> all;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;    
    Disjoint_Sets D(n);
    For(i,0,m){
        ll x,y;cin>>x>>y;x--;y--;
        edges[i] = {x,y};
        D.merge(x,y);
        adj[x].insert(y);
        adj[y].insert(x);
    }
    For(i,0,n) all.insert(D.find(i));

    if(all.size()>=2){
        cout<<0<<endl;
        return 0;
    }else{

        ll ans = 0;
        For(i,0,n-1){
            ll c = 0;
            bool plus = 1;
            For(j,i+1,n){
                if(adj[i].find(j)!=adj[i].end()){
                    c++;
                    continue;
                }else{
                    c = j;
                    plus = 0;
                    break;
                }
            }

            if(plus){
                ans++;
                c = i+1;
            }

            vector<ll> to_erase;
            for(ll x:adj[c]){
                if(adj[i].find(x)==adj[i].end()) to_erase.pb(x);
            }
            for(ll x:to_erase){
                adj[c].erase(x);
            }
        }

        cout<<ans<<endl;

    }




























    
}