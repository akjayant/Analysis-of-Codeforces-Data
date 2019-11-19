#include<bits/stdc++.h>

using namespace std;


#define ss second
#define ff first
#define int long long
//#define double long double
#define pb push_back

const int N = 2e5 + 1, MOD = 1e9 + 7, mod = 998244353, INF = 3e18;

mt19937 Flash_new_51(51515);

using vi = vector <int>;
using vp = vector <pair <int, int>>;

map <int, int> mp;
multiset <int> s;
set <int> s1;

signed main() {
   #ifdef Flash
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
   int n, k;
   cin >> n >> k;
   for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        s.insert(x);
        s1.insert(x);
   }
   if (s1.size() == 1) {
    cout << 0;
    return 0;
   }
   while (k > 0){
        if (s1.size() == 1) {
        cout << 0;
        return 0;
       }
       int o = *s1.begin(), o1 = *s1.rbegin();
       s1.erase(o);
       int ol = *s1.begin();
       s1.insert(o);
       s1.erase(o1);
       int ol1 = *s1.rbegin();
       s1.insert(o1);
       if (o == o1) break;
       if (mp[o] < mp[o1]) {
            s1.erase(o);
            int l1 = *s1.begin();
            if (mp[o] * (l1 - o) >= k) {
                int oo = k / mp[o];
                o+= oo;
                cout << o1 - o;
                return 0;
            }
            k-= mp[o] * (l1 - o);
            mp[l1]+= mp[o];
       }
       else {
           s1.erase(o1);
           int l1 = *s1.rbegin();
           if (mp[o1] * (o1 - l1) >= k) {
                int oo = k / mp[o1];
                o1-= oo;
                cout << o1 - o;
                return 0;
           }
           k-= mp[o1] * (o1 - l1);
           mp[l1]+= mp[o1];
       }
      // cout << k << endl;
   }
   cout << 0;


}
