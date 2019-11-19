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

int main() {
  int z;
  cin >> z;
  while (z--) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = ceil((double)a / (double)c);
    int y = ceil((double)b / (double)d);
    if (x + y <= k) {
      cout << x << " " << y << endl;
    } else {
      cout << -1 << endl;
    }
  }
}