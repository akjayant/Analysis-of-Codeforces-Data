#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define int LL
#define INF 2147483647
#define LLINF 9223372036854775807
#define LL long long
#define xyx AKIOI
#define Dilute AKIOI
#define Chtholly_Tree AKIOI
#define time_interspace AKIOI
#define memset0 AKIOI
#define Isonan AKIOI
#define Sooke AKIOI
#define yeID AKIOI
#define _szh_ AKIOI
#define scimoon AKIOI
#define xay5421 AKIOI
#define dzh caibi
using namespace std;
int inline read(){
    int num=0,neg=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
    while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
    return num*neg;
}
LL n,a[100010],tot=1;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
signed main()
{
	n=read();a[1]=n;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			a[++tot]=i;
			if(i*i!=n)a[++tot]=n/i;
		}
	}int ans=gcd(a[1],a[2]);
	if(tot==1){cout<<a[1];return 0;}
	for(int i=3;i<=tot;i++)ans=gcd(ans,a[i]);cout<<ans;
	return 0;
}
