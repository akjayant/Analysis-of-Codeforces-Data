#include <bits/stdc++.h>

//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("Ofast")

#define F first
#define S second
#define MT make_tuple
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
  int t; cin >>t;
  for(int i=0; i<t; i++){
    int n; cin >> n;
    string s; cin >> s;
    int mi=n, ma=-1, cc=0;
    // cerr << n << " "<<s<<"\n";
    for(int j=0; j<n; j++){
      if(s[j]=='0')
        continue;
      mi=min(mi, j);
      ma=max(ma, j);
      cc++;
    }
    cout << max(max((n-mi)*2, (ma+1)*2), n+cc)<<"\n";
  }
}
