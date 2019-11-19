#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

using ll = long long;//__int128;

//a*x + b*y = gcd(a,b)
ll extgcd(ll a, ll b, ll &x, ll &y){
  ll d = a;
  if(b){
    d = extgcd(b, a%b, y, x);
    y -= (a / b)*x;
  }else{
    x = 1;
    y = 0;
  }
  return d;    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n_, p_, w_, d_;
  cin >> n_ >> p_ >> w_ >> d_;
  ll n = n_, p = p_, w = w_, d = d_;
  if(n*w < p){
    cout << -1 << endl;
    return 0;
  }
  ll x, y;
  ll g = extgcd(w,d,x,y);
  cerr << x << " " << y << endl;
  assert(w%g == 0);
  assert(d%g == 0);
  if(p%g){
    cout << -1 << endl;
    return 0;
  }
  ll X = (p+w-1)/w;
  ll t = (X*w-p)/g;
  X -= t*x;
  ll Y = -y*t;
  cerr << X << " " << Y << endl;
  assert(X*w + Y*d == p);
  //x *= p/g, y *= p/g;
  if(Y < 0){
    // cerr << X << " " << Y << endl;
    ll Y_ = abs(Y), t = (Y_+(w/g)-1)/(w/g);
    Y += t*(w/g);
    X -= t*(d/g);
    // cerr << X << " " << Y << endl;
  }
  // {
  //   X += (d/g)*(y/(w/g));
  //   y %= w/g;
  // }
  // if(y < 0){
  //   // cerr << X << " " << y << endl;
  //   ll y_ = abs(y), t = (y_+(w/g)-1)/(w/g);
  //   y += t*(w/g);
  //   X -= t*(d/g);
  //   // cerr << X << " " << y << endl;
  // }
  // {
  //   X += (d/g)*(y/(w/g));
  //   y %= w/g;
  // }
  //assert(X*w + y*d == g);
  cerr << X << " " << Y << endl;
  if(X < 0 or Y < 0 or X+Y > n){
    cout << -1 << endl;
    return 0;
  }
  //cout << (long long)x*(p/g) << " " << (long long)y*(p/g) << " " << (long long)(n-x*(p/g)-y*(p/g)) << endl;
  cout << X << " " << Y << " " << (n-X-Y) << endl;
}
