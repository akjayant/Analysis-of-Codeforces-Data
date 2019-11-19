#include<bits/stdc++.h>
using namespace std;

int n;
long long c[2003];
long long k[2003];
vector<pair<int,int> > v;
bool vstd[2003];
vector<int> solnodes;
vector<pair<int,int> > soledges;

long long dis(long long x,long long y,long long xx,long long yy){
	return abs(x-xx) + abs(y-yy);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back({x,y});
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	long long ans = 0;
	for(int t=0;t<n;t++){
		//if(vstd[t])continue;
		/*
		long long mn = 1e9+1,idx = -1;
		for(int i=0;i<n;i++){
			if(c[i] < mn && ! vstd[i]){
				mn = c[i];
				idx = i;
			}
		}
		if(vstd[idx] || idx == -1)continue;
		ans += mn;
		vstd[idx] = true;
		solnodes.push_back(idx);
		*/
		priority_queue<pair<long long,pair<int,int> > > pq;
		for(int i=0;i<n;i++){
			pq.push({-c[i],{i,i}});
			/*
			if(i == idx) continue;
			long long val = k[idx] + k[i];
			val *= dis(v[i].first,v[i].second,v[idx].first,v[idx].second);
			pq.push({-val,{idx,i}});
			*/
		}
		
		while(!pq.empty()){
			long long val = -pq.top().first;
			int id1 = pq.top().second.first, id2 = pq.top().second.second;
			pq.pop();
			if(vstd[id2])continue;
			if(id1 == id2){
				vstd[id1] = true;
				solnodes.push_back(id1);
				ans += val;
				for(int i=0;i<n;i++){
					if(i == id2 || vstd[i]) continue;
					long long val = k[id2] + k[i];
					val *= dis(v[i].first,v[i].second,v[id2].first,v[id2].second);
					pq.push({-val,{id2,i}});
				}
				continue;
			}
			if(val < c[id2]){
				ans+= val;
				soledges.push_back({id1,id2});
				vstd[id2] = true;
				for(int i=0;i<n;i++){
					if(i == id2 || vstd[i]) continue;
					long long val = k[id2] + k[i];
					val *= dis(v[i].first,v[i].second,v[id2].first,v[id2].second);
					pq.push({-val,{id2,i}});
				}
			}
		}
	}
	//for(int i=0;i<n;i++) cout<<vstd[i]<<" ";cout<<endl;
	cout<<ans<<endl;
	cout<<solnodes.size()<<endl;
	for(int x:solnodes) cout<<x+1<<" ";cout<<endl;
	cout<<soledges.size()<<endl;
	for(auto p:soledges) cout<<p.first+1<<" "<<p.second+1<<endl;
	return 0;
}

/*
3
1 4
3 1
4 2
1 4 5
6 2 3
*/
/*
4
1 4
1 4
3 1
4 2
16 1 4 5
3 1 2 3
*/
/*
4
1 1
1 1
2 2
2 2
1 10 2 10
1 1 1 1
*/
