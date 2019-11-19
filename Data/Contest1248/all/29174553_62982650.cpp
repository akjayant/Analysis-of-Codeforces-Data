#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define all(a) a.begin(),a.end()
#define ull unsigned long long
#define endl '\n'
#define y1 yaumru
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define iter vector<int>::iterator
#define int long long
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

template<class T>
using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd1(chrono::steady_clock::now().time_since_epoch().count());

//find_by_order
//order_of_key

const int N=1e5+7;
const int inf=1e18+5;
const int mod=1e9+7;
const ld eps=1e-9;

int a[N];

main ()
{
    ios;
    int n;
    cin>>n;
    int sum=0;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int x=0;
    for (int i=1;i<=n/2;++i){
        x+=a[i];
    }
    int ans=x*x+(sum-x)*(sum-x);
    if (n%2==1){
        x+=a[n/2+1];
        ans=max(ans,x*x+(sum-x)*(sum-x));
    }
    cout<<ans<<endl;
}
