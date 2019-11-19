
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack> 
#include <map>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;



vector<pair<long long,long long> > in;
long long c[2003];
long long k[2003];

long long id[20003];

long long root(long long i){
	if(id[i]==i)
		return i;
	return id[i]=root(id[i]);
}
void unite(long long a, long long b){
	a = root(a);
	b = root(b);
	if(a==b)return;
	id[a]=b;
}



vector<pair<pair<long long,long long> , pair<long long,long long> > > edges;

long long dist(long long i, long long j){
	return abs(in[i].first - in[j].first) + abs(in[i].second - in[j].second) ;
}


vector<long long> power;
vector<pair<long long,long long> > conn;
long long kruskal(){
	sort(edges.begin(), edges.end());
	long long cost =0;
	for(auto p: edges){
		long long d = p.first.first;
		long long t = p.first.second;
		long long a = p.second.first;
		long long b =p.second.second;
		if(root(a)==root(b))
			continue;
		cost+=d;
		unite(a, b);
		if(t==1)
			power.push_back(a);
		else {
			conn.push_back({a, b});
		}
	}
	return cost;
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	for(int i =0;i<n;i++) {
		long long x, y;
		cin>> x>> y;
		in.push_back({x, y});
	}
	for(int i = 1;i<=n;i++)
		cin>>c[i];

	for(int i = 1;i<=n;i++)
		cin>>k[i];
	for(int i =0;i<=n;i++)
		id[i]=i;
	
	for(int i  = 1;i<=n;i++){
		edges.push_back({{c[i], 1} , {i, 0}});
	}
	for(int i= 0;i<n;i++){
		for(int j =i + 1;j<n;j++){
			long long d= dist(i,j)*(k[i +1] + k[j +1]);
			edges.push_back({{d, 2}, {i+1,j+1}});
		}
	}	
	long long cost = kruskal();
	cout<<cost<<"\n";
	cout<<power.size()<<"\n";
	for(long long x: power)
		cout<<x<<" ";
	cout<<"\n";
	cout<<conn.size()<<"\n";
	for(auto pp : conn)
		cout<<pp.first<<" "<<pp.second<<"\n";

	return 0;
}

