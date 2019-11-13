#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long i64;
typedef i64 int_t;
typedef vector<int_t> vi;
typedef vector<vi> vvi;

typedef pair<int_t, int_t> pi;

#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define REP(s, e, i) for(i=(s); i < (e); ++i)

int main(int argc, char *argv[]) {

  i64 K, k;
  cin >> K;
  REP(0, K, k) {
    i64 n;
    cin >> n;
    getchar();
    string s, t;
    getline(cin, s);
    getline(cin, t);

    i64 i;
    i64 swap = 0;
    bool ans = true;
    char cs, ct;
    REP(0, n, i) {
      if(s[i] != t[i]) {
	switch(swap) {
	case 0:
	  cs = s[i];
	  ct = t[i];
	  swap = 1;
	  break;
	case 1:
	  if(s[i] != cs || t[i] != ct) {
	    ans = false;
	  }
	  swap = 2;
	  break;
	case 2:
	  ans = false;
	  break;
	}
      }
    }
    if(swap == 1)
      ans = false;
      
    cout << (ans ? "YES" : "NO") << endl;
  }

  return 0;
}
