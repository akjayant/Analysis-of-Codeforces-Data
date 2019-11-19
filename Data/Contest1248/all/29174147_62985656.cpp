#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read(){
	int f=1,ans=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return f*ans;
}
const int MAXN=511;
char str[MAXN];
int N,f1[MAXN],f2[MAXN];
inline void Dp1(){
	int totl=0,totr=0;
	for(register int i=1;i<=N;++i){
		if(str[i]=='(') totl++;
		else if(totl==0){
			totr++;
		}else totl--;
		if(totl==0) f1[i]=totr;
		else f1[i]=-1;
	}
}
inline void Dp2(){
	int totl=0,totr=0;
	for(register int i=N;i>=1;--i){
		if(str[i]==')') totr++;
		else if(totr==0){
			totl++;
		}else totr--;
		if(totr==0) f2[i]=totl;
		else f2[i]=-2;
	}
}
int Maxn,Ans,L,R;
int main(){
//	freopen("1.in","r",stdin);
	N=read();scanf("%s",str+1);
	Maxn=-1;
	for(register int i=1;i<=N;++i){
		for(register int j=i;j<=N;++j){
			swap(str[i],str[j]);
			Dp1();
			Dp2();Ans=(f1[N]==0);
			for(register int k=1;k<N;++k) Ans+=(f1[k]==f2[k+1]);
			if(Maxn<Ans) {Maxn=Ans;L=i,R=j;}
			swap(str[i],str[j]);
		}
	}
	printf("%d\n%d %d\n",Maxn,L,R);
	return 0;
}/*
10
()()())(()
*/
