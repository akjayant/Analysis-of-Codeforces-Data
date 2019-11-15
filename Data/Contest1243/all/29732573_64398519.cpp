#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;
#define N 1000009
#define M 29
#define INF 1000000007
#define MOD 1000000007
#define MOD1 1000000009
#define MOD2 1000000007
typedef long long int ll;
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pf(x) printf("%d ",x);
#define pf2(x,y) printf("%d %d\n",x,y);
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z);
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tr(x) cout<<x<< endl;
#define tr2(x,y) cout<<x<<" "<<y<< endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(x,y,z,a) cout<<x<<" "<<y<<" "<<z<<  " " << a << " " << endl;
#define sz(x) ((ll) (x).size())

int a[M];
string s1, s2;
// vector<int> v;
bool check(int n){
  for(int i = 0; i<n; i++){
    a[s1[i]-'a']++;
    a[s2[i]-'a']++;
  }
  for(int i = 0; i<26; i++){
    if(a[i]%2){
      return 0;
    }
  }
  return 1;
}
vector<pair<int,int>> v;
void solve(){
  int i,j,k,n,m,x,y;
  sd(n);
  x = 0;
  v.clear();
  fill(a, a+M, 0);
  // s.clear();
  set<int> s;
  cin >> s1 >> s2;
  if(check(n)==0){
    puts("No");
    return;
  }
  bool f = 0;
  for(i = 0; i<n; i++){
    if(s1[i]==s2[i]){continue;}
    f = 0;
    for(j = i+1; j<n; j++){
      if(s1[j]==s1[i]){
        f = 1;
        v.pb(mp(j,i));
        swap(s1[j],s2[i]);
        break;
      }
    }
    if(f){continue;}
    for(j = i+1; j<n; j++){
      if(s2[j]==s1[i]){
        swap(s1[j],s2[j]);
        swap(s1[j],s2[i]);
        v.pb(mp(j,j));
        v.pb(mp(j,i));
        f = 1;
        break;
      }
    }
    if(f==0){
      puts("No");
      return ;
    }
  }

  puts("Yes");
  tr(sz(v));
  for(auto p:v){
    tr2(p.fi+1, p.se+1);
  }


 
}

int  main(){
  int i,j,c,x = 0,y,idx1, idx2,t,i1,m,z = 0,n,k;
  sd(t);
  while(t--){
    solve();
    // tr(x);
  }
}