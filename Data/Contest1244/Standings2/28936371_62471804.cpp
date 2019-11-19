#include<bits/stdc++.h>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
	int x=0,p=1;char c=getchar();
	while (c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while (c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu
const int N=1005;
int n;
char s[N];
//
void solve(){
	n=getint();
	scanf("%s",s);
	int l=INF,r=-INF;
	rep(i,n)if(s[i]=='1'){
		l=min(l,i);
		r=max(r,i);
	}
	int res=0;
	if(l==INF)res=n;
	else{
		res=max(res,max(2*(n-l),2*(r+1)));
		res=max(res,2*(r-l+1)+max(l,n-r-1));
	}
	cout<<res<<endl;
}
int main(){
	int t=getint();
	rep(i,t)solve();
	
	return 0;
}
