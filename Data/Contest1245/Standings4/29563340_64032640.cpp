#include<bits/stdc++.h>
using namespace std;

int n;
long long cc[2123];
long long kk[2123];
vector<pair<int,int> > vv;
bool vs[2123];
vector<int> s1;
vector<pair<int,int> > s2;

long long distance(long long a,long long b,long long c,long long d){
	return abs(a-c) + abs(b-d);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>b>>a;
		vv.push_back({b,a});
	}
	for(int i=0;i<n;i++){
		cin>>cc[i];
	}
	for(int i=0;i<n;i++){
		cin>>kk[i];
	}
	long long answer = 0;
	for(int t=0;t<n;t++){
		priority_queue<pair<long long,pair<int,int> > > prqu;
		for(int i=0;i<n;i++){
			prqu.push({-cc[i],{i,i}});
		}
		
		while(!prqu.empty()){
			long long val = -prqu.top().first;
			int i1 = prqu.top().second.first, i2 = prqu.top().second.second;
			prqu.pop();
			if(vs[i2])continue;
			if(i1 == i2){
				vs[i1] = true;
				s1.push_back(i1);
				answer += val;
				for(int i=0;i<n;i++){
					if(i == i2 || vs[i]) continue;
					long long val = kk[i2] + kk[i];
					val *= distance(vv[i].first,vv[i].second,vv[i2].first,vv[i2].second);
					prqu.push({-val,{i2,i}});
				}
				continue;
			}
			if(val < cc[i2]){
				answer += val;
				s2.push_back({i1,i2});
				vs[i2] = true;
				for(int i=0;i<n;i++){
					if(i == i2 || vs[i]) continue;
					long long val = kk[i2] + kk[i];
					val *= distance(vv[i].first,vv[i].second,vv[i2].first,vv[i2].second);
					prqu.push({-val,{i2,i}});
				}
			}
		}
	}
	cout<<answer<<'\n';
	cout<<s1.size()<<'\n';
	
	for(int i=0;i<(int)s1.size();i++){
		cout<<s1[i]+1<<" ";
	}
	cout<<'\n';
	cout<<s2.size()<<'\n';
	
	for(int i=0;i<(int)s2.size();i++){
		cout<<s2[i].first+1<<" "<<s2[i].second+1<<'\n';
	}
	
	return 0;
}
