    #include <bits/stdc++.h>
    #pragma optimize("Ofast")
    using namespace std;
    set<int> a[200020],s;
    vector<int> z;
    int n,m;
    int dfs(int i){
    	int re=1;
    	for (auto it=s.begin();it!=s.end();){
    		if (a[i].count(*it)==0) {
    			int x=*it;
    			s.erase(x);
    			re+=dfs(x);
    			it=s.lower_bound(x);
    		} else it++;
    	}
    	return re;
    }
    int main() {
        ios_base::sync_with_stdio(0);
    	cin>>n>>m;
    	for(int i=0;i<m;i++) {
    		int x, y;
    		cin>>x>>y;
    		a[x].insert(y);
    		a[y].insert(x);
    	}
    	for(int i=1;i<=n;i++)s.insert(i);
    	while(s.size()){
    		int x = *s.begin();
    		s.erase(x);
    		z.push_back(dfs(x));
    	}
    	sort(z.begin(),z.end());
    	cout<<(int)z.size()-1<<endl;
    	//for (auto& i:z)cout<<i<<" ";
    	return 0;
    }
