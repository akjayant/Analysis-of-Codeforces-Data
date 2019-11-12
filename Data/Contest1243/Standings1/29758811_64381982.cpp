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
ll Q,n,ans;
string a,b;
map<pair<ll, ll> , set<ll> >  m;
set<ll> :: iterator it;
bool solv()
{
    m.clear();
    for(int i = 0; i < n; i++) m[{a[i], b[i]}].insert(i);
    bool edd = 0;

    for(int i = 0; i < n; i++) if(a[i] != b[i])
    {
//        cout<<i<<" - "<<a[i]<<" "<<b[i]<<"\n";
//        cout<<i<<" : "<<m[{a[i], b[i]}].size()<<"\n";
        if(m[{a[i], b[i]}].find(i) != m[{a[i], b[i]}].end()) m[{a[i], b[i]}].erase(i);
        if(edd) return 0;
        it = m[{a[i], b[i]}].begin();
        if(it != m[{a[i], b[i]}].end())
        {
//            cout<<" : "<<*it<<;
            swap(a[i], b[*it]);
            if(m[{a[i], b[i]}].find(*it) != m[{a[i], b[i]}].end()) m[{a[i], b[i]}].erase(it);
        } else return 0;
        edd = 1;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>Q;
    while(Q--)
    {
        cin>>n;
        cin>>a>>b;
        if(solv()) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
