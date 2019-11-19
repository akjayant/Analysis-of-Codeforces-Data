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
#define ALL(a) (a).begin(), (a).end()

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
  ll n, k; cin >> n >> k;
  vector<ll> a(n); in(a);
  sort(ALL(a));
  ll nmi=1, nma=1;
  ll mi=a[nmi-1], ma=a[n-nma];
  while(ma-mi>0 && k>0){
    while(a[nmi]==mi)
      nmi++;
    while(a[n-nma-1]==ma)
      nma++;

    // if(nmi<nma){
    //   if(k>=nmi){
    //     k-=nmi;
    //     mi++;
    //   } else
    //     break;
    // } else{
    //   if(k>=nma){
    //     k-=nma;
    //     ma--;
    //   } else
    //     break;
    // }
    if(nmi<nma){
      if((a[nmi]-mi)*nmi<=k){
        k-=(a[nmi]-mi)*nmi;
        mi=a[nmi];
      } else {
        mi+=k/nmi;
        k-=k/nmi*nmi;
        break;
      }
    } else{
      if((ma-a[n-nma-1])*nma<=k){
        k-=(ma-a[n-nma-1])*nma;
        ma=a[n-nma-1];
      } else {
        ma-=k/nma;
        k-=k/nma*nma;
        break;
      }
    }
  }
  cout << ma-mi<<"\n";
}
