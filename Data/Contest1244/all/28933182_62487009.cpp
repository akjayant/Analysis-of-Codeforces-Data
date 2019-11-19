#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll tab[3][100005];

int path[100005];

int colors[6][3]={{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,2,1},{3,1,2}};

int res[100005];

vector < vector < int > > G(100005);

ll cost(int g){
	ll ans = 0;
	for(int i=0;i<n;i++){
//		cerr << "kolor " << colors[g][i%3] << " dla " << path[i] << " +" << tab[colors[g][i%3]-1][path[i]-1] << "\n";
		ans += tab[colors[g][i%3]-1][path[i]-1];
	}
	//cerr << "koszt" << ans << "\n\n";
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<3;i++){
		for(int y=0;y<n;y++){
			scanf("%lld", &tab[i][y]);
		}
	}
	for(int i=1;i<n;i++){//n-1
		int t1,t2;
		scanf("%d %d", &t1,&t2);
		G[t1].push_back(t2);
		G[t2].push_back(t1);
		if(G[t1].size()>2 or G[t2].size()>2){
			printf("-1\n");
			return 0;
		}
	}
	//now we know its a path
	for(int i=1;i<=n;i++){
		if(G[i].size()==1){
			path[0] = i;
			path[1] = G[i][0];
			break;
		}
	}
	
	for(int i=2;i<n;i++){
		if(G[path[i-1]][0]!=path[i-2])
			path[i]=G[path[i-1]][0];
		else
			path[i]=G[path[i-1]][1];
	}
	
	//for(int i=0;i<n;i++)printf("%d ", path[i]);
	
	ll ans = 1e18;//inf
	int comb = -1;
	for(int i=0;i<6;i++){
		
		ll cur = cost(i);
		if( cur < ans ){
			ans = cur;
			comb = i;
		}
	}
	
	printf("%lld\n", ans);
	for(int i=0;i<n;i++){
		//tab[colors[i%3]][path[i]];
		res[path[i]] = colors[comb][i%3];
	}
	for(int i=1;i<=n;i++){
		printf("%d ", res[i]);
	}
	printf("\n");
	
	return 0;
}
