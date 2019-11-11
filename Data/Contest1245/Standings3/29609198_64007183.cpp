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
    ll n;
    cin>>n;
    ll n1 = n/2+n%2;
    ll dd[3];
    cin>>dd[0]>>dd[1]>>dd[2];
    ll d[3];
    clr(d,0);
    string s;
    cin>>s;
    string s1;
    rep(i,0,n){
      s1 += "*";
    }
    ll ans = 0;
    rep(i,0,s.sz){
      if(s[i]=='S'){
        d[0]++;
      }
      if(s[i]=='R'){
        d[1]++;
      }
      if(s[i]=='P'){
        d[2]++;
      }
    }
    ll ddd[3];
    clr(ddd,0);
    rep(i,0,3){
      ll a = min(dd[i],d[i]);
      ans += a;
      dd[i] -= a;
      ddd[i] += a;
    }
    rep(i,0,s1.sz){
      if(s[i]=='S'){
        if(ddd[0]>0){
          s1[i] = 'R';
          ddd[0]--;
        }
      }
      if(s[i]=='R'){
        if(ddd[1]>0){
          s1[i] = 'P';
          ddd[1]--;
        }
      }
      if(s[i]=='P'){
        if(ddd[2]>0){
          s1[i] = 'S';
          ddd[2]--;
        }
      }      
    }
    ll index = 0;
    string ss = "RPS";
    rep(i,0,s1.sz){
      while(dd[index]<=0){
        index++;
      }
      if(s1[i]=='*'){
        s1[i] = ss[index];
        dd[index]--;
      }
    }
    if(ans>=n1){
      cout << "YES" << endl;
      cout << s1 << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
  return 0;
}