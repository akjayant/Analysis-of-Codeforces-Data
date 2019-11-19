#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<ii>;
const ll MOD = 998244353;
const int INF = 1e9+9;
const int MAXN = 1000006;


int h[10][10];
long double ent[10][10][2];

inline void foll(int &x, int &y) {
  if (x%2) {
    if (y == 9) {
      x--;
    } else {
      y++;
    }
  } else {
    if (y == 0) {
      x--;
    } else {
      y--;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> h[i][j];
    }
  }
  ent[0][0][0] = -6;
  for (int i = 0; i < 10; i++) {
    for (int j = (i%2? 9 : 0); j >= 0 && j < 10; j=(i%2? j-1:j+1)) {
      int x=i, y=j, k = 0;
      for (;k < 6 && (x!=0 || y != 0); k++) {
        foll(x,y);
        ent[i][j][0] += ent[x][y][1];
      }
      ent[i][j][0]+=6;
      if (k > 0) ent[i][j][0]/=k;
      ent[i][j][1] = min(ent[i][j][0], ent[i-h[i][j]][j][0]);
    }
  }
  // for (int i = 0; i < 10; i++) {
  //   cerr << ent[0][i][0] << " " << ent[0][i][1] << endl;
  // }
  printf("%.10Lf\n", ent[9][0][0]);
}
