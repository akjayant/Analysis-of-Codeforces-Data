#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-8)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

typedef long long ll;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

bool debug = 0;
int n;
char tmp[10010];
string s,t;
const string YES = "Yes", NO = "No";

void compute() {
  vector<int> vec;
  rep(i,n) {
    if( s[i] != t[i] ) vec.push_back(i);
  }
  if( debug ) rep(i,(int)vec.size()) cout << "? " << vec[i] << endl;
  if( vec.size() != 2 ) {
    cout << NO << endl;
    return;
  }
  char c = s[vec[0]];
  s[vec[0]] = t[vec[1]];
  t[vec[1]] = c;
  
  if( debug ) cout << "s = " << s << ", t = " << t << endl;
  if( s[vec[0]] == t[vec[0]] && s[vec[1]] == t[vec[1]] ) {
    cout << YES << endl;
  } else {
    cout << NO << endl;
  }
  
}

int main() {
  int T;
  scanf("%d",&T);
  while( T-- ) {
    scanf("%d",&n);
    scanf("%s",&tmp[0]);
    s = string(tmp);
    scanf("%s",&tmp[0]);
    t = string(tmp);
    if( debug ) cout << s << " " << t << endl;
    compute();
  }
  return 0;
}
