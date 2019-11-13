#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
typedef long long LL;
const int N = 1e4+50,M=1000;
const int p = 1e9+7;
int head[N],nex[M],to[M],w[M],tot=1;
inline void ade(int a,int b,int c){
	to[++tot]=b; nex[tot]=head[a]; w[tot]=c; head[a]=tot;
}
inline void add(int a,int b,int c){
	ade(a,b,c);	ade(b,a,0);
}
inline void ade1(int a,int b,int c){
	to[++tot]=b; nex[tot]=head[a]; w[tot]=c; head[a]=tot;
}
inline void add1(int a,int b,int c){
	ade(a,b,c);	ade(b,a,0);
}
inline LL quick(LL a,LL b){
    LL res = 1;
    for(;b;){
        if(b&1) res = (res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<quick(quick(2,m)-1,n)<<endl;
}

