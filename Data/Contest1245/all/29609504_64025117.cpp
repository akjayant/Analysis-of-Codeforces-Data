#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
typedef pair<int,int> pr;
#define mpr make_pair
#define int ll
#define case int ___T; scanf("%d", &___T); for(int cas=1;cas<=___T;cas++)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
const ll INF = 0x3f3f3f3f3f3f3f3f;
const db eps = 1e-7;
const ll maxn = 2e3+5;
const ll maxm = 1e7;
const ll mod = 1e9+7;

int uu[maxn][2],mp[maxn][maxn],u1[maxn],u2[maxn];
int dist[maxn],vis[maxn],pre[maxn];
vector<int> as1;
vector<pr> as2;

signed main()
{
	int n;
	rd(n);
	for(int i=0;i<n;i++){
		rd(uu[i][0]);
		rd(uu[i][1]);
	}
	for(int i=0;i<n;i++) rd(u1[i]);
	for(int i=0;i<n;i++) rd(u2[i]);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mp[i][j] = (abs(uu[i][0]-uu[j][0])+abs(uu[i][1]-uu[j][1]))*(u2[i]+u2[j]);
		}
	}
	memset(dist,0x3f,sizeof(dist));
	int ans = 0;
	for(int k=0;k<n;k++)
	{
		int tmp = INF,num;
		int fg = 1;
		for(int i=0;i<n;i++)
		{
			if(dist[i]<tmp&&vis[i]==0){
				tmp = dist[i];
				num = i;
				fg = 1;
			}
			if(u1[i]<tmp&&vis[i]==0){
				tmp = u1[i];
				num = i;
				fg = 0;
			}
		}
		if(fg){
			ans += tmp;
			as2.push_back(mpr(num,pre[num]));
			vis[num] = 1;
			for(int i=0;i<n;i++){
				if(mp[i][num]<dist[i]){
					dist[i] = mp[i][num];
					pre[i] = num;
				}
			}
		}
		else{
			ans += tmp;
			as1.push_back(num);
			vis[num] = 1;
			for(int i=0;i<n;i++){
				if(mp[i][num]<dist[i]){
					dist[i] = mp[i][num];
					pre[i] = num;
				}
			}
		}
	}
	cout<<ans<<endl;
	cout<<as1.size()<<endl;
	for(int i=0;i<as1.size();i++){
		pt(as1[i]+1,' ');
	}
	cout<<endl;
	cout<<as2.size()<<endl;
	for(int i=0;i<as2.size();i++){
		pt(as2[i].first+1,' ');
		pt(as2[i].second+1,'\n');
	}
	cout<<endl;
	
	return 0;
}
