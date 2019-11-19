#include<bits/stdc++.h>
using namespace std;
const int M=4e5+5;
int n,K;
char s[M];
bool check(){
	if(n&1)return 0;
	for(int i=2;i<=n;i++)
		if(s[i]==s[i-1])return 0;
	for(int i=1;i<=n;i++)
		if((s[i]=='B')!=(K&1))putchar('B');
		else putchar('W');
	putchar('\n');
	return 1;
}
bool mark[M];
int pre[M];
char pid[M];
int nxt[M];
char nid[M];
int main(){
	scanf("%d%d%s",&n,&K,s+1);
	if(check())return 0;
	for(int i=n+1;i<=2*n;i++)s[i]=s[i-n];
	n<<=1;
	int id=0;
	char ic=0;
	for(int i=2;i<=n;i++)
		if(s[i]==s[i-1]){
			mark[i]=1;
			id=i,ic=s[i];
		}else pre[i]=id,pid[i]=ic;
	id=2*n+1,ic=0;
	for(int i=n-1;i>=1;i--)
		if(s[i]==s[i+1]){
			mark[i]=1;
			id=i,ic=s[i];
		}else nxt[i]=id,nid[i]=ic;
	for(int i=1;i<=n/2;i++){
		if(mark[i]||mark[i+n/2])putchar(s[i]);
		else {
			int a;char b;
			if(i+n/2-pre[i+n/2]<nxt[i]-i){
				a=i+n/2-pre[i+n/2],b=pid[i+n/2];
			}else {
				a=nxt[i]-i,b=nid[i];
			}
			if(a<=K)putchar(b);
			else putchar((s[i]=='B')!=(K&1)?'B':'W');
		}
	}
	putchar('\n');
	return 0;
}