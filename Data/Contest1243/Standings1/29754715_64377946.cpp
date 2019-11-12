#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
#define si set<int>
#define sll set<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define fo(i,a,b) for(int i=a;i<b;i++)
#define fo_(i,a,b) for(int i=a;i>b;i--)
#define M(a) memset(a,0,sizeof a)
#define M_(a) memset(a ,-1,sizeof a)
#define deb(x)  cerr << #x << " = " << x << endl
#define pb push_back
#define F first
#define S second
#define OK order_of_key
#define FO find_by_order
#define PI 3.14159265
#define nmax 100100
const ll inf = std::numeric_limits<ll>::max();
const int infint = std::numeric_limits<int>::max();
const ll mod = 1e9+7;
using namespace __gnu_pbds;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int k;
    cin >> k;
    while(k--){
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        vi v;
        fo(i,0,n){
            if(s[i] == t[i]) continue;
            v.pb(i);
        }
        if(v.empty()){
            cout << "Yes\n";
            continue;
        }
        if(v.size() > 2 || v.size() == 1){
            cout << "No\n";
        }else{
            if(s[v[0]] == s[v[1]] && t[v[0]] == t[v[1]]){
                cout << "Yes\n";
            }else cout << "No\n";
        }
    }


    return 0;
}

