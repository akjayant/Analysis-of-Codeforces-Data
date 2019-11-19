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
//ruogu_alter
int a,b,c,d,e;
//
int main(){
	int t=getint();
	rep(ttt,t){
		a=getint();b=getint();c=getint();d=getint();
		e=getint();
		bool flag=false;
		for(int i=0;i<=e;i++)if(i*c>=a&&(e-i)*d>=b){
			cout<<i<<" "<<e-i<<endl;
			flag=true;
			break;
		}
		if(!flag)printf("%d\n",-1);
	}
	return 0;
}
