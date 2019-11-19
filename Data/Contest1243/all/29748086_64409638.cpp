#include <iostream> 
#include <list> 
#include <limits.h> 
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long

using namespace std;

map < long long , bool > ff;
map < int , int > f;
map < int , long long > to;

vector < int > a[15];
bool p[(1<<15)],DP[(1<<15)];
int fi[(1<<15)],us[(1<<15)],fr[(1<<15)];
int n,i,x,j,now,k;
long long sum[15],al,y,s;
vector < pair < int , pair < int , int > > > ans;

int main(){
  cin>>n;
  for (i=0;i<n;i++) {
    cin>>y;
    for (int j=0;j<y;j++) {
      scanf("%d",&x);
      f[x]=i;
      ff[x]=1;
      a[i].push_back(x);
      sum[i]+=x;
    }
    al+=sum[i];
  }
  if (al%n != 0) {
    cout<<"No"<<endl;
    return 0;
  }
  al/=n;
  for (i=0;i<n;i++) {
    for (j=0;j<a[i].size();j++) {
      y=al-(sum[i]-a[i][j]);
      to[a[i][j]]=y;
    }
  }

  for (i=0;i<n;i++) {
    for (j=0;j<a[i].size();j++) {
      now=(1<<i);
      for (k=0;k<n;k++)
        us[k]=0;
      us[i]=1;
      s=to[a[i][j]];
      while (s != a[i][j]) {
        if (!ff[s]) break;
        if (us[f[s]]) break;
        us[f[s]]=1;
        now|=(1<<f[s]);
        s=to[s];
      }
      if (s == a[i][j]) {
        p[now]=1;
        fi[now]=a[i][j];
      }
    }
  }
  DP[0]=1;
  for (i=1;i<(1<<n);i++)
    for (j=i;j;j=(j-1)&i)
      if (DP[i-j] && p[j]) {
        DP[i]=1;
        fr[i]=j;
      }
      if (!DP[(1<<n)-1]) {
        cout<<"No"<<endl;
        return 0;
      }
      for (i=(1<<n)-1;i;) {
        s=fi[fr[i]];
        do {
          ans.push_back({f[to[s]],{to[s],f[s]+1}});
          s=to[s];
        } while (s != fi[fr[i]]);
        i-=fr[i];
      }
      sort(ans.begin(),ans.end());
      cout<<"Yes"<<endl;
      for (i=0;i<ans.size();i++)
        cout<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
    }