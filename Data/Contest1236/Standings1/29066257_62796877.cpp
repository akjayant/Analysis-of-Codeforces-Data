/*
  user: sky48
  language: c++
  for dream for young
*/
#include<iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define N 5005
typedef long long ll;
using namespace std;
int a[N][N],n,now; 
int gets()
{
	int v=0; char ch;bool f=0;
	while(!isdigit(ch=getchar())) if(ch=='-') f=1; v=ch-48;
	while( isdigit(ch=getchar())) v=(v<<1)+(v<<3)+ch-48;
	return f?-v:v;
}
int main ()
{
//  freopen("tt.txt","r",stdin);
	n=gets();
	rep(i,1,n){
		rep(j,1,n) a[i][j]=++now; 
		i++;
		if(i>n) break; 
		for(int j=n;j>=1;j--) a[i][j]=++now;
	}
	rep(i,1,n){ rep(j,1,n) printf("%d ",a[j][i]); puts(""); }
	return 0;
}
