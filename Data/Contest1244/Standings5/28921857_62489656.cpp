#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); 
  int n;
  cin >> n;
  vector<vector<ll>> c(3, vector<ll>(n));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n; j++)
      cin >> c[i][j];
  vector<vector<int> > t(n);
  for (int i = 0; i < n-1; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    t[x].push_back(y);
    t[y].push_back(x);
  }
  int rt= -1;
  bool ok = true;
  for (int i = 0; i  <n; i++) {
    if (t[i].size() == 1) rt = i;
    if (t[i].size() > 2) ok = false;
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> ord(n);
  ord[0] = rt;
  ord[1] = t[ord[0]][0];
  int pos = 1;
  ll millor = LLONG_MAX;
  while (pos < n-1) {
    if (t[ord[pos]][0] == ord[pos-1]) ord[pos+1] = t[ord[pos]][1];
    else ord[pos+1] = t[ord[pos]][0];
    pos++;
  }
  
  
  int in = 0, seg = 0;
  for (int i = 0;  i< 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i != j) {
        ll cost = c[i][ord[0]] + c[j][ord[1]];
        int p =j, ap = i;
        for (int pp = 2; pp < n; pp++) {
          cost += c[3-p-ap][ord[pp]];
          int apvell = ap;
          ap = p;
          p = 3-apvell-p;
        }
        if (cost < millor) {
          millor = cost;
          in = i;
          seg = j;
        }
      }
    }
  }
  cout << millor << endl;
  vector<int> col(n);
  col[ord[0]] = in;
  col[ord[1]] = seg;
  for (int pp = 2; pp < n; pp++) {
    col[ord[pp]] = 3- col[ord[pp-1]] -col[ord[pp-2]];
  }
  for (int i = 0; i < n; i++)
    cout << col[i]+1 << " ";
  cout << endl;
}

