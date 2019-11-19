//by Judge
#include<cstdio>
#include<cstring>
#include<iostream>
#define Rg register
#define fp(i,a,b) for(Rg int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(Rg int i=(a),I=(b)-1;i>I;--i)
#define ll long long
using namespace std;
const int mod=1e9+7;
const int M=1e5+3;
typedef int arr[M];
inline int inc(int x,int y){return (x+=y)>=mod?x-mod:x;}
int n,m; arr f;
int main(){
	cin>>n>>m; if(n<m) swap(n,m);
	f[1]=2,f[2]=4; fp(i,3,n) f[i]=inc(f[i-1],f[i-2]);
	return !printf("%d\n",inc(inc(f[n],f[m]),mod-2));
}
