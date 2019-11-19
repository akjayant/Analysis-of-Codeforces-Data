#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
#define INF 2000000000000000;

int cost[MAX][3];
int res[10][MAX];
vector<int> g[MAX];
int op;
int id=0;
long long melhor=INF;
long long total;

void dfs(int node, int dis1, int dis2, int dis3, int parent){
	total+=cost[node][dis3];
	res[id][node]=dis3+1;
	
	for (int i=0; i<g[node].size(); i++){
		if (g[node][i]!=parent) dfs(g[node][i],dis3,dis1,dis2,node);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	
	for (int i=0; i<3; i++){
		for (int j=0; j<n; j++) scanf("%d", &cost[j][i]);
	}
	bool ans=true;
	for (int i=0; i<n-1; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
		if (g[x].size()>2 or g[y].size()>2){
			ans=false;
		}
	}
	
	if (!ans){
		printf("-1\n");
		return 0;
	}
	
	int ini;
	for (int i=0; i<n; i++){
		if (g[i].size()==1) ini=i;
	}
	//cout<<ini<<endl;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			for (int k=0; k<3; k++){
				if (i!=j and j!=k and k!=i){
					//cout<<i<<" "<<j<<" "<<k<<endl;
					total=0;
					dfs(ini,i,j,k,-1);
					if (total<melhor){
						melhor=total;
						op=id;
					}
					//cout<<total<<endl;
					id++;
				}
			}
		}
	}
	
	printf("%lld\n",melhor);
	for (int i=0; i<n; i++) printf("%d ", res[op][i]);
	


}
