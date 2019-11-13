#include<bits/stdc++.h>
#define LL long long 
using namespace std;

inline int read(){
	int res=0,f=1;char ch=' ';
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
const int N=2005;
const int mod=998244353;
int T,n;
int num[4],ans[N],remain[4],tot,win;//1->R 2->P 3->S
char s[N];
inline void print(int x){
	if(x==1) printf("R");
	if(x==2) printf("P");
	if(x==3) printf("S");
}
int main(){
	T=read();
	while(T--){
		memset(ans,0,sizeof(ans));
		n=read();win=0;
		for(register int i=1;i<=3;i++) num[i]=read();
		for(register int i=1;i<=n;i++){
			cin>>s[i];
			if(s[i]=='R'){
				if(num[2]) num[2]--,win++,ans[i]=2;
			}
			if(s[i]=='P'){
				if(num[3]) num[3]--,win++,ans[i]=3;
			}
			if(s[i]=='S'){
				if(num[1]) num[1]--,win++,ans[i]=1;
			}
		}	//1->R 2->P 3->S
		if(win*2<n){
			puts("NO");
		}
		else{
			puts("YES");
			for(register int i=1;i<=n;i++){
				if(ans[i]) print(ans[i]);
				else{
					if(num[1]) print(1),num[1]--;
					else if(num[2]) print(2),num[2]--;
					else if(num[3]) print(3),num[3]--;
				}
			}
			printf("\n");
		}
	}
	return 0;
}