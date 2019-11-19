//Code by : Y-k-y
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define int long long
const int N=100010;
using namespace std;
inline int rnd(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
inline void wr(int x){
	if(x<0){putchar('-');x=-x;}if(x>9) wr(x/10);putchar(x%10+'0');
}
int n,m,T,t[5];
signed main(){
	cin>>T;
	while(T--){
		n=rnd();memset(t,0,sizeof(t));
		int x;
		for(int i=1;i<=n;i++){
			x=rnd();
			t[x&1]++;
		}
		m=rnd();
		int ans=0;
		for(int i=1;i<=m;i++){
			x=rnd();
			ans+=t[(x&1)];
		}
		wr(ans);puts("");
	}
	return 0;
}

