#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

#define LL long long
#define debug(x) cerr<<#x<<": "<<x<<endl;
#define fgx cerr<<"--------------"<<endl;
#define dgx cerr<<"=============="<<endl;

inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int INF = 2147483600;
const int MAXN = 200010;

int N,M,K;
vector<int> vec[2][MAXN+1];

inline int Getmn(int ln,int d,int bd,int rt){
	int pos=lower_bound(vec[d][ln].begin(),vec[d][ln].end(),bd)-vec[d][ln].begin();
	if(pos==vec[d][ln].size()) return rt; return min(rt,vec[d][ln][pos]);
}
inline int Getmx(int ln,int d,int bd,int rt){
	int pos=upper_bound(vec[d][ln].begin(),vec[d][ln].end(),bd)-vec[d][ln].begin();
	--pos; if(pos==-1) return rt; return max(rt,vec[d][ln][pos]);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(),M=read(),K=read();
	for(int i=1;i<=K;i++){
		int x=read(),y=read();
		vec[0][x].push_back(y);
		vec[1][y].push_back(x);
	} 
	int nx=1,ny=1,rl=1,rr=N,ll=1,lr=M,dir=1;
	for(int i=1;i<=N;i++) sort(vec[0][i].begin(),vec[0][i].end());
	for(int i=1;i<=M;i++) sort(vec[1][i].begin(),vec[1][i].end());
	LL vis=1;
	while(ll<=lr&&rl<=rr){
		//cout<<nx<<" "<<ny<<": "<<dir<<" "<<rl<<" "<<rr<<" | "<<ll<<" "<<lr<<" "<<vis<<endl;
		
		if(dir==1) {
			lr=Getmn(nx,0,ll,lr+1)-1;
			vis+=abs(lr-ny);
			ny=lr; ++rl;
		} else if(dir==3){
			ll=Getmx(nx,0,lr,ll-1)+1;
			vis+=abs(ll-ny);
			ny=ll; --rr;
		} else if(dir==2){
			rr=Getmn(ny,1,rl,rr+1)-1;
			vis+=abs(rr-nx);
			nx=rr; --lr;
		} else {
			rl=Getmx(ny,1,rr,rl-1)+1;
			vis+=abs(rl-nx);
			nx=rl; ++ll;
		} dir=(dir+1)%4;
		//cout<<rl<<" "<<rr<<" | "<<ll<<" "<<lr<<" | "<<nx<<" "<<ny<<endl;system("pause"); 
	}// cout<<vis<<endl;
	if((LL)vis+K==(LL)N*M){
		puts("Yes");
	} else puts("No");
	return 0;
}
