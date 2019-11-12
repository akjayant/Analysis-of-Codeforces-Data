#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e4+10,M=1e4+10;
int a[305][305],n;
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
inline LL quick(LL a,LL b,LL p){
    LL res = 1;
    for(;b;){
        if(b&1) res = (res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}
int main(){
    cin>>n;
    int t = n*n;
    for(int k=1;k<=n;k++){
        if(k&1){
            for(int i=1;i<=n;i++)
                a[i][k]=t--;
        }
        else{
            for(int i=n;i>=1;i--)
                a[i][k]=t--;
        }
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++)	printf("%d ",a[i][j]);puts("");
	}
        
    return 0;
}

