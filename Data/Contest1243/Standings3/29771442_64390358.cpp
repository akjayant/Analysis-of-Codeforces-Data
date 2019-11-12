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

bool check() {
  map<char,int> mp;
  rep(i,n) {
    ++mp[s[i]];
    ++mp[t[i]];
  }
  for(auto v : mp)  {
    if( v.second & 1 ) return false;
  }
  return true;
}

int getPos(string &u,char c,int sp) {
  REP(i,sp,n) {
    if( u[i] == c ) return i;
  }
  return -1;
}

void compute() {
  if( !check() ) { cout << NO << endl; return; }
  typedef pair<int,int> ii;
  vector<ii> vec;
  rep(i,n-1) {
    if( s[i] == t[i] ) continue;
    int pos = getPos(s,s[i],i+1);
    if( pos != -1 ) {
      char tmp = t[i];
      t[i] = s[pos];
      s[pos] = tmp;
      vec.push_back(ii(pos,i));
      continue;
    }
    pos = getPos(t,s[i],i+1);
    if(debug) assert( pos != -1 );
    char tmp = t[pos];
    t[pos] = s[pos];
    s[pos] = tmp;
    vec.push_back(ii(pos,pos));

    tmp = t[i];
    t[i] = s[pos];
    s[pos] = tmp;
    vec.push_back(ii(pos,i));
  }
  if(debug) {
    cout << s << " == " << t << endl;
    assert( s == t );
  }
  cout << YES << endl;
  cout << vec.size() << endl;
  rep(i,(int)vec.size()) {
    cout << vec[i].first + 1 << " " << vec[i].second + 1 << endl;
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
