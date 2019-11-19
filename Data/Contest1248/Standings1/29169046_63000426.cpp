#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=500+10;
int n,i,j,k,ans,l,r;
char s[N];
int check(){
	int cnt=0,val=0,mx=-99999,pos=0;
	for (int i=1;i<=n;++i){
		if (s[i]=='(') val--;
		else val++;
		if (val>mx){
			mx=val;
			pos=i;
		}
	}
	if (pos==n) pos=1;
	else pos+=1;
	val=0;
	for (int i=pos;i<=n;++i){
		if (s[i]=='(') val--;
		else val++;
		if (val==0) cnt++; 
	}
	for (int i=1;i<pos;++i){
		if (s[i]=='(') val--;
		else val++;
		if (val==0) cnt++; 
	}
	return cnt;
}
int main(){
	scanf("%d%s",&n,s+1);
	int val=0;
	for (i=1;i<=n;++i){
		if (s[i]=='(') val++;
		else val--;
	}
	if (val!=0) return printf("0\n1 1\n"),0;
	for (i=1;i<=n;++i){
		for (j=i+1;j<=n;++j){
			swap(s[i],s[j]);
			int res=check();
			if (ans<res){
				ans=res;
				l=i,r=j;
			}
			swap(s[i],s[j]);
		}
	}
	printf("%d\n%d %d\n",ans,l,r);
	return 0;
}