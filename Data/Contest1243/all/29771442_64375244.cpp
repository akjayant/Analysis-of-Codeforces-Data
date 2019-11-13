#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-8)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

typedef long long ll;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

int n;
int a[1010];

void compute() {
  for(int i=n;i>=1;--i) {
    int cnt = 0;
    rep(j,n) {
      if( a[j] >= i ) ++cnt;
      else break;
    }
    if( cnt >= i ) {
      cout << i << endl;
      return ;
    }
  }
  puts("1");
}

int main() {
  int T;
  scanf("%d",&T);
  while( T-- ) {
    scanf("%d",&n);
    rep(i,n) scanf("%d",&a[i]);
    sort(a,a+n,greater<int>());
    compute();
  }
  return 0;
}
