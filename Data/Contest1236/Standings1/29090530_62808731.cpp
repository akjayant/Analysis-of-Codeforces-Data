#include <algorithm>
#include <iostream>

using namespace std;

const int kMaxN = 100001;
const int kDir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct Node {
  int x, y;
};

int b[4];
Node rn[kMaxN], cn[kMaxN];
int rr[kMaxN][2], cr[kMaxN][2];
int k, d;
long long n, m, tot, x, y, tmp;

bool CompareR(Node n1, Node n2) {
  if (n1.x != n2.x) {
    return n1.x < n2.x;
  }
  return n1.y < n2.y;
}

bool CompareC(Node n1, Node n2) {
  if (n1.y != n2.y) {
    return n1.y < n2.y;
  }
  return n1.x < n2.x;
}

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    cin >> rn[i].x >> rn[i].y;
    cn[i] = rn[i];
  }
  sort(rn + 1, rn + 1 + k, CompareR);
  sort(cn + 1, cn + 1 + k, CompareC);
  for (int i = 1; i <= k; i++) {
    if (rr[rn[i].x][0] == 0) {
      rr[rn[i].x][0] = i;
    }
    rr[rn[i].x][1] = i;
  }
  for (int i = 1; i <= k; i++) {
    if (cr[cn[i].y][0] == 0) {
      cr[cn[i].y][0] = i;
    }
    cr[cn[i].y][1] = i;
  }
  tot = 0;
  x = 1;
  y = 0;
  d = 3;
  b[0] = m + 1;
  b[1] = n + 1;
  b[2] = b[3] = 0;
  while (true) {
    d = (d + 1) % 4;
    tmp = b[d];
    if (d == 0) {
      if (rr[x][0] != 0) {
        for (int i = rr[x][0]; i <= rr[x][1]; i++) {
          if (rn[i].y > y) {
            if (rn[i].y < tmp) {
              tmp = rn[i].y;
            }
            break;
          }
        }
      }
      if (y == tmp - 1) {
        break;
      }
      tot += tmp - 1 - y;
      y = tmp - 1;
      b[3] = x;
    } else if (d == 1) {
      if (cr[y][0] != 0) {
        for (int i = cr[y][0]; i <= cr[y][1]; i++) {
          if (cn[i].x > x) {
            if (cn[i].x < tmp) {
              tmp = cn[i].x;
            }
            break;
          }
        }
      }
      if (x == tmp - 1) {
        break;
      }
      tot += tmp - 1 - x;
      x = tmp - 1;
      b[0] = y;
    } else if (d == 2) {
      if (rr[x][0] != 0) {
        for (int i = rr[x][1]; i >= rr[x][0]; i--) {
          if (rn[i].y < y) {
            if (rn[i].y > tmp) {
              tmp = rn[i].y;
            }
            break;
          }
        }
      }
      if (y == tmp + 1) {
        break;
      }
      tot += y - tmp - 1;
      y = tmp + 1;
      b[1] = x;
    } else {
      if (cr[y][0] != 0) {
        for (int i = cr[y][1]; i >= cr[y][0]; i--) {
          if (cn[i].x < x) {
            if (cn[i].x > tmp) {
              tmp = cn[i].x;
            }
            break;
          }
        }
      }
      if (x == tmp + 1) {
        break;
      }
      tot += x - tmp - 1;
      x = tmp + 1;
      b[2] = y;
    }
        // cout << d << " " << x << " " << y << endl;
  }
  if (n * m == k + tot) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
