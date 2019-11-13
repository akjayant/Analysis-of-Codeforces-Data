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
  vector<int> a[k];
  rep(i,k){
    cin >> n[i];
    rep(j,n[i]){
      int t;
      cin >> t;
      a[i].pb(t);
    }
  }
  rep(i,k){
    sort(a[i].rbegin(),a[i].rend());
    int l=1;
    if(n[i]>1){
      while(a[i][l]>=l+1){
	l++;
	if(l==n[i]) break;
      }
    }
    cout << l << endl;
  }
	  
  
  return 0;
    

}
