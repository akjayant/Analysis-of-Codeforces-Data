#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=b-1LL;i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define endl "\n"
#define print(x) cout<<#x<<" = "<<x<<endl;

#define MOD 1000000007

long long gcd(long long a, long long b){
  return b == 0LL ? a : gcd(b, a % b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll T;
  cin>>T;
  rep(tt,0,T){
  ll a,b;
  cin>>a>>b;
  if(gcd(a,b)==1){
    cout << "Finite" << endl;
  }
  else{
    cout<< "Infinite" << endl;
  }
  }

  return 0;
}