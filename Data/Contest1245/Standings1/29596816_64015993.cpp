#include<bits/stdc++.h>
#define rep(q,a,b) for(int q=a,q##_end_=b;q<=q##_end_;++q)
#define dep(q,a,b) for(int q=a,q##_end_=b;q>=q##_end_;--q)
#define mem(a,b) memset(a,b,sizeof a )
using namespace std;
void in(int &r){
	static char c;
	r=0;
	bool flag=0;
	while(c=getchar(),!isdigit(c))if(c=='-')flag=1;
	do r=(r<<1)+(r<<3)+(c^48);
	while(c=getchar(),isdigit(c));
	if(flag)r=-r;
}
const int mn=2005;
int n;
struct node{
	int x,y;
}an[mn];
int val[mn],k[mn];
int last[mn];
int id[mn];
bool cmp(int a,int b){
	return val[a]<val[b];
}
int main(){
	int n;
	in(n);
	rep(q,1,n)in(an[q].x),in(an[q].y);
	rep(q,1,n)in(val[q]);
	rep(q,1,n)in(k[q]);
	rep(q,1,n)id[q]=q;
	sort(id+1,id+n+1,cmp);
	long long ans=0;
	rep(q,1,n){
		ans+=val[id[q]];
		rep(w,q+1,n){
			long long vt=(abs(an[id[w]].x-an[id[q]].x)+abs(an[id[w]].y-an[id[q]].y))*1LL*(k[id[w]]+k[id[q]]);
			if(vt<val[id[w]])last[id[w]]=id[q],val[id[w]]=vt;
		}
		sort(id+q+1,id+n+1,cmp);
	}
	printf("%I64d\n",ans);
	int tot=0;
	rep(q,1,n)if(!last[q]){
		++tot;
	}
	cout<<tot<<endl;
	rep(q,1,n)if(!last[q]){
		printf("%d ",q);
	}
	putchar('\n');
	cout<<n-tot<<endl;
	rep(q,1,n)if(last[q]){
		printf("%d %d\n",last[q],q);
	}
	return 0;
}