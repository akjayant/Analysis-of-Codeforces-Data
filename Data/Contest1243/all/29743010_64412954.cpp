#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5+5;
set<int> G[maxn];
set<int> st;
int vis[maxn];
int n, m;
int p[maxn];
map<int, int> ans;
inline bool scan_d(int &num)  {        char in;bool IsN=false;        in=getchar();        if(in==EOF) return false;        while(in!='-'&&(in<'0'||in>'9')) in=getchar();        if(in=='-'){ IsN=true;num=0;}        else num=in-'0';        while(in=getchar(),in>='0'&&in<='9'){                num*=10,num+=in-'0';        }        if(IsN) num=-num;        return true;}
int find(int x) {
    return p[x] == x ? p[x] : p[x] = find(p[x]); 
}
void bfs(int s) {
    queue<int> q;
    q.push(s);
    for(int i = 1;i <= n;i++) 
        if(i != s) st.insert(i);
    set<int> st2;
    while(q.size()>0) {
        int now = q.front();
        q.pop();
        set<int>:: iterator it;
        st2.clear();
        for(it = st.begin(); it != st.end();it++) {
            if(!G[now].count(*it)) {
                p[find(now)] = find(*it);
                st2.insert(*it);
                q.push(*it);
            }
        }
        for(it = st2.begin(); it != st2.end();it++) {
            st.erase(*it);
        }
    }
}
int isPrime(ll n){	
	if(n==1 || n==2 || n==3) return 1;
	if(n%6!=1 && n%6!=5) return 0;
	double n_sqrt=floor(sqrt((double)n));
    int m=n_sqrt;
	for(int i=5;i<=m;i+=6){
	    if(n%(i)==0 | n%(i+2)==0) return 0;
	}
    return 1;
} 
int main(){
    cin>>n>>m;
    for(int i = 1;i <= n;i++) p[i]=i;
    for(int i = 1;i <= m;i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].insert(v);
        G[v].insert(u);
    }
    for(int i = 1;i <= n;i++) {
        if(p[i] == i) {
            bfs(i);
        }
    }
    for(int i = 1;i <= n;i++) 
        ans[p[i]]++;
    printf("%d\n", ans.size() - 1);
    return 0;
}