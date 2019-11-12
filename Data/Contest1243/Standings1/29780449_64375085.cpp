//In the name of Allah
//In the name of the compassionate of the merciful
//Ya Ali!
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int ll ;
typedef long double ld ;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll maxn = 1000 * 101 ;
const ll INF2 = 1e9 ;
const ll INF = 1e18 ;

#define f first
#define s second
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front

// cout << *ss.find_by_order(index) ; -> return the value that indexed in index position
// cout << ss.order_of_key(value) ; -> lower_bound in ordered_set

ll mod = 1e9 + 7 , p1 = 999999929 , p2 = 999999937 ;

ll q ;

int main()
{
std::ios::sync_with_stdio(0) ;
cin.tie(0) ;
cout.tie(0) ;

cin >> q ;
while(q--){
    ll n , ans = 1 ;
    vector<ll> a ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++){
        ll x ;
        cin >> x;
        a.pub(x) ;
    }
    sort(a.begin() , a.end()) ;
    for(int i = n-1 ; i >= 0 ; i --){
        ll x = n-i ;
        if(a[i] >= x)ans = x ;
    }
    cout << ans << "\n" ;
}
 return 0;
}
/*
                  _     _   __
            /_\  (_    (_)  __)
           /   \  _) . (_) (__
*/
