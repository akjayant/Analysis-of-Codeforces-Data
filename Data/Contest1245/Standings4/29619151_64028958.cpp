#include<iostream>
#include<queue>
#include<vector>
using namespace::std;

pair<long long int,long long int> ar[2005];
long long int sp[2005],k[2005],pred[2005];
bool visited[2005];

long long int cost(int i,int j){
	return (abs(ar[i].first-ar[j].first)+abs(ar[i].second-ar[j].second))*(k[i]+k[j]);
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>ar[i].first>>ar[i].second;
	priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>> q;
	for(int i=0;i<n;i++)
		cin>>sp[i],q.push({sp[i],i}),pred[i]=-1;
	for(int i=0;i<n;i++)
		cin>>k[i];
	while(!q.empty()){
		int i=q.top().second;q.pop();
		if(visited[i]) continue;
		visited[i]=1;
		//cout<<i<<'\n';
		for(int j=0;j<n;j++)
			if(!visited[j] && sp[j]>cost(i,j))
				q.push({sp[j]=cost(i,j),j}),pred[j]=i;
			//else if(j!=i) cout<<sp[j]<<' '<<cost(i,j)<<' '<<i<<' '<<j<<'\n';
	}
	long long int ans=0;
	vector<int> power;
	vector<pair<int,int>> edges;
	for(int i=0;i<n;i++){
		ans+=sp[i];
		if(pred[i]==-1)
			power.push_back(i+1);
		else edges.push_back({i+1,pred[i]+1});
	}
	cout<<ans<<'\n'<<power.size()<<'\n';
	for(auto a:power)
		cout<<a<<' ';
	cout<<'\n'<<edges.size()<<'\n';
	for(auto a:edges)
		cout<<a.first<<' '<<a.second<<'\n';

}
