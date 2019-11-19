#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

ll beauty(string & s) {
  int n = s.size();
  ll veg = 1;
  ll ob = 0, pc = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') ob ++;
    else ob--;
    if (ob == pc) {
      veg++;
    }
    else if (ob < pc) {
      pc = ob;
      veg = 1;
    }
  }
  if (ob != 0) return 0;
  else if (pc == 0) return veg-1;
  else return veg;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
  int n; 
  cin >> n;
  
    string s;
    cin >> s;
    ll res = beauty(s), ib = 0, jb = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        swap(s[i], s[j]);
        ll c = beauty(s);
        swap(s[i], s[j]);
        if (c > res) {
          res = c;
          ib = i;
          jb = j;
        }
      }
    }
    cout << res << endl;
    cout << ib+1 << " " << jb+1 << endl;
  
}

