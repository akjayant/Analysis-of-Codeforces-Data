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

const int maxn = 1000* 100 + 5;
int a[maxn];

int32_t main(){
      int n;
      cin >>n;
      for(int i = 0; i < n; i ++)
            cin >>a[i];
      sort(a, a + n);
      int s1 = 0, s2 = 0;
      for(int i = 0; i < n; i ++){
            s2 += a[i];
            if(i < n/ 2)
                  s1 += a[i];
      }
      s2 -= s1;
      cout <<(s2* s2) + (s1* s1) <<endl;
      return false;
}
