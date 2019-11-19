#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

template <typename T> inline int Chkmax (T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline int Chkmin (T &a, T b) { return a > b ? a = b, 1 : 0; }

template <typename T> inline T read(){
    T sum = 0;
    int fl = 1,ch = getchar();
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') fl = -1;
    for(; isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) + ch - '0';
    return sum * fl;
}

const int maxn = 1e6 + 5;

int n,m,ans = 0;
int head[maxn],cnt;
int vis[maxn];

set <int> s1,s2;

struct edge{
	int to;
	int next;
}e[maxn];

void add_edge(int u,int v){
	cnt++;
	e[cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

inline void Solve (){
	for(int i = head[1]; i; i = e[i].next){
		int y = e[i].to;
		vis[y] = 1;
		s1.insert(y);
	}
	for(int i = 2; i <= n; i++){
		if(!vis[i]) s2.insert(i);
	}
	for(int i = 2; i <= n; i++){
		if(s2.empty()){
			int x = *s1.begin();
			vis[x] = 0;
			s2.insert(x);
			s1.insert(x);
			ans++;
		}
		set <int> :: iterator it = s2.begin();
		for(int j = head[*it]; j; j = e[j].next){
			int y = e[j].to;
			if(vis[y]) s1.erase(y);
		}
		for(set <int> :: iterator j = s1.begin(); j != s1.end(); j++){
			vis[*j] = 0;
			s2.insert(*j);	
		}
		s1.clear();
		for(int j = head[*it]; j; j = e[j].next){
			int y = e[j].to;
			if(vis[y]) s1.insert(y);
		}
		s2.erase(*it);
	}
	printf("%d\n",ans);
}

inline void Input (){
	n = read<int>();
	m = read<int>();
	for(int i = 1; i <= m; i++){
		int x,y;
		x = read<int>();
		y = read<int>();
		add_edge(x,y);
		add_edge(y,x);
	}
}

int main(){
	Input();
	Solve();
	return 0;
}
