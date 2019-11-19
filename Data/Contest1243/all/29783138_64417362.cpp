#include<bits/stdc++.h>
using namespace std;
#define pfi(a) printf("%d",a);
#define pfl(a) printf("%lld",a);
#define pfin(a) printf("%d\n",a);
#define pfln(a) printf("%lld\n",a);
#define sfi(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
const int M=1e9+7;
const int maxn=5e5+5;

vector<int> v[maxn];
 
int main(){
 ios_base::sync_with_stdio(false);
 	
 	
 	int n,m;
 	cin>>n>>m;

 	int sz[maxn]={0};
 	//int cnt[maxn]={0};
 	map<int,int> mp;
 	set<int> s1,s2;

 	f(i,0,m){
 		int x,y;
 		cin>>x>>y;
 		v[x].push_back(y); v[y].push_back(x);
 		sz[x]++;
 		sz[y]++;

 	}

 	int cost=0;

 	

 	set<pair<int,int> > s;

 	int node=1;

 	for(int i=2;i<=n;i++){
 		s.insert({0,i});
 		mp[i]=0;
 	}

 	int cnt=0;
 	int vis[n+1]={0};

 	while(cnt!=n){
 		cnt++;
 		if(cnt==n)
 			break;
 		vis[node]=1;
 		if(s.find({mp[node],node})!=s.end()){
 			s.erase({mp[node],node});
 		}
 		for(int x:v[node]){
 			if(vis[x]) continue;
 			s.erase({mp[x],x});
 			s.insert({mp[x]-1,x});
 			mp[x]--;
 		}

 		auto it=s.end();
 		it--;
 		pair<int,int> temp1=*it;

 		if(temp1.first+cnt>0){
 	
 		}
 		else{
 			cost++;
 		}
 		node=temp1.second;
 	}

 	cout<<cost;
 	
	return 0;
}