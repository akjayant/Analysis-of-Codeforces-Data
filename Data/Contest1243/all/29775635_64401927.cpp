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
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f, M = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1), EPS = 1e-9;
// const int N = ;

bool comp(int a, int b, int c, int d) {
  return a*b == c*d;
}

void solve() {
    int n;
    string a,b;
    int cont[256] = {}, ca[256] = {}, cb[256] = {};
    cin >> n;
    cin >> a >> b;
    for(int i = 0; i < n; i++) {
      cont[a[i]]++; cont[b[i]]++;
    }
    for(char c = 'a'; c <= 'z'; c++) {
      if(cont[c]%2) {
        cout << "No\n";
        return;
      }
    }
    vii ans;
    for(int i = 0; i < n; i++) {
      if(a[i]==b[i]) continue;
      int j;
      for(j = i+1; j < n and a[i] != a[j] and a[i] != b[j]; j++);
      if(a[j] == a[i]) {
        ans.push_back({j,i});
        swap(a[j], b[i]);
      }
      else {
        ans.push_back({j,j});
        ans.push_back({j,i});
        swap(a[j], b[j]);
        swap(a[j], b[i]);
      }
    }
    cout << "Yes\n";
    cout << ans.size() << '\n';
    for(auto &p : ans) {
      cout << p.first+1 << ' ' << p.second+1 << '\n';
    }
}

int main () {
  fastio;
  int k;
  cin >> k;
  while(k--) {
    solve();
  }
  return 0;
}
