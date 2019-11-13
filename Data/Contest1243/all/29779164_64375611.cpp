#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long int ll ;
typedef vector<long long int> vi;
typedef pair<ll,ll> pi;

#define PB push_back
#define EB emplace_back
#define REP(i,a,b) for(long long int i=a ; i<=b ; i++)
#define REV(i,a,b) for(long long int i=a ; i>=b ; i--)
#define F first
#define S second
#define MP make_pair
#define INF 100000000000000000
#define MOD 1000000007
#define MT make_tuple

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,ans=0;
    cin>>t;
    while (t--){
        cin>>n;
        ans=0;
        ll a[n];
        REP(i,0,n-1){
            cin>>a[i];
        }
        sort(a,a+n);
        REV(i,n-1,0){
            ans= __max(ans,__min(a[i],n-i));
        }
        cout<<ans<<"\n";
    }
    return 0;
}
