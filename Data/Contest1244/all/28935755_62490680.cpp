#include <bits/stdc++.h>
#include <algorithm>
#define pi 3.14159265358
using namespace std;
typedef long long ll;
const ll mod=1000000007;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int maxn = 3e6 + 5;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
ll arr[3][100100];
vector<int> vec[100100];
bool vis[100100];
int id[100100];
dfs(int index){
	for(int j=0;j<vec[index].size();j++){
		if(vis[vec[index][j]])
			continue;
		vis[vec[index][j]]=1;
//		cout<<vec[index][j]<<endl;
		id[vec[index][j]]=id[index]%3+1;
		dfs(vec[index][j]);
	}
}
int main(){
	int n,u,v;
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[0][i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[1][i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[2][i]);
	}
	for(int i=0;i<n-1;i++){
		u=read();
		v=read();
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	/*if(n==1){
		ll mn=min(arr[2][1],min(arr[0][1],arr[1][1]));
		if(mn==arr[0][1])
			printf("%lld\n1\n",mn);
		else if(mn==arr[1][1])
			printf("%lld\n2\n",mn);
		else if(mn==arr[2][1])
			printf("%lld\n3\n",mn);
		return 0;
	}
	if(n==2){
		ll mn=1e15;
		mn=min(mn,arr[2][1]+arr[0][2]);
		mn=min(mn,arr[2][1]+arr[1][2]);
		mn=min(mn,arr[0][1]+arr[1][2]);
		mn=min(mn,arr[0][1]+arr[2][2]);
		mn=min(mn,arr[1][1]+arr[0][2]);
		mn=min(mn,arr[1][1]+arr[2][2]);
		if(mn==arr[2][1]+arr[0][2])
			printf("%lld\n",mn);
		else if()
		return 0;
	}*/
	for(int i=1;i<=n;i++){
		if(vec[i].size()>2){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(vec[i].size()==1){
			vis[i]=1;
			id[i]=1;
			dfs(i);
			break;
		}
	}
	ll ans=1e16;
//	cout<<"123"<<endl;
	for(int j=0;j<3;j++){
		for(int k=0;k<3;k++){
			for(int l=0;l<3;l++){
				if(j==l||j==k||l==k)
					continue;
				ll temp=0;
				for(int i=1;i<=n;i++){
					if(id[i]==1){
						temp+=arr[j][i];
					}
					else if(id[i]==2){
						temp+=arr[k][i];
					}
					else{
						temp+=arr[l][i];
					}
				}
				ans=min(ans,temp);
			}
		}
	}
	printf("%lld\n",ans);
	for(int j=0;j<3;j++){
		for(int k=0;k<3;k++){
			for(int l=0;l<3;l++){
				if(j==l||j==k||l==k)
					continue;
				ll temp=0;
				for(int i=1;i<=n;i++){
					if(id[i]==1){
						temp+=arr[j][i];
					}
					else if(id[i]==2){
						temp+=arr[k][i];
					}
					else{
						temp+=arr[l][i];
					}
				}
				if(ans==temp){
					for(int i=1;i<=n;i++){
						if(id[i]==1){
							printf("%d ",j+1);
						}
						else if(id[i]==2){
							printf("%d ",k+1);
						}
						else{
							printf("%d ",l+1);
						}
					}
					printf("\n");
					return 0;
				}
			}
		}
	}
}