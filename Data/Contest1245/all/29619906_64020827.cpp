#include <bits/stdc++.h>
#define D if(false)

using namespace std;

// a + b = a ^ b + 2 * (a & b)

// DP[r][al][ar][bl][br]

typedef long long ll;

ll dp(vector<ll>& table,
      const bitset<32>& lo, const bitset<32>& hi,
      int r, int al, int ar, int bl, int br) {
  long idx = r;
  idx = idx * 2 + al;
  idx = idx * 2 + ar;
  idx = idx * 2 + bl;
  idx = idx * 2 + br;

  while(table[idx] < 0) {
    table[idx] = 0;

    if(r == 0) { table[idx] = 1; break; }

    vector<pair<int,int> > gg;
    for(int a = 0; a < 2; a++) {
      for(int b = 0; b < 2; b++) {
        if(a && b) continue;
        bool good = 1;

        int nal = al, nar = ar;
        int nbl = bl, nbr = br;
        if(a > lo[r-1]) {
          nal = 1;
        } else if(a < lo[r-1] && !al) {
          good = 0;
        }

        if(b > lo[r-1]) {
          nbl = 1;
        } else if(b < lo[r-1] && !bl) {
          good = 0;
        }

        if(a < hi[r-1]) {
          nar = 1;
        } else if(a > hi[r-1] && !ar) {
          good = 0;
        }

        if(b < hi[r-1]) {
          nbr = 1;
        } else if(b > hi[r-1] && !br) {
          good = 0;
        }

        if(good) {
          D gg.push_back({a,b});
          table[idx] += dp(table, lo, hi, r-1, nal, nar, nbl, nbr);
        }
      }
    }

    D {
      cout << r << " " << al << ar << bl << br << ": " << table[idx] << endl;
      for(int i = 0; i < gg.size(); i++) {
        cout << "\t" << gg[i].first << "," << gg[i].second << endl;
      }
    }
  }

  return table[idx];
}

int main() {
  int t; cin >> t;

  while(t--) {
    int a, b; cin >> a >> b;

    bitset<32> aa(a), bb(b);

    vector<ll> table(33 * 16, -1);
    ll res = dp(table, aa, bb, 32, 0, 0, 0, 0);
    cout << res << endl;
  }

  return 0;
}
