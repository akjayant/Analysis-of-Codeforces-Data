#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXN=100000+5;

vector<int> e[MAXN];

bool vis[MAXN];

int N,M;
int pre[MAXN],nex[MAXN];

void read() {
	scanf("%d%d",&N,&M);
	int i,x,y;
	for(i=1;i<=M;i++) {
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(i=0;i<=N;i++) {
		pre[i]=i-1;
		nex[i]=i+1;
	}
}

inline void del(int x) {
	int a=pre[x],b=nex[x];
	nex[a]=b;
	pre[b]=a;
}

void solve() {
	int cnt=0,ans=-1;
	int j;
	while(cnt<N) {
		queue<int> q;
		q.push(nex[0]);
		del(nex[0]);
		cnt++;
		ans++;
		while(!q.empty()) {
			int x=q.front();
			q.pop();
			for(vector<int>::iterator it=e[x].begin();it!=e[x].end();it++) {
				vis[*it]=true;
			}
			for(j=nex[0];j<=N;j=nex[j]) {
				if(!vis[j]) {
					del(j);
					q.push(j);
					cnt++;
				}
			}
			for(vector<int>::iterator it=e[x].begin();it!=e[x].end();it++) {
				vis[*it]=false;
			}
		}
	}
	printf("%d\n",ans);
}

int main() {
	read();
	solve();
	return 0;
}