#include<bits/stdc++.h>
using namespace std;
long long int c[3][100005];
vector<int> g[100005];
vector<int> tree;
int main(){
	int n, u, v;
	scanf("%d", &n);

	for(int i=0;i<3;i++){
		for(int j=1;j<=n;j++){
			scanf("%lld", &c[i][j]);
		}
	}

	for(int i=0;i<n-1;i++){
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int cnt=0;
	for(int i=1;i<=n;i++){
		if(g[i].size()==1){
			cnt++;
			u=i;
		}
	}
	if(cnt>=3){
		printf("-1\n");
		return 0;
	}

	int par=-1;
	for(int i=0;i<n;i++){
		tree.push_back(u);
		if(g[u].size()==1){
			par=u;
			u=g[u][0];
		}
		else{
			if(g[u][0]==par){
				par=u;
				u=g[u][1];
			}
			else{
				par=u;
				u=g[u][0];
			}
		}
	}


	// Trying 0 and 1
	vector<pair<long long, int> > anss;
	long long ans=0;
	int colors[6][100005];
	for(int i=0;i<n;i++){
		if(i%3==0){
			colors[0][tree[i]]=0;
			ans+=c[0][tree[i]];
		}
		else if(i%3==1){
			colors[0][tree[i]]=1;
			ans+=c[1][tree[i]];
		}
		else{
			colors[0][tree[i]]=2;
			ans+=c[2][tree[i]];
		}
	}
	anss.push_back(make_pair(ans, 0));

	// Trying 1 & 0
	ans=0;
	for(int i=0;i<n;i++){
		if(i%3==0){
			colors[1][tree[i]]=1;
			ans+=c[1][tree[i]];
		}
		else if(i%3==1){
			colors[1][tree[i]]=0;
			ans+=c[0][tree[i]];
		}
		else{
			colors[1][tree[i]]=2;
			ans+=c[2][tree[i]];
		}
	}
	anss.push_back(make_pair(ans, 1));

	// Trying 0 & 2
	ans=0;
	for(int i=0;i<n;i++){
		if(i%3==0){
			colors[2][tree[i]]=0;
			ans+=c[0][tree[i]];
		}
		else if(i%3==1){
			colors[2][tree[i]]=2;
			ans+=c[2][tree[i]];
		}
		else{
			colors[2][tree[i]]=1;
			ans+=c[1][tree[i]];
		}
	}
	anss.push_back(make_pair(ans, 2));

	// Trying 2 & 0
	ans=0;
	for(int i=0;i<n;i++){
		if(i%3==0){
			colors[3][tree[i]]=2;
			ans+=c[2][tree[i]];
		}
		else if(i%3==1){
			colors[3][tree[i]]=0;
			ans+=c[0][tree[i]];
		}
		else{
			colors[3][tree[i]]=1;
			ans+=c[1][tree[i]];
		}
	}
	anss.push_back(make_pair(ans, 3));

	// Trying 1 & 2
	ans=0;
	for(int i=0;i<n;i++){
		if(i%3==0){
			colors[4][tree[i]]=1;
			ans+=c[1][tree[i]];
		}
		else if(i%3==1){
			colors[4][tree[i]]=2;
			ans+=c[2][tree[i]];
		}
		else{
			colors[4][tree[i]]=0;
			ans+=c[0][tree[i]];
		}
	}
	anss.push_back(make_pair(ans, 4));

	// Trying 2 & 1
	ans=0;
	for(int i=0;i<n;i++){

		if(i%3==0){
			colors[5][tree[i]]=2;
			ans+=c[2][tree[i]];
		}
		else if(i%3==1){
			colors[5][tree[i]]=1;
			ans+=c[1][tree[i]];
		}
		else{
			colors[5][tree[i]]=0;
			ans+=c[0][tree[i]];
		}
	}
	anss.push_back(make_pair(ans, 5));


	
	// Printing answer
	sort(anss.begin(), anss.end());
	// printf("%d\n", anss[0].second);
	printf("%lld\n", anss[0].first);
	for(int i=1;i<=n;i++){
		printf("%d ", colors[anss[0].second][i]+1);
	}
	printf("\n");
	return 0;
}