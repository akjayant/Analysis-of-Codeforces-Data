#include<stdio.h>
#include<iostream>
using namespace std;
int n,f[505][2],g[505][2];
int ans=-1,al=0,ar=0;
char sh[505];
int main(){
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		scanf("%c",&sh[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			swap(sh[i],sh[j]);
			int cntl=0,cntr=0,res=0;
			for(int k=1;k<=n;k++){
				if(sh[k]=='(') cntl++;
				else{
					if(cntl) cntl--;
					else cntr++;
				}
				f[k][0]=cntl;
				g[k][0]=cntr; 
			}
			cntl=cntr=0;
			for(int k=n;k>=1;k--){
				if(sh[k]==')') cntr++;
				else{
					if(cntr) cntr--;
					else cntl++;
				}
				f[k][1]=cntl;
				g[k][1]=cntr;
			}
			for(int k=0;k<n;k++)
			if((!f[k][0])&&(!g[k+1][1])&&g[k][0]==f[k+1][1]) res++;
			swap(sh[i],sh[j]);
			if(res>ans) ans=res,al=i,ar=j;
		}
	}
	if(sh[al]==')') swap(al,ar);
	printf("%d\n%d %d",ans,al,ar);
	return 0;
}