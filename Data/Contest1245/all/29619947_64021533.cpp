#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
  int t;
  scanf("%d",&t);
  while(t--) {
    map<char,int> m;
    int n, a, b, c;
    cin >> n;
    cin >> a >> b >> c >> s;
    for(auto it:s) m[it]++;
    string ans="";
    for(int i = 0 ; i <= a; i++)
      for(int j = 0 ; j <= b; j++)
	for(int k = 0 ; k <= c; k++) {
	  if(ans.size()) continue;
	  if(i + j + k < ( n + 1)/2) continue;
	  if(i > m['S'] || j > m['R'] || k > m['P']) continue;
	  for(int l = 0; l < n; l++) {
	    ans+='#';
	  }
	  int a1=a,b1=b,c1=c;
	  for(int l = 0; l < n; l++) {
	    if(s[l] == 'S' && i) ans[l]='R',i--,a1--;
	    if(s[l] == 'R' && j) ans[l]='P',j--,b1--;
	    if(s[l] == 'P' && k) ans[l]='S',k--,c1--;
	  }
	  for(int l = 0; l < n; l++) {
	    if(ans[l] != '#') continue;
	    if( a1 ) ans[l] = 'R', a1--;
	    else if( b1 ) ans[l] = 'P', b1--;
	    else ans[l] = 'S', c1--;
	  }
	  assert(a1==0 && b1==0 && c1==0);
	}
    if(ans.size()) cout << "YES\n" << ans << endl;
    else cout<<"NO\n";
  }
  return 0 ;
}
