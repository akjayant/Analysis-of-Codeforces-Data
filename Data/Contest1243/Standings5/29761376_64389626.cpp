#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int k;
  cin >> k;
  int n[k];
  string s[k],t[k];
  rep(i,k){
    cin >> n[i];
    cin >> s[i] >> t[i];
  }
  rep(i,k){
    bool ok=false;
    rep(j,n[i]){
      if(s[i][j]!=t[i][j]) break;
      if(j==n[i]-1) ok=true;
    }
    if(!ok){
      int d1,d2;
      d1=d2=-1;
      bool ng=true;
      rep(j,n[i]){
	if(s[i][j]!=t[i][j]){
	  if(d1==-1) d1=j;
	  else if(d2==-1){
	    d2=j;
	    ng=false;
	  }
	  else{
	    ng=true;
	  }
	}
      }
      if(!ng){
	if(s[i][d1]==s[i][d2] && t[i][d1]==t[i][d2]){
	  ok=true;
	}
      }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  
  return 0;
    

}
