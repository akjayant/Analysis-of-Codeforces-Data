#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define mod 1000000007
#define bitcount(x) __builtin_popcount(x)
#define all(v) (v).begin(), (v).end()
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;
inline int add(int a, int b, int p = mod){ int c = a + b; if(c >= p) c -= p; return c; }
inline int sub(int a, int b, int p = mod){ int c = a - b; if(c < 0) c += p; return c; }
inline int mul(int a, int b, int p = mod){ return (a * (long long)1 * b) % p; }

using namespace __gnu_pbds;
template<class key, class cmp = std::less<key>>
using ordered_set = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
//methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;



void Onigiri()
{
    
    int n;
    cin>>n;
    vector<int>d;
    if(n==1){
        cout<<1;return;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)d.push_back(n/i),d.push_back(i);
   
    }
    if(d.size()==0)
    {
        cout<<n;return;
    }
    sort(d.begin(), d.end());
    
    int g=d[0];
    for(int i=1;i<d.size();i++)
    {
        g=__gcd(g,d[i]);
    }
    cout<<g;
}   

signed main()
{

ios_base::sync_with_stdio(false);cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif

    int t = 1;
   // cin >> t;
    while (t--)
    {
        Onigiri();
       // cout<<endl;
    }
    return 0;
}