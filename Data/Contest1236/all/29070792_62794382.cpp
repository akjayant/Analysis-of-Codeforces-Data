#include<bits/stdc++.h>
#define ll long long
#define scan(x) scanf("%d",&x)
#define scanl(x) scanf("%I64d",&x)
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=3e2+5;
const int mod=1e9+7; 
int n;
int m;
vector<int> ans[maxn];
int f[maxn][maxn];
void cal(){
	int minn=mod;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int z=0;z<ans[i].size();z++){
				f[i][j]+=lower_bound(ans[j].begin(),ans[j].end(),ans[i][z])-ans[j].begin();
			}
			minn=min(f[i][j],minn);
		}
	}
	cout<<minn<<"\n";
}
int main(){
//	freopen("in.txt","r",stdin);
	scan(n);
	for(int i=1;i<=n;i++){
		for(int j=(i-1)*n+1,k=1;j<=i*n;j++,k++){
			if(i&1){
				ans[k].push_back(j);
			}
			else ans[n-k+1].push_back(j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<ans[i].size();j++){
			if(j!=0) cout<<" ";
			cout<<ans[i][j];
		}
		cout<<"\n";
	}
	return 0;
}