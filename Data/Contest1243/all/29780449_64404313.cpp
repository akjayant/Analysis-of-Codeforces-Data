//In the name of Allah
//In the name of the compassionate of the merciful
//Ya Ali!
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll ;
typedef long double ld ;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll maxn = (1000 * 1000) + 10 ;
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

ll n , mark[maxn] ;
vector<ll> vv , av ;

int main()
{
std::ios::sync_with_stdio(0) ;
cin.tie(0) ;
cout.tie(0) ;

cin >> n ;
if(n == 1)return cout << 1 , 0 ;

for(int i = 2 ; i <= (1000 * 1000) ; i ++){
    if(!mark[i]){
        av.pub(i) ;
        for(int j = i ; j <= (1000 * 1000) ; j += i)mark[j] = 1 ;
    }
}


ll nn = n ;
for(int i = 0 ; i < av.size() ; i ++){
    //cout << av[i] << "\n" ;
    ll x = av[i] ;
    if(nn%x == 0)vv.pub(x) ;
    while(nn%x == 0)nn /= x ;
}
if(nn > 1)vv.pub(nn) ;

sort(vv.begin() , vv.end()) ;

if(vv.size() > 1)cout << 1 ;
else cout << vv[0] ;

 return 0;
}
/*
                  _     _   __
            /_\  (_    (_)  __)
           /   \  _) . (_) (__
*/
