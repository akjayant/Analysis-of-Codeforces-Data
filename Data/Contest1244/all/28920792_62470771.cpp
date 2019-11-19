#include <bits/stdc++.h>
 
using namespace std;
using LL = long long int; 

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}
 
template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.st <<","<<P.nd <<")";
}

string s;
int n;

int main() {
  int z;
  cin >> z;
  while (z--) {
    cin >> n;
    cin >> s;
    int maks = 0;
    bool czy = false;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == '1') {
        czy = true;
        maks = i;
      }
    }
    if (!czy) {
      cout << n << endl;
      continue;
    }
    int res = 0;
    res = (maks + 1) * 2;
    int minn = -1;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == '1' && minn == -1) {
        minn = i;
        break;
      }
    }
    if (minn != -1) {
      res = max(res, (n - minn) * 2);
    }
    cout << res << endl;
  }
}