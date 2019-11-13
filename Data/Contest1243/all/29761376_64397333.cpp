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
  rep(i,k)cin >> n[i] >> s[i] >> t[i];
  rep(i,k){
    bool ok=true;
    vector<pair<int,int> >ans;
    rep(j,n[i]){
      if(s[i][j]!=t[i][j]){
	for(int l=j+1;l<n[i];l++){
	  if(s[i][j]==s[i][l]){
	    ans.pb(mp(l+1,j+1));
	    swap(s[i][l],t[i][j]);
	    break;
	  }
	  else if(s[i][j]==t[i][l]){
	    ans.pb(mp(l+1,l+1));
	    ans.pb(mp(l+1,j+1));
	    swap(s[i][l],t[i][l]);
	    swap(s[i][l],t[i][j]);
	    break;
	  }
	}
      }
    }
    rep(j,n[i]){
      if(s[i][j]!=t[i][j]) ok=false;
    }
    if(ok){
      cout << "Yes" << endl;
      if(ans.size()==0){
	cout << 1 << endl;
	cout << 1 <<" " << 1 << endl;
      }      
      else{
	cout << ans.size() << endl;
	rep(j,ans.size()){
	  cout << ans[j].first << " " << ans[j].second << endl;
	}
      }
    }
    else cout << "No"  << endl;
  }
  return 0;
    

}
