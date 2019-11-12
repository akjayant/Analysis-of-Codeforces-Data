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

    i64 i, j;
    bool ans = true;
    vi count(26, 0);
    REP(0, n, i) {      
      count[s[i]-'a']++;
      count[t[i]-'a']++;
    }
    REP(0, 26, i) {
      if(count[i] % 2 != 0)
	ans = false;
    }
    if(!ans) {
      cout << "NO" << endl;
    }
    else {
      cout << "YES" << endl;
      vector<pi> ops;
      REP(0, n, i) {
	bool found = false;
	REP(i+1,n,j) {
	  if(s[j] == s[i]) {
	    swap(s[j], t[i]);
	    ops.pb(make_pair(j+1,i+1));
	    found = true;
	    break;
	  }
	}
	if(!found) {
	  REP(i+1,n,j) {
	    if(t[j] == s[i]) {
	      swap(s[j], t[j]);
	      ops.pb(make_pair(j+1,j+1));
	      swap(s[j], t[i]);
	      ops.pb(make_pair(j+1,i+1));
	      break;
	    }
	  }
	}
      }
      cout << sz(ops) << endl;
      REP(0, sz(ops), i) {
	cout << ops[i].first << " " << ops[i].second << endl;
      }
    }
  }

  return 0;
}
