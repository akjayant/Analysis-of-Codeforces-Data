#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


void solve() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  vector<set<int>> ccnt(26);
  vector<char> cs(n), ct(n);
  for (int i = 0; i < n; i++) {
    char c = s.at(i) - 'a';
    ccnt.at(c).insert(i);
    cs.at(i) = c;
    char d = t.at(i) - 'a';
    ccnt.at(d).insert(n+i);
    ct.at(i) = d;
  }
  for (int c = 0; c < 26; c++) {
    if (ccnt.at(c).size() % 2 == 1) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
  vector<pair<int,int>> out;
  for (int i = n-1; i >= 0; i--) {
    int c = cs.at(i);
    int d = ct.at(i);
    if (c == d) {
      ccnt.at(c).erase(i);
      ccnt.at(d).erase(n+i);
      continue;
    }
    for (int j : ccnt.at(c)) {
      if (j == i) continue;
      if (j >= n) {
	int jj = j;
	j -= n;
	out.emplace_back(j, j);
	// cout << j+1 << " " << j+1 << "\n";
	int e = cs.at(j);
	ccnt.at(e).erase(j);
	ccnt.at(e).insert(jj);
	ccnt.at(c).erase(jj);
	ccnt.at(c).insert(j);
	cs.at(j) = c;
	ct.at(j) = e;
      }
      out.emplace_back(j, i);
      // cout << j+1 << " " << i+1 << "\n";
      ccnt.at(c).erase(j);
      ccnt.at(c).erase(i);
      ccnt.at(d).erase(n+i);
      ccnt.at(d).insert(j);
      cs.at(j) = d;
      ct.at(i) = c;
      break;
    }
  }
  cout << out.size() << "\n";
  for (auto p : out) {
    cout << p.first + 1 << " " << p.second + 1 << "\n";
  }
}


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int k; cin >> k;
  for (int kk = 0; kk < k; kk++) {
    solve();
  }

  return 0;
}

