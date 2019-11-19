#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <bitset>
#include <array>

using namespace std;

const int maxn=1e5+5;
typedef long long ll;

const int komb[6][2]={{0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}};

int cost[3][maxn];
vector < int > ms[maxn];
ll val;
int col[maxn];

void dfs(int x, int boja, int prosli){
	val+=cost[boja-1][x];
	col[x]=boja;
	set < int > s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.erase(boja);
	s.erase(col[prosli]);
	int nova=*s.begin();
	for(int i=0; i<ms[x].size(); i++){
		if(ms[x][i]!=prosli){
			dfs(ms[x][i], nova, x);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i=0; i<3; i++){
		for(int j=0; j<n; j++){
			cin >> cost[i][j];
		}
	}
	int a, b;
	for(int i=0; i<n-1; i++){
		cin >> a >> b;
		a--;
		b--;
		ms[a].push_back(b);
	
		ms[b].push_back(a);
	}
	int root;
	for(int i=0; i<n; i++){
		if(ms[i].size()>2){
			cout << -1 << '\n';
			return 0;
		}
		if(ms[i].size()==1){
			root=i;
		}
	}
	int ind;
	ll mini=1e18;
	for(int i=0; i<6; i++){
		col[root]=komb[i][0]+1;
		val=cost[komb[i][0]][root];
		dfs(ms[root][0], komb[i][1]+1, root);
		if(mini>val){
			mini=val;
			ind=i;
		}
		memset(col, 0, sizeof(col));
	}
	col[root]=komb[ind][0]+1;
	val=cost[komb[ind][0]][root];
	dfs(ms[root][0], komb[ind][1]+1, root);
	cout << mini << '\n';
	for(int i=0; i<n; i++){
		cout << col[i] << " ";
	}
	cout << '\n';
	return 0;
}