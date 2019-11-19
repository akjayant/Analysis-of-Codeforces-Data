#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define INF 100000000000000000
#define modulo 1000000007
#define int long long int
using namespace std;
int dist(ii A,ii B){
      return abs(A.first-B.first)+abs(A.second-B.second);
}
vector<int> no;
int F(int x){
      if(x==no[x])return x;
      return no[x]=F(no[x]);
}
bool dsu(int a,int b){
      a=F(a);
      b=F(b);
      if(a==b)return false;
      no[a]=b;
      return true;
}
int32_t main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int n;
      cin>>n;
      vector<ii>A(n);
      vector<int> C(n);
      vector<int> K(n);
      vector<pair<int,ii> > edge;
      for(int i=0;i<n;i++)cin>>A[i].first>>A[i].second;
      for(int i=0;i<n;i++)cin>>C[i];
      for(int i=0;i<n;i++)cin>>K[i];
      for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                  edge.pb({dist(A[i],A[j])*(K[i]+K[j]),{i,j}});
            }
      }
      for(int i=0;i<n;i++){
            edge.pb({C[i],{i,n}});
            no.pb(i);
      }
      no.pb(n);
      int ans=0;
      vector<ii> arr;
      vector<int> c;
      sort(all(edge));
      for(vector<pair<int,ii> >::iterator itr=edge.begin();itr!=edge.end();itr++){
            if(dsu(itr->second.first,itr->second.second)){
                  ans+=itr->first;
                  if(itr->second.second==n)c.pb(itr->second.first);
                  else arr.pb(itr->second);
            }
      }
      cout<<ans;
      cout<<"\n"<<c.size()<<"\n";
      for(int i=0;i<c.size();i++)cout<<c[i]+1<<" ";
      cout<<"\n"<<arr.size()<<"\n";
      for(int i=0;i<arr.size();i++)cout<<arr[i].first+1<<" "<<arr[i].second+1<<"\n";
}
