#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

template<class T>void byebye(T _rpl){cout<<_rpl<<endl;exit(0);}
int nextint(){int x;scanf("%d",&x);return x;}
ll nextll(){ll x;scanf("%lld",&x);return x;}

const ll mod=1e9+7;

int read(){
	int f=1,ret=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ret=ret*10+(c-'0');c=getchar();}
	return ret*f;
}

const int dx[]={-1,0,1,0},dy[]={0,-1,0,1};

int res[1005][1005];
int n,m,ans;
ll a[3][100005];

bool check(){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			int cnt=0;
			for(int k=0;k<4;++k){
				int x=i+dx[k],y=j+dy[k];
				if(x>=0&&x<n&&y>=0&&y<m){
					if(res[i][j]==res[x][y])++cnt;
				}
			}
			if(cnt>1)return false;
		}
	}
}

void fill(int x,int y){
//	cerr<<x<<' '<<y<<endl;
	if(x==n){
		if(check())ans++;
		return;
	}
	if(y==m){fill(x+1,0);return;}
	res[x][y]=0;
	fill(x,y+1);
	res[x][y]=1;
	fill(x,y+1);
}

int main(){
	cin>>n>>m;
	//fill(0,0);
	//cout<<ans<<endl;
	a[0][1]=2;
	a[0][2]=4;
	for(int i=3;i<=100000;++i){
		a[0][i]=a[0][i-1]+a[0][i-2];
		a[0][i]%=mod;
	}
	ll ans=a[0][n]+a[0][m]-2ll;
	if(ans<0)ans+=mod;
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}
