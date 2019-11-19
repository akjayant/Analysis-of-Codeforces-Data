#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> x(n), y(n), c(n), k(n);
	for (int i=0;i<n;++i) cin >> x[i] >> y[i];

	priority_queue<pair<long long,pair<int, int> > > pque;

	for (int i=0;i<n;++i) {cin >> c[i]; pque.push(make_pair(-c[i],make_pair(i,-1)));}
	for (int i=0;i<n;++i) cin >> k[i];
	
	long long cost=0;
	int remvert=n;
	vector<bool> spanned(n,false);
	vector<int> pst(0);
	vector<pair<int,int> > conn(0);
	
	
	while (remvert) {
		int u,v;
		long long money;
		money=-pque.top().first;
		u=pque.top().second.first;
		v=pque.top().second.second;
		pque.pop();
		if (spanned[u]) continue;
		
		if (v==-1) pst.push_back(u);//cout << "built pst in " << u << " for " << money << " yen." << endl;
		else conn.push_back(make_pair(u, v));//cout << "connected " << u << " to " << v << " for " << money << " yen." << endl;
		
		spanned[u]=true;
		remvert--;
		cost+=money;
		
		for (int w=0;w<n;++w) if (w!=u) {
			money=(k[u]+k[w])*(abs(x[u]-x[w])+abs(y[u]-y[w]));
			pque.push(make_pair(-money,make_pair(w,u)));
		}
		
	}
	cout << cost << endl;
	cout << pst.size() << endl;
	for(int i=0;i<pst.size();++i) cout << 1+pst[i] << endl;
	cout << conn.size() << endl;
	for(int i=0;i<conn.size();++i) cout << 1+conn[i].first << " " << 1+conn[i].second << endl;
	

}