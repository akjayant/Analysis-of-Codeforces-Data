#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll co[3][100100];
vector<int> g[100100];

ll sum=0;
int used[100100];
int colar[100100];

void dfs(int s,int now){
	sum+=co[now][s];
	used[s]=1;
	for(int p:g[s]){
		if(!used[p]){
			dfs(p,(now+1)%3);
		}
	}
}

void dfs1(int s,int now){
	sum+=co[now][s];
	used[s]=1;
	for(int p:g[s]){
		if(!used[p]){
			dfs1(p,(now-1+3)%3);
		}
	}
}

void dfs2(int s,int now){
	used[s]=1;
	colar[s]=now+1;
	for(int p:g[s]){
		if(!used[p]){
			dfs2(p,(now+1)%3);
		}
	}
}

void dfs3(int s,int now){
	used[s]=1;
	colar[s]=now+1;
	for(int p:g[s]){
		if(!used[p]){
			dfs3(p,(now-1+3)%3);
		}
	}
}

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			cin >> co[i][j];
		}
	}
	for(int i=0;i<n-1;i++){
		int x,y; cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int s=-1;
	for(int i=0;i<n;i++){
		if(g[i].size()>2){
			cout << -1 << endl;
			return 0;
		}
		if(g[i].size()==1){
			s=i;
		}
	}
	ll ans=1e15;
	sum=0;
	for(int i=0;i<n;i++){
		used[i]=0;
	}
	dfs(s,0);
	ans=min(ans,sum);

	sum=0;
	for(int i=0;i<n;i++){
		used[i]=0;
	}
	dfs1(s,0);
	ans=min(ans,sum);

	sum=0;
	for(int i=0;i<n;i++){
		used[i]=0;
	}
	dfs(s,1);
	ans=min(ans,sum);

	sum=0;
	for(int i=0;i<n;i++){
		used[i]=0;
	}
	dfs1(s,1);
	ans=min(ans,sum);

	sum=0;
	for(int i=0;i<n;i++){
		used[i]=0;
	}
	dfs(s,2);
	ans=min(ans,sum);

	sum=0;
	for(int i=0;i<n;i++){
		used[i]=0;
	}
	dfs1(s,2);
	ans=min(ans,sum);
	cout << ans << endl;



	sum=0;
	for(int i=0;i<n;i++){
		used[i]=0;
	}
	dfs(s,0);
	if(sum==ans){
		for(int i=0;i<n;i++){
			used[i]=0;
		}
		dfs2(s,0);
		for(int i=0;i<n;i++){
			cout << colar[i] << " ";
		}
		cout << endl;
		return 0;
	}

	sum=0;
	for(int i=0;i<n;i++){
		used[i]=0;
	}
	dfs(s,1);
	if(sum==ans){
		for(int i=0;i<n;i++){
			used[i]=0;
		}
		dfs2(s,1);
		for(int i=0;i<n;i++){
			cout << colar[i] << " ";
		}
		cout << endl;
		return 0;
	}

	sum=0;
	for(int i=0;i<n;i++){
		used[i]=0;
	}
	dfs(s,2);
	if(sum==ans){
		for(int i=0;i<n;i++){
			used[i]=0;
		}
		dfs2(s,2);
		for(int i=0;i<n;i++){
			cout << colar[i] << " ";
		}
		cout << endl;
		return 0;
	}

	sum=0;
	for(int i=0;i<n;i++){
		used[i]=0;
	}
	dfs1(s,0);
	if(sum==ans){
		for(int i=0;i<n;i++){
			used[i]=0;
		}
		dfs3(s,0);
		for(int i=0;i<n;i++){
			cout << colar[i] << " ";
		}
		cout << endl;
		return 0;
	}

	sum=0;
	for(int i=0;i<n;i++){
		used[i]=0;
	}
	dfs1(s,1);
	if(sum==ans){
		for(int i=0;i<n;i++){
			used[i]=0;
		}
		dfs3(s,1);
		for(int i=0;i<n;i++){
			cout << colar[i] << " ";
		}
		cout << endl;
		return 0;
	}

	sum=0;
	for(int i=0;i<n;i++){
		used[i]=0;
	}
	dfs1(s,2);
	if(sum==ans){
		for(int i=0;i<n;i++){
			used[i]=0;
		}
		dfs3(s,2);
		for(int i=0;i<n;i++){
			cout << colar[i] << " ";
		}
		cout << endl;
		return 0;
	}
}