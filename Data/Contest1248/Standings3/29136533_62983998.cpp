///not today

#include<bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define pb push_back
#define ll long long
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define pipii pair< int, pair<int, int> >
#define plpll pair< ll, pair<ll, ll> >

using namespace std;

int32_t main(){
      int T;
      cin >>T;
      for(int t = 0; t < T; t ++){
            int n, m, cn1[2] = {0, 0}, cn2[2] = {0, 0};
            cin >>n;
            for(int i = 0; i < n; i ++){
                  int x;
                  cin >>x;
                  cn1[x% 2] ++;
            }
            cin >>m;
            for(int i = 0; i < m; i ++){
                  int x;
                  cin >>x;
                  cn2[x% 2] ++;
            }
            cout <<(cn1[0]* cn2[0]) + (cn1[1]* cn2[1]) <<' ';
      }
      return false;
}
