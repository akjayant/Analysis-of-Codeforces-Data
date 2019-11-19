#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <functional>
#include <set>
#include <ctime>
#include <random>
#include <chrono>
#include <cassert>
#include <tuple>
#include <utility>
using namespace std;

namespace {
  using Integer = long long; //__int128;
  template<class T, class S> istream& operator >> (istream& is, pair<T,S>& p){return is >> p.first >> p.second;}
  template<class T> istream& operator >> (istream& is, vector<T>& vec){for(T& val: vec) is >> val; return is;}
  template<class T> istream& operator ,  (istream& is, T& val){ return is >> val;}
  template<class T, class S> ostream& operator << (ostream& os, const pair<T,S>& p){return os << p.first << " " << p.second;}
  template<class T> ostream& operator << (ostream& os, const vector<T>& vec){for(size_t i=0; i<vec.size(); i++) os << vec[i] << (i==vec.size()-1?"":" "); return os;}
  template<class T> ostream& operator ,  (ostream& os, const T& val){ return os << " " << val;}

  template<class H> void print(const H& head){ cout << head; }
  template<class H, class ... T> void print(const H& head, const T& ... tail){ cout << head << " "; print(tail...); }
  template<class ... T> void println(const T& ... values){ print(values...); cout << endl; }

  template<class H> void eprint(const H& head){ cerr << head; }
  template<class H, class ... T> void eprint(const H& head, const T& ... tail){ cerr << head << " "; eprint(tail...); }
  template<class ... T> void eprintln(const T& ... values){ eprint(values...); cerr << endl; }

  class range{ Integer start_, end_, step_; public: struct range_iterator{ Integer val, step_; range_iterator(Integer v, Integer step) : val(v), step_(step) {} Integer operator * (){return val;} void operator ++ (){val += step_;} bool operator != (range_iterator& x){return step_ > 0 ? val < x.val : val > x.val;} }; range(Integer len) : start_(0), end_(len), step_(1) {} range(Integer start, Integer end) : start_(start), end_(end), step_(1) {} range(Integer start, Integer end, Integer step) : start_(start), end_(end), step_(step) {} range_iterator begin(){ return range_iterator(start_, step_); } range_iterator   end(){ return range_iterator(  end_, step_); } };

  inline string operator "" _s (const char* str, size_t size){ return move(string(str)); }
  constexpr Integer my_pow(Integer x, Integer k, Integer z=1){return k==0 ? z : k==1 ? z*x : (k&1) ? my_pow(x*x,k>>1,z*x) : my_pow(x*x,k>>1,z);}
  constexpr Integer my_pow_mod(Integer x, Integer k, Integer M, Integer z=1){return k==0 ? z%M : k==1 ? z*x%M : (k&1) ? my_pow_mod(x*x%M,k>>1,M,z*x%M) : my_pow_mod(x*x%M,k>>1,M,z);}
  constexpr unsigned long long operator "" _ten (unsigned long long value){ return my_pow(10,value); }

  inline int k_bit(Integer x, int k){return (x>>k)&1;} //0-indexed

  mt19937 mt(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count());

  template<class T> string join(const vector<T>& v, const string& sep){ stringstream ss; for(size_t i=0; i<v.size(); i++){ if(i>0) ss << sep; ss << v[i]; } return ss.str(); }

  inline string operator * (string s, int k){ string ret; while(k){ if(k&1) ret += s; s += s; k >>= 1; } return ret; }
}
constexpr long long mod = 9_ten + 7;

int main(){
  int n = 10;
  vector<vector<int>> h(n, vector<int>(n));
  cin >> h;

  vector<double> dp(n*n, 0.0);
  vector<double> dp_(n*n, 0.0);
  vector<vector<int>> x(n, vector<int>(n));
  vector<int> ii;
  for(int i=0, t=0; i<n; i++){
    if(i%2 == 0) for(int j=0; j<n; j++){
      x[i][j] = t++;
      ii.push_back(i*n + j);
    }
    if(i%2 == 1) for(int j=n-1; j>=0; j--){
      x[i][j] = t++;
      ii.push_back(i*n + j);
    }
  }

  double six_inv = 1.0 / 6.0;
  for(int u=1; u<ii.size(); u++){
    int i = ii[u] / n;
    int j = ii[u] % n;

    int stay = max(6-u, 0);
    double er = 0.0;
    for(int k=1; k<=6; k++){
      int v = u-k;
      if(v<0) continue;

      er += dp[v];
    }
    er *= six_inv;
    er += 1.0;
    double el = 1.0 - stay * six_inv;
    er /= el;

    dp[u] = dp_[u] = er;

    if(h[i][j] != 0){
      int v = x[i-h[i][j]][j];
      dp[u] = min(dp[u], dp_[v]);
    }
  }

  printf("%.12f\n", dp.back());

  return 0;
}
