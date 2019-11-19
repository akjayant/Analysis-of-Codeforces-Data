#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <iomanip>

using namespace std;

int m[10][10];
double f[10][10];

struct my {
  double v;
  int i;
  int j;
};

int main() {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> m[i][j];
    }
  }

  f[0][0] = 0;
  f[0][1] = 6;
  f[0][2] = 6;
  f[0][3] = 6;
  f[0][4] = 6;
  f[0][5] = 6;

  deque<my> d;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (i == 0 && j == 0) {
        f[i][j] = 0;
        d.push_back({f[i][j], i, j});
      } else if (i == 0 && j < 6) {
        f[i][j] = 6;
        d.push_back({f[i][j], i, j});
      } else {
        int j1 = (i % 2 == 0) ? j : 9 - j;
        f[i][j1] = 0;
        for (auto elem : d) {
          double comp = 1 / 6. * (elem.v + 1);
          if (m[elem.i][elem.j] != 0) {
            double newval =  1 / 6. * (f[elem.i - m[elem.i][elem.j]][elem.j] + 1);
            if (newval > comp) {
              f[i][j1] += comp;
            } else {
              f[i][j1] += newval;
            }
          } else {
            f[i][j1] += comp;
          }
        }
        d.push_back({f[i][j1], i, j1});
        d.pop_front();
      }
    }
  }
  cout << fixed << setprecision(7) << f[9][0] << endl;
  return 0;
}