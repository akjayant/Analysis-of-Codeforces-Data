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

  int t;
  cin >> t;
  int n[t];
  int a[t],b[t],c[t];
  string s[t];
  rep(i,t){
    cin >> n[i];
    cin >> a[i] >> b[i] >> c[i];
    cin >> s[i];
  }
  rep(i,t){
    int tmp=0;
    int r,sc,p;
    r=sc=p=0;
    rep(j,n[i]){
      if(s[i][j]=='R') ++r;
      if(s[i][j]=='P') ++p;
      if(s[i][j]=='S') ++sc;
    }
    tmp=min(r,b[i])+min(sc,a[i])+min(p,c[i]);
    if(tmp>=(n[i]+1)/2){
      cout << "YES" << endl;
      rep(j,n[i]){
	bool ok=false;
	if(s[i][j]=='R'){
	  if(b[i]>0){
	    cout << "P";
	    --b[i];
	    ok=true;
	  }
	  --r;		    
	}
	if(s[i][j]=='P'){
	  if(c[i]>0){
	    cout << "S";
	    --c[i];
	    ok=true;
	  }
	  --p;
	}
	if(s[i][j]=='S'){
	  if(a[i]>0){
            cout << "R";
            --a[i];
	    ok=true;
          }
	  --sc;
	}
	if(!ok){
	  if(r < b[i]){
	    cout << "P";
	    --b[i];	    
	  }
	  else if (sc < a[i]){
	    cout << "R";
	    --a[i];
	  }
	  else if(p < c[i]){
	    cout << "S";
	    --c[i];
	  }
	}
      }
      cout << "" << endl;
    }
    else cout << "NO" << endl;
  }

  
  return 0;
    

}
