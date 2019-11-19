#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];

int main() {
	// your code goes here
	int n,i,j,root,h[100005],x,y,z,xx,yy,zz,cc[100005];
	bool used[100005]={0};
	long long c[5][100005],t[5][5]={0},cmin=1e16;
	cin >> n;
	for(i=1;i<=n;i++) cin >> c[1][i];
	for(i=1;i<=n;i++) cin >> c[2][i];
	for(i=1;i<=n;i++) cin >> c[3][i];
	for(i=1;i<n;i++){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(i=1;i<=n;i++){
		if(g[i].size()==1) root=i;
		if(g[i].size()>2){
			cout << "-1" << endl;
			return 0;
		}
	}
	int memo=root,memo1;
	for(i=1;i<n;i++){
		used[memo]=true;
		h[i]=memo;
		for(j=0;j<g[memo].size();j++){
			if(!used[g[memo][j]]){
				memo1=g[memo][j];
			}
		}
		memo=memo1;
	}
	h[n]=memo;
	for(i=1;i<=n;i++){
		for(j=1;j<=3;j++){
			t[i%3+1][j]+=c[j][h[i]];
		}
	}
	for(i=1;i<=6;i++){
		x=i%3+1;
		if(i<=2) y=1;
		else if(i<=4) y=3;
		else y=2;
		z=6-x-y;
		long long cmemo=0;
		cmemo=t[1][x]+t[2][y]+t[3][z];
		if(cmin>cmemo){
			xx=x; yy=y; zz=z;
			cmin=cmemo;
		}
	}
	for(i=1;i<=n;i++){
		if(i%3==1) cc[h[i]]=yy;
		if(i%3==2) cc[h[i]]=zz;
		if(i%3==0) cc[h[i]]=xx;
	}
	cout << cmin << endl;
	for(i=1;i<=n;i++){
		cout << cc[i];
		if(i==n) cout << endl;
		else cout << " ";
	}
	return 0;
}