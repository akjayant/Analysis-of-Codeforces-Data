#include<bits/stdc++.h>
#define N 100005
using namespace std;
bool cur1;
int n,sze;
long long K;
struct node{
	int x,id;
}Q[N];
inline bool cmp(node a,node b){
	return a.x<b.x;
}
int cnt[N],num[N];
inline void Rd(int &res){
	char c;res=0;
	while(c=getchar(),c<48);
	do res=(res<<3)+(res<<1)+(c^48);
	while(c=getchar(),c>47);
	return;
}
bool cur2;
int main(){
//	printf("%lf MB\n",(&cur2-&cur1)/1024.0/1024);
	Rd(n);scanf("%lld",&K);
	for(int i=1;i<=n;i++)Rd(Q[i].x),Q[i].id=i;
	sort(Q+1,Q+n+1,cmp);
	Q[0].x=-2e9;
	for(int i=1;i<=n;i++){
		if(Q[i].x!=Q[i-1].x)cnt[++sze]=1,num[sze]=Q[i].x;
		else cnt[sze]++;
	}
	int l=1,r=sze;
	long long L=cnt[1],R=cnt[sze];
	while(l<r){
		long long o1=L*(num[l+1]-num[l]),o2=R*(num[r]-num[r-1]);
		if(L<R){
			if(o1>K){
				printf("%d\n",num[r]-num[l]-K/L);
				return 0;
			}
			K-=o1;
			L+=cnt[l+1];
			l++;
		}
		else{
			if(o2>K){
				printf("%d\n",num[r]-num[l]-K/R);
				return 0;
			}
			K-=o2;
			R+=cnt[r-1];
			r--;
		}
	}
	puts("0");
	return 0;
}