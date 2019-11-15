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

const i64 NUM = 1000000007LL;

int main(int argc, char *argv[]) {
  string s;
  getline(cin, s);
  i64 n = sz(s), i;

  if(s[0] == 'm' || s[0] == 'w') {
    cout << 0 << endl;
    return 0;
  }
  else {
    i64 a0 = 1, a1 = 1;
    REP(1, n, i) {
      switch(s[i]) {
      case 'm':
      case 'w':
	cout << 0 << endl;
	return 0;
      case 'n':
	if(s[i-1] == 'n') {
	  i64 a2 = (a1 + a0) % NUM;
	  a0 = a1;
	  a1 = a2;
	}
	else {
	  a0 = a1;
	}
	break;
      case 'u':
	if(s[i-1] == 'u') {
	  i64 a2 = (a1 + a0) % NUM;
	  a0 = a1;
	  a1 = a2;
	}
	else {
	  a0 = a1;
	}
	break;
      default:	
	a0 = a1;
	break;
      }
    }
    cout << a1 << endl;
  }

  return 0;
}
