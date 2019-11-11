#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define eps 1e-5

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;

int main(){ _
   int t;
   cin >> t;
   while(t--){
      int a, b;
      cin >> a >> b;
      if(__gcd(a,b) == 1) cout << "Finite" << endl;
      else cout << "Infinite" << endl;
   }
   exit(0);
}
