#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

const int MAXN = 100010;

const int MIN_MODE = 0;
const int MAX_MODE = 1;

int n, m, k;
int l, r, u, b;

using namespace std;

unordered_map<int, vector<int>> x_obs;
unordered_map<int, vector<int>> y_obs;

#define DEBUG false
#define PRT 

int status = 0;

void AddObs(int x, int y) {
  if (x_obs.find(x) == x_obs.end()) {
    x_obs[x] = vector<int>();
  }
  if (y_obs.find(y) == y_obs.end()) {
    y_obs[y] = vector<int>();
  }
  x_obs[x].push_back(y);
  y_obs[y].push_back(x);
}

void PrepareObs() {
  for (const auto& it : x_obs) {
    auto k = it.first;
    auto& v = x_obs[k];
    sort(v.begin(), v.end());
  }
  for (const auto& it : y_obs) {
    auto k = it.first;
    auto& v = y_obs[k];
    sort(v.begin(), v.end());
  }
  if (DEBUG) {
    for (const auto& it : x_obs) {
      PRT("X=%d ", it.first);
      for (auto k : x_obs[it.first]) {
        PRT("%d ", k);
      }
      PRT("\n");
    }
    for (const auto& it : y_obs) {
      PRT("Y=%d ", it.first);
      for (auto k : y_obs[it.first]) {
        PRT("%d ", k);
      }
      PRT("\n");
    }
  }
}

const int MAX_V = 2147483647;
const int MIN_V = -2147483647;

int QueryMin(const vector<int>& v, int least) {
  int l = 0;
  int r = v.size() - 1;
  // v[l] < least <= v[r]
  if (least > v[r]) return MAX_V;
  if (v[0] >= least) return v[0];
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (v[mid] >= least) r = mid; else l = mid;
  }
  return v[r];
}
 
int QueryMax(const vector<int>& v, int most) {
  int l = 0;
  int r = v.size() - 1;
  // v[l] <= most < v[r]
  if (most >= v[r]) return v[r];
  if (v[0] > most) return MIN_V;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (v[mid] > most) r = mid; else l = mid;
  }
  return v[l];
}

int QueryXMin(int x, int least) {
  PRT("query x min %d %d\n", x, least);
  if (x_obs.find(x) == x_obs.end()) {
    return MAX_V;
  }
  return QueryMin(x_obs[x], least);
} 

int QueryXMax(int x, int most) {
  PRT("query x max %d %d\n", x, most);
  if (x_obs.find(x) == x_obs.end()) {
    return MIN_V;
  }
  return QueryMax(x_obs[x], most);
} 

int QueryYMin(int y, int least) {
  PRT("query y min %d %d\n", y, least);
  if (y_obs.find(y) == y_obs.end()) {
    return MAX_V;
  }
  if (DEBUG) {
    for (int k : y_obs[y]) {
      PRT("%d ", k);
    }
    PRT("\n");
  }
  return QueryMin(y_obs[y], least);
} 

int QueryYMax(int y, int most) {
  PRT("query y max %d %d\n", y, most);
  if (y_obs.find(y) == y_obs.end()) {
    return MIN_V;
  }
  return QueryMax(y_obs[y], most);
} 

int GetIndex(const vector<int>& v, int x) {
  int l = 0;
  int r = v.size() - 1;
  // v[l] <= x < v[r]
  if (x < v[l]) return -1;
  if (x > v[r]) return -1;
  if (x == v[r]) return r;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (v[mid] > x) r = mid; else l = mid;
  }
  if (x == v[l]) return l;
  return -1;
}

int CheckAll(int l, int r, int u, int b) {
  PRT("Check all %d %d %d %d\n", l, r, u, b);
  for (int i = u; i <= b; i++) {
    if (x_obs.find(i) == x_obs.end()) {
      status = -1;
      return 0;
    }
    int lid = GetIndex(x_obs[i], l);
    int rid = GetIndex(x_obs[i], r);
    if (lid == -1 || rid == -1) {
      status = -1;
      return 0;
    }
    if (rid - lid != r - l) {
      status = -1;
      return 0;
    }
  }
  return 1;
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    AddObs(x, y);
  }
  PrepareObs();
  int dir = 0;  // 0 East 1 South 2 West 3 North
  l = 1;
  r = m;
  u = 1;
  b = n;
  while (l <= r && u <= b) {
    PRT("State %d %d %d %d %d\n", l, r, u, b, dir);
    if (dir == 0) {  // E
      int t = QueryXMin(u, l);
      PRT("obs %d\n", t);
      if (t <= r) {
        if (!CheckAll(t, r, u, b)) break;
        r = t - 1;
      }
      u += 1;
    } else if (dir == 1) {  // S
      int t = QueryYMin(r, u);
      PRT("obs %d\n", t);
      if (t <= b) {
        if (!CheckAll(l, r, t, b)) break;
        b = t - 1;
      }
      r -= 1;
    } else if (dir == 2) {  // W
      int t = QueryXMax(b, r);
      PRT("obs %d\n", t);
      if (t >= l) {
        if (!CheckAll(l, t, u, b)) break;
        l = t + 1;
      }
      b -= 1;
    } else if (dir == 3) {  // N
      int t = QueryYMax(l, b);
      PRT("obs %d\n", t);
      if (t >= u) {
        if (!CheckAll(l, r, u, t)) break;
        u = t + 1;
      }
      l += 1;
    }
    dir = (dir + 1) % 4;
  }
  if (status == -1) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
} 
