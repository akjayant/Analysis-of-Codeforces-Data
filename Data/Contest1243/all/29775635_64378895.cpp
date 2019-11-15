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
// const int N = ;

bool comp(int a, int b, int c, int d) {
  return a*b == c*d;
}

int main () {
  fastio;
  int k;
  cin >> k;
  while(k--) {
    int n;
    string a,b;
    cin >> n;
    cin >> a >> b;
    vi dif;
    for(int i = 0; i < n; i++) {
      if(a[i] != b[i]) dif.push_back(i);
    }
    if(dif.size() == 0) {
      cout << "Yes\n";
    }
    else if(dif.size() != 2) {
      cout << "No\n";
    }
    else if(b[dif[0]] == b[dif[1]] and a[dif[0]] == a[dif[1]]) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }
  return 0;
}
