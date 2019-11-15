#include <bits/stdc++.h>

#define st first
#define nd second
#define pb push_back
#define mp make_pair

#define cl(x,y) memset(x, y, sizeof(x))
#define dbs(x) cerr << x << endl;
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define fori(i,a,b) for(int i = a; i < b; i++)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileio freopen("input.txt","r",stdin); freopen("output.txt", "w",stdout);

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, M = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1), EPS = 1e-9;
const int N = 1100;
int a[N];

int main () {
  fastio;

  int n, k;

  cin >> k;
  while(k--) {
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> a[i];
    sort(a,a+n, greater<int>());
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(a[i] >= i+1) ans++;
      else break;
    }
    cout << ans << '\n';
  }

  return 0;
}
