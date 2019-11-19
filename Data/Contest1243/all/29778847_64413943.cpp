#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = 1'000'000'007; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}

class union_find
{
	int  _setnum;
	vector<int> par, nume;
public:
	union_find(){
	}
	
	union_find(int x){
		par.resize(x);
		nume.resize(x);
		init();
	}
	
	~union_find(){
		//
		
	}
	
	void clear(){
		_setnum = 0;
		par.clear();
		nume.clear();
	}
	
	void init(){
		_setnum = par.size();
		for(int i = 0; i < par.size(); i++){
			par[i] = i;
			nume[i] = 1;
		}
	}
	
	void resize(int x){
		
		par.resize(x);
		nume.resize(x);
		init();
	}

	int find(int x){
		return par[x] == x ? x : par[x] = find(par[x]);
	}

	void unite(int x, int y){
		x = find(x);
		y = find(y);
	
		if(x == y)return;
		
		_setnum--;
		
		if(nume[x] > nume[y]) std::swap(x,y);
		
		par[x] = y;
		nume[y] += nume[x];
	}
	
	bool same(int x, int y){
		return find(x) == find(y);
	}
	
	int numel(int x){
		return nume[find(x)];
	}
	
	int size(){
		return par.size();
	}
	
	int setnum(){
		return _setnum;
	}
};


signed main(){
	// cin.tie(nullptr);
	// ios::sync_with_stdio(false);
	// cout<<fixed<<setprecision(10);
		
		union_find uf;
		vector<vector<int>> G;
		vector<int> ad, ad2;
		int N, M;
		
		cin>>N>>M;
		
		uf.resize(N);
		ad.resize(N,1);
		ad2.resize(N,1);
		G.resize(N);
		
		for(int i = 0; i < M; i++){
			int a, b;
			cin>>a>>b;
			a--, b--;
			G[a].push_back(b);
			G[b].push_back(a);
			
		}
		
		for(int i = 0; i < N; i++){
			sort(G[i].begin(), G[i].end());
			
			for(int j = 0; j < N;){
				int con = lower_bound(G[i].begin(), G[i].end(), ad[j] + j) - lower_bound(G[i].begin(), G[i].end(), j);
				if(con < ad[j]){
					uf.unite(i, j);
					if(j && uf.same(j-1,j)){
						ad[j - ad2[j-1]] += ad[j];
						ad2[j + ad[j] - 1] += ad2[j-1];
					}
				}
				j += ad[j];
			}
		}
		
		cout<<uf.setnum()-1<<endl;
	
	return 0;
}