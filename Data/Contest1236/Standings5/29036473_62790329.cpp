#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define endl '\n'
#define all(a) a.begin(),a.end()
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define iter set< pair<int,int> >::iterator
#define int long long
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

template<class T>
using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

//find_by_order
//order_of_key

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd1(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e5+7;
const int inf=1e18+5;
const int mod=1e9+7;

int st(int n,int k)
{
    int ans=1;
    while(k){
        if (k%2==1){
            ans=(ans*n)%mod;
        }
        n=(n*n)%mod;
        k/=2;
    }
    return ans;
}

main ()
{
    ios;
    int n,m;
    cin>>n>>m;
    int kol=st(2,m)-1;
    if (kol<0)kol+=mod;
    int ans=st(kol,n);
    cout<<ans<<endl;
}
