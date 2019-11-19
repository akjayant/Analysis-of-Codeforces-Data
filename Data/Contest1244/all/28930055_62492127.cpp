#include<bits/stdc++.h>
#define fi first
#define se second 
#define mk make_pair
#define pb push_back
#define P pair<ll,ll>
#define INF 0x3f3f3f3f
#define mod 1000000007
#define lowbit(n) n&-n
#define mem(i) memset(i,0,sizeof(i))
#define bcnt(x) __builtin_popcount(x)
#define bcntz(x) __builtin_ctz(x)
using namespace std;
const int maxn=100010;
typedef long long ll;
typedef long double ld; 
int n,m;
int gi(){
    char a=getchar();int b=0;
    while(a<'0'||a>'9')a=getchar();
    while(a>='0'&&a<='9')b=b*10+a-'0',a=getchar();
    return b;
}
int tot=0,head[maxn];
struct abcd{
	int to,nxt,id;
	ll f;
}table[2*maxn];
void Ginit(){ tot=0;mem(table);mem(head);}
void Add(int x,int y,ll z){
	table[++tot].to=y;
	table[tot].f=z;
	table[tot].nxt=head[x];
	//table[tot].id=id;
	head[x]=tot;
}

int To[maxn];
void dfs(int x,int p){
	for(int i=head[x];i;i=table[i].nxt){
		if(table[i].to==p) continue;	
		To[x]=table[i].to;dfs(table[i].to,x);
	}
}


void no(){
	cout<<"-1"<<endl;
	exit(0);
}
ll sum[4][4],c1[maxn],c2[maxn],c3[maxn],dd[maxn],ans[4],c[maxn];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c1[i];
	for(int i=1;i<=n;i++) cin>>c2[i];
	for(int i=1;i<=n;i++) cin>>c3[i];
	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		Add(x,y,1);Add(y,x,1);
		dd[x]++;dd[y]++;
	}
	int root;
	for(int i=1;i<=n;i++){
		if(dd[i]>2){
			no();
		}
		if(dd[i]==1){
			root=i;
		}
	}
	vector<int> v[4];
	dfs(root,0);
	int cnt=0;
	for(int i=root;i;i=To[i]){
		v[cnt%3+1].pb(i);
		sum[cnt%3+1][1]+=c1[i];
		sum[cnt%3+1][2]+=c2[i];
		sum[cnt%3+1][3]+=c3[i];
		cnt++;
	}
	ll mn=1e18;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++){
				if(i==j || j==k || i==k) continue;
				if(sum[1][i]+sum[2][j]+sum[3][k]<mn){
					mn=sum[1][i]+sum[2][j]+sum[3][k];
					ans[1]=i,ans[2]=j,ans[3]=k;
				}
			}
	cout<<mn<<endl;
	for(int i=1;i<=3;i++)
		for(int j=0;j<v[i].size();j++){
			c[v[i][j]]=ans[i];
		}
	for(int i=1;i<=n;i++) cout<<c[i]<<" ";cout<<endl;
	
	return 0;
}

