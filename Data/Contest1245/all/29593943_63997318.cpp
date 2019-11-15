#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector < vector <pii> > graph;

signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t;
   cin >> t;
   while(t--){
       int a, b;
       cin >> a >> b;
       if(__gcd(a, b) > 1){
           cout << "Infinite\n";
       }
       else{
           cout << "Finite\n";
       }
   }
   return 0;
}
