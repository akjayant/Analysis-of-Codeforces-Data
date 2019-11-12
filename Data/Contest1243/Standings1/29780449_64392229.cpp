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

ll q , o0 = 'a';

int main()
{
std::ios::sync_with_stdio(0) ;
cin.tie(0) ;
cout.tie(0) ;

cin >> q ;
while(q--){
  ll n , ok = 1;
  map<ll , ll> mm , mark ;
  vector<pair<ll,ll> > ans ;
  string s1 , t1 ;
  cin >> n >> s1 >> t1 ;
  for(int i = 0 ; i < s1.size() ; i ++)mm[s1[i]] ++ ;
  for(int i = 0 ; i < t1.size() ; i ++)mm[t1[i]] ++ ;

  for(int i = 0 ; i < 26 ; i ++){
    if(mm[i+o0] & 1)ok = 0 ;
  }
  if(ok == 0){
    cout << "No" << "\n" ;
    continue ;
  }

  for(int i = 0 ; i < n ; i ++){
    char ch = s1[i] , ch2 = t1[i] ;
    if(ch == ch2)continue ;

    for(int j = i+1 ; j < n ; j ++){
        if(s1[j] == ch){
            ans.pub({j+1 , i+1}) ;
            swap(s1[j] , t1[i]) ;
            break ;
        }
        else if(t1[j] == ch){
            ans.pub({j+1 , j+1}) ;
            ans.pub({j+1 , i+1}) ;
            swap(s1[j] , t1[j]) ;
            swap(s1[j] , t1[i]) ;
            break ;
        }
    }
  }
  cout << "Yes" << "\n" << ans.size() << "\n" ;
  for(int i = 0 ; i < ans.size() ; i ++)cout << ans[i].f << " " << ans[i].s << "\n" ;
}
 return 0;
}
/*
                  _     _   __
            /_\  (_    (_)  __)
           /   \  _) . (_) (__
*/
