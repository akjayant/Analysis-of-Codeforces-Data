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

  i64 t, T, i;
  cin >> T;
  REP(0, T, t) {
    i64 n, a, b, c;
    cin >> n >> a >> b >> c;
    getchar();
    string s;
    getline(cin, s);
    
    string ans = s;
    i64 wins = 0;
    REP(0, n, i) {
      ans[i] = ' ';
      switch(s[i]) {
      case 'R':
	if(b > 0) {
	  --b;
	  ans[i] = 'P';
	  ++wins;
	}
	break;
      case 'P':
	if(c > 0) {
	  --c;
	  ans[i] = 'S';
	  ++wins;
	}
	break;
      case 'S':
	if(a > 0) {
	  --a;
	  ans[i] = 'R';
	  ++wins;
	}
	break;
      }
    }

    REP(0, n, i) {
      if(ans[i] == ' ') {
	if(a > 0) {
	  ans[i] = 'R';
	  --a;
	}
	else if(b > 0) {
	  ans[i] = 'P';
	  --b;
	}
	else {
	  ans[i] = 'S';
	  --c;
	}
      }
    }

    if(wins >= (n + 1) / 2) {
      cout << "YES" << endl << ans << endl;
    }
    else {
      cout << "NO" << endl;
    }

  }

  return 0;
}
