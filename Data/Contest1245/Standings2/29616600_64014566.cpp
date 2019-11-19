/*
* @Author: wxyww
* @Date: 2019-11-01 23:04:22
* @Last Modified time: 2019-11-01 23:19:47
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 2010;
ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
struct node {
	ll x,y,w;
}a[N];
ll dis[N],vis[N];
int fa[N];
vector<int>ans;
ll dist(int x,int y) {
	return (a[x].w + a[y].w) * (abs(a[x].x - a[y].x) + abs(a[x].y - a[y].y));
}
int main() {
	int n = read();
	for(int i = 1;i <= n;++i) {
		a[i].x = read();a[i].y = read();
	}
	for(int i = 1;i <= n;++i) {
		dis[i] = read();
		fa[i] = i;
	}

	for(int i = 1;i <= n;++i) a[i].w = read();


	dis[0] = 1e18;

	for(int i = 1;i <= n;++i) {
		int mn = 0;
		for(int j = 1;j <= n;++j)
			if(!vis[j] && dis[j] <= dis[mn]) mn = j;
		vis[mn] = 1;
		for(int j = 1;j <= n;++j) {
			if(vis[j]) continue;
			if(dis[j] > dist(mn,j)) {
				dis[j] = dist(mn,j);
				fa[j] = mn;
			}
		}
	}
	ll anss = 0;
	int tot = 0;
	for(int i = 1;i <= n;++i) {
		if(fa[i] == i) tot++;
		anss += dis[i];	
		// printf("!!%lld\n",dis[i]);
	}
	cout<<anss<<endl;
	printf("%d\n",tot);
	for(int i = 1;i <= n;++i) if(fa[i] == i) printf("%d ",i);

	puts("");
	printf("%d\n",n - tot);
	for(int i = 1;i <= n;++i) {
		if(fa[i] != i) {
			printf("%d %d\n",fa[i],i);
		}

	}

	return 0;
}