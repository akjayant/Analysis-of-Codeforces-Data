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
        si ss;
        fo(i,0,n){
            if(s[i] == t[i]) continue;
            ss.insert(i);
        }
        bool done = true;
        vector<pii> ans;
        while(!ss.empty() && done){
            int now = *ss.begin();
            ss.erase(now);
            done = false;
            if(s[now] == t[now]) {done = true; continue;}
            for(auto i : ss){
                if(s[now] == s[i]){
                    char save = s[i];
                    s[i] = t[now];
                    t[now] = save;
                    ans.pb({i,now});
                    done = true;
                    break;
                }
                if(s[now] == t[i]){
                    char save = t[i];
                    t[i] = s[i];
                    s[i] = save;
                    ans.pb({i,i});
                    save = s[i];
                    s[i] = t[now];
                    t[now] = save;
                    ans.pb({i,now});
                    done = true;
                    break;
                }
            }
        }
        if(ss.empty() && done){
            cout << "Yes\n";
            cout << ans.size() << '\n';
            for(auto i : ans) cout << i.F+1 << ' ' << i.S+1 << '\n';
        }else{
            cout << "No\n";
        }
    }


    return 0;
}

