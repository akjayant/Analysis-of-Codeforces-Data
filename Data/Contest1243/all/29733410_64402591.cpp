//problem link : https://codeforces.com/contest/920/problem/E
//soln : https://codeforces.com/contest/920/submission/34934391

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=10000020;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
    #ifdef LOCAL
        freopen("920E.txt","r",stdin);
    #endif
    buf[fread(buf,1,MAXSIZE,stdin)]='\0';
    bufpos=0;
}
#if NEG
int readint(){
    bool isneg;
    int val=0;
    for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
    bufpos+=(isneg=buf[bufpos]=='-');
    for(;isdigit(buf[bufpos]);bufpos++)
        val=val*10+buf[bufpos]-'0';
    return isneg?-val:val;
}
#else
int readint(){
    int val=0;
    for(;!isdigit(buf[bufpos]);bufpos++);
    for(;isdigit(buf[bufpos]);bufpos++)
        val=val*10+buf[bufpos]-'0';
    return val;
}
#endif
char readchar(){
    for(;isspace(buf[bufpos]);bufpos++);
    return buf[bufpos++];
}
int readstr(char* s){
    int cur=0;
    for(;isspace(buf[bufpos]);bufpos++);
    for(;!isspace(buf[bufpos]);bufpos++)
        s[cur++]=buf[bufpos];
    s[cur]='\0';
    return cur;
}
const int maxn=200002;
vector<int> e[maxn];
int fa[maxn],sz[maxn];
int getf(int x){
    return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void mer(int x,int y){
    x=getf(x);
    y=getf(y);
    if (x==y)
        return;
    fa[x]=y;
    sz[y]+=sz[x];
}
int cnt[maxn];
int now[maxn];
set<int> rt;
int main(){
    init();
    int n=readint(),m=readint();
    while(m--){
        int u=readint(),v=readint();
        if (u>v)
            swap(u,v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
        sz[i]=1;
        for(const auto& v : e[i])
            cnt[getf(v)]++;
        for(set<int>::iterator it=rt.begin();it!=rt.end();){
            int v=*it;
            if (cnt[v]<sz[v]){
                mer(v,i);
                rt.erase(it++);
            }else it++;
            cnt[v]=0;
        }
        rt.insert(i);
    }
    printf("%d\n",rt.size() - 1);
}