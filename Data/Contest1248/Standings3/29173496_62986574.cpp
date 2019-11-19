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
int n,x,y,a[N];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)a[i]=rnd();
	sort(a+1,a+1+n);
	int num=1;
	int l=1,r=n;
	while(l<=r){
		if(num&1)x+=a[r],r--;
		else y+=a[l],l++;
		num++;
	}
	wr(x*x+y*y);
	return 0;
}

