#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define ll long long
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define PB push_back
using namespace std;
using namespace __gnu_pbds;

const ll N = 3e5 + 200;
const ll MOD = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll n,Q,pos;
string s,t;
vector<pair<ll, ll> > ans;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>Q;
    while(Q--)
    {
        cin>>n;
        cin>>s>>t;
        ans.clear();
        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[i])
            {
                ll f = 0;
                for(int j = i + 1; j < n; j++)
                {

                    if(s[j] == t[j]) continue;
                    if(t[j] == t[i])
                    {
                        ans.PB({i, j});
                        swap(s[i], t[j]);
                        f = 1;
                        break;
                    }
                }
                if(f == 1)continue;
                for(int j = i + 1; j < n; j++)
                {
                    if(s[j] == t[j])continue;
                    if(s[j] == t[i]){
                        ans.PB({j, j});
                        swap(s[j], t[j]);
                        ans.PB({i, j});
                        swap(s[i], t[j]);
                        f = 1;
                        break;
                    }
                }
            }
        }

        if(s == t)
        {
            cout<<"Yes\n";
            cout<<ans.size()<<"\n";
            for(auto x : ans) cout<<x.fi + 1<<" "<<x.se + 1<<"\n";
        }
        else cout<<"No\n";
    }
    return 0;
}
