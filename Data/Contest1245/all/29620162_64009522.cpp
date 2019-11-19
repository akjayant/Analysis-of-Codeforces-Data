#include<iostream>
#include<vector>
#include<math.h>
#include<utility>
#include<algorithm>
#define int long long
const int N=2055;
using namespace std;
int par[N],x[N],y[N],c[N],k[N];
int find(int v){
	if(par[v]==v)
		return par[v];
	par[v]=find(par[v]);
	return par[v];
}
void merge(int a,int b){
	int c=find(a);
	int d=find(b);
	if(c!=d)
	par[c]=d;
}
  main(){
 	ios::sync_with_stdio(false);
 	cin.tie(NULL);
 	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<N;i++)
		par[i]=i;
	vector < pair<int, pair<int,int> > > v;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		v.push_back(make_pair(c[i],make_pair(0,i)));
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];

	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int cost=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
			v.push_back(make_pair(cost,make_pair(i,j)));
	
		}
	}
	sort(v.begin(),v.end());
	int cost=0;
	vector<int> cities;
	vector< pair<int,int> > ed;
	for(int i=0;i<v.size();i++){
		int co=v[i].first;
		int a=v[i].second.first;
		int b=v[i].second.second;
		if(find(a)!=find(b)){
			merge(a,b);
			cost+=co;
			if(a==0){
				cities.push_back(b);
			}
			else if(b==0)
				cities.push_back(a);
			else{
				ed.push_back(make_pair(a,b));
			}
		}
	}
	cout<<cost<<endl;
	cout<<cities.size()<<endl;
	for(int i=0;i<cities.size();i++)
		cout<<cities[i]<<" ";
	cout<<endl;
	cout<<ed.size()<<endl;
	for(int i=0;i<ed.size();i++)
		cout<<ed[i].first<<" "<<ed[i].second<<endl;

}