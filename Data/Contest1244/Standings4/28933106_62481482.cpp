#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

using namespace std;

int inf = 0x3f3f3f3f;
typedef long long ll;
ll linf = 0x3f3f3f3f3f3f3f3f;

vector<int> cl[4];
vector<vector<int>> g;
int ar[3]= {0, 1,2};
int ptr;
int col[100004];
int sol[100004];

long long dfs(int v, int p){
    if(p==-1){
	ptr=0;
    }
    int color = ar[ptr%3];
    col[v] = color;
    long long ret = cl[color][v];
    ptr++;
    for(auto u: g[v]){
	if(u==p) continue;
	ret+=dfs(u, v);
    }
    return ret;
}


int main(){
    int n;
    scanf("%d", &n);
    g.resize(n);
    for(int i=0;i<3;i++){
	cl[i].resize(n);
	for(int j=0;j<n;j++){
	    scanf("%d",&cl[i][j]);
	}
    }
    for(int i=0;i<n-1;i++){
	int t1,t2;
	scanf("%d %d", &t1, &t2);
	t1--;t2--;
	g[t1].push_back(t2);
	g[t2].push_back(t1);
    }
    int start;
    
    for(int i=0;i<n;i++){
	if(g[i].size()>=3) {
	    printf("-1\n");
	    return 0;
	}
	if(g[i].size()<=1) start = i;
    }
    ll t, opt = linf;
    for(int i=0;i<10;i++){
	t=dfs(start, -1);
	if(t<opt){
	    opt = t;
	    memcpy(sol,col, sizeof(col));
	}
	next_permutation(ar, ar+3);
    }
    printf("%I64d\n%d", opt, sol[0]+1);
    for(int i=1;i<n;i++){
	printf(" %d",sol[i]+1);
    }
    puts("");

    return 0;
}
