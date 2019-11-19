#include <bits/stdc++.h>

//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("Ofast")

#define F first
#define S second
#define MT make_tuple
#define MP make_pair
#define SZ(a) ((int)(a).size())
#define PB push_back
#define LBS 20
#define MOD ((long long)1e9+7) //1e9+9
#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i)+1)
#define PAR(i) ((i)/2)

using namespace std;

typedef long long ll;
typedef double rat;
typedef long long bi;
typedef pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::map<int, int> mii;
typedef bitset<LBS> bis;
typedef std::vector<bis> vbs;

template<class T>
void in(T &a){
  for(auto &x: a)
    cin >> x;
}

template<class T>
void out(T &a, string sep=" "){
  for(auto x: a)
    cout << x<<sep;
  cout << '\n';
}

template<class T>
void err(T &a, string sep=" "){
  for(auto x: a)
    cerr << x <<sep;
  cerr << '\n';
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  std::vector<ll> c[3];
  for(auto &x: c){
    x=std::vector<ll>(n);
    in(x);
  }
  std::vector<std::vector<int> > e(n);
  for(int i=1; i<n; i++){
    int a, b; cin >> a >> b; a--; b--;
    e[a].PB(b);
    e[b].PB(a);
  }
  int s=0, f=-1, ts;
  for(int i=0; i<n; i++){
    if(SZ(e[i])>2){
      cout << "-1\n";
      return 0;
    }
    if(SZ(e[i])==1)
      s=i;
  }
  ts=s;
  ll r[3][3]={0};
  for(int i=0; i<n; i++){
    for(int a=0; a<3; a++)
      for(int b=0; b<3; b++){
        if(a==b)
          continue;
        if(i%3==0)
          r[a][b]+=c[a][s];
        else if(i%3==1)
          r[a][b]+=c[b][s];
        else
          r[a][b]+=c[3-a-b][s];
    }
    int n=-1;
    for(int x: e[s])
      if(x!=f)
        n=x;
    f=s;
    s=n;
  }
  ii b={0,1};
  for(auto x: {MP(0,2), MP(1,0), MP(1,2), MP(2,0), MP(2,1)})
    if(r[x.F][x.S]<r[b.F][b.S])
      b=x;
  cout << r[b.F][b.S]<<"\n";
  std::vector<int> co(n);
  s=ts; f=-1;
  for(int i=0; i<n; i++){
    if(i%3==0)
      co[s]=b.F+1;
    else if(i%3==1)
      co[s]=b.S+1;
    else
      co[s]=3-b.F-b.S+1;
    int n=-1;
    for(int x: e[s])
      if(x!=f)
        n=x;
    f=s;
    s=n;
  }
  out(co);
}
